import cocotb
from cocotb.triggers import RisingEdge,Timer, ClockCycles,FallingEdge
from cocotb.clock import Clock
from cocotb.binary import BinaryValue
from cocotb.regression import TestFactory
import random


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
    print("dut output : ", dut_output.value , " type : ", type(dut_output.value))
    dut_output_sign = str(dut_output.value)[0]
    dut_output_exponent = str(dut_output.value)[1:5]
    dut_output_mantissa = str(dut_output.value)[5:]
    print(dut_output_sign, dut_output_exponent, dut_output_mantissa)
    return dut_output_sign, dut_output_exponent, dut_output_mantissa

async def scoreboard(dut , dut_s, dut_e, dut_m , rm_s, rm_e, rm_m):
    await RisingEdge(dut.CLK)
    print("dut s : {0} rm s : {1} {2} {3}".format(int(dut_s, 2), int(rm_s), type(int(dut_s, 2)), type(int(rm_s))))
    print("dut e : {0} rm e : {1} {2} {3}".format(int(dut_e, 2), int(rm_e), type(int(dut_e, 2)), type(int(rm_e))))
    print("dut m : {0} rm m : {1} {2} {3}".format(int(dut_m, 2), int(rm_m.zfill(3), 2), type(int(dut_m, 2)), type(int(rm_m.zfill(3), 2))))
    assert int(dut_s, 2) == int(rm_s) , "dut sign is not equal to the ref model sign"
    assert int(dut_e, 2) == int(rm_e), "dut exponent is not equal to the ref model exponent"
    assert int(dut_m, 2) == int(rm_m.zfill(3), 2), "dut mantissa is not equal to the ref model mantissa"
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

def ref_model(sign1, exp1, mantissa1, sign2, exp2, mantissa2, rounding_mode, exponent_bias):
    
    rm_sign = sign1 ^ sign2
    rm_exponent = exp1 + exp2 - exponent_bias
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
    
    return rm_sign , rm_exponent , rounded_man
    
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
    exp_bias = 4
    await input_driver(dut, sign1, exp1, man1, sign2, exp2, man2, r_mode, exp_bias)
    await Timer(10, 'ns')
    # await output_monitor(dut)
    dut_sign , dut_exp, dut_mantissa = await output_monitor(dut)
    # print("dut sign : {0} dut exp : {1} dut mantissa : {2}".format(dut_sign, dut_exp, dut_mantissa))
    rm_sign, rm_exp, rm_mantissa = ref_model(sign1, exp1, man1, sign2, exp2, man2, r_mode, exp_bias)
    print("rm sign : {0} rm exp : {1} rm man : {2} types {3} {4} {5}".format(rm_sign, rm_exp, rm_mantissa , type(rm_sign), type(rm_exp), type(rm_mantissa)))
    await scoreboard(dut, dut_sign, dut_exp, dut_mantissa, rm_sign, rm_exp, rm_mantissa)