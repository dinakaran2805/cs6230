import cocotb
from cocotb.triggers import RisingEdge,Timer, ClockCycles,FallingEdge
from cocotb.clock import Clock
from cocotb.binary import BinaryValue
from cocotb.regression import TestFactory
import random
from reference_model import main_model, multiplication, cfloat8_1_4_3_to_decimal, decimal_to_cfloat8_1_4_3


async def initial_setup(dut):
    cocotb.start_soon(Clock(dut.CLK, 1, units='ns').start())
    await RisingEdge(dut.CLK)
    dut.RST_N.value = 0
    await RisingEdge(dut.CLK)
    dut.RST_N.value = 1

async def input_driver(dut, sign1, exp1, mantissa1, sign2, exp2, mantissa2, rounding_mode, exponent_bias):
    input_value = sign1 << 20 | exp1 << 16 | mantissa1 << 13 | sign2 << 12 | exp2 << 8 | mantissa2 << 5 | rounding_mode << 4 | exponent_bias << 0
    
    await RisingEdge(dut.CLK)   
    dut.EN_send.value = 1
    dut.send_data_input.value = input_value
    await RisingEdge(dut.CLK)
    dut.EN_send.value = 0 

async def output_monitor(dut):
    await RisingEdge(dut.CLK)
    dut_output = dut.receive
    dut._log.info("dut output : ", dut_output.value , " type : ", type(dut_output.value))
    dut_output_sign = str(dut_output.value)[0]
    dut_output_exponent = str(dut_output.value)[1:5]
    dut_output_mantissa = str(dut_output.value)[5:]
    print(dut_output_sign, dut_output_exponent, dut_output_mantissa)
    return dut_output_sign, dut_output_exponent, dut_output_mantissa

async def scoreboard(dut , dut_s, dut_e, dut_m , rm_output):
    rm_s, rm_e, rm_m = split_string_into_bits(rm_output)
    await RisingEdge(dut.CLK)
    print("dut s : {0} rm s : {1} {2} {3}".format(int(dut_s, 2), rm_s, type(int(dut_s, 2)), type(rm_s)))
    print("dut e : {0} rm e : {1} {2} {3}".format(int(dut_e, 2), rm_e, type(int(dut_e, 2)), type(rm_e)))
    print("dut m : {0} rm m : {1} {2} {3}".format(int(dut_m, 2), rm_m, type(int(dut_m, 2)), type(rm_m)))
    assert int(dut_s, 2) == rm_s , "dut sign is not equal to the ref model sign"
    assert int(dut_e, 2) == rm_e, "dut exponent is not equal to the ref model exponent"
    assert int(dut_m, 2) == rm_m, "dut mantissa is not equal to the ref model mantissa"
    print("TEST PASSED!!!")


def hidden_bit_cal(exp):
    if(exp > 0):
        hidden_bit = 1
    else:
        hidden_bit = 0
    return hidden_bit    

def fn_to_shift_to_first_one_from_msb(input_string):
    for i, char in enumerate(input_string):
        if char == '1':
            print("val of i : ", i)
            return input_string[i:] , (i+1)
        
def cfloat8_1_4_3_to_decimal(n):
    sign = (-1)**int(n[0])
    mant = n[5:]
    exp = int(n[1:5],2)
    if exp == 0:
        num = int(mant[0])*0.5 + int(mant[1])*0.25 + int(mant[2])*0.125
    else:
        num = 1 + int(mant[0])*0.5 + int(mant[1])*0.25 + int(mant[2])*0.125
    
    #print("dddd",sign, num, exp)
    d = sign * num * (2**exp)
    return d

def decimal_to_cfloat8_1_4_3(d):
    if d >= 0:
        sign = "0"
    else:
        sign = "1"
        
    num = abs(d)
    e = 0
    while (num >= 2):
        if e <= 15:
            e += 1
            num = num/2
        else:
            e = 15
            num = 1.875
            
    exp = f'{e:04b}'
    
    if num >= 1:
        num = num - 1
    mant = ""
    for x in range(3):
        temp = num*2
        if  int(temp) == 0:
            mant += "0"
            num = temp
        else:
            mant += "1"
            num = temp - 1
        
        #print(sign, exp, mant)
    
    n = sign + exp + mant
    return n


def rm_for_multiplication (op1, op2, bias):

    op1 = cfloat8_1_4_3_to_decimal(op1)
    op2 = cfloat8_1_4_3_to_decimal(op2)
    q = op1 * op2
    
    uf = 0
    guf = 0
    of = 0
    unk = 0
    z = 0
    temp_q = 0
    if q >=0 and q < 0.0625:
        z = 1
        uf = 1
        temp_q = 0
    elif q >= 0.0625 and q < 0.125:
        temp_q = 0.125
        uf = 1
        guf = 1
    elif q >= 0.125 and q <= 0.875:
        x = 1
        while (x<7):
            a = (q - x*0.125)
            b = (q - (x+1)*0.125)
            if (a >= 0) and (b < 0) :
                if a < abs(b) :
                    temp_q = x*0.125
                else:
                    temp_q = (x+1)*0.125
                break
            x += 1
        uf = 1
        guf = 1
        
    elif q > 0.875 and q < 2:
        a = q - 0.875
        b = 2 - q
        if a < b :
            temp_q = 0.875
            guf = 1
        else:
            temp_q = 2
            unk = 1
        uf = 1
    
    elif q >= 2 and q <= (1.875 * (2**15)):
        num = q
        e = 0
        while (num >= 2):
            e += 1
            num = num/2
        num = num - 1
        x = 0
        while (x<8):
            a = (num - x*0.125)
            b = (num - (x+1)*0.125)
            if (a >= 0) and (b < 0) :
                if a < abs(b) :
                    temp = x*0.125
                else:
                    temp = (x+1)*0.125
                break
            x += 1
        temp_q = (1+temp)*(2**e)
    
    elif q > (1.875 * (2**15)):
        temp_q = (1.875 * (2**15))
        of = 1

    result = (temp_q * (2**bias))
    if(op1 * op2 > 0):
        final_result = result
    elif(op1*op2 < 0):
        final_result = -result
    res_in_cfloat = decimal_to_cfloat8_1_4_3(final_result)       
    return res_in_cfloat         
    # return (temp_q * (2**bias))



def ref_model(sign1, exp1, mantissa1, sign2, exp2, mantissa2, rounding_mode, exponent_bias):
    
    rm_sign = sign1 ^ sign2
    rm_exponent = exp1 + exp2 - exponent_bias
    rm_exponent_temp = rm_exponent
    hidden_bit1 = hidden_bit_cal(exp1)
    hidden_bit2 = hidden_bit_cal(exp2)
    man1 = hidden_bit1 << 3 | mantissa1 << 0
    man2 = hidden_bit2 << 3 | mantissa2 << 0
    final_man = man1 * man2
    final_man = bin(final_man)[2:].zfill(8)
    
    if(final_man[:2] == '01'):
        normalized_man = final_man[2:]
        
    elif(final_man[:2] == '10' or final_man[:2] == '11'):
        normalized_man = final_man[1:7]
        rm_exponent += 1
    else:
        normalized_man , exp_addition= fn_to_shift_to_first_one_from_msb(final_man[2:])
        normalized_man = normalized_man.ljust(6 , '0')
        rm_exponent += exp_addition
    
    if(normalized_man[3] == '1'):
        rounded_man = bin(int(normalized_man[:3], 2) + 1)[2:].zfill(3)
    else:
        rounded_man = normalized_man[:3]

    if(rm_exponent_temp >= 15):
        rm_exponent = 15
        rounded_man = 7    
    
    return rm_sign , rm_exponent , rounded_man

def split_string_into_bits(input):
    input = str(input).zfill(8)
    print("dina final debug today : {0}".format(input, type(input)))
    sign = int(str(input)[0], 2)
    exp = int(str(input)[1:5],2)
    man = int(str(input)[5:], 2)
    return sign, exp, man

async def testbench(dut, input1, input2, exp_bias):
    await initial_setup(dut)

    sign1, exp1, man1 = split_string_into_bits(input1)
    sign2, exp2, man2 = split_string_into_bits(input2)    
    r_mode = 1
    await input_driver(dut, sign1, exp1, man1, sign2, exp2, man2, r_mode, exp_bias)
    await Timer(10, 'ns')
    dut_sign , dut_exp, dut_mantissa = await output_monitor(dut)
    rm_output = main_model(input1, input2, exp_bias)
    # rm_sign, rm_exp, rm_mantissa = rm_for_multiplication()
    print("rm output : {0}".format(rm_output))
    await scoreboard(dut, dut_sign, dut_exp, dut_mantissa, rm_output)


@cocotb.test()
async def tb_pipeline(dut):
    await initial_setup(dut)
    input1_list = ["10010011","10011011","10100011","10101011","10110011"]
    input2_list = ["10001001","10001101","10001010","00001001","10001001"] 
    exp_bias = 1   
    r_mode = 1
    for i in range(len(input1_list)):
        sign1, exp1, man1 = split_string_into_bits(input1_list[i])
        sign2, exp2, man2 = split_string_into_bits(input2_list[i])
        await input_driver(dut, sign1, exp1, man1, sign2, exp2, man2, r_mode, exp_bias)

    for j in range(len(input1_list)):
        dut_sign , dut_exp, dut_mantissa = await output_monitor(dut)
        rm_output = main_model(input1_list[j], input2_list[j], exp_bias)
        # rm_sign, rm_exp, rm_mantissa = rm_for_multiplication()
        print("rm output for {0}: {1}".format(j,rm_output))
        # await scoreboard(dut, dut_sign, dut_exp, dut_mantissa, rm_output)

    await Timer(20,'ns')    





@cocotb.test()
async def test(dut):
    await initial_setup(dut)
    sign1 = 1
    exp1 = 2
    man1 = 3
    sign2 = 1
    exp2 = 1
    man2 = 1
    r_mode = 1
    exp_bias = 2
    await input_driver(dut, sign1, exp1, man1, sign2, exp2, man2, r_mode, exp_bias)
    await Timer(10, 'ns')
    # await output_monitor(dut)
    dut_sign , dut_exp, dut_mantissa = await output_monitor(dut)
    # print("dut sign : {0} dut exp : {1} dut mantissa : {2}".format(dut_sign, dut_exp, dut_mantissa))
    rm_sign, rm_exp, rm_mantissa = ref_model(sign1, exp1, man1, sign2, exp2, man2, r_mode, exp_bias)
    print("rm sign : {0} rm exp : {1} rm man : {2} types {3} {4} {5}".format(rm_sign, rm_exp, rm_mantissa , type(rm_sign), type(rm_exp), type(rm_mantissa)))
    await scoreboard(dut, dut_sign, dut_exp, dut_mantissa, rm_sign, rm_exp, rm_mantissa)


@cocotb.test()
async def tb_normal(dut):
    input1 = "10010011"
    input2 = "10001001"
    bias = 2
    await testbench(dut, input1, input2, bias)    

@cocotb.test()
async def tb_subnormal(dut):
    input1 = "10000011"
    input2 = "11001001"
    bias = 2
    await testbench(dut, input1, input2, bias)        

@cocotb.test()
async def tb_overflow(dut):
    input1 = "11111001"
    input2 = "11111010"
    bias = 2
    await testbench(dut, input1, input2, bias)

@cocotb.test()
async def tb_zero(dut):
    input1 = "10001000"
    input2 = "10001000"
    bias = 2
    await testbench(dut, input1, input2, bias)    
