// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VmkTestbench__Syms.h"


//======================

void VmkTestbench::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VmkTestbench::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VmkTestbench::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VmkTestbench::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VmkTestbench::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+39,"CLK", false,-1);
        tracep->declBit(c+40,"RST_N", false,-1);
        tracep->declBit(c+39,"top CLK", false,-1);
        tracep->declBit(c+40,"top RST_N", false,-1);
        tracep->declBus(c+1,"top count", false,-1, 31,0);
        tracep->declBus(c+2,"top count$D_IN", false,-1, 31,0);
        tracep->declBit(c+41,"top count$EN", false,-1);
        tracep->declBus(c+3,"top testmodule_exp_op1", false,-1, 3,0);
        tracep->declBus(c+4,"top testmodule_exp_op1$D_IN", false,-1, 3,0);
        tracep->declBit(c+5,"top testmodule_exp_op1$EN", false,-1);
        tracep->declBus(c+6,"top testmodule_exp_op2", false,-1, 3,0);
        tracep->declBus(c+7,"top testmodule_exp_op2$D_IN", false,-1, 3,0);
        tracep->declBit(c+5,"top testmodule_exp_op2$EN", false,-1);
        tracep->declBus(c+8,"top testmodule_final_exp", false,-1, 3,0);
        tracep->declBus(c+9,"top testmodule_final_exp$D_IN", false,-1, 3,0);
        tracep->declBit(c+5,"top testmodule_final_exp$EN", false,-1);
        tracep->declBus(c+10,"top testmodule_final_man", false,-1, 5,0);
        tracep->declBus(c+11,"top testmodule_final_man$D_IN", false,-1, 5,0);
        tracep->declBit(c+12,"top testmodule_final_man$EN", false,-1);
        tracep->declBus(c+13,"top testmodule_final_output", false,-1, 7,0);
        tracep->declBus(c+14,"top testmodule_final_output$D_IN", false,-1, 7,0);
        tracep->declBit(c+15,"top testmodule_final_output$EN", false,-1);
        tracep->declBit(c+16,"top testmodule_final_sign", false,-1);
        tracep->declBit(c+17,"top testmodule_final_sign$D_IN", false,-1);
        tracep->declBit(c+18,"top testmodule_final_sign$EN", false,-1);
        tracep->declBus(c+19,"top testmodule_man_op1", false,-1, 2,0);
        tracep->declBus(c+20,"top testmodule_man_op1$D_IN", false,-1, 2,0);
        tracep->declBit(c+12,"top testmodule_man_op1$EN", false,-1);
        tracep->declBus(c+21,"top testmodule_man_op2", false,-1, 2,0);
        tracep->declBus(c+22,"top testmodule_man_op2$D_IN", false,-1, 2,0);
        tracep->declBit(c+12,"top testmodule_man_op2$EN", false,-1);
        tracep->declBus(c+23,"top testmodule_output_man", false,-1, 2,0);
        tracep->declBus(c+24,"top testmodule_output_man$D_IN", false,-1, 2,0);
        tracep->declBit(c+12,"top testmodule_output_man$EN", false,-1);
        tracep->declArray(c+25,"top testmodule_rg_operands", false,-1, 79,0);
        tracep->declArray(c+42,"top testmodule_rg_operands$D_IN", false,-1, 79,0);
        tracep->declBit(c+28,"top testmodule_rg_operands$EN", false,-1);
        tracep->declBit(c+29,"top testmodule_sign_op1", false,-1);
        tracep->declBit(c+30,"top testmodule_sign_op1$D_IN", false,-1);
        tracep->declBit(c+18,"top testmodule_sign_op1$EN", false,-1);
        tracep->declBit(c+31,"top testmodule_sign_op2", false,-1);
        tracep->declBit(c+32,"top testmodule_sign_op2$D_IN", false,-1);
        tracep->declBit(c+18,"top testmodule_sign_op2$EN", false,-1);
        tracep->declBus(c+33,"top testmodule_stage", false,-1, 2,0);
        tracep->declBus(c+34,"top testmodule_stage$D_IN", false,-1, 2,0);
        tracep->declBit(c+35,"top testmodule_stage$EN", false,-1);
        tracep->declBit(c+28,"top CAN_FIRE_RL_giveInp", false,-1);
        tracep->declBit(c+41,"top CAN_FIRE_RL_greet", false,-1);
        tracep->declBit(c+36,"top CAN_FIRE_RL_testmodule_display_output", false,-1);
        tracep->declBit(c+18,"top CAN_FIRE_RL_testmodule_stage1", false,-1);
        tracep->declBit(c+5,"top CAN_FIRE_RL_testmodule_stage2", false,-1);
        tracep->declBit(c+12,"top CAN_FIRE_RL_testmodule_stage3", false,-1);
        tracep->declBit(c+15,"top CAN_FIRE_RL_testmodule_stage4", false,-1);
        tracep->declBit(c+41,"top CAN_FIRE_RL_testmodule_trial", false,-1);
        tracep->declBit(c+28,"top WILL_FIRE_RL_giveInp", false,-1);
        tracep->declBit(c+41,"top WILL_FIRE_RL_greet", false,-1);
        tracep->declBit(c+36,"top WILL_FIRE_RL_testmodule_display_output", false,-1);
        tracep->declBit(c+18,"top WILL_FIRE_RL_testmodule_stage1", false,-1);
        tracep->declBit(c+5,"top WILL_FIRE_RL_testmodule_stage2", false,-1);
        tracep->declBit(c+12,"top WILL_FIRE_RL_testmodule_stage3", false,-1);
        tracep->declBit(c+15,"top WILL_FIRE_RL_testmodule_stage4", false,-1);
        tracep->declBit(c+41,"top WILL_FIRE_RL_testmodule_trial", false,-1);
        tracep->declBus(c+37,"top MUX_testmodule_stage$write_1__VAL_2", false,-1, 2,0);
        tracep->declBus(c+38,"top x__h1457", false,-1, 2,0);
    }
}

void VmkTestbench::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VmkTestbench::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VmkTestbench::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->top__DOT__count),32);
        tracep->fullIData(oldp+2,(((IData)(1U) + vlTOPp->top__DOT__count)),32);
        tracep->fullCData(oldp+3,(vlTOPp->top__DOT__testmodule_exp_op1),4);
        tracep->fullCData(oldp+4,((0xfU & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                           >> 0xbU))),4);
        tracep->fullBit(oldp+5,((2U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
        tracep->fullCData(oldp+6,(vlTOPp->top__DOT__testmodule_exp_op2),4);
        tracep->fullCData(oldp+7,((0xfU & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                           >> 3U))),4);
        tracep->fullCData(oldp+8,(vlTOPp->top__DOT__testmodule_final_exp),4);
        tracep->fullCData(oldp+9,((0xfU & ((IData)(vlTOPp->top__DOT__testmodule_exp_op1) 
                                           + (IData)(vlTOPp->top__DOT__testmodule_exp_op2)))),4);
        tracep->fullCData(oldp+10,(vlTOPp->top__DOT__testmodule_final_man),6);
        tracep->fullCData(oldp+11,((0x3fU & ((IData)(vlTOPp->top__DOT__testmodule_man_op1) 
                                             * (IData)(vlTOPp->top__DOT__testmodule_man_op2)))),6);
        tracep->fullBit(oldp+12,((3U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
        tracep->fullCData(oldp+13,(vlTOPp->top__DOT__testmodule_final_output),8);
        tracep->fullCData(oldp+14,((((IData)(vlTOPp->top__DOT__testmodule_final_sign) 
                                     << 7U) | (((IData)(vlTOPp->top__DOT__testmodule_final_exp) 
                                                << 3U) 
                                               | (IData)(vlTOPp->top__DOT__testmodule_output_man)))),8);
        tracep->fullBit(oldp+15,((4U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
        tracep->fullBit(oldp+16,(vlTOPp->top__DOT__testmodule_final_sign));
        tracep->fullBit(oldp+17,(((IData)(vlTOPp->top__DOT__testmodule_sign_op1) 
                                  ^ (IData)(vlTOPp->top__DOT__testmodule_sign_op2))));
        tracep->fullBit(oldp+18,((1U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
        tracep->fullCData(oldp+19,(vlTOPp->top__DOT__testmodule_man_op1),3);
        tracep->fullCData(oldp+20,((7U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                          >> 8U))),3);
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__testmodule_man_op2),3);
        tracep->fullCData(oldp+22,((7U & vlTOPp->top__DOT__testmodule_rg_operands[2U])),3);
        tracep->fullCData(oldp+23,(vlTOPp->top__DOT__testmodule_output_man),3);
        tracep->fullCData(oldp+24,((7U & ((4U & (IData)(vlTOPp->top__DOT__testmodule_final_man))
                                           ? ((IData)(1U) 
                                              + ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                                                 >> 3U))
                                           : ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                                              >> 3U)))),3);
        tracep->fullWData(oldp+25,(vlTOPp->top__DOT__testmodule_rg_operands),80);
        tracep->fullBit(oldp+28,((0x80000002U > (0x80000000U 
                                                 ^ vlTOPp->top__DOT__count))));
        tracep->fullBit(oldp+29,(vlTOPp->top__DOT__testmodule_sign_op1));
        tracep->fullBit(oldp+30,((1U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                        >> 0xfU))));
        tracep->fullBit(oldp+31,(vlTOPp->top__DOT__testmodule_sign_op2));
        tracep->fullBit(oldp+32,((1U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                        >> 7U))));
        tracep->fullCData(oldp+33,(vlTOPp->top__DOT__testmodule_stage),3);
        tracep->fullCData(oldp+34,(((0x80000002U > 
                                     (0x80000000U ^ vlTOPp->top__DOT__count))
                                     ? 1U : (7U & (
                                                   (4U 
                                                    == (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                    ? 
                                                   ((IData)(1U) 
                                                    + (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                     ? 
                                                    ((IData)(1U) 
                                                     + (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                     : 
                                                    ((2U 
                                                      == (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                      ? 
                                                     ((IData)(1U) 
                                                      + (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                      : 
                                                     ((1U 
                                                       == (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                       ? 
                                                      ((IData)(1U) 
                                                       + (IData)(vlTOPp->top__DOT__testmodule_stage))
                                                       : 2U))))))),3);
        tracep->fullBit(oldp+35,((((((4U == (IData)(vlTOPp->top__DOT__testmodule_stage)) 
                                     | (3U == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                    | (2U == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                   | (1U == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                  | (0x80000002U > 
                                     (0x80000000U ^ vlTOPp->top__DOT__count)))));
        tracep->fullBit(oldp+36,((5U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
        tracep->fullCData(oldp+37,((7U & ((IData)(1U) 
                                          + (IData)(vlTOPp->top__DOT__testmodule_stage)))),3);
        tracep->fullCData(oldp+38,((7U & ((IData)(1U) 
                                          + ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                                             >> 3U)))),3);
        tracep->fullBit(oldp+39,(vlTOPp->CLK));
        tracep->fullBit(oldp+40,(vlTOPp->RST_N));
        tracep->fullBit(oldp+41,(1U));
        __Vtemp1[0U] = 4U;
        __Vtemp1[1U] = 1U;
        __Vtemp1[2U] = 0x13c4U;
        tracep->fullWData(oldp+42,(__Vtemp1),80);
    }
}
