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

def denormal(op):
    if op in [0.125, 00.250, 0.375, 0.5, 0.625, 0.750, 0.875]:
        return 1
    else:
        return 0

def division (op1, op2, bias):
    
    dn = denormal(op1) or denormal(op2) 

    q = op2/op1

    
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
       # uf = 1
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
        #uf = 1
    
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
    status = '0'+str(dn)+str(of)+str(uf)+str(guf)+str(unk)+str(z)
    return result, status

def div_rm(a, b, bias):
    #b = "00000010"
    #a = "00001000"
    #bias = 0
    
    op1 = cfloat8_1_4_3_to_decimal(a)
    op2 = cfloat8_1_4_3_to_decimal(b)
    #print(op1 , op2)
    quo, status = division (abs(op1), abs(op2), bias)
    #print(quo)
    if op1*op2 > 0:
        q = quo
    elif op1*op2 < 0:
        q = -quo
    result = decimal_to_cfloat8_1_4_3(q)
    return result, status
#print(main())
