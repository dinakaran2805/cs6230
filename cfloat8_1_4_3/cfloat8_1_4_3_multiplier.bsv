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
    method Action send(Tuple4#(DT_cf8_143, DT_cf8_143, Bit#(1), Bit#(4)) data_input);
    method DT_cf8_143 receive();     
endinterface

typedef struct {
    Bit#(1)    sign;
    Bit#(4)    exponent;
    Bit#(3)    mantissa;

}DT_cf8_143 deriving(Bits,Eq);

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

function Bit#(3) fn_round_to_nearest(Bit#(6) normalized_mantissa);
    Bit#(3) rounded_value;
    if(normalized_mantissa[2] == 1'b1)
    begin
        rounded_value = normalized_mantissa[5:3] + 3'b001;
    end   
    else
    begin
        rounded_value = normalized_mantissa[5:3];
    end     

    return rounded_value;

endfunction


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

    Reg#(Bit#(4)) final_bias <- mkReg(0);
    Reg#(Bit#(3)) rounded_man <- mkReg(0);


    Reg#(Tuple4#(DT_cf8_143, DT_cf8_143,  Bit#(1), Bit#(4))) rg_operands <- mkReg(tuple4(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000},DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000},1'b0, 4'b0));
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
        final_bias <= tpl_4(rg_operands);
        final_exp <=  (exp_op1 + exp_op2);
        $display("DEBUGG of prev stage ::: sign_op1 :",sign_op1 , " sign_op2 :",sign_op2, " final_sign :", final_sign);
        $display("DEBUGG ::: exp_op1 :", exp_op1, " exp_op2 :", exp_op2);
        $display("val of final exp : ", final_exp, "val of bias : ",tpl_4(rg_operands),pack(tpl_4(rg_operands)));
        if(final_exp != 4'b0000)
        begin
        $display("DINA DEBUGGG : val of final_exp : %b" , final_exp);
        stage <= stage+1;
        end    
        $display("***************************************************************************");
    endrule

    // rule to calculate the mantissa
    rule stage3(stage == 3);
        $display("stage3");
        Bit#(1) hidden_bit_op1;
        Bit#(1) hidden_bit_op2;
        Bit#(4) inter_mantissa1;
        Bit#(4) inter_mantissa2;

        hidden_bit_op1 = fn_hidden_bit_calc(exp_op1);
        hidden_bit_op2 = fn_hidden_bit_calc(exp_op2);

        man_op1 <= tpl_1(rg_operands).mantissa;
        man_op2 <= tpl_2(rg_operands).mantissa;

        inter_mantissa1 = {hidden_bit_op1,man_op1};
        inter_mantissa2 = {hidden_bit_op2,man_op2};
    
        final_man <= zeroExtend(inter_mantissa1 * inter_mantissa2);
        $display("DEBUGG of prev stage ::: exp_op1 :", exp_op1, " exp_op2 :", exp_op2 , " final_exp" , final_exp);
        $display("DEBUGG ::: man_op1 : ", man_op1 , " man_op2 : ", man_op2);
        $display("final_man : %b",final_man);

        if(final_man != 8'b00000000)
        begin
            stage <= stage+1;
        end     
        $display("***************************************************************************");
    endrule

    // rule to normalize the value
    rule stage4(stage == 4);
    //TODO : rounding mode and normalization if required
        $display("val of final man : %b ", final_man);
        
        if(final_man[7:6] == 2'b01)
            begin
                normalized_man <= final_man[5:0];
            end
        else if(final_man[7:6] == 2'b10 || final_man[7:6] == 2'b11)
            begin
                $display("the value of the hidden product is 10 or 11 . The exact value is : %b" ,final_man[7:6]);
                normalized_man <= zeroExtend(final_man[5:0] >> 1);
                final_exp <= final_exp + 1;
                $display("before shifting : %b" , final_man[5:0] , "after shifting : %b ", normalized_man);
            end    
        
        else
            begin
                Bit#(4) count_temp;
                let count_msb = countZerosMSB(final_man[5:0]);
                count_msb = count_msb + 1;
                count_temp = zeroExtend(pack(count_msb));
                $display("latest DEBUGG : count_temp  : %b" , count_temp , "final_exp : %b ", final_exp);
                if(count_temp < final_exp)
                    begin
                        normalized_man <= final_man[5:0] << count_temp;
                        final_exp <= final_exp - count_temp;
                    end    
                else
                    begin
                        normalized_man <= final_man[5:0] << final_exp;
                        final_exp <= 0;
                    end        
                $display("DEBUGG MSB count zeros : %b " , count_msb , "final exp : %b" , final_exp);
                $display("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");

            end    
        $display("value of normalized man : %b", normalized_man);
        


    
        $display("stage4");
        $display("val of final output : ", final_output);
        if(normalized_man != 6'b000)
        begin
            $display("DEBUGG of prev stage ::: man_op1 : ", man_op1 , " man_op2 : ", man_op2 , "output man : %b", normalized_man);
            stage <= stage+1;
        end
        $display("***************************************************************************");
    endrule
    // rule for rounding mode and final value
    rule stage5(stage == 5);
        $display("stage5");
        if(tpl_3(rg_operands) == 1'b1)
            begin
            rounded_man <= fn_round_to_nearest(normalized_man);
            end
        //TODO add else condition to support the other rounding mode    
        $display("value of rounded man : %b" , rounded_man);
        final_output <= DT_cf8_143{sign: final_sign, exponent: final_exp, mantissa: rounded_man};
        $display("INTER VALUES sign : ", final_sign, " exp : ", final_exp , " mantissa : ", rounded_man);
        $display("displaying the output ::: sign", final_output.sign , " exp : ", final_output.exponent, " man : ", final_output.mantissa);
    endrule


    method Action send(Tuple4#(DT_cf8_143,DT_cf8_143, Bit#(1) , Bit#(4)) data_input);
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
