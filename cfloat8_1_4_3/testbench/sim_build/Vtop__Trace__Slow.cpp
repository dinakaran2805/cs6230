// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"CLK", false,-1);
        tracep->declBit(c+2,"RST_N", false,-1);
        tracep->declBus(c+3,"send_data_input", false,-1, 20,0);
        tracep->declBit(c+4,"EN_send", false,-1);
        tracep->declBit(c+5,"RDY_send", false,-1);
        tracep->declBus(c+6,"receive", false,-1, 7,0);
        tracep->declBit(c+7,"RDY_receive", false,-1);
        tracep->declBit(c+8,"cfloat8_mul CLK", false,-1);
        tracep->declBit(c+9,"cfloat8_mul RST_N", false,-1);
        tracep->declBus(c+10,"cfloat8_mul send_data_input", false,-1, 20,0);
        tracep->declBit(c+11,"cfloat8_mul EN_send", false,-1);
        tracep->declBit(c+12,"cfloat8_mul RDY_send", false,-1);
        tracep->declBus(c+13,"cfloat8_mul receive", false,-1, 7,0);
        tracep->declBit(c+14,"cfloat8_mul RDY_receive", false,-1);
        tracep->declBus(c+15,"cfloat8_mul exp_op1", false,-1, 3,0);
        tracep->declBus(c+16,"cfloat8_mul exp_op1$D_IN", false,-1, 3,0);
        tracep->declBit(c+17,"cfloat8_mul exp_op1$EN", false,-1);
        tracep->declBus(c+18,"cfloat8_mul exp_op2", false,-1, 3,0);
        tracep->declBus(c+19,"cfloat8_mul exp_op2$D_IN", false,-1, 3,0);
        tracep->declBit(c+20,"cfloat8_mul exp_op2$EN", false,-1);
        tracep->declBus(c+21,"cfloat8_mul final_bias", false,-1, 3,0);
        tracep->declBus(c+22,"cfloat8_mul final_bias$D_IN", false,-1, 3,0);
        tracep->declBit(c+23,"cfloat8_mul final_bias$EN", false,-1);
        tracep->declBus(c+24,"cfloat8_mul final_exp", false,-1, 3,0);
        tracep->declBus(c+25,"cfloat8_mul final_exp$D_IN", false,-1, 3,0);
        tracep->declBit(c+26,"cfloat8_mul final_exp$EN", false,-1);
        tracep->declBus(c+27,"cfloat8_mul final_man", false,-1, 7,0);
        tracep->declBus(c+28,"cfloat8_mul final_man$D_IN", false,-1, 7,0);
        tracep->declBit(c+29,"cfloat8_mul final_man$EN", false,-1);
        tracep->declBus(c+30,"cfloat8_mul final_output", false,-1, 7,0);
        tracep->declBus(c+31,"cfloat8_mul final_output$D_IN", false,-1, 7,0);
        tracep->declBit(c+32,"cfloat8_mul final_output$EN", false,-1);
        tracep->declBit(c+33,"cfloat8_mul final_sign", false,-1);
        tracep->declBit(c+34,"cfloat8_mul final_sign$D_IN", false,-1);
        tracep->declBit(c+35,"cfloat8_mul final_sign$EN", false,-1);
        tracep->declBus(c+36,"cfloat8_mul man_op1", false,-1, 2,0);
        tracep->declBus(c+37,"cfloat8_mul man_op1$D_IN", false,-1, 2,0);
        tracep->declBit(c+38,"cfloat8_mul man_op1$EN", false,-1);
        tracep->declBus(c+39,"cfloat8_mul man_op2", false,-1, 2,0);
        tracep->declBus(c+40,"cfloat8_mul man_op2$D_IN", false,-1, 2,0);
        tracep->declBit(c+41,"cfloat8_mul man_op2$EN", false,-1);
        tracep->declBus(c+42,"cfloat8_mul normalized_count", false,-1, 3,0);
        tracep->declBus(c+43,"cfloat8_mul normalized_count$D_IN", false,-1, 3,0);
        tracep->declBit(c+44,"cfloat8_mul normalized_count$EN", false,-1);
        tracep->declBus(c+45,"cfloat8_mul normalized_man", false,-1, 5,0);
        tracep->declBus(c+46,"cfloat8_mul normalized_man$D_IN", false,-1, 5,0);
        tracep->declBit(c+47,"cfloat8_mul normalized_man$EN", false,-1);
        tracep->declBus(c+48,"cfloat8_mul output_man", false,-1, 2,0);
        tracep->declBus(c+49,"cfloat8_mul output_man$D_IN", false,-1, 2,0);
        tracep->declBit(c+50,"cfloat8_mul output_man$EN", false,-1);
        tracep->declBus(c+51,"cfloat8_mul rg_operands", false,-1, 20,0);
        tracep->declBus(c+52,"cfloat8_mul rg_operands$D_IN", false,-1, 20,0);
        tracep->declBit(c+53,"cfloat8_mul rg_operands$EN", false,-1);
        tracep->declBus(c+54,"cfloat8_mul rounded_man", false,-1, 2,0);
        tracep->declBus(c+55,"cfloat8_mul rounded_man$D_IN", false,-1, 2,0);
        tracep->declBit(c+56,"cfloat8_mul rounded_man$EN", false,-1);
        tracep->declBit(c+57,"cfloat8_mul sign_op1", false,-1);
        tracep->declBit(c+58,"cfloat8_mul sign_op1$D_IN", false,-1);
        tracep->declBit(c+59,"cfloat8_mul sign_op1$EN", false,-1);
        tracep->declBit(c+60,"cfloat8_mul sign_op2", false,-1);
        tracep->declBit(c+61,"cfloat8_mul sign_op2$D_IN", false,-1);
        tracep->declBit(c+62,"cfloat8_mul sign_op2$EN", false,-1);
        tracep->declBus(c+63,"cfloat8_mul stage", false,-1, 2,0);
        tracep->declBus(c+64,"cfloat8_mul stage$D_IN", false,-1, 2,0);
        tracep->declBit(c+65,"cfloat8_mul stage$EN", false,-1);
        tracep->declBit(c+66,"cfloat8_mul CAN_FIRE_RL_stage1", false,-1);
        tracep->declBit(c+67,"cfloat8_mul CAN_FIRE_RL_stage2", false,-1);
        tracep->declBit(c+68,"cfloat8_mul CAN_FIRE_RL_stage3", false,-1);
        tracep->declBit(c+69,"cfloat8_mul CAN_FIRE_RL_stage4", false,-1);
        tracep->declBit(c+70,"cfloat8_mul CAN_FIRE_RL_stage5", false,-1);
        tracep->declBit(c+71,"cfloat8_mul CAN_FIRE_RL_trial", false,-1);
        tracep->declBit(c+72,"cfloat8_mul CAN_FIRE_send", false,-1);
        tracep->declBit(c+73,"cfloat8_mul WILL_FIRE_RL_stage1", false,-1);
        tracep->declBit(c+74,"cfloat8_mul WILL_FIRE_RL_stage2", false,-1);
        tracep->declBit(c+75,"cfloat8_mul WILL_FIRE_RL_stage3", false,-1);
        tracep->declBit(c+76,"cfloat8_mul WILL_FIRE_RL_stage4", false,-1);
        tracep->declBit(c+77,"cfloat8_mul WILL_FIRE_RL_stage5", false,-1);
        tracep->declBit(c+78,"cfloat8_mul WILL_FIRE_RL_trial", false,-1);
        tracep->declBit(c+79,"cfloat8_mul WILL_FIRE_send", false,-1);
        tracep->declBus(c+80,"cfloat8_mul MUX_final_exp$write_1__VAL_1", false,-1, 3,0);
        tracep->declBus(c+81,"cfloat8_mul MUX_final_exp$write_1__VAL_2", false,-1, 3,0);
        tracep->declBus(c+82,"cfloat8_mul MUX_stage$write_1__VAL_2", false,-1, 2,0);
        tracep->declBit(c+83,"cfloat8_mul MUX_final_exp$write_1__SEL_1", false,-1);
        tracep->declBus(c+84,"cfloat8_mul NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL__ETC___d30", false,-1, 7,0);
        tracep->declBus(c+85,"cfloat8_mul IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___d60", false,-1, 5,0);
        tracep->declBus(c+86,"cfloat8_mul x__h1900", false,-1, 5,0);
        tracep->declBus(c+87,"cfloat8_mul x__h3146", false,-1, 5,0);
        tracep->declBus(c+88,"cfloat8_mul x__h3260", false,-1, 5,0);
        tracep->declBus(c+89,"cfloat8_mul count_temp__h2059", false,-1, 3,0);
        tracep->declBus(c+90,"cfloat8_mul inter_mantissa1__h1426", false,-1, 3,0);
        tracep->declBus(c+91,"cfloat8_mul inter_mantissa2__h1427", false,-1, 3,0);
        tracep->declBus(c+92,"cfloat8_mul x__h1971", false,-1, 3,0);
        tracep->declBus(c+93,"cfloat8_mul x__h3220", false,-1, 3,0);
        tracep->declBus(c+94,"cfloat8_mul IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___d55", false,-1, 2,0);
        tracep->declBus(c+95,"cfloat8_mul rounded_value__h3724", false,-1, 2,0);
        tracep->declBit(c+96,"cfloat8_mul hidden_bit_op1__h1358", false,-1);
        tracep->declBit(c+97,"cfloat8_mul hidden_bit_op2__h1359", false,-1);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->CLK));
        tracep->fullBit(oldp+2,(vlTOPp->RST_N));
        tracep->fullIData(oldp+3,(vlTOPp->send_data_input),21);
        tracep->fullBit(oldp+4,(vlTOPp->EN_send));
        tracep->fullBit(oldp+5,(vlTOPp->RDY_send));
        tracep->fullCData(oldp+6,(vlTOPp->receive),8);
        tracep->fullBit(oldp+7,(vlTOPp->RDY_receive));
        tracep->fullBit(oldp+8,(vlTOPp->cfloat8_mul__DOT__CLK));
        tracep->fullBit(oldp+9,(vlTOPp->cfloat8_mul__DOT__RST_N));
        tracep->fullIData(oldp+10,(vlTOPp->cfloat8_mul__DOT__send_data_input),21);
        tracep->fullBit(oldp+11,(vlTOPp->cfloat8_mul__DOT__EN_send));
        tracep->fullBit(oldp+12,(vlTOPp->cfloat8_mul__DOT__RDY_send));
        tracep->fullCData(oldp+13,(vlTOPp->cfloat8_mul__DOT__receive),8);
        tracep->fullBit(oldp+14,(vlTOPp->cfloat8_mul__DOT__RDY_receive));
        tracep->fullCData(oldp+15,(vlTOPp->cfloat8_mul__DOT__exp_op1),4);
        tracep->fullCData(oldp+16,(vlTOPp->cfloat8_mul__DOT__exp_op1__024D_IN),4);
        tracep->fullBit(oldp+17,(vlTOPp->cfloat8_mul__DOT__exp_op1__024EN));
        tracep->fullCData(oldp+18,(vlTOPp->cfloat8_mul__DOT__exp_op2),4);
        tracep->fullCData(oldp+19,(vlTOPp->cfloat8_mul__DOT__exp_op2__024D_IN),4);
        tracep->fullBit(oldp+20,(vlTOPp->cfloat8_mul__DOT__exp_op2__024EN));
        tracep->fullCData(oldp+21,(vlTOPp->cfloat8_mul__DOT__final_bias),4);
        tracep->fullCData(oldp+22,(vlTOPp->cfloat8_mul__DOT__final_bias__024D_IN),4);
        tracep->fullBit(oldp+23,(vlTOPp->cfloat8_mul__DOT__final_bias__024EN));
        tracep->fullCData(oldp+24,(vlTOPp->cfloat8_mul__DOT__final_exp),4);
        tracep->fullCData(oldp+25,(vlTOPp->cfloat8_mul__DOT__final_exp__024D_IN),4);
        tracep->fullBit(oldp+26,(vlTOPp->cfloat8_mul__DOT__final_exp__024EN));
        tracep->fullCData(oldp+27,(vlTOPp->cfloat8_mul__DOT__final_man),8);
        tracep->fullCData(oldp+28,(vlTOPp->cfloat8_mul__DOT__final_man__024D_IN),8);
        tracep->fullBit(oldp+29,(vlTOPp->cfloat8_mul__DOT__final_man__024EN));
        tracep->fullCData(oldp+30,(vlTOPp->cfloat8_mul__DOT__final_output),8);
        tracep->fullCData(oldp+31,(vlTOPp->cfloat8_mul__DOT__final_output__024D_IN),8);
        tracep->fullBit(oldp+32,(vlTOPp->cfloat8_mul__DOT__final_output__024EN));
        tracep->fullBit(oldp+33,(vlTOPp->cfloat8_mul__DOT__final_sign));
        tracep->fullBit(oldp+34,(vlTOPp->cfloat8_mul__DOT__final_sign__024D_IN));
        tracep->fullBit(oldp+35,(vlTOPp->cfloat8_mul__DOT__final_sign__024EN));
        tracep->fullCData(oldp+36,(vlTOPp->cfloat8_mul__DOT__man_op1),3);
        tracep->fullCData(oldp+37,(vlTOPp->cfloat8_mul__DOT__man_op1__024D_IN),3);
        tracep->fullBit(oldp+38,(vlTOPp->cfloat8_mul__DOT__man_op1__024EN));
        tracep->fullCData(oldp+39,(vlTOPp->cfloat8_mul__DOT__man_op2),3);
        tracep->fullCData(oldp+40,(vlTOPp->cfloat8_mul__DOT__man_op2__024D_IN),3);
        tracep->fullBit(oldp+41,(vlTOPp->cfloat8_mul__DOT__man_op2__024EN));
        tracep->fullCData(oldp+42,(vlTOPp->cfloat8_mul__DOT__normalized_count),4);
        tracep->fullCData(oldp+43,(vlTOPp->cfloat8_mul__DOT__normalized_count__024D_IN),4);
        tracep->fullBit(oldp+44,(vlTOPp->cfloat8_mul__DOT__normalized_count__024EN));
        tracep->fullCData(oldp+45,(vlTOPp->cfloat8_mul__DOT__normalized_man),6);
        tracep->fullCData(oldp+46,(vlTOPp->cfloat8_mul__DOT__normalized_man__024D_IN),6);
        tracep->fullBit(oldp+47,(vlTOPp->cfloat8_mul__DOT__normalized_man__024EN));
        tracep->fullCData(oldp+48,(vlTOPp->cfloat8_mul__DOT__output_man),3);
        tracep->fullCData(oldp+49,(vlTOPp->cfloat8_mul__DOT__output_man__024D_IN),3);
        tracep->fullBit(oldp+50,(vlTOPp->cfloat8_mul__DOT__output_man__024EN));
        tracep->fullIData(oldp+51,(vlTOPp->cfloat8_mul__DOT__rg_operands),21);
        tracep->fullIData(oldp+52,(vlTOPp->cfloat8_mul__DOT__rg_operands__024D_IN),21);
        tracep->fullBit(oldp+53,(vlTOPp->cfloat8_mul__DOT__rg_operands__024EN));
        tracep->fullCData(oldp+54,(vlTOPp->cfloat8_mul__DOT__rounded_man),3);
        tracep->fullCData(oldp+55,(vlTOPp->cfloat8_mul__DOT__rounded_man__024D_IN),3);
        tracep->fullBit(oldp+56,(vlTOPp->cfloat8_mul__DOT__rounded_man__024EN));
        tracep->fullBit(oldp+57,(vlTOPp->cfloat8_mul__DOT__sign_op1));
        tracep->fullBit(oldp+58,(vlTOPp->cfloat8_mul__DOT__sign_op1__024D_IN));
        tracep->fullBit(oldp+59,(vlTOPp->cfloat8_mul__DOT__sign_op1__024EN));
        tracep->fullBit(oldp+60,(vlTOPp->cfloat8_mul__DOT__sign_op2));
        tracep->fullBit(oldp+61,(vlTOPp->cfloat8_mul__DOT__sign_op2__024D_IN));
        tracep->fullBit(oldp+62,(vlTOPp->cfloat8_mul__DOT__sign_op2__024EN));
        tracep->fullCData(oldp+63,(vlTOPp->cfloat8_mul__DOT__stage),3);
        tracep->fullCData(oldp+64,(vlTOPp->cfloat8_mul__DOT__stage__024D_IN),3);
        tracep->fullBit(oldp+65,(vlTOPp->cfloat8_mul__DOT__stage__024EN));
        tracep->fullBit(oldp+66,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1));
        tracep->fullBit(oldp+67,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2));
        tracep->fullBit(oldp+68,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3));
        tracep->fullBit(oldp+69,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage4));
        tracep->fullBit(oldp+70,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage5));
        tracep->fullBit(oldp+71,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_trial));
        tracep->fullBit(oldp+72,(vlTOPp->cfloat8_mul__DOT__CAN_FIRE_send));
        tracep->fullBit(oldp+73,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1));
        tracep->fullBit(oldp+74,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2));
        tracep->fullBit(oldp+75,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3));
        tracep->fullBit(oldp+76,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4));
        tracep->fullBit(oldp+77,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5));
        tracep->fullBit(oldp+78,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_trial));
        tracep->fullBit(oldp+79,(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_send));
        tracep->fullCData(oldp+80,(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_1),4);
        tracep->fullCData(oldp+81,(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2),4);
        tracep->fullCData(oldp+82,(vlTOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2),3);
        tracep->fullBit(oldp+83,(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FSEL_1));
        tracep->fullCData(oldp+84,(vlTOPp->cfloat8_mul__DOT__NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL___05FETC___05F_d30),8);
        tracep->fullCData(oldp+85,(vlTOPp->cfloat8_mul__DOT__IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___05F_d60),6);
        tracep->fullCData(oldp+86,(vlTOPp->cfloat8_mul__DOT__x___05Fh1900),6);
        tracep->fullCData(oldp+87,(vlTOPp->cfloat8_mul__DOT__x___05Fh3146),6);
        tracep->fullCData(oldp+88,(vlTOPp->cfloat8_mul__DOT__x___05Fh3260),6);
        tracep->fullCData(oldp+89,(vlTOPp->cfloat8_mul__DOT__count_temp___05Fh2059),4);
        tracep->fullCData(oldp+90,(vlTOPp->cfloat8_mul__DOT__inter_mantissa1___05Fh1426),4);
        tracep->fullCData(oldp+91,(vlTOPp->cfloat8_mul__DOT__inter_mantissa2___05Fh1427),4);
        tracep->fullCData(oldp+92,(vlTOPp->cfloat8_mul__DOT__x___05Fh1971),4);
        tracep->fullCData(oldp+93,(vlTOPp->cfloat8_mul__DOT__x___05Fh3220),4);
        tracep->fullCData(oldp+94,(vlTOPp->cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55),3);
        tracep->fullCData(oldp+95,(vlTOPp->cfloat8_mul__DOT__rounded_value___05Fh3724),3);
        tracep->fullBit(oldp+96,(vlTOPp->cfloat8_mul__DOT__hidden_bit_op1___05Fh1358));
        tracep->fullBit(oldp+97,(vlTOPp->cfloat8_mul__DOT__hidden_bit_op2___05Fh1359));
    }
}
