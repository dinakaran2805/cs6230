// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"



// FUNCTIONS
Vtop__Syms::Vtop__Syms(Vtop* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_cfloat8_mul.configure(this, name(), "cfloat8_mul", "cfloat8_mul", -9, VerilatedScope::SCOPE_MODULE);
    
    // Setup scope hierarchy
    __Vhier.add(0, &__Vscope_cfloat8_mul);
    
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_TOP.varInsert(__Vfinal,"CLK", &(TOPp->CLK), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"EN_send", &(TOPp->EN_send), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"RDY_receive", &(TOPp->RDY_receive), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"RDY_send", &(TOPp->RDY_send), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"RST_N", &(TOPp->RST_N), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"receive", &(TOPp->receive), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"send_data_input", &(TOPp->send_data_input), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,20,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CAN_FIRE_RL_stage1", &(TOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CAN_FIRE_RL_stage2", &(TOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CAN_FIRE_RL_stage3", &(TOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CAN_FIRE_RL_stage4", &(TOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage4), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CAN_FIRE_RL_stage5", &(TOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage5), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CAN_FIRE_RL_trial", &(TOPp->cfloat8_mul__DOT__CAN_FIRE_RL_trial), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CAN_FIRE_send", &(TOPp->cfloat8_mul__DOT__CAN_FIRE_send), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"CLK", &(TOPp->cfloat8_mul__DOT__CLK), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"EN_send", &(TOPp->cfloat8_mul__DOT__EN_send), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___d60", &(TOPp->cfloat8_mul__DOT__IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___05F_d60), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___d55", &(TOPp->cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"MUX_final_exp$write_1__SEL_1", &(TOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FSEL_1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"MUX_final_exp$write_1__VAL_1", &(TOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"MUX_final_exp$write_1__VAL_2", &(TOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"MUX_stage$write_1__VAL_2", &(TOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL__ETC___d30", &(TOPp->cfloat8_mul__DOT__NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL___05FETC___05F_d30), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"RDY_receive", &(TOPp->cfloat8_mul__DOT__RDY_receive), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"RDY_send", &(TOPp->cfloat8_mul__DOT__RDY_send), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"RST_N", &(TOPp->cfloat8_mul__DOT__RST_N), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"WILL_FIRE_RL_stage1", &(TOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"WILL_FIRE_RL_stage2", &(TOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"WILL_FIRE_RL_stage3", &(TOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"WILL_FIRE_RL_stage4", &(TOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"WILL_FIRE_RL_stage5", &(TOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"WILL_FIRE_RL_trial", &(TOPp->cfloat8_mul__DOT__WILL_FIRE_RL_trial), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"WILL_FIRE_send", &(TOPp->cfloat8_mul__DOT__WILL_FIRE_send), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_ETC___d57", &(TOPp->cfloat8_mul__DOT___0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_ETC___05F_d57), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"count_temp__h2059", &(TOPp->cfloat8_mul__DOT__count_temp___05Fh2059), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"exp_op1", &(TOPp->cfloat8_mul__DOT__exp_op1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"exp_op1$D_IN", &(TOPp->cfloat8_mul__DOT__exp_op1__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"exp_op1$EN", &(TOPp->cfloat8_mul__DOT__exp_op1__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"exp_op2", &(TOPp->cfloat8_mul__DOT__exp_op2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"exp_op2$D_IN", &(TOPp->cfloat8_mul__DOT__exp_op2__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"exp_op2$EN", &(TOPp->cfloat8_mul__DOT__exp_op2__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_bias", &(TOPp->cfloat8_mul__DOT__final_bias), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_bias$D_IN", &(TOPp->cfloat8_mul__DOT__final_bias__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_bias$EN", &(TOPp->cfloat8_mul__DOT__final_bias__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_exp", &(TOPp->cfloat8_mul__DOT__final_exp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_exp$D_IN", &(TOPp->cfloat8_mul__DOT__final_exp__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_exp$EN", &(TOPp->cfloat8_mul__DOT__final_exp__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_man", &(TOPp->cfloat8_mul__DOT__final_man), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_man$D_IN", &(TOPp->cfloat8_mul__DOT__final_man__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_man$EN", &(TOPp->cfloat8_mul__DOT__final_man__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_output", &(TOPp->cfloat8_mul__DOT__final_output), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_output$D_IN", &(TOPp->cfloat8_mul__DOT__final_output__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_output$EN", &(TOPp->cfloat8_mul__DOT__final_output__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_sign", &(TOPp->cfloat8_mul__DOT__final_sign), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_sign$D_IN", &(TOPp->cfloat8_mul__DOT__final_sign__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"final_sign$EN", &(TOPp->cfloat8_mul__DOT__final_sign__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"hidden_bit_op1__h1358", &(TOPp->cfloat8_mul__DOT__hidden_bit_op1___05Fh1358), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"hidden_bit_op2__h1359", &(TOPp->cfloat8_mul__DOT__hidden_bit_op2___05Fh1359), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"inter_mantissa1__h1426", &(TOPp->cfloat8_mul__DOT__inter_mantissa1___05Fh1426), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"inter_mantissa2__h1427", &(TOPp->cfloat8_mul__DOT__inter_mantissa2___05Fh1427), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"man_op1", &(TOPp->cfloat8_mul__DOT__man_op1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"man_op1$D_IN", &(TOPp->cfloat8_mul__DOT__man_op1__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"man_op1$EN", &(TOPp->cfloat8_mul__DOT__man_op1__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"man_op2", &(TOPp->cfloat8_mul__DOT__man_op2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"man_op2$D_IN", &(TOPp->cfloat8_mul__DOT__man_op2__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"man_op2$EN", &(TOPp->cfloat8_mul__DOT__man_op2__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"normalized_count", &(TOPp->cfloat8_mul__DOT__normalized_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"normalized_count$D_IN", &(TOPp->cfloat8_mul__DOT__normalized_count__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"normalized_count$EN", &(TOPp->cfloat8_mul__DOT__normalized_count__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"normalized_man", &(TOPp->cfloat8_mul__DOT__normalized_man), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"normalized_man$D_IN", &(TOPp->cfloat8_mul__DOT__normalized_man__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"normalized_man$EN", &(TOPp->cfloat8_mul__DOT__normalized_man__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"output_man", &(TOPp->cfloat8_mul__DOT__output_man), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"output_man$D_IN", &(TOPp->cfloat8_mul__DOT__output_man__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"output_man$EN", &(TOPp->cfloat8_mul__DOT__output_man__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"receive", &(TOPp->cfloat8_mul__DOT__receive), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"rg_operands", &(TOPp->cfloat8_mul__DOT__rg_operands), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,20,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"rg_operands$D_IN", &(TOPp->cfloat8_mul__DOT__rg_operands__024D_IN), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,20,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"rg_operands$EN", &(TOPp->cfloat8_mul__DOT__rg_operands__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"rounded_man", &(TOPp->cfloat8_mul__DOT__rounded_man), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"rounded_man$D_IN", &(TOPp->cfloat8_mul__DOT__rounded_man__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"rounded_man$EN", &(TOPp->cfloat8_mul__DOT__rounded_man__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"rounded_value__h3724", &(TOPp->cfloat8_mul__DOT__rounded_value___05Fh3724), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"send_data_input", &(TOPp->cfloat8_mul__DOT__send_data_input), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,20,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"sign_op1", &(TOPp->cfloat8_mul__DOT__sign_op1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"sign_op1$D_IN", &(TOPp->cfloat8_mul__DOT__sign_op1__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"sign_op1$EN", &(TOPp->cfloat8_mul__DOT__sign_op1__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"sign_op2", &(TOPp->cfloat8_mul__DOT__sign_op2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"sign_op2$D_IN", &(TOPp->cfloat8_mul__DOT__sign_op2__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"sign_op2$EN", &(TOPp->cfloat8_mul__DOT__sign_op2__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"stage", &(TOPp->cfloat8_mul__DOT__stage), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"stage$D_IN", &(TOPp->cfloat8_mul__DOT__stage__024D_IN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"stage$EN", &(TOPp->cfloat8_mul__DOT__stage__024EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"x__h1900", &(TOPp->cfloat8_mul__DOT__x___05Fh1900), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"x__h1971", &(TOPp->cfloat8_mul__DOT__x___05Fh1971), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"x__h3146", &(TOPp->cfloat8_mul__DOT__x___05Fh3146), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"x__h3220", &(TOPp->cfloat8_mul__DOT__x___05Fh3220), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_cfloat8_mul.varInsert(__Vfinal,"x__h3260", &(TOPp->cfloat8_mul__DOT__x___05Fh3260), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
    }
}
