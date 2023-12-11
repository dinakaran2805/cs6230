package testbench;

import cfloat8_1_4_3_multiplier ::*;
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

(* synthesize *)
module mkTestbench (Empty);
    Ifc_cfloat8_1_4_3 testmodule <- cfloat8_mul;
    Reg#(Int#(32)) count <- mkReg(0);
    rule greet;
        if(count > 20)
        begin
        $finish(0);
        end
        $display("hi dina");
        count <= count + 1 ;
    endrule
    
    rule giveInp(count <2);
        let op1 = DT_cf8_143{sign: 1'b1, exponent: 4'b0010, mantissa: 3'b011};
        let op2 = DT_cf8_143{sign: 1'b1, exponent: 4'b001, mantissa: 3'b01};
        Bit#(1) rm_mode = 1'b1;
        Bit#(4) exp_bias = 4'b0100;
        testmodule.send(tuple4(op1, op2, rm_mode, exp_bias));
        // testmodule.send(tuple4(dt_cf8_143{sign: 1'b0, exponent: 4'b0010, mantissa: 3'b011}, dt_cf8_143{sign: 1'b0, exponent: 4'b0000, mantissa: 3'b001}, rm_mode, exp_bias))
    endrule 
    
    // rule seeInp;
    //     testmodule.receive();
    // endrule    
endmodule


endpackage