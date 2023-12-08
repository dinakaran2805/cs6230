    `include "Logger.bsv"
package cfloat8_1_4_3_multiplier;
import Vector::*;
import DefaultValue      ::*;
import Real              ::*;
import BUtils            ::*;
import FShow             ::*;
import GetPut            ::*;
import ClientServer      ::*;
import FIFO              ::*;
import FixedPoint        ::*;
import DReg  :: *;
// import Logger ::*;

interface Ifc_cfloat8_1_4_3;
    method Action send(Tuple4#(DT_cf8_143, DT_cf8_143, Int#(32),Int#(32)) data_input);
    method DT_cf8_143 receive();     
endinterface

typedef struct {
    Bit#(1)    sign;
    Bit#(4)    exponent;
    Bit#(3)    mantissa;

}DT_cf8_143 deriving(Bits,Eq);

(* synthesize *)
module cfloat8_mul(Ifc_cfloat8_1_4_3);

    Reg#(Bit#(3)) stage <- mkReg(0);
    

    Reg#(Bit#(1)) final_sign <- mkReg(0);
    Reg#(Bit#(4)) final_exp <- mkReg(0);
    Reg#(Bit#(8)) final_man <- mkReg(0);
    Reg#(Bit#(3)) output_man <- mkReg(0);

    Reg#(Bit#(1)) sign_op1 <- mkReg(0);
    Reg#(Bit#(1)) sign_op2 <- mkReg(0);
    Reg#(Bit#(4)) exp_op1 <- mkReg(0);
    Reg#(Bit#(4)) exp_op2 <- mkReg(0);
    Reg#(Bit#(3)) man_op1 <- mkReg(0);
    Reg#(Bit#(3)) man_op2 <- mkReg(0);

    Reg#(Bit#(4)) normalized_count <- mkReg(0);
    Reg#(Bit#(6)) normalized_man <- mkReg(0);


    Reg#(Tuple4#(DT_cf8_143, DT_cf8_143,  Int#(32), Int#(32))) rg_operands <- mkReg(tuple4(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000},DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000},0, 0));
    Reg#(DT_cf8_143) final_output <- mkReg(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000});
    rule trial;
       
        $display("welcome to the project");
        $display("***************************************************************************");
    endrule   
    
    rule stage1(stage == 1);
        sign_op1 <= tpl_1(rg_operands).sign;
        sign_op2 <= tpl_2(rg_operands).sign;
        
       
        final_sign <= sign_op1 ^ sign_op2;
        $display("DEBUGG ::: sign_op1 :",sign_op1 , " sign_op2 :",sign_op2);
        $display("val of final sign : ", final_sign);
        stage <= stage +1;
        $display("val of stage: ",stage); 
        $display("***************************************************************************");
    endrule

    rule stage2(stage == 2);
        $display("stage2");
        exp_op1 <= tpl_1(rg_operands).exponent;
        exp_op2 <= tpl_2(rg_operands).exponent;
        final_exp <=  (exp_op1 + exp_op2);
        $display("DEBUGG of prev stage ::: sign_op1 :",sign_op1 , " sign_op2 :",sign_op2, " final_sign :", final_sign);
        $display("DEBUGG ::: exp_op1 :", exp_op1, " exp_op2 :", exp_op2);
        $display("val of final exp : ", final_exp, "val of bias : ",tpl_4(rg_operands),pack(tpl_4(rg_operands)));
        stage <= stage+1;
        $display("***************************************************************************");
    endrule
function Bit#(1) fn_hidden_bit_calc(Bit#(4) exponent);
    Bit#(1) hidden_bit_value;
    if(exponent == 0)
        begin
        hidden_bit_value = 1'b0;
        end
    else
        begin
        hidden_bit_value = 1'b1;
        end
    return hidden_bit_value;
endfunction

    rule stage3(stage == 3);
        $display("stage3");
        Bit#(1) hidden_bit_op1;
        Bit#(1) hidden_bit_op2;
        Bit#(8) inter_mantissa1;
        Bit#(8) inter_mantissa2;

        hidden_bit_op1 = fn_hidden_bit_calc(exp_op1);
        hidden_bit_op2= fn_hidden_bit_calc(exp_op2);

        man_op1 <= tpl_1(rg_operands).mantissa;
        man_op2 <= tpl_2(rg_operands).mantissa;

        inter_mantissa1 = zeroExtend({hidden_bit_op1,man_op1});
        inter_mantissa2 = zeroExtend({hidden_bit_op2,man_op2});
    
        final_man <= inter_mantissa1 * inter_mantissa2;
        $display("DEBUGG of prev stage ::: exp_op1 :", exp_op1, " exp_op2 :", exp_op2 , " final_exp" , final_exp);
        $display("DEBUGG ::: man_op1 : ", man_op1 , " man_op2 : ", man_op2);
        $display("final_man : %b",final_man);

        // round to nearest as per my understanding
        // if(final_man[2] == 1)
        // begin
        //     output_man <= final_man[5:3] +3'b001;
        //     $display("val aft rounding : %b", output_man);
        // end
        // else
        // begin
        //     output_man <= final_man[5:3];
        //     $display("val aft rounding : %b", output_man);
        // end
        if(final_man != 8'b00000000)
        begin
            stage <= stage+1;
        end     
        $display("***************************************************************************");
    endrule

    // rule round_off;
    //     $display("stage round off");
    //     $display("bit[4] :", final_man[3], "final_man : %b",final_man);
    //     $display("***************************************************************************");
    // endrule    

    rule stage4(stage == 4);
    //TODO : rounding mode and normalization if required
    // final_output.sign <= final_sign;
    // final_output.exponent <= final_exp;
    // final_output.mantissa <= final_man;

        if(final_man[7:6] == 2'b01)
        begin
        normalized_man <= final_man[5:0];
        end
        // else
        // begin
        // int j = 5;
        // while (final_man[j] == 1'b0)
        //     normalized_count <= normalized_count + 1;
        //     j = j+1;
        // normalized_count <= normalized_count + 1;
        // normalized_man <= final_man[5:0] << 1;
        // final_exp <= final_exp + normalized_count;     
        // end            


    
        $display("stage4");
        $display("DEBUGG of prev stage ::: man_op1 : ", man_op1 , " man_op2 : ", man_op2 , "output man : ", output_man);
        final_output <= DT_cf8_143{sign: final_sign, exponent: final_exp, mantissa: output_man};
        $display("val of final output : ", final_output);
        stage <= stage+1;
        $display("***************************************************************************");
    endrule

    rule display_output(stage == 5);
        $display("stage5");
        $display("INTER VALUES sign : ", final_sign, " exp : ", final_exp , " mantissa : ", output_man);
        $display("displaying the output ::: sign", final_output.sign , " exp : ", final_output.exponent, " man : ", final_output.mantissa);
    endrule


    method Action send(Tuple4#(DT_cf8_143,DT_cf8_143, Int#(32) , Int#(32)) data_input);
        rg_operands<=data_input;
        stage <= 1;
        $display("Inside the method SEND");
        $display("val at operand1 is : ",tpl_1(rg_operands), " operand2 : ",tpl_2(rg_operands) , " r mode : ", tpl_3(rg_operands), " exp_bias", tpl_4(rg_operands) );
    endmethod

    method DT_cf8_143 receive();
        return final_output;
    endmethod
    // method ReturnType#(8,23) receive();
    //     $display("val at operand1 is : ",rg_operands.0, "operand2 : ",rg_operands.1 , "r mode : ", rg_operands.2, "exp_bias", rg_operands.3 );
    // endmethod    

endmodule    

endpackage
