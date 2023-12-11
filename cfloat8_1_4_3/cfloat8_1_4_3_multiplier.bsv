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

    Reg#(Bit#(3)) stage <- mkReg(1);
    
    Reg#(Bit#(3)) status_flags <- mkReg(0);

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

    Reg#(Bit#(1)) buffer1_sign1 <- mkReg(0);
    Reg#(Bit#(1)) buffer1_sign2 <- mkReg(0);
    Reg#(Bit#(4)) buffer1_exp1 <- mkReg(0);
    Reg#(Bit#(4)) buffer1_exp2 <- mkReg(0);
    Reg#(Bit#(3)) buffer1_man1 <- mkReg(0);
    Reg#(Bit#(3)) buffer1_man2 <- mkReg(0);
    Reg#(Bit#(1)) buffer1_rmode <- mkReg(0);
    Reg#(Bit#(4)) buffer1_bias <- mkReg(0);


    Reg#(Bit#(1)) buffer2_sign1 <- mkReg(0);
    Reg#(Bit#(1)) buffer2_sign2 <- mkReg(0);
    Reg#(Bit#(4)) buffer2_exp1 <- mkReg(0);
    Reg#(Bit#(4)) buffer2_exp2 <- mkReg(0);
    Reg#(Bit#(3)) buffer2_man1 <- mkReg(0);
    Reg#(Bit#(3)) buffer2_man2 <- mkReg(0);
    Reg#(Bit#(1)) buffer2_rmode <- mkReg(0);
    Reg#(Bit#(4)) buffer2_bias <- mkReg(0);


    Reg#(Bit#(1)) buffer3_sign1 <- mkReg(0);
    Reg#(Bit#(1)) buffer3_sign2 <- mkReg(0);
    Reg#(Bit#(4)) buffer3_exp1 <- mkReg(0);
    Reg#(Bit#(4)) buffer3_exp2 <- mkReg(0);
    Reg#(Bit#(3)) buffer3_man1 <- mkReg(0);
    Reg#(Bit#(3)) buffer3_man2 <- mkReg(0);
    Reg#(Bit#(1)) buffer3_rmode <- mkReg(0);
    Reg#(Bit#(4)) buffer3_bias <- mkReg(0);

    Reg#(Bit#(1)) buffer4_rmode <- mkReg(0);
    Reg#(Bit#(4)) buffer4_bias <- mkReg(0);

    Reg#(Bit#(1)) buffer5_rmode <- mkReg(0);
    Reg#(Bit#(4)) buffer5_bias <- mkReg(0);
    
    Reg#(Bit#(4)) normalized_count <- mkReg(0);
    Reg#(Bit#(6)) normalized_man <- mkReg(0);
    Reg#(Bit#(4)) normalized_exp <- mkReg(0);

    Reg#(Bit#(4)) final_bias <- mkReg(0);
    Reg#(Bit#(3)) rounded_man <- mkReg(0);

    Reg#(DT_cf8_143) stage1_output <- mkReg(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000});
    Reg#(DT_cf8_143) stage2_output <- mkReg(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000});
    Reg#(DT_cf8_143) stage3_output <- mkReg(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000});
    Reg#(DT_cf8_143) stage4_output <- mkReg(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000});
    Reg#(DT_cf8_143) stage5_output <- mkReg(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000});

    Reg#(Tuple4#(DT_cf8_143, DT_cf8_143,  Bit#(1), Bit#(4))) rg_operands <- mkReg(tuple4(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000},DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000},1'b0, 4'b0));
    Reg#(DT_cf8_143) final_output <- mkReg(DT_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b000});
    // rule trial;
       
    //     $display("welcome to the project");
    //     $display("***************************************************************************");
    // endrule   
    
    rule stage1;
        // sign_op1 <= tpl_1(rg_operands).sign;
        // sign_op2 <= tpl_2(rg_operands).sign;
        
        buffer1_sign1 <= tpl_1(rg_operands).sign;
        buffer1_sign2 <= tpl_2(rg_operands).sign;
        buffer1_exp1 <= tpl_1(rg_operands).exponent;
        buffer1_exp2 <= tpl_2(rg_operands).exponent;
        buffer1_man1 <= tpl_1(rg_operands).mantissa;
        buffer1_man2 <= tpl_2(rg_operands).mantissa;
        buffer1_rmode <= tpl_3(rg_operands);
        buffer1_bias <= tpl_4(rg_operands);
       
        final_sign <= buffer1_sign1 ^ buffer1_sign2;
        stage1_output <= DT_cf8_143{sign: final_sign, exponent: 4'b0000, mantissa: 3'b000};
        $display("STAGE 1 OUTPUT : sign : ", stage1_output.sign, " exponent : ", stage1_output.exponent, " mantissa : ", stage1_output.mantissa);
        // $display("DEBUGG ::: sign_op1 :",sign_op1 , " sign_op2 :",sign_op2);
        // $display("val of final sign : ", final_sign);
        // // stage <= 2;
        // $display("val of stage: ",stage); 
        // $display("***************************************************************************");
    endrule

    rule stage2;
        $display("stage2");
        // exp_op1 <= tpl_1(rg_operands).exponent;
        // exp_op2 <= tpl_2(rg_operands).exponent;

        buffer2_sign1 <= buffer1_sign1;
        buffer2_sign2 <= buffer1_sign2;
        buffer2_exp1 <=  buffer1_exp1;
        buffer2_exp2 <=  buffer1_exp2;
        buffer2_man1 <= buffer1_man1;
        buffer2_man2 <= buffer1_man2;
        buffer2_rmode <= buffer1_rmode;
        buffer2_bias <= buffer1_bias;

        // final_bias <= tpl_4(rg_operands);
        final_exp <=  (buffer2_exp1 + buffer2_exp2 - buffer2_bias);
        stage2_output <= DT_cf8_143{sign: stage1_output.sign, exponent: final_exp, mantissa: 3'b000};
        $display("STAGE 2 OUTPUT : sign : ", stage2_output.sign, " exponent : ", stage2_output.exponent, " mantissa : ", stage2_output.mantissa);
        // $display("DEBUGG of prev stage ::: sign_op1 :",sign_op1 , " sign_op2 :",sign_op2, " final_sign :", final_sign);
        // $display("DEBUGG ::: exp_op1 :", exp_op1, " exp_op2 :", exp_op2);
        // $display("val of final exp : ", final_exp, "val of bias : ",tpl_4(rg_operands),pack(tpl_4(rg_operands)));
        // if(final_exp != 4'b0000)
        // begin
        // $display("DINA DEBUGGG : val of final_exp : %b" , final_exp);
        // stage <= 3;
        // end    
        $display("***************************************************************************");
    endrule

    // rule to calculate the mantissa
    rule stage3;
        $display("stage3");
        Bit#(1) hidden_bit_op1;
        Bit#(1) hidden_bit_op2;
        Bit#(8) inter_mantissa1;
        Bit#(8) inter_mantissa2;
        

        buffer3_sign1 <= buffer2_sign1;
        buffer3_sign2 <= buffer2_sign2;
        buffer3_exp1 <=  buffer2_exp1;
        buffer3_exp2 <=  buffer2_exp2;
        buffer3_man1 <= buffer2_man1;
        buffer3_man2 <= buffer2_man2;
        buffer3_rmode <= buffer2_rmode;
        buffer3_bias <= buffer2_bias;


        hidden_bit_op1 = fn_hidden_bit_calc(buffer3_exp1);
        hidden_bit_op2 = fn_hidden_bit_calc(buffer3_exp2);

        // man_op1 <= tpl_1(rg_operands).mantissa;
        // man_op2 <= tpl_2(rg_operands).mantissa;

        inter_mantissa1 = zeroExtend({hidden_bit_op1,buffer3_man1});
        inter_mantissa2 = zeroExtend({hidden_bit_op2,buffer3_man2});
        
        let inter_man = inter_mantissa1 * inter_mantissa2;
        final_man <= inter_man;
        stage3_output <= DT_cf8_143{sign: stage2_output.sign, exponent: stage2_output.exponent, mantissa: stage2_output.mantissa};
        $display("STAGE 3 OUTPUT : sign : ", stage3_output.sign, " exponent : ", stage3_output.exponent, " mantissa : ", stage3_output.mantissa);
        // $display("DEBUGG of prev stage ::: exp_op1 :", exp_op1, " exp_op2 :", exp_op2 , " final_exp" , final_exp);
        // $display("DEBUGG ::: man_op1 : ", man_op1 , " man_op2 : ", man_op2);
        // $display("final_man : %b",final_man);

        // if(final_man != 8'b00000000)
        // begin
        // stage <= 4;
        // end     
        $display("***************************************************************************");
    endrule

    // rule to normalize the value
    rule stage4;
        $display("val of final man : %b ", final_man);
        buffer4_rmode <= buffer3_rmode;
        buffer4_bias <= buffer3_bias;

        if(final_man[7:6] == 2'b01)
            begin
                normalized_man <= final_man[5:0];
                stage4_output <= DT_cf8_143{sign: stage3_output.sign, exponent: stage3_output.exponent, mantissa: stage3_output.mantissa};
            end
        else if(final_man[7:6] == 2'b10 || final_man[7:6] == 2'b11)
            begin
                $display("the value of the hidden product is 10 or 11 . The exact value is : %b" ,final_man[7:6]);
                normalized_man <= zeroExtend(final_man[5:0] >> 1);
                normalized_exp <= stage3_output.exponent + 1;
                stage4_output <= DT_cf8_143{sign: stage3_output.sign, exponent: normalized_exp, mantissa: stage3_output.mantissa};
                $display("before shifting : %b" , final_man[5:0] , "after shifting : %b ", normalized_man);
            end    
        
        else
            begin
                Bit#(4) count_temp;
                let count_msb = countZerosMSB(final_man[5:0]);
                count_msb = count_msb + 1;
                count_temp = zeroExtend(pack(count_msb));
                $display("latest DEBUGG : count_temp  : %b" , count_temp , "final_exp : %b ", stage3_output.sign);
                if(count_temp < stage3_output.exponent)
                    begin
                        normalized_man <= final_man[5:0] << count_temp;
                        normalized_exp <= stage3_output.exponent - count_temp;
                        stage4_output <= DT_cf8_143{sign: stage3_output.sign, exponent: normalized_exp, mantissa: stage3_output.mantissa};
                    end    
                else
                    begin
                        //This condition will give a denormal value
                        normalized_man <= final_man[5:0] << stage3_output.exponent;
                        normalized_exp <= 0;
                        stage4_output <= DT_cf8_143{sign: stage3_output.sign, exponent: normalized_exp, mantissa: stage3_output.mantissa};
                    end        
                
                // $display("DEBUGG MSB count zeros : %b " , count_msb , "final exp : %b" , final_exp);
                // $display("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");

            end    
        // $display("value of normalized man : %b", normalized_man);
        


        $display("STAGE 4 OUTPUT : sign : ", stage4_output.sign, " exponent : ", stage4_output.exponent, " mantissa : ", stage4_output.mantissa);    
        // $display("stage4");
        // $display("val of final output : ", final_output);
        // if(normalized_man != 6'b000)
        // begin
        // $display("DEBUGG of prev stage ::: man_op1 : ", man_op1 , " man_op2 : ", man_op2 , "output man : %b", normalized_man);
        // stage <= 5;
        // end
        $display("***************************************************************************");
    endrule
    // rule for rounding mode and final normalization
    rule stage5;
        $display("stage5");
        buffer5_rmode <= buffer4_rmode;
        buffer5_bias <= buffer4_bias;

        if(buffer5_rmode == 1'b1)
            begin
            rounded_man <= fn_round_to_nearest(normalized_man);
            end
        //TODO add else condition to support the other rounding mode    
        $display("value of rounded man : %b" , rounded_man);

        stage5_output <= DT_cf8_143{sign: stage4_output.sign, exponent: stage4_output.exponent, mantissa: rounded_man};

        if(stage5_output.exponent == 4'b0000 && stage5_output.mantissa == 3'b000)
            begin
            status_flags <= 3'b001;
            end
        else if(stage5_output.exponent == 4'b0000 && stage5_output.mantissa != 3'b000)
            begin
            status_flags <= 3'b010;
            end
        else
            begin
            status_flags <= 3'b100;
            end    
        $display("status flags : ", status_flags);
        $display("STAGE 5 OUTPUT : sign : ", stage5_output.sign, " exponent : ", stage5_output.exponent, " mantissa : ", stage5_output.mantissa);    
        // final_output <= DT_cf8_143{sign: final_sign, exponent: final_exp, mantissa: rounded_man};
        // $display("INTER VALUES sign : ", stage4_output.sign, " exp : ", stage4_output.exponent , " mantissa : ", rounded_man);
        // $display("displaying the output ::: sign", stage5_output.sign , " exp : ", stage5_output.exponent, " man : ", stage5_output.mantissa);
    endrule


    method Action send(Tuple4#(DT_cf8_143,DT_cf8_143, Bit#(1) , Bit#(4)) data_input);
        rg_operands<=data_input;
        // stage <= 1;
        $display("Inside the method SEND");
        $display("val at operand1 is : ",tpl_1(rg_operands), " operand2 : ",tpl_2(rg_operands) , " r mode : ", tpl_3(rg_operands), " exp_bias", tpl_4(rg_operands) );
    endmethod

    method DT_cf8_143 receive();
        return stage5_output;
    endmethod
    // method ReturnType#(8,23) receive();
    //     $display("val at operand1 is : ",rg_operands.0, "operand2 : ",rg_operands.1 , "r mode : ", rg_operands.2, "exp_bias", rg_operands.3 );
    // endmethod    

endmodule    

endpackage
