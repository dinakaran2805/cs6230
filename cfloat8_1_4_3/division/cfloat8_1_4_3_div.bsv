package cfloat8_1_4_3_div;

//import common_func ::*;
import DReg ::*;
import Vector ::*;

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
   bit gd_underflow;
   bit unknown;
   bit zero;
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
    bit underflow ;
    Bit#(4) categ ;
} Stage7 deriving (Bits);

function Tuple2#(Bit#(4), Int#(7)) pre_proc (Cfloat_type#(4,3) op);
  Int#(7) shift = 0;
  Bit#(4) hm = 0;
  Int#(7) e = 0;
  Bit#(4) temp = 0;

  if (denormal(op) == 1) begin
    temp = {0,op.m};
    shift = unpack(zeroExtend(pack(countZerosMSB(temp))));
  end
  else begin
    temp = {1,op.m};
    shift = 0;
  end

  hm = temp << shift;
  e = unpack({3'b0, op.e}) - shift;

  return tuple2(hm, e);
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
  method bit valid;
endinterface


(*synthesize*)
module mk_cfloat8_div(Ifc_Cfloat_div);

  Reg#(Cfloat_type#(4,3)) rg_op1 <- mkReg(unpack(0));
  Reg#(Cfloat_type#(4,3)) rg_op2 <- mkReg(unpack(0));
  Reg#(Bit#(6)) rg_bias <- mkReg(0);
  Reg#(Int#(7)) rg_bias_1 <- mkReg(0);

  Reg#(Stage1) rg_stage1 <- mkReg(unpack(0));
  Reg#(Div) rg_stage2 <- mkReg(unpack(0));
  Reg#(Div) rg_stage3 <- mkReg(unpack(0));
  Reg#(Div) rg_stage4 <- mkReg(unpack(0));
  Reg#(Div) rg_stage5 <- mkReg(unpack(0));
  Reg#(Div) rg_stage6 <- mkReg(unpack(0));
  Reg#(Stage7) rg_stage7 <- mkReg(unpack(0));

  Vector#(9, Reg#(Bit#(1))) rg_valid <- replicateM(mkDReg(0));
  
  Reg#(Exception) rg_status <- mkReg(unpack(0));
  Reg#(Cfloat_type#(4,3)) rg_output <- mkReg(unpack(0));

  rule stage1_check;
    bit invalid = 0;
    bit denor = 0;

    let {hm1, e1} = pre_proc(rg_op1);
    let {hm2, e2} = pre_proc(rg_op2);

    Bit#(8) divisor = 0; 
    Bit#(8) dividend = 0;
    Int#(7) exp = 0; 
    bit sign = (rg_op2.s ^ rg_op1.s);
    denor = denormal(rg_op1) | denormal(rg_op2);

    if (hm1 > hm2) begin
      divisor = {hm1, 4'b0} >> 1;
      exp = e2 - e1 - 1;
    end
    else begin
      divisor = {hm1, 4'b0};
      exp = e2 - e1;
    end
    dividend = {hm2, 4'b0};

    rg_bias_1 <= unpack(zeroExtend(rg_bias));
    rg_stage1 <= Stage1 {sign : sign, exp : exp, num : dividend, den : divisor, denormal : denor, invalid : invalid};
    rg_valid[1] <= rg_valid[0];
    if (rg_valid[1] == 1) $display("STAGE1 :: sign : %0b, exp : %0b, num : %0b, den : %0b, denormal : %0b, invalid : %0b hm1 : %0b hm2 : %0b e1 : %0b e2 : %0b", sign, exp, dividend, divisor, denor, invalid, hm1, hm2, e1, e2);

  endrule

  rule stage2_div1;
    
    Bit#(8) r = rg_stage1.num; // - rg_stage1.den;
    Bit#(13) res = fn_div_stage (r, rg_stage1.den, 0);

    //$display("shift %0b, bias %0b", rg_shift_den, rg_bias_1);
    //rg_bias_shift <= rg_bias_1 - rg_shift_den; 
    Int#(7) exp = rg_stage1.exp + rg_bias_1;

    rg_stage2 <= Div {sign : rg_stage1.sign, exp : exp, rem : res[7:0], den : rg_stage1.den, quo: res[12:8], denormal : rg_stage1.denormal, invalid : rg_stage1.invalid};
    rg_valid[2] <= rg_valid[1];
    if (rg_valid[2] == 1) $display("STAGE2 :: exp %0b rem : %0b quo : %0b", exp, res[7:0], res[12:8]);
  endrule

  rule stage3_div2;
    
    Bit#(13) res = fn_div_stage (rg_stage2.rem, rg_stage2.den, rg_stage2.quo);
    //Int#(7) exp = rg_stage2.exp + rg_bias_shift;
    
    rg_stage3 <= Div {sign : rg_stage2.sign, exp : rg_stage2.exp, rem : res[7:0], den : rg_stage2.den, quo: res[12:8], denormal : rg_stage2.denormal, invalid : rg_stage2.invalid};
    rg_valid[3] <= rg_valid[2];
    if (rg_valid[3] == 1) $display("STAGE3 :: rem : %0b quo : %0b", res[7:0], res[12:8]);
  endrule

  rule stage4_div3;

    Bit#(13) res = fn_div_stage (rg_stage3.rem, rg_stage3.den, rg_stage3.quo);

    rg_stage4 <= Div {sign : rg_stage3.sign, exp : rg_stage3.exp, rem : res[7:0], den : rg_stage3.den, quo: res[12:8], denormal : rg_stage3.denormal, invalid : rg_stage3.invalid};
    rg_valid[4] <= rg_valid[3];
    if (rg_valid[4] == 1) $display("STAGE4 :: rem : %0b quo : %0b", res[7:0], res[12:8]);
  endrule

  rule stage5_div4;

    Bit#(13) res = fn_div_stage (rg_stage4.rem, rg_stage4.den, rg_stage4.quo);

    rg_stage5 <= Div {sign : rg_stage4.sign, exp : rg_stage4.exp, rem : res[7:0], den : rg_stage4.den, quo: res[12:8], denormal : rg_stage4.denormal, invalid : rg_stage4.invalid};
    rg_valid[5] <= rg_valid[4];
    if (rg_valid[5] == 1) $display("STAGE5 :: rem : %0b quo : %0b", res[7:0], res[12:8]);
  endrule

  rule stage6_div5;

    Bit#(13) res = fn_div_stage (rg_stage5.rem, rg_stage5.den, rg_stage5.quo);

    rg_stage6 <= Div {sign : rg_stage5.sign, exp : rg_stage5.exp, rem : res[7:0], den : rg_stage5.den, quo: res[12:8], denormal : rg_stage5.denormal, invalid : rg_stage5.invalid};
    rg_valid[6] <= rg_valid[5];
    if (rg_valid[6] == 1) $display("STAGE6 :: rem : %0b quo : %0b", res[7:0], res[12:8]);
  endrule

  rule stage7_norm;
    Int#(7) exp = rg_stage6.exp;

    Bit#(4) pre_exp = 4'b0;
    Bit#(5) pre_res = 5'b0;
    Bit#(4) categ = 4'b0000;
    bit underflow = 0;

    if (exp > 15) begin
      pre_res = 5'b11110;
      pre_exp = 4'b1111;
      categ = 4'b0001;
    end 
    else if ((exp >= 1) && (exp <= 15)) begin
      pre_res = rg_stage6.quo;
      pre_exp = truncate(pack(exp));
      categ = 4'b0010;
    end
    else if (exp == 0) begin
      pre_res = rg_stage6.quo;
      pre_exp = 0;
      categ = 4'b0100;
    end
    else if (exp == -1) begin
      pre_res = rg_stage6.quo >> 1;
      pre_exp = 0;
      categ = 4'b1000;
    end
    else if (exp == -2) begin
      pre_res = rg_stage6.quo >> 2;
      pre_exp = 0;
      categ = 4'b1000;
    end
    else if (exp == -3) begin
      pre_res = rg_stage6.quo >> 3;
      pre_exp = 0;
      categ = 4'b1000;
    end
    else if (exp == -4) begin
      if (rg_stage6.quo[3] == 1) begin
        pre_res = 5'b00010;
        categ = 4'b1000;
      end
      else begin
        pre_res = 5'b00000;
        categ = 4'b0000;
      end
      pre_exp = 0;
      underflow = 1;
    end
    else begin
      pre_res = 5'b00000;
      pre_exp = 0;
      categ = 4'b0000;
    end

    rg_stage7 <= Stage7 {sign : rg_stage6.sign, pre_exp : pre_exp,  res: pre_res, denormal : rg_stage6.denormal, invalid : rg_stage6.invalid, underflow : underflow, categ : categ };
    rg_valid[7] <= rg_valid[6];
    if (rg_valid[7] == 1) $display("STAGE7 :: pre_exp : %0b pre_res : %0b, underflow : %0b, categ : %0b", pre_exp, pre_res, underflow, categ);
  endrule

  rule stage8_round;
    Bit#(4) final_res;
    Bit#(4) final_exp; 
    bit overflow = 0;
    bit underflow = 0;
    bit invalid = 0;
    bit gd_underflow = 0;
    bit unknown = 0;
    bit zero = 0;
    Bit#(4) categ = rg_stage7.categ; 

    if (rg_stage7.res[0] == 1) begin
      if (rg_stage7.res[4:1] == 4'b1111) begin
        if (rg_stage7.pre_exp == 4'b1111) begin
          final_res = 4'b1111;
          final_exp = 4'b1111;
        end
        else begin
          final_res = 4'b1000;
          final_exp = rg_stage7.pre_exp + 1;
        end
        categ = categ >> 1;
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

    if (categ == 4'b0001) begin
      overflow = 1;
    end
    else if (categ == 4'b0100) begin
      if (final_res[2] == 1) begin
        final_res = 4'b1000;
        final_exp = 1;
      end
      else begin
        final_res = 4'b0111;
        final_exp = 0;
        gd_underflow = 1;
      end
      //underflow = 1;
      unknown = 1;
    end
    else if (categ == 4'b1000) begin
     // underflow = 1;
      gd_underflow = 1;
    end
    else if (categ == 4'b0000) begin
      //underflow = 1;
      zero = 1;
    end

    rg_output <= Cfloat_type {s : rg_stage7.sign, e : final_exp, m : final_res[2:0]};
    rg_status <= Exception {invalid : rg_stage7.invalid, denormal : rg_stage7.denormal, overflow : overflow, underflow : rg_stage7.underflow, gd_underflow : gd_underflow, unknown : unknown, zero : zero};
    rg_valid[8] <= rg_valid[7]; 
    if (rg_valid[8] == 1) $display("STAGE8 :: final exp : %0b final res : %0b, overflow : %0b, gd_uf : %0b, unk : %0b, zero : %0b", final_exp, final_res, overflow, gd_underflow, unknown, zero);
  endrule

  method Action send(Cfloat_type#(4,3) op1, Cfloat_type#(4,3) op2, Bit#(6) bias);
    rg_op1 <= op1;
    rg_op2 <= op2;
    rg_bias <= bias;
    rg_valid[0] <= 1;
      
  endmethod

  method Cfloat_type#(4,3) res;
    return rg_output;
  endmethod

  method Exception status;
    return rg_status;
  endmethod

  method bit valid;
    return rg_valid[8];
  endmethod

endmodule

endpackage
