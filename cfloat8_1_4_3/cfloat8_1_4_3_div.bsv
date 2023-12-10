package cfloat8_1_4_3_div;

typedef struct {
   Bool     s;
   Bit#(ew)  e;
   Bit#(mw)  m;
} Cfloat_type#(numeric type ew, numeric type mw) deriving (Bits);


typedef struct {
   Bool invalid;
   Bool denormal;
   Bool overflow;
   Bool underflow;
} Exception deriving (Bits);


function Tuple3#(bit, bit, bit) fn_operands_check (Cfloat_type#(4,3) op);
  
  bit invalid_op = 0;
  bit denormal_op = 0;
  bit hidden = 0;

  if (op.e >= 0 && op.e <= 15) begin
    if (op.e != 0) begin
      hidden = 1;
      if (op.m != 0)begin
        denormal_op = 1;
      end
    end
  end
  else begin
    invalid_op = 1;
  end
  return tuple3(invalid_op, denormal_op, hidden);
endfunction

interface Ifc_Cfloat_div;        
  method Action send(Cfloat_type#(4,3) op1, Cfloat_type#(4,3) op2, Bit#(6) bias);
  method Cfloat_type#(4,3) res;
  method Exception status;
endinterface


(*synthesize*)
module mk_cfloat8_div(Ifc_Cfloat_div);
  
  Reg#(Tuple3#(bit, bit, bit)) ch_op1<-mkReg(tuple3(0,0,0));
  Reg#(Tuple3#(bit, bit, bit)) ch_op2<-mkReg(tuple3(0,0,0));
  Reg#(Cfloat_type#(4,3)) rg_op1 <- mkReg(unpack(0));
  Reg#(Cfloat_type#(4,3)) rg_op2 <- mkReg(unpack(0));
  Reg#(bit) h1 <- mkReg(0);
  Reg#(bit) h2 <- mkReg(0);  
  Reg#(Bit#(8)) out1 <- mkReg(0);
  Reg#(Exception) rg_status <- mkReg(unpack(0));
  Reg#(Bit#(4)) status1 <- mkReg(0);
  Reg#(Cfloat_type#(4,3)) rg_output <- mkReg(unpack(0));

  rule stage1_check;
    ch_op1 <= fn_operands_check(rg_op1);
    ch_op2 <= fn_operands_check(rg_op2);

    status1[3:2] <= {unpack(tpl_1(ch_op1) ^ tpl_1(ch_op2)), unpack(tpl_2(ch_op1) ^ tpl_2(ch_op2))};

    h1 <= tpl_3(ch_op1);
    h2 <= tpl_3(ch_op2);

  endrule

  rule stage2_div;

    out1 <= zeroExtend({h2,rg_op2.m} / {h1,rg_op1.m});
    rg_output <= unpack(out1);
    rg_status <= unpack(status1);
  endrule


  method Action send(Cfloat_type#(4,3) op1, Cfloat_type#(4,3) op2, Bit#(6) bias);
    rg_op1 <= op1;
    rg_op2 <= op2;
      
  endmethod

  method Cfloat_type#(4,3) res;
    return rg_output;
  endmethod

  method Exception status;
    return rg_status;
  endmethod

endmodule

endpackage
