// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->CLK));
        tracep->chgBit(oldp+1,(vlTOPp->RST_N));
        tracep->chgIData(oldp+2,(vlTOPp->send_data_input),21);
        tracep->chgBit(oldp+3,(vlTOPp->EN_send));
        tracep->chgBit(oldp+4,(vlTOPp->RDY_send));
        tracep->chgCData(oldp+5,(vlTOPp->receive),8);
        tracep->chgBit(oldp+6,(vlTOPp->RDY_receive));
        tracep->chgBit(oldp+7,(vlTOPp->cfloat8_mul__DOT__CLK));
        tracep->chgBit(oldp+8,(vlTOPp->cfloat8_mul__DOT__RST_N));
        tracep->chgIData(oldp+9,(vlTOPp->cfloat8_mul__DOT__send_data_input),21);
        tracep->chgBit(oldp+10,(vlTOPp->cfloat8_mul__DOT__EN_send));
        tracep->chgBit(oldp+11,(vlTOPp->cfloat8_mul__DOT__RDY_send));
        tracep->chgCData(oldp+12,(vlTOPp->cfloat8_mul__DOT__receive),8);
        tracep->chgBit(oldp+13,(vlTOPp->cfloat8_mul__DOT__RDY_receive));
        tracep->chgCData(oldp+14,(vlTOPp->cfloat8_mul__DOT__exp_op1),4);
        tracep->chgCData(oldp+15,(vlTOPp->cfloat8_mul__DOT__exp_op1__024D_IN),4);
        tracep->chgBit(oldp+16,(vlTOPp->cfloat8_mul__DOT__exp_op1__024EN));
        tracep->chgCData(oldp+17,(vlTOPp->cfloat8_mul__DOT__exp_op2),4);
        tracep->chgCData(oldp+18,(vlTOPp->cfloat8_mul__DOT__exp_op2__024D_IN),4);
        tracep->chgBit(oldp+19,(vlTOPp->cfloat8_mul__DOT__exp_op2__024EN));
        tracep->chgCData(oldp+20,(vlTOPp->cfloat8_mul__DOT__final_bias),4);
        tracep->chgCData(oldp+21,(vlTOPp->cfloat8_mul__DOT__final_bias__024D_IN),4);
        tracep->chgBit(oldp+22,(vlTOPp->cfloat8_mul__DOT__final_bias__024EN));
        tracep->chgCData(oldp+23,(vlTOPp->cfloat8_mul__DOT__final_exp),4);
        tracep->chgCData(oldp+24,(vlTOPp->cfloat8_mul__DOT__final_exp__024D_IN),4);
        tracep->chgBit(oldp+25,(vlTOPp->cfloat8_mul__DOT__final_exp__024EN));
        tracep->chgCData(oldp+26,(vlTOPp->cfloat8_mul__DOT__final_man),8);
        tracep->chgCData(oldp+27,(vlTOPp->cfloat8_mul__DOT__final_man__024D_IN),8);
        tracep->chgBit(oldp+28,(vlTOPp->cfloat8_mul__DOT__final_man__024EN));
        tracep->chgCData(oldp+29,(vlTOPp->cfloat8_mul__DOT__final_output),8);
        tracep->chgCData(oldp+30,(vlTOPp->cfloat8_mul__DOT__final_output__024D_IN),8);
        tracep->chgBit(oldp+31,(vlTOPp->cfloat8_mul__DOT__final_output__024EN));
        tracep->chgBit(oldp+32,(vlTOPp->cfloat8_mul__DOT__final_sign));
        tracep->chgBit(oldp+33,(vlTOPp->cfloat8_mul__DOT__final_sign__024D_IN));
        tracep->chgBit(oldp+34,(vlTOPp->cfloat8_mul__DOT__final_sign__024EN));
        tracep->chgCData(oldp+35,(vlTOPp->cfloat8_mul__DOT__man_op1),3);
        tracep->chgCData(oldp+36,(vlTOPp->cfloat8_mul__DOT__man_op1__024D_IN),3);
        tracep->chgBit(oldp+37,(vlTOPp->cfloat8_mul__DOT__man_op1__024EN));
        tracep->chgCData(oldp+38,(vlTOPp->cfloat8_mul__DOT__man_op2),3);
        tracep->chgCData(oldp+39,(vlTOPp->cfloat8_mul__DOT__man_op2__024D_IN),3);
        tracep->chgBit(oldp+40,(vlTOPp->cfloat8_mul__DOT__man_op2__024EN));
        tracep->chgCData(oldp+41,(vlTOPp->cfloat8_mul__DOT__normalized_count),4);
        tracep->chgCData(oldp+42,(vlTOPp->cfloat8_mul__DOT__normalized_count__024D_IN),4);
        tracep->chgBit(oldp+43,(vlTOPp->cfloat8_mul__DOT__normalized_count__024EN));
        tracep->chgCData(oldp+44,(vlTOPp->cfloat8_mul__DOT__normalized_man),6);
        tracep->chgCData(oldp+45,(vlTOPp->cfloat8_mul__DOT__normalized_man__024D_IN),6);
        tracep->chgBit(oldp+46,(vlTOPp->cfloat8_mul__DOT__normalized_man__024EN));
        tracep->chgCData(oldp+47,(vlTOPp->cfloat8_mul__DOT__output_man),3);
        tracep->chgCData(oldp+48,(vlTOPp->cfloat8_mul__DOT__output_man__024D_IN),3);
        tracep->chgBit(oldp+49,(vlTOPp->cfloat8_mul__DOT__output_man__024EN));
        tracep->chgIData(oldp+50,(vlTOPp->cfloat8_mul__DOT__rg_operands),21);
        tracep->chgIData(oldp+51,(vlTOPp->cfloat8_mul__DOT__rg_operands__024D_IN),21);
        tracep->chgBit(oldp+52,(vlTOPp->cfloat8_mul__DOT__rg_operands__024EN));
        tracep->chgCData(oldp+53,(vlTOPp->cfloat8_mul__DOT__rounded_man),3);
        tracep->chgCData(oldp+54,(vlTOPp->cfloat8_mul__DOT__rounded_man__024D_IN),3);
        tracep->chgBit(oldp+55,(vlTOPp->cfloat8_mul__DOT__rounded_man__024EN));
        tracep->chgBit(oldp+56,(vlTOPp->cfloat8_mul__DOT__sign_op1));
        tracep->chgBit(oldp+57,(vlTOPp->cfloat8_mul__DOT__sign_op1__024D_IN));
        tracep->chgBit(oldp+58,(vlTOPp->cfloat8_mul__DOT__sign_op1__024EN));
        tracep->chgBit(oldp+59,(vlTOPp->cfloat8_mul__DOT__sign_op2));
        tracep->chgBit(oldp+60,(vlTOPp->cfloat8_mul__DOT__sign_op2__024D_IN));
        tracep->chgBit(oldp+61,(vlTOPp->cfloat8_mul__DOT__sign_op2__024EN));
        tracep->chgCData(oldp+62,(vlTOPp->cfloat8_mul__DOT__stage),3);
        tracep->chgCData(oldp+63,(vlTOPp->cfloat8_mul__DOT__stage__024D_IN),3);
        tracep->chgBit(oldp+64,(vlTOPp->cfloat8_mul__DOT__stage__024EN));
        tracep->chgBit(oldp+65,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1));
        tracep->chgBit(oldp+66,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2));
        tracep->chgBit(oldp+67,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3));
        tracep->chgBit(oldp+68,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage4));
        tracep->chgBit(oldp+69,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage5));
        tracep->chgBit(oldp+70,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_trial));
        tracep->chgBit(oldp+71,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_send));
        tracep->chgBit(oldp+72,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1));
        tracep->chgBit(oldp+73,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2));
        tracep->chgBit(oldp+74,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3));
        tracep->chgBit(oldp+75,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4));
        tracep->chgBit(oldp+76,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5));
        tracep->chgBit(oldp+77,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_trial));
        tracep->chgBit(oldp+78,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_send));
        tracep->chgCData(oldp+79,(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_1),4);
        tracep->chgCData(oldp+80,(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2),4);
        tracep->chgCData(oldp+81,(vlTOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2),3);
        tracep->chgBit(oldp+82,(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FSEL_1));
        tracep->chgCData(oldp+83,(vlTOPp->cfloat8_mul__DOT__NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL___05FETC___05F_d30),8);
        tracep->chgCData(oldp+84,(vlTOPp->cfloat8_mul__DOT__IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___05F_d60),6);
        tracep->chgCData(oldp+85,(vlTOPp->cfloat8_mul__DOT__x___05Fh1900),6);
        tracep->chgCData(oldp+86,(vlTOPp->cfloat8_mul__DOT__x___05Fh3146),6);
        tracep->chgCData(oldp+87,(vlTOPp->cfloat8_mul__DOT__x___05Fh3260),6);
        tracep->chgCData(oldp+88,(vlTOPp->cfloat8_mul__DOT__count_temp___05Fh2059),4);
        tracep->chgCData(oldp+89,(vlTOPp->cfloat8_mul__DOT__inter_mantissa1___05Fh1426),4);
        tracep->chgCData(oldp+90,(vlTOPp->cfloat8_mul__DOT__inter_mantissa2___05Fh1427),4);
        tracep->chgCData(oldp+91,(vlTOPp->cfloat8_mul__DOT__x___05Fh1971),4);
        tracep->chgCData(oldp+92,(vlTOPp->cfloat8_mul__DOT__x___05Fh3220),4);
        tracep->chgCData(oldp+93,(vlTOPp->cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55),3);
        tracep->chgCData(oldp+94,(vlTOPp->cfloat8_mul__DOT__rounded_value___05Fh3724),3);
        tracep->chgBit(oldp+95,(vlTOPp->cfloat8_mul__DOT__hidden_bit_op1___05Fh1358));
        tracep->chgBit(oldp+96,(vlTOPp->cfloat8_mul__DOT__hidden_bit_op2___05Fh1359));
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
