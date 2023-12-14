//
// Generated by Bluespec Compiler, version 2022.01-10-g3a4741b2 (build 3a4741b2)
//
// On Thu Dec 14 11:07:30 IST 2023
//
//
// Ports:
// Name                         I/O  size props
// RDY_send                       O     1 const
// receive                        O     8 reg
// RDY_receive                    O     1 const
// CLK                            I     1 clock
// RST_N                          I     1 reset
// send_data_input                I    21 reg
// EN_send                        I     1
//
// No combinational paths from inputs to outputs
//
//

`ifdef BSV_ASSIGNMENT_DELAY
`else
  `define BSV_ASSIGNMENT_DELAY
`endif

`ifdef BSV_POSITIVE_RESET
  `define BSV_RESET_VALUE 1'b1
  `define BSV_RESET_EDGE posedge
`else
  `define BSV_RESET_VALUE 1'b0
  `define BSV_RESET_EDGE negedge
`endif

module cfloat8_mul(CLK,
		   RST_N,

		   send_data_input,
		   EN_send,
		   RDY_send,

		   receive,
		   RDY_receive);
  input  CLK;
  input  RST_N;

  // action method send
  input  [20 : 0] send_data_input;
  input  EN_send;
  output RDY_send;

  // value method receive
  output [7 : 0] receive;
  output RDY_receive;

  // signals for module outputs
  wire [7 : 0] receive;
  wire RDY_receive, RDY_send;

  // register buffer1_bias
  reg [3 : 0] buffer1_bias;
  wire [3 : 0] buffer1_bias$D_IN;
  wire buffer1_bias$EN;

  // register buffer1_exp1
  reg [3 : 0] buffer1_exp1;
  wire [3 : 0] buffer1_exp1$D_IN;
  wire buffer1_exp1$EN;

  // register buffer1_exp2
  reg [3 : 0] buffer1_exp2;
  wire [3 : 0] buffer1_exp2$D_IN;
  wire buffer1_exp2$EN;

  // register buffer1_man1
  reg [2 : 0] buffer1_man1;
  wire [2 : 0] buffer1_man1$D_IN;
  wire buffer1_man1$EN;

  // register buffer1_man2
  reg [2 : 0] buffer1_man2;
  wire [2 : 0] buffer1_man2$D_IN;
  wire buffer1_man2$EN;

  // register buffer1_rmode
  reg buffer1_rmode;
  wire buffer1_rmode$D_IN, buffer1_rmode$EN;

  // register buffer1_sign1
  reg buffer1_sign1;
  wire buffer1_sign1$D_IN, buffer1_sign1$EN;

  // register buffer1_sign2
  reg buffer1_sign2;
  wire buffer1_sign2$D_IN, buffer1_sign2$EN;

  // register buffer2_bias
  reg [3 : 0] buffer2_bias;
  wire [3 : 0] buffer2_bias$D_IN;
  wire buffer2_bias$EN;

  // register buffer2_exp1
  reg [3 : 0] buffer2_exp1;
  wire [3 : 0] buffer2_exp1$D_IN;
  wire buffer2_exp1$EN;

  // register buffer2_exp2
  reg [3 : 0] buffer2_exp2;
  wire [3 : 0] buffer2_exp2$D_IN;
  wire buffer2_exp2$EN;

  // register buffer2_man1
  reg [2 : 0] buffer2_man1;
  wire [2 : 0] buffer2_man1$D_IN;
  wire buffer2_man1$EN;

  // register buffer2_man2
  reg [2 : 0] buffer2_man2;
  wire [2 : 0] buffer2_man2$D_IN;
  wire buffer2_man2$EN;

  // register buffer2_rmode
  reg buffer2_rmode;
  wire buffer2_rmode$D_IN, buffer2_rmode$EN;

  // register buffer2_sign1
  reg buffer2_sign1;
  wire buffer2_sign1$D_IN, buffer2_sign1$EN;

  // register buffer2_sign2
  reg buffer2_sign2;
  wire buffer2_sign2$D_IN, buffer2_sign2$EN;

  // register buffer3_bias
  reg [3 : 0] buffer3_bias;
  wire [3 : 0] buffer3_bias$D_IN;
  wire buffer3_bias$EN;

  // register buffer3_exp
  reg [3 : 0] buffer3_exp;
  wire [3 : 0] buffer3_exp$D_IN;
  wire buffer3_exp$EN;

  // register buffer3_exp1
  reg [3 : 0] buffer3_exp1;
  wire [3 : 0] buffer3_exp1$D_IN;
  wire buffer3_exp1$EN;

  // register buffer3_exp2
  reg [3 : 0] buffer3_exp2;
  wire [3 : 0] buffer3_exp2$D_IN;
  wire buffer3_exp2$EN;

  // register buffer3_man1
  reg [2 : 0] buffer3_man1;
  wire [2 : 0] buffer3_man1$D_IN;
  wire buffer3_man1$EN;

  // register buffer3_man2
  reg [2 : 0] buffer3_man2;
  wire [2 : 0] buffer3_man2$D_IN;
  wire buffer3_man2$EN;

  // register buffer3_rmode
  reg buffer3_rmode;
  wire buffer3_rmode$D_IN, buffer3_rmode$EN;

  // register buffer3_sign1
  reg buffer3_sign1;
  wire buffer3_sign1$D_IN, buffer3_sign1$EN;

  // register buffer3_sign2
  reg buffer3_sign2;
  wire buffer3_sign2$D_IN, buffer3_sign2$EN;

  // register buffer4_bias
  reg [3 : 0] buffer4_bias;
  wire [3 : 0] buffer4_bias$D_IN;
  wire buffer4_bias$EN;

  // register buffer4_exp
  reg [3 : 0] buffer4_exp;
  wire [3 : 0] buffer4_exp$D_IN;
  wire buffer4_exp$EN;

  // register buffer4_exp1
  reg [3 : 0] buffer4_exp1;
  wire [3 : 0] buffer4_exp1$D_IN;
  wire buffer4_exp1$EN;

  // register buffer4_exp2
  reg [3 : 0] buffer4_exp2;
  wire [3 : 0] buffer4_exp2$D_IN;
  wire buffer4_exp2$EN;

  // register buffer4_man1
  reg [2 : 0] buffer4_man1;
  wire [2 : 0] buffer4_man1$D_IN;
  wire buffer4_man1$EN;

  // register buffer4_man2
  reg [2 : 0] buffer4_man2;
  wire [2 : 0] buffer4_man2$D_IN;
  wire buffer4_man2$EN;

  // register buffer4_rmode
  reg buffer4_rmode;
  wire buffer4_rmode$D_IN, buffer4_rmode$EN;

  // register buffer4_sign1
  reg buffer4_sign1;
  wire buffer4_sign1$D_IN, buffer4_sign1$EN;

  // register buffer4_sign2
  reg buffer4_sign2;
  wire buffer4_sign2$D_IN, buffer4_sign2$EN;

  // register buffer5_bias
  reg [3 : 0] buffer5_bias;
  wire [3 : 0] buffer5_bias$D_IN;
  wire buffer5_bias$EN;

  // register buffer5_rmode
  reg buffer5_rmode;
  wire buffer5_rmode$D_IN, buffer5_rmode$EN;

  // register exp_op1
  reg [3 : 0] exp_op1;
  wire [3 : 0] exp_op1$D_IN;
  wire exp_op1$EN;

  // register exp_op2
  reg [3 : 0] exp_op2;
  wire [3 : 0] exp_op2$D_IN;
  wire exp_op2$EN;

  // register final_bias
  reg [3 : 0] final_bias;
  wire [3 : 0] final_bias$D_IN;
  wire final_bias$EN;

  // register final_exp
  reg [6 : 0] final_exp;
  wire [6 : 0] final_exp$D_IN;
  wire final_exp$EN;

  // register final_man
  reg [7 : 0] final_man;
  wire [7 : 0] final_man$D_IN;
  wire final_man$EN;

  // register final_sign
  reg final_sign;
  wire final_sign$D_IN, final_sign$EN;

  // register man_op1
  reg [2 : 0] man_op1;
  wire [2 : 0] man_op1$D_IN;
  wire man_op1$EN;

  // register man_op2
  reg [2 : 0] man_op2;
  wire [2 : 0] man_op2$D_IN;
  wire man_op2$EN;

  // register normalized_count
  reg [3 : 0] normalized_count;
  wire [3 : 0] normalized_count$D_IN;
  wire normalized_count$EN;

  // register normalized_exp
  reg [3 : 0] normalized_exp;
  reg [3 : 0] normalized_exp$D_IN;
  wire normalized_exp$EN;

  // register normalized_man
  reg [5 : 0] normalized_man;
  reg [5 : 0] normalized_man$D_IN;
  wire normalized_man$EN;

  // register output_man
  reg [2 : 0] output_man;
  wire [2 : 0] output_man$D_IN;
  wire output_man$EN;

  // register rg_operands
  reg [20 : 0] rg_operands;
  wire [20 : 0] rg_operands$D_IN;
  wire rg_operands$EN;

  // register rounded_man
  reg [2 : 0] rounded_man;
  wire [2 : 0] rounded_man$D_IN;
  wire rounded_man$EN;

  // register sign_op1
  reg sign_op1;
  wire sign_op1$D_IN, sign_op1$EN;

  // register sign_op2
  reg sign_op2;
  wire sign_op2$D_IN, sign_op2$EN;

  // register stage
  reg [2 : 0] stage;
  wire [2 : 0] stage$D_IN;
  wire stage$EN;

  // register stage1_output
  reg [7 : 0] stage1_output;
  wire [7 : 0] stage1_output$D_IN;
  wire stage1_output$EN;

  // register stage2_output
  reg [7 : 0] stage2_output;
  wire [7 : 0] stage2_output$D_IN;
  wire stage2_output$EN;

  // register stage3_output
  reg [7 : 0] stage3_output;
  wire [7 : 0] stage3_output$D_IN;
  wire stage3_output$EN;

  // register stage4_output
  reg [7 : 0] stage4_output;
  wire [7 : 0] stage4_output$D_IN;
  wire stage4_output$EN;

  // register stage5_output
  reg [7 : 0] stage5_output;
  wire [7 : 0] stage5_output$D_IN;
  wire stage5_output$EN;

  // register status_flags
  reg [2 : 0] status_flags;
  wire [2 : 0] status_flags$D_IN;
  wire status_flags$EN;

  // register temp2_exp_int
  reg [6 : 0] temp2_exp_int;
  wire [6 : 0] temp2_exp_int$D_IN;
  wire temp2_exp_int$EN;

  // register temp3_exp_int
  reg [6 : 0] temp3_exp_int;
  wire [6 : 0] temp3_exp_int$D_IN;
  wire temp3_exp_int$EN;

  // register temp4_exp_int
  reg [6 : 0] temp4_exp_int;
  wire [6 : 0] temp4_exp_int$D_IN;
  wire temp4_exp_int$EN;

  // register temp5_exp_int
  reg [6 : 0] temp5_exp_int;
  wire [6 : 0] temp5_exp_int$D_IN;
  wire temp5_exp_int$EN;

  // rule scheduling signals
  wire CAN_FIRE_RL_stage1,
       CAN_FIRE_RL_stage2,
       CAN_FIRE_RL_stage3,
       CAN_FIRE_RL_stage4,
       CAN_FIRE_RL_stage5,
       CAN_FIRE_send,
       WILL_FIRE_RL_stage1,
       WILL_FIRE_RL_stage2,
       WILL_FIRE_RL_stage3,
       WILL_FIRE_RL_stage4,
       WILL_FIRE_RL_stage5,
       WILL_FIRE_send;

  // remaining internal signals
  wire [15 : 0] _0_CONCAT_NOT_buffer3_exp1_1_EQ_0_2_3_CONCAT_bu_ETC___d53;
  wire [7 : 0] inter_mantissa1__h3123, inter_mantissa2__h3124;
  wire [5 : 0] IF_0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_ETC___d89,
	       x__h4722,
	       x__h4785,
	       x__h4852;
  wire [3 : 0] count_temp__h3621, x__h3155, x__h3163, x__h4924, x__h4985;
  wire [2 : 0] rounded_value__h5244, x__h3624;
  wire _0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_IF_ETC___d86,
       hidden_bit_op1__h3121,
       hidden_bit_op2__h3122;

  // action method send
  assign RDY_send = 1'd1 ;
  assign CAN_FIRE_send = 1'd1 ;
  assign WILL_FIRE_send = EN_send ;

  // value method receive
  assign receive = stage5_output ;
  assign RDY_receive = 1'd1 ;

  // rule RL_stage5
  assign CAN_FIRE_RL_stage5 = 1'd1 ;
  assign WILL_FIRE_RL_stage5 = 1'd1 ;

  // rule RL_stage4
  assign CAN_FIRE_RL_stage4 = 1'd1 ;
  assign WILL_FIRE_RL_stage4 = 1'd1 ;

  // rule RL_stage3
  assign CAN_FIRE_RL_stage3 = 1'd1 ;
  assign WILL_FIRE_RL_stage3 = 1'd1 ;

  // rule RL_stage2
  assign CAN_FIRE_RL_stage2 = 1'd1 ;
  assign WILL_FIRE_RL_stage2 = 1'd1 ;

  // rule RL_stage1
  assign CAN_FIRE_RL_stage1 = 1'd1 ;
  assign WILL_FIRE_RL_stage1 = 1'd1 ;

  // register buffer1_bias
  assign buffer1_bias$D_IN = rg_operands[3:0] ;
  assign buffer1_bias$EN = 1'd1 ;

  // register buffer1_exp1
  assign buffer1_exp1$D_IN = rg_operands[19:16] ;
  assign buffer1_exp1$EN = 1'd1 ;

  // register buffer1_exp2
  assign buffer1_exp2$D_IN = rg_operands[11:8] ;
  assign buffer1_exp2$EN = 1'd1 ;

  // register buffer1_man1
  assign buffer1_man1$D_IN = rg_operands[15:13] ;
  assign buffer1_man1$EN = 1'd1 ;

  // register buffer1_man2
  assign buffer1_man2$D_IN = rg_operands[7:5] ;
  assign buffer1_man2$EN = 1'd1 ;

  // register buffer1_rmode
  assign buffer1_rmode$D_IN = rg_operands[4] ;
  assign buffer1_rmode$EN = 1'd1 ;

  // register buffer1_sign1
  assign buffer1_sign1$D_IN = rg_operands[20] ;
  assign buffer1_sign1$EN = 1'd1 ;

  // register buffer1_sign2
  assign buffer1_sign2$D_IN = rg_operands[12] ;
  assign buffer1_sign2$EN = 1'd1 ;

  // register buffer2_bias
  assign buffer2_bias$D_IN = buffer1_bias ;
  assign buffer2_bias$EN = 1'd1 ;

  // register buffer2_exp1
  assign buffer2_exp1$D_IN = buffer1_exp1 ;
  assign buffer2_exp1$EN = 1'd1 ;

  // register buffer2_exp2
  assign buffer2_exp2$D_IN = buffer1_exp2 ;
  assign buffer2_exp2$EN = 1'd1 ;

  // register buffer2_man1
  assign buffer2_man1$D_IN = buffer1_man1 ;
  assign buffer2_man1$EN = 1'd1 ;

  // register buffer2_man2
  assign buffer2_man2$D_IN = buffer1_man2 ;
  assign buffer2_man2$EN = 1'd1 ;

  // register buffer2_rmode
  assign buffer2_rmode$D_IN = buffer1_rmode ;
  assign buffer2_rmode$EN = 1'd1 ;

  // register buffer2_sign1
  assign buffer2_sign1$D_IN = buffer1_sign1 ;
  assign buffer2_sign1$EN = 1'd1 ;

  // register buffer2_sign2
  assign buffer2_sign2$D_IN = buffer1_sign2 ;
  assign buffer2_sign2$EN = 1'd1 ;

  // register buffer3_bias
  assign buffer3_bias$D_IN = buffer2_bias ;
  assign buffer3_bias$EN = 1'd1 ;

  // register buffer3_exp
  assign buffer3_exp$D_IN = stage2_output[6:3] ;
  assign buffer3_exp$EN = 1'd1 ;

  // register buffer3_exp1
  assign buffer3_exp1$D_IN = buffer2_exp1 ;
  assign buffer3_exp1$EN = 1'd1 ;

  // register buffer3_exp2
  assign buffer3_exp2$D_IN = buffer2_exp2 ;
  assign buffer3_exp2$EN = 1'd1 ;

  // register buffer3_man1
  assign buffer3_man1$D_IN = buffer2_man1 ;
  assign buffer3_man1$EN = 1'd1 ;

  // register buffer3_man2
  assign buffer3_man2$D_IN = buffer2_man2 ;
  assign buffer3_man2$EN = 1'd1 ;

  // register buffer3_rmode
  assign buffer3_rmode$D_IN = buffer2_rmode ;
  assign buffer3_rmode$EN = 1'd1 ;

  // register buffer3_sign1
  assign buffer3_sign1$D_IN = buffer2_sign1 ;
  assign buffer3_sign1$EN = 1'd1 ;

  // register buffer3_sign2
  assign buffer3_sign2$D_IN = buffer2_sign2 ;
  assign buffer3_sign2$EN = 1'd1 ;

  // register buffer4_bias
  assign buffer4_bias$D_IN = buffer3_bias ;
  assign buffer4_bias$EN = 1'd1 ;

  // register buffer4_exp
  assign buffer4_exp$D_IN = buffer3_exp ;
  assign buffer4_exp$EN = 1'd1 ;

  // register buffer4_exp1
  assign buffer4_exp1$D_IN = buffer3_exp1 ;
  assign buffer4_exp1$EN = 1'd1 ;

  // register buffer4_exp2
  assign buffer4_exp2$D_IN = buffer3_exp2 ;
  assign buffer4_exp2$EN = 1'd1 ;

  // register buffer4_man1
  assign buffer4_man1$D_IN = buffer3_man1 ;
  assign buffer4_man1$EN = 1'd1 ;

  // register buffer4_man2
  assign buffer4_man2$D_IN = buffer3_man2 ;
  assign buffer4_man2$EN = 1'd1 ;

  // register buffer4_rmode
  assign buffer4_rmode$D_IN = buffer3_rmode ;
  assign buffer4_rmode$EN = 1'd1 ;

  // register buffer4_sign1
  assign buffer4_sign1$D_IN = buffer3_sign1 ;
  assign buffer4_sign1$EN = 1'd1 ;

  // register buffer4_sign2
  assign buffer4_sign2$D_IN = buffer3_sign2 ;
  assign buffer4_sign2$EN = 1'd1 ;

  // register buffer5_bias
  assign buffer5_bias$D_IN = buffer4_bias ;
  assign buffer5_bias$EN = 1'd1 ;

  // register buffer5_rmode
  assign buffer5_rmode$D_IN = buffer4_rmode ;
  assign buffer5_rmode$EN = 1'd1 ;

  // register exp_op1
  assign exp_op1$D_IN = 4'h0 ;
  assign exp_op1$EN = 1'b0 ;

  // register exp_op2
  assign exp_op2$D_IN = 4'h0 ;
  assign exp_op2$EN = 1'b0 ;

  // register final_bias
  assign final_bias$D_IN = 4'h0 ;
  assign final_bias$EN = 1'b0 ;

  // register final_exp
  assign final_exp$D_IN = 7'h0 ;
  assign final_exp$EN = 1'b0 ;

  // register final_man
  assign final_man$D_IN =
	     _0_CONCAT_NOT_buffer3_exp1_1_EQ_0_2_3_CONCAT_bu_ETC___d53[7:0] ;
  assign final_man$EN = 1'd1 ;

  // register final_sign
  assign final_sign$D_IN = buffer1_sign1 ^ buffer1_sign2 ;
  assign final_sign$EN = 1'd1 ;

  // register man_op1
  assign man_op1$D_IN = 3'h0 ;
  assign man_op1$EN = 1'b0 ;

  // register man_op2
  assign man_op2$D_IN = 3'h0 ;
  assign man_op2$EN = 1'b0 ;

  // register normalized_count
  assign normalized_count$D_IN = 4'h0 ;
  assign normalized_count$EN = 1'b0 ;

  // register normalized_exp
  always@(final_man or
	  _0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_IF_ETC___d86 or
	  x__h4985 or x__h4924)
  begin
    case (final_man[7:6])
      2'b10, 2'b11: normalized_exp$D_IN = x__h4924;
      default: normalized_exp$D_IN =
		   _0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_IF_ETC___d86 ?
		     x__h4985 :
		     4'd0;
    endcase
  end
  assign normalized_exp$EN = final_man[7:6] != 2'b01 ;

  // register normalized_man
  always@(final_man or
	  IF_0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_ETC___d89 or
	  x__h4722)
  begin
    case (final_man[7:6])
      2'd0:
	  normalized_man$D_IN =
	      IF_0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_ETC___d89;
      2'b01: normalized_man$D_IN = final_man[5:0];
      2'b10, 2'b11: normalized_man$D_IN = x__h4722;
    endcase
  end
  assign normalized_man$EN = 1'd1 ;

  // register output_man
  assign output_man$D_IN = 3'h0 ;
  assign output_man$EN = 1'b0 ;

  // register rg_operands
  assign rg_operands$D_IN = send_data_input ;
  assign rg_operands$EN = EN_send ;

  // register rounded_man
  assign rounded_man$D_IN =
	     normalized_man[2] ? rounded_value__h5244 : normalized_man[5:3] ;
  assign rounded_man$EN = buffer5_rmode ;

  // register sign_op1
  assign sign_op1$D_IN = 1'b0 ;
  assign sign_op1$EN = 1'b0 ;

  // register sign_op2
  assign sign_op2$D_IN = 1'b0 ;
  assign sign_op2$EN = 1'b0 ;

  // register stage
  assign stage$D_IN = 3'h0 ;
  assign stage$EN = 1'b0 ;

  // register stage1_output
  assign stage1_output$D_IN = { final_sign, 7'd0 } ;
  assign stage1_output$EN = 1'd1 ;

  // register stage2_output
  assign stage2_output$D_IN = { stage1_output[7], temp2_exp_int[3:0], 3'b0 } ;
  assign stage2_output$EN = 1'd1 ;

  // register stage3_output
  assign stage3_output$D_IN = stage2_output ;
  assign stage3_output$EN = 1'd1 ;

  // register stage4_output
  assign stage4_output$D_IN =
	     (final_man[7:6] == 2'b01) ?
	       stage3_output :
	       { stage3_output[7], normalized_exp, stage3_output[2:0] } ;
  assign stage4_output$EN = 1'd1 ;

  // register stage5_output
  assign stage5_output$D_IN =
	     { stage4_output[7],
	       ((temp5_exp_int ^ 7'h40) < 7'd79) ?
		 { stage4_output[6:3], rounded_man } :
		 7'd127 } ;
  assign stage5_output$EN = 1'd1 ;

  // register status_flags
  assign status_flags$D_IN =
	     (stage5_output[6:3] == 4'b0 && stage5_output[2:0] == 3'b0) ?
	       3'b001 :
	       ((stage5_output[6:3] == 4'b0 && stage5_output[2:0] != 3'b0) ?
		  3'b010 :
		  3'b100) ;
  assign status_flags$EN = 1'd1 ;

  // register temp2_exp_int
  assign temp2_exp_int$D_IN =
	     { {3{buffer2_exp1[3]}}, buffer2_exp1 } +
	     { {3{buffer2_exp2[3]}}, buffer2_exp2 } -
	     { {3{buffer2_bias[3]}}, buffer2_bias } ;
  assign temp2_exp_int$EN = 1'd1 ;

  // register temp3_exp_int
  assign temp3_exp_int$D_IN = temp2_exp_int ;
  assign temp3_exp_int$EN = 1'd1 ;

  // register temp4_exp_int
  assign temp4_exp_int$D_IN = temp3_exp_int ;
  assign temp4_exp_int$EN = 1'd1 ;

  // register temp5_exp_int
  assign temp5_exp_int$D_IN = temp4_exp_int ;
  assign temp5_exp_int$EN = 1'd1 ;

  // remaining internal signals
  assign IF_0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_ETC___d89 =
	     _0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_IF_ETC___d86 ?
	       x__h4785 :
	       x__h4852 ;
  assign _0_CONCAT_IF_final_man_1_BIT_5_0_THEN_0_ELSE_IF_ETC___d86 =
	     count_temp__h3621 < stage3_output[6:3] ;
  assign _0_CONCAT_NOT_buffer3_exp1_1_EQ_0_2_3_CONCAT_bu_ETC___d53 =
	     inter_mantissa1__h3123 * inter_mantissa2__h3124 ;
  assign count_temp__h3621 = { 1'd0, x__h3624 } ;
  assign hidden_bit_op1__h3121 = buffer3_exp1 != 4'd0 ;
  assign hidden_bit_op2__h3122 = buffer3_exp2 != 4'd0 ;
  assign inter_mantissa1__h3123 = { 4'd0, x__h3155 } ;
  assign inter_mantissa2__h3124 = { 4'd0, x__h3163 } ;
  assign rounded_value__h5244 = normalized_man[5:3] + 3'b001 ;
  assign x__h3155 = { hidden_bit_op1__h3121, buffer3_man1 } ;
  assign x__h3163 = { hidden_bit_op2__h3122, buffer3_man2 } ;
  assign x__h3624 =
	     (final_man[5] ?
		3'd0 :
		(final_man[4] ?
		   3'd1 :
		   (final_man[3] ?
		      3'd2 :
		      (final_man[2] ?
			 3'd3 :
			 (final_man[1] ?
			    3'd4 :
			    (final_man[0] ? 3'd5 : 3'd6)))))) +
	     3'd1 ;
  assign x__h4722 = { 1'd0, final_man[5:1] } ;
  assign x__h4785 = final_man[5:0] << count_temp__h3621 ;
  assign x__h4852 = final_man[5:0] << stage3_output[6:3] ;
  assign x__h4924 = stage3_output[6:3] + 4'd1 ;
  assign x__h4985 = stage3_output[6:3] - count_temp__h3621 ;

  // handling of inlined registers

  always@(posedge CLK)
  begin
    if (RST_N == `BSV_RESET_VALUE)
      begin
        buffer1_bias <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer1_exp1 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer1_exp2 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer1_man1 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer1_man2 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer1_rmode <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer1_sign1 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer1_sign2 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer2_bias <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer2_exp1 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer2_exp2 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer2_man1 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer2_man2 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer2_rmode <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer2_sign1 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer2_sign2 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer3_bias <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer3_exp <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer3_exp1 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer3_exp2 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer3_man1 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer3_man2 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer3_rmode <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer3_sign1 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer3_sign2 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer4_bias <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer4_exp <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer4_exp1 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer4_exp2 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer4_man1 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer4_man2 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	buffer4_rmode <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer4_sign1 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer4_sign2 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	buffer5_bias <= `BSV_ASSIGNMENT_DELAY 4'd0;
	buffer5_rmode <= `BSV_ASSIGNMENT_DELAY 1'd0;
	exp_op1 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	exp_op2 <= `BSV_ASSIGNMENT_DELAY 4'd0;
	final_bias <= `BSV_ASSIGNMENT_DELAY 4'd0;
	final_exp <= `BSV_ASSIGNMENT_DELAY 7'd0;
	final_man <= `BSV_ASSIGNMENT_DELAY 8'd0;
	final_sign <= `BSV_ASSIGNMENT_DELAY 1'd0;
	man_op1 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	man_op2 <= `BSV_ASSIGNMENT_DELAY 3'd0;
	normalized_count <= `BSV_ASSIGNMENT_DELAY 4'd0;
	normalized_exp <= `BSV_ASSIGNMENT_DELAY 4'd0;
	normalized_man <= `BSV_ASSIGNMENT_DELAY 6'd0;
	output_man <= `BSV_ASSIGNMENT_DELAY 3'd0;
	rg_operands <= `BSV_ASSIGNMENT_DELAY 21'd0;
	rounded_man <= `BSV_ASSIGNMENT_DELAY 3'd0;
	sign_op1 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	sign_op2 <= `BSV_ASSIGNMENT_DELAY 1'd0;
	stage <= `BSV_ASSIGNMENT_DELAY 3'd1;
	stage1_output <= `BSV_ASSIGNMENT_DELAY 8'd0;
	stage2_output <= `BSV_ASSIGNMENT_DELAY 8'd0;
	stage3_output <= `BSV_ASSIGNMENT_DELAY 8'd0;
	stage4_output <= `BSV_ASSIGNMENT_DELAY 8'd0;
	stage5_output <= `BSV_ASSIGNMENT_DELAY 8'd0;
	status_flags <= `BSV_ASSIGNMENT_DELAY 3'd0;
	temp2_exp_int <= `BSV_ASSIGNMENT_DELAY 7'd0;
	temp3_exp_int <= `BSV_ASSIGNMENT_DELAY 7'd0;
	temp4_exp_int <= `BSV_ASSIGNMENT_DELAY 7'd0;
	temp5_exp_int <= `BSV_ASSIGNMENT_DELAY 7'd0;
      end
    else
      begin
        if (buffer1_bias$EN)
	  buffer1_bias <= `BSV_ASSIGNMENT_DELAY buffer1_bias$D_IN;
	if (buffer1_exp1$EN)
	  buffer1_exp1 <= `BSV_ASSIGNMENT_DELAY buffer1_exp1$D_IN;
	if (buffer1_exp2$EN)
	  buffer1_exp2 <= `BSV_ASSIGNMENT_DELAY buffer1_exp2$D_IN;
	if (buffer1_man1$EN)
	  buffer1_man1 <= `BSV_ASSIGNMENT_DELAY buffer1_man1$D_IN;
	if (buffer1_man2$EN)
	  buffer1_man2 <= `BSV_ASSIGNMENT_DELAY buffer1_man2$D_IN;
	if (buffer1_rmode$EN)
	  buffer1_rmode <= `BSV_ASSIGNMENT_DELAY buffer1_rmode$D_IN;
	if (buffer1_sign1$EN)
	  buffer1_sign1 <= `BSV_ASSIGNMENT_DELAY buffer1_sign1$D_IN;
	if (buffer1_sign2$EN)
	  buffer1_sign2 <= `BSV_ASSIGNMENT_DELAY buffer1_sign2$D_IN;
	if (buffer2_bias$EN)
	  buffer2_bias <= `BSV_ASSIGNMENT_DELAY buffer2_bias$D_IN;
	if (buffer2_exp1$EN)
	  buffer2_exp1 <= `BSV_ASSIGNMENT_DELAY buffer2_exp1$D_IN;
	if (buffer2_exp2$EN)
	  buffer2_exp2 <= `BSV_ASSIGNMENT_DELAY buffer2_exp2$D_IN;
	if (buffer2_man1$EN)
	  buffer2_man1 <= `BSV_ASSIGNMENT_DELAY buffer2_man1$D_IN;
	if (buffer2_man2$EN)
	  buffer2_man2 <= `BSV_ASSIGNMENT_DELAY buffer2_man2$D_IN;
	if (buffer2_rmode$EN)
	  buffer2_rmode <= `BSV_ASSIGNMENT_DELAY buffer2_rmode$D_IN;
	if (buffer2_sign1$EN)
	  buffer2_sign1 <= `BSV_ASSIGNMENT_DELAY buffer2_sign1$D_IN;
	if (buffer2_sign2$EN)
	  buffer2_sign2 <= `BSV_ASSIGNMENT_DELAY buffer2_sign2$D_IN;
	if (buffer3_bias$EN)
	  buffer3_bias <= `BSV_ASSIGNMENT_DELAY buffer3_bias$D_IN;
	if (buffer3_exp$EN)
	  buffer3_exp <= `BSV_ASSIGNMENT_DELAY buffer3_exp$D_IN;
	if (buffer3_exp1$EN)
	  buffer3_exp1 <= `BSV_ASSIGNMENT_DELAY buffer3_exp1$D_IN;
	if (buffer3_exp2$EN)
	  buffer3_exp2 <= `BSV_ASSIGNMENT_DELAY buffer3_exp2$D_IN;
	if (buffer3_man1$EN)
	  buffer3_man1 <= `BSV_ASSIGNMENT_DELAY buffer3_man1$D_IN;
	if (buffer3_man2$EN)
	  buffer3_man2 <= `BSV_ASSIGNMENT_DELAY buffer3_man2$D_IN;
	if (buffer3_rmode$EN)
	  buffer3_rmode <= `BSV_ASSIGNMENT_DELAY buffer3_rmode$D_IN;
	if (buffer3_sign1$EN)
	  buffer3_sign1 <= `BSV_ASSIGNMENT_DELAY buffer3_sign1$D_IN;
	if (buffer3_sign2$EN)
	  buffer3_sign2 <= `BSV_ASSIGNMENT_DELAY buffer3_sign2$D_IN;
	if (buffer4_bias$EN)
	  buffer4_bias <= `BSV_ASSIGNMENT_DELAY buffer4_bias$D_IN;
	if (buffer4_exp$EN)
	  buffer4_exp <= `BSV_ASSIGNMENT_DELAY buffer4_exp$D_IN;
	if (buffer4_exp1$EN)
	  buffer4_exp1 <= `BSV_ASSIGNMENT_DELAY buffer4_exp1$D_IN;
	if (buffer4_exp2$EN)
	  buffer4_exp2 <= `BSV_ASSIGNMENT_DELAY buffer4_exp2$D_IN;
	if (buffer4_man1$EN)
	  buffer4_man1 <= `BSV_ASSIGNMENT_DELAY buffer4_man1$D_IN;
	if (buffer4_man2$EN)
	  buffer4_man2 <= `BSV_ASSIGNMENT_DELAY buffer4_man2$D_IN;
	if (buffer4_rmode$EN)
	  buffer4_rmode <= `BSV_ASSIGNMENT_DELAY buffer4_rmode$D_IN;
	if (buffer4_sign1$EN)
	  buffer4_sign1 <= `BSV_ASSIGNMENT_DELAY buffer4_sign1$D_IN;
	if (buffer4_sign2$EN)
	  buffer4_sign2 <= `BSV_ASSIGNMENT_DELAY buffer4_sign2$D_IN;
	if (buffer5_bias$EN)
	  buffer5_bias <= `BSV_ASSIGNMENT_DELAY buffer5_bias$D_IN;
	if (buffer5_rmode$EN)
	  buffer5_rmode <= `BSV_ASSIGNMENT_DELAY buffer5_rmode$D_IN;
	if (exp_op1$EN) exp_op1 <= `BSV_ASSIGNMENT_DELAY exp_op1$D_IN;
	if (exp_op2$EN) exp_op2 <= `BSV_ASSIGNMENT_DELAY exp_op2$D_IN;
	if (final_bias$EN)
	  final_bias <= `BSV_ASSIGNMENT_DELAY final_bias$D_IN;
	if (final_exp$EN) final_exp <= `BSV_ASSIGNMENT_DELAY final_exp$D_IN;
	if (final_man$EN) final_man <= `BSV_ASSIGNMENT_DELAY final_man$D_IN;
	if (final_sign$EN)
	  final_sign <= `BSV_ASSIGNMENT_DELAY final_sign$D_IN;
	if (man_op1$EN) man_op1 <= `BSV_ASSIGNMENT_DELAY man_op1$D_IN;
	if (man_op2$EN) man_op2 <= `BSV_ASSIGNMENT_DELAY man_op2$D_IN;
	if (normalized_count$EN)
	  normalized_count <= `BSV_ASSIGNMENT_DELAY normalized_count$D_IN;
	if (normalized_exp$EN)
	  normalized_exp <= `BSV_ASSIGNMENT_DELAY normalized_exp$D_IN;
	if (normalized_man$EN)
	  normalized_man <= `BSV_ASSIGNMENT_DELAY normalized_man$D_IN;
	if (output_man$EN)
	  output_man <= `BSV_ASSIGNMENT_DELAY output_man$D_IN;
	if (rg_operands$EN)
	  rg_operands <= `BSV_ASSIGNMENT_DELAY rg_operands$D_IN;
	if (rounded_man$EN)
	  rounded_man <= `BSV_ASSIGNMENT_DELAY rounded_man$D_IN;
	if (sign_op1$EN) sign_op1 <= `BSV_ASSIGNMENT_DELAY sign_op1$D_IN;
	if (sign_op2$EN) sign_op2 <= `BSV_ASSIGNMENT_DELAY sign_op2$D_IN;
	if (stage$EN) stage <= `BSV_ASSIGNMENT_DELAY stage$D_IN;
	if (stage1_output$EN)
	  stage1_output <= `BSV_ASSIGNMENT_DELAY stage1_output$D_IN;
	if (stage2_output$EN)
	  stage2_output <= `BSV_ASSIGNMENT_DELAY stage2_output$D_IN;
	if (stage3_output$EN)
	  stage3_output <= `BSV_ASSIGNMENT_DELAY stage3_output$D_IN;
	if (stage4_output$EN)
	  stage4_output <= `BSV_ASSIGNMENT_DELAY stage4_output$D_IN;
	if (stage5_output$EN)
	  stage5_output <= `BSV_ASSIGNMENT_DELAY stage5_output$D_IN;
	if (status_flags$EN)
	  status_flags <= `BSV_ASSIGNMENT_DELAY status_flags$D_IN;
	if (temp2_exp_int$EN)
	  temp2_exp_int <= `BSV_ASSIGNMENT_DELAY temp2_exp_int$D_IN;
	if (temp3_exp_int$EN)
	  temp3_exp_int <= `BSV_ASSIGNMENT_DELAY temp3_exp_int$D_IN;
	if (temp4_exp_int$EN)
	  temp4_exp_int <= `BSV_ASSIGNMENT_DELAY temp4_exp_int$D_IN;
	if (temp5_exp_int$EN)
	  temp5_exp_int <= `BSV_ASSIGNMENT_DELAY temp5_exp_int$D_IN;
      end
  end

  // synopsys translate_off
  `ifdef BSV_NO_INITIAL_BLOCKS
  `else // not BSV_NO_INITIAL_BLOCKS
  initial
  begin
    buffer1_bias = 4'hA;
    buffer1_exp1 = 4'hA;
    buffer1_exp2 = 4'hA;
    buffer1_man1 = 3'h2;
    buffer1_man2 = 3'h2;
    buffer1_rmode = 1'h0;
    buffer1_sign1 = 1'h0;
    buffer1_sign2 = 1'h0;
    buffer2_bias = 4'hA;
    buffer2_exp1 = 4'hA;
    buffer2_exp2 = 4'hA;
    buffer2_man1 = 3'h2;
    buffer2_man2 = 3'h2;
    buffer2_rmode = 1'h0;
    buffer2_sign1 = 1'h0;
    buffer2_sign2 = 1'h0;
    buffer3_bias = 4'hA;
    buffer3_exp = 4'hA;
    buffer3_exp1 = 4'hA;
    buffer3_exp2 = 4'hA;
    buffer3_man1 = 3'h2;
    buffer3_man2 = 3'h2;
    buffer3_rmode = 1'h0;
    buffer3_sign1 = 1'h0;
    buffer3_sign2 = 1'h0;
    buffer4_bias = 4'hA;
    buffer4_exp = 4'hA;
    buffer4_exp1 = 4'hA;
    buffer4_exp2 = 4'hA;
    buffer4_man1 = 3'h2;
    buffer4_man2 = 3'h2;
    buffer4_rmode = 1'h0;
    buffer4_sign1 = 1'h0;
    buffer4_sign2 = 1'h0;
    buffer5_bias = 4'hA;
    buffer5_rmode = 1'h0;
    exp_op1 = 4'hA;
    exp_op2 = 4'hA;
    final_bias = 4'hA;
    final_exp = 7'h2A;
    final_man = 8'hAA;
    final_sign = 1'h0;
    man_op1 = 3'h2;
    man_op2 = 3'h2;
    normalized_count = 4'hA;
    normalized_exp = 4'hA;
    normalized_man = 6'h2A;
    output_man = 3'h2;
    rg_operands = 21'h0AAAAA;
    rounded_man = 3'h2;
    sign_op1 = 1'h0;
    sign_op2 = 1'h0;
    stage = 3'h2;
    stage1_output = 8'hAA;
    stage2_output = 8'hAA;
    stage3_output = 8'hAA;
    stage4_output = 8'hAA;
    stage5_output = 8'hAA;
    status_flags = 3'h2;
    temp2_exp_int = 7'h2A;
    temp3_exp_int = 7'h2A;
    temp4_exp_int = 7'h2A;
    temp5_exp_int = 7'h2A;
  end
  `endif // BSV_NO_INITIAL_BLOCKS
  // synopsys translate_on

  // handling of system tasks

  // synopsys translate_off
  always@(negedge CLK)
  begin
    #0;
    if (RST_N != `BSV_RESET_VALUE) $display("status flags : ", status_flags);
    if (RST_N != `BSV_RESET_VALUE)
      $display("STAGE 5 OUTPUT : sign : ",
	       stage5_output[7],
	       " exponent : ",
	       stage5_output[6:3],
	       " mantissa : ",
	       stage5_output[2:0]);
  end
  // synopsys translate_on
endmodule  // cfloat8_mul

