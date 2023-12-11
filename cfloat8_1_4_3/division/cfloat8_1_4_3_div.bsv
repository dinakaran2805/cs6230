package cfloat8_1_4_3_div;

//import common_func ::*;

typedef struct {
   bit     s;
   Bit#(ew)  e;
   Bit#(mw)  m;
} Cfloat_type#(numeric type ew, numeric type mw) deriving (Bits);

typedef struct {
   bit invalid;
   bit denormal;
   bit overflow;
   bit underflow;
} Exception deriving (Bits);

function bit denormal( Cfloat_type#(4,3) op );
   return op.e == 0 ? 1 : 0;
endfunction

function bit hidden( Cfloat_type#(4,3) op );
   return unpack(denormal(op)) ? 0 : 1;
endfunction

function bit zero( Cfloat_type#(4,3) op );
  return (unpack(denormal(op)) && (op.m == 0)) ? 1 : 0;
endfunction


typedef struct {
    bit sign        ;
    Int#(7) exp     ;
    Bit#(8) num  ;
    Bit#(8) den  ;
    bit denormal    ;
    bit invalid     ;
} Stage1 deriving (Bits);

typedef struct {
    bit sign        ;
    Int#(7) exp     ;
    Bit#(8) rem  ;
    Bit#(8) den  ;
    Bit#(5) quo ;
    bit denormal    ;
    bit invalid     ;
} Div deriving (Bits);


typedef struct {
    bit sign        ;
    Bit#(4) pre_exp     ;
    Bit#(5) res;
    bit denormal    ;
    bit invalid     ;
    bit overflow;
    bit underflow;
} Stage7 deriving (Bits);


function Bit#(3) shift_den (Cfloat_type#(4,3) op1, Cfloat_type#(4,3) op2);
  Bit#(3) shift = 3'b0;
  if (op2.m < op1.m) begin
    shift = pack(countZerosMSB({hidden(op2),op2.m}) + 1);
  end
  return shift;
endfunction

function Bit#(13) fn_div_stage (Bit#(8) r, Bit#(8) den, Bit#(5) quo);
    Bit#(5) q = 5'b0;
    Bit#(8) r2 = 8'b0;
 
    if (r >= den) begin
      q = {quo[3:0], 1'b1};
      r2 = r - den;
    end
    else begin
      q = {quo[3:0], 1'b0};
      r2 = r << 1;
    end
    return {q,r2};
endfunction


interface Ifc_Cfloat_div;        
  method Action send(Cfloat_type#(4,3) op1, Cfloat_type#(4,3) op2, Bit#(6) bias);
  method Cfloat_type#(4,3) res;
  method Exception status;
endinterface


(*synthesize*)
module mk_cfloat8_div(Ifc_Cfloat_div);

  Reg#(Cfloat_type#(4,3)) rg_op1 <- mkReg(unpack(0));
  Reg#(Cfloat_type#(4,3)) rg_op2 <- mkReg(unpack(0));
  Reg#(Bit#(6)) rg_bias <- mkReg(0);
  Reg#(Int#(7)) rg_shift_den <- mkReg(0);
  Reg#(Int#(7)) rg_bias_1 <- mkReg(0);
  Reg#(Int#(7)) rg_bias_shift <- mkReg(0);

  Reg#(Stage1) rg_stage1 <- mkReg(unpack(0));
  Reg#(Div) rg_stage2 <- mkReg(unpack(0));
  Reg#(Div) rg_stage3 <- mkReg(unpack(0));
  Reg#(Div) rg_stage4 <- mkReg(unpack(0));
  Reg#(Div) rg_stage5 <- mkReg(unpack(0));
  Reg#(Div) rg_stage6 <- mkReg(unpack(0));
  Reg#(Stage7) rg_stage7 <- mkReg(unpack(0));
  
  Reg#(Exception) rg_status <- mkReg(unpack(0));
  Reg#(Cfloat_type#(4,3)) rg_output <- mkReg(unpack(0));

  rule stage1_check;
    bit invalid = 0;
    bit denor = denormal(rg_op1) | denormal(rg_op2);
    Bit#(8) divisor = {hidden(rg_op1), rg_op1.m, 4'b0} >> shift_den(rg_op1, rg_op2);
    Bit#(8) dividend = {hidden(rg_op2), rg_op2.m, 4'b0};
    Int#(7) exp = unpack({3'b0,rg_op2.e} - {3'b0,rg_op1.e});
    bit sign = (rg_op2.s ^ rg_op1.s);
//TODO:propagate shift_den, bias 
    rg_shift_den <= unpack(zeroExtend(shift_den(rg_op1, rg_op2)));
    rg_bias_1 <= unpack(zeroExtend(rg_bias));
    rg_stage1 <= Stage1 {sign : sign, exp : exp, num : dividend, den : divisor, denormal : denor, invalid : invalid};

  endrule

  rule stage2_div1;
    
    Bit#(8) r = rg_stage1.num - rg_stage1.den;
    Bit#(13) res = fn_div_stage (r, rg_stage2.den, rg_stage2.quo);

    rg_bias_shift <= rg_bias_1 - rg_shift_den; 

    rg_stage2 <= Div {sign : rg_stage1.sign, exp : rg_stage1.exp, rem : res[7:0], den : rg_stage1.den, quo: res[12:8], denormal : rg_stage1.denormal, invalid : rg_stage1.invalid};
  endrule

  rule stage3_div2;
    
    Bit#(13) res = fn_div_stage (rg_stage2.rem, rg_stage2.den, rg_stage2.quo);
    Int#(7) exp = rg_stage2.exp + rg_bias_shift;
    
    rg_stage3 <= Div {sign : rg_stage2.sign, exp : exp, rem : res[7:0], den : rg_stage2.den, quo: res[12:8], denormal : rg_stage2.denormal, invalid : rg_stage2.invalid};
  endrule

  rule stage4_div3;

    Bit#(13) res = fn_div_stage (rg_stage3.rem, rg_stage3.den, rg_stage3.quo);

    rg_stage4 <= Div {sign : rg_stage3.sign, exp : rg_stage3.exp, rem : res[7:0], den : rg_stage3.den, quo: res[12:8], denormal : rg_stage3.denormal, invalid : rg_stage3.invalid};
  endrule

  rule stage5_div4;

    Bit#(13) res = fn_div_stage (rg_stage4.rem, rg_stage4.den, rg_stage4.quo);

    rg_stage5 <= Div {sign : rg_stage4.sign, exp : rg_stage4.exp, rem : res[7:0], den : rg_stage4.den, quo: res[12:8], denormal : rg_stage4.denormal, invalid : rg_stage4.invalid};
  endrule

  rule stage6_div5;

    Bit#(13) res = fn_div_stage (rg_stage5.rem, rg_stage5.den, rg_stage5.quo);

    rg_stage6 <= Div {sign : rg_stage5.sign, exp : rg_stage5.exp, rem : res[7:0], den : rg_stage5.den, quo: res[12:8], denormal : rg_stage5.denormal, invalid : rg_stage5.invalid};
  endrule

  rule stage7_norm;
    Int#(7) exp = rg_stage6.exp;

    Bit#(4) pre_exp = 4'b0;
    Bit#(5) pre_res = 5'b0;
    bit overflow = 0;
    bit underflow = 0;
    bit invalid = 0;

    if (exp > 15) begin
      pre_res = 5'b11110;
      pre_exp = 4'b1111;
      overflow = 1;
    end 
    else if ((exp >= 1) && (exp <= 15)) begin
      pre_res = rg_stage6.quo;
      pre_exp = truncate(pack(exp));
    end
    else if (exp == 0) begin
      pre_res = rg_stage6.quo;
      invalid = 1;
    end
    else if (exp == -1) begin
      pre_res = rg_stage6.quo >> 1;
    end
    else if (exp == -2) begin
      pre_res = rg_stage6.quo >> 2;
    end
    else if (exp == -3) begin
      pre_res = rg_stage6.quo >> 3;
    end
    else begin
      underflow = 1;
      pre_res = rg_stage6.quo >> 3;
      pre_exp = truncate(pack(exp)) + 3;
    end

    rg_stage7 <= Stage7 {sign : rg_stage6.sign, pre_exp : pre_exp,  res: pre_res, denormal : rg_stage6.denormal, invalid : (rg_stage6.invalid | invalid), overflow: overflow, underflow : underflow};

  endrule

  rule stage8_round;
    Bit#(4) final_res;
    Bit#(4) final_exp; 
    bit overflow;
    if (rg_stage7.res[0] == 1) begin
      if (rg_stage7.res[4:1] == 4'b1111) begin
        final_res = 4'b1000;
        final_exp = rg_stage7.pre_exp + 1;
       end
       else begin
        final_res = rg_stage7.res[4:1] + 1;
        final_exp = rg_stage7.pre_exp;
      end

    end
    else begin
      final_res = rg_stage7.res[4:1];
      final_exp = rg_stage7.pre_exp;
    end

    if (final_exp > 15) begin
      overflow = 1;
    end
    else begin
      overflow = 0;
    end
    rg_output <= Cfloat_type {s : rg_stage7.sign, e : final_exp, m : final_res[2:0]};
    rg_status <= Exception {invalid : rg_stage7.invalid, denormal : rg_stage7.denormal, overflow : (overflow | rg_stage7.overflow), underflow : rg_stage7.underflow};
  endrule

  method Action send(Cfloat_type#(4,3) op1, Cfloat_type#(4,3) op2, Bit#(6) bias);
    rg_op1 <= op1;
    rg_op2 <= op2;
    rg_bias <= bias;
      
  endmethod

  method Cfloat_type#(4,3) res;
    return rg_output;
  endmethod

  method Exception status;
    return rg_status;
  endmethod

endmodule

endpackage
