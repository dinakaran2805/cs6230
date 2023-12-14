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
    Reg#(Bit#(7)) final_exp <- mkReg(0);
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
    Reg#(Bit#(4)) buffer3_exp <- mkReg(0);

    Reg#(Bit#(1)) buffer4_rmode <- mkReg(0);
    Reg#(Bit#(4)) buffer4_bias <- mkReg(0);
    Reg#(Bit#(1)) buffer4_sign1 <- mkReg(0);
    Reg#(Bit#(1)) buffer4_sign2 <- mkReg(0);
    Reg#(Bit#(4)) buffer4_exp1 <- mkReg(0);
    Reg#(Bit#(4)) buffer4_exp2 <- mkReg(0);
    Reg#(Bit#(3)) buffer4_man1 <- mkReg(0);
    Reg#(Bit#(3)) buffer4_man2 <- mkReg(0);
    
    Reg#(Bit#(4)) buffer4_exp <- mkReg(0);

    Reg#(Bit#(1)) buffer5_rmode <- mkReg(0);
    Reg#(Bit#(4)) buffer5_bias <- mkReg(0);

    Reg#(Int#(7)) temp2_exp_int <- mkReg(0);
    Reg#(Int#(7)) temp3_exp_int <- mkReg(0);
    Reg#(Int#(7)) temp4_exp_int <- mkReg(0);
    Reg#(Int#(7)) temp5_exp_int <- mkReg(0);
    
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
    
    
    rule stage1;
        
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
        // $display("STAGE 1 OUTPUT : sign : ", stage1_output.sign, " exponent : ", stage1_output.exponent, " mantissa : ", stage1_output.mantissa);
        
    endrule

    rule stage2;
        Bit#(7) temp_exp;
        Int#(7) temp_exp_int;
        Int#(7) temp_exp1_int;
        Int#(7) temp_exp2_int;
        Int#(7) temp_bias_int;
        buffer2_sign1 <= buffer1_sign1;
        buffer2_sign2 <= buffer1_sign2;
        buffer2_exp1 <=  buffer1_exp1;
        buffer2_exp2 <=  buffer1_exp2;
        buffer2_man1 <= buffer1_man1;
        buffer2_man2 <= buffer1_man2;
        buffer2_rmode <= buffer1_rmode;
        buffer2_bias <= buffer1_bias;

        temp_exp1_int = unpack(signExtend(buffer2_exp1));
        temp_exp2_int = unpack(signExtend(buffer2_exp2));
        temp_bias_int = unpack(signExtend(buffer2_bias));
        temp_exp =  (signExtend(buffer2_exp1) + signExtend(buffer2_exp2) - signExtend(buffer2_bias)) ;
        // temp_exp_int = unpack(temp_exp);
        temp2_exp_int <= (temp_exp1_int + temp_exp2_int-temp_bias_int);
        if(temp2_exp_int > 15)
            begin
                //overflow condition for exponent
                temp_exp = 15; 
            end
        stage2_output <= DT_cf8_143{sign: stage1_output.sign, exponent: truncate(pack(temp2_exp_int)), mantissa: 3'b000};
        // $display("STAGE 2 OUTPUT : sign : ", stage2_output.sign, " exponent : ", stage2_output.exponent, " mantissa : ", stage2_output.mantissa);
  
    endrule

    // rule to calculate the mantissa
    rule stage3;
        Bit#(1) hidden_bit_op1;
        Bit#(1) hidden_bit_op2;
        Bit#(8) inter_mantissa1;
        Bit#(8) inter_mantissa2;
        
        temp3_exp_int <= temp2_exp_int;

        buffer3_sign1 <= buffer2_sign1;
        buffer3_sign2 <= buffer2_sign2;
        buffer3_exp1 <=  buffer2_exp1;
        buffer3_exp2 <=  buffer2_exp2;
        buffer3_man1 <= buffer2_man1;
        buffer3_man2 <= buffer2_man2;
        buffer3_rmode <= buffer2_rmode;
        buffer3_bias <= buffer2_bias;
        buffer3_exp <= stage2_output.exponent;


        hidden_bit_op1 = fn_hidden_bit_calc(buffer3_exp1);
        hidden_bit_op2 = fn_hidden_bit_calc(buffer3_exp2);


        inter_mantissa1 = zeroExtend({hidden_bit_op1,buffer3_man1});
        inter_mantissa2 = zeroExtend({hidden_bit_op2,buffer3_man2});
        
        let inter_man = inter_mantissa1 * inter_mantissa2;
        final_man <= inter_man;
        stage3_output <= DT_cf8_143{sign: stage2_output.sign, exponent: stage2_output.exponent, mantissa: stage2_output.mantissa};
        // $display("STAGE 3 OUTPUT : sign : ", stage3_output.sign, " exponent : ", stage3_output.exponent, " mantissa : ", stage3_output.mantissa);

    endrule

    // rule to normalize the value
    rule stage4;

        temp4_exp_int <= temp3_exp_int;

        buffer4_sign1 <= buffer3_sign1;
        buffer4_sign2 <= buffer3_sign2;
        buffer4_exp1 <=  buffer3_exp1;
        buffer4_exp2 <=  buffer3_exp2;
        buffer4_man1 <= buffer3_man1;
        buffer4_man2 <= buffer3_man2;

        buffer4_rmode <= buffer3_rmode;
        buffer4_bias <= buffer3_bias;
        buffer4_exp <= buffer3_exp;

        if(final_man[7:6] == 2'b01)
            begin
                normalized_man <= final_man[5:0];
                stage4_output <= DT_cf8_143{sign: stage3_output.sign, exponent: stage3_output.exponent, mantissa: stage3_output.mantissa};
            end
        else if(final_man[7:6] == 2'b10 || final_man[7:6] == 2'b11)
            begin
                normalized_man <= zeroExtend(final_man[5:0] >> 1);
                normalized_exp <= stage3_output.exponent + 1;
                stage4_output <= DT_cf8_143{sign: stage3_output.sign, exponent: normalized_exp, mantissa: stage3_output.mantissa};
                
            end    
        
        else
            begin
                Bit#(4) count_temp;
                let count_msb = countZerosMSB(final_man[5:0]);
                count_msb = count_msb + 1;
                count_temp = zeroExtend(pack(count_msb));
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
                
                

            end    

        // $display("STAGE 4 OUTPUT : sign : ", stage4_output.sign, " exponent : ", stage4_output.exponent, " mantissa : ", stage4_output.mantissa);    
        // $display("***************************************************************************");
    endrule


    // rule for rounding mode and final normalization
    rule stage5;
        Bit#(4) temp_exponent;
        Bit#(3) temp_mantissa;
        buffer5_rmode <= buffer4_rmode;
        buffer5_bias <= buffer4_bias;
        temp5_exp_int <= temp4_exp_int;

        if(buffer5_rmode == 1'b1)
            begin
            rounded_man <= fn_round_to_nearest(normalized_man);
            end
        //TODO add else condition to support the other rounding mode

        temp_exponent = stage4_output.exponent;
        temp_mantissa = rounded_man;
        if(temp5_exp_int >= 15)
        begin
                temp_exponent = 15;
                temp_mantissa = 7;
        end
        stage5_output <= DT_cf8_143{sign: stage4_output.sign, exponent: temp_exponent, mantissa: temp_mantissa};

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

    endrule


    method Action send(Tuple4#(DT_cf8_143,DT_cf8_143, Bit#(1) , Bit#(4)) data_input);
        rg_operands<=data_input;
    endmethod

    method DT_cf8_143 receive();
        return stage5_output;
    endmethod 

endmodule    

endpackage
