package cfloat8_1_4_3_div;

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

typedef struct {
    bit sign        ;
    Bit#(4) exp     ;
    Bit#(4) dividend;
    Bit#(4) divisor ;
    bit denormal    ;
    bit invalid     ;
} Stage1 deriving (Bits);

typedef struct {
    bit sign        ;
    Bit#(4) exp     ;
    Bit#(8) quotient;
    bit denormal    ;
    bit invalid     ;
} Stage2 deriving (Bits);

function Bit#(3) fn_operand_check (Cfloat_type#(4,3) op);
  
  bit invalid_op = 0;
  bit denormal_op = 0;
  bit hidden = 0;

  if (op.e >= 0 && op.e <= 15) begin
    if (op.e != 0) begin
      hidden = 1;
    end
    else begin
       if (op.m != 0) begin
        denormal_op = 1;
      end
    end
  end
  else begin
    invalid_op = 1;
  end
  return {invalid_op, denormal_op, hidden};
endfunction

function Bit#(4) fn_check(Cfloat_type#(4,3) op1, Cfloat_type#(4,3) op2);
   bit invalid = 0;
   bit denormal = 0;
   bit hid1 = 0;
   bit hid2 = 0;

   //Tuple3#(bit, bit, bit) ch_op1 = tuple3(0,0,0);
   //Tuple3#(bit, bit, bit) ch_op2 = tuple3(0,0,0);

   Bit#(3) ch_op1 =  fn_operand_check(op1);
   Bit#(3) ch_op2 =  fn_operand_check(op2);
   invalid = ch_op1[2] | ch_op2[2];
   denormal = ch_op1[1] | ch_op2[1];
   hid1 = ch_op1[0];
   hid2 = ch_op2[0];

   return {invalid, denormal, hid1, hid2};
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

  Reg#(Stage1) rg_stage1 <- mkReg(unpack(0));
  Reg#(Stage2) rg_stage2 <- mkReg(unpack(0));
  
  Reg#(Exception) rg_status <- mkReg(unpack(0));
  Reg#(Cfloat_type#(4,3)) rg_output <- mkReg(unpack(0));

  rule stage1_check;
    Bit#(4) ch = unpack(fn_check(rg_op1, rg_op2));
    bit invalid = ch[3];
    bit denormal = ch[2];
    Bit#(4) divisor = {ch[1], rg_op1.m};
    Bit#(4) dividend = {ch[0], rg_op2.m};
    Bit#(4) exp = rg_op2.e - rg_op1.e;
    bit sign = (rg_op2.s ^ rg_op1.s);

    rg_stage1 <= Stage1 {sign : sign, exp : exp, dividend : dividend, divisor : divisor, denormal : denormal, invalid : invalid};

  endrule

  rule stage2_div;
    Bit#(8) quot = zeroExtend(rg_stage1.dividend / rg_stage1.divisor);
    rg_stage2 <= Stage2 {sign : rg_stage1.sign, exp : rg_stage1.exp, quotient : quot, denormal : rg_stage1.denormal, invalid : rg_stage1.invalid};
    //rg_output <= unpack(out1);
    //rg_status <= unpack(status1);

  endrule

  rule stage3_norm;
    

  rule final_s;
    rg_output <= Cfloat_type {s : rg_stage2.sign, e : rg_stage2.exp, m : rg_stage2.quotient[2:0]};
    rg_status <= Exception {invalid : rg_stage2.invalid, denormal : rg_stage2.denormal, overflow : 1'b0, underflow : 1'b0};
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
