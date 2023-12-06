// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VmkTestbench__Syms.h"


void VmkTestbench::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VmkTestbench::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->top__DOT__count),32);
            tracep->chgIData(oldp+1,(((IData)(1U) + vlTOPp->top__DOT__count)),32);
            tracep->chgCData(oldp+2,(vlTOPp->top__DOT__testmodule_exp_op1),4);
            tracep->chgCData(oldp+3,((0xfU & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                              >> 0xbU))),4);
            tracep->chgBit(oldp+4,((2U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
            tracep->chgCData(oldp+5,(vlTOPp->top__DOT__testmodule_exp_op2),4);
            tracep->chgCData(oldp+6,((0xfU & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                              >> 3U))),4);
            tracep->chgCData(oldp+7,(vlTOPp->top__DOT__testmodule_final_exp),4);
            tracep->chgCData(oldp+8,((0xfU & ((IData)(vlTOPp->top__DOT__testmodule_exp_op1) 
                                              + (IData)(vlTOPp->top__DOT__testmodule_exp_op2)))),4);
            tracep->chgCData(oldp+9,(vlTOPp->top__DOT__testmodule_final_man),6);
            tracep->chgCData(oldp+10,((0x3fU & ((IData)(vlTOPp->top__DOT__testmodule_man_op1) 
                                                * (IData)(vlTOPp->top__DOT__testmodule_man_op2)))),6);
            tracep->chgBit(oldp+11,((3U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
            tracep->chgCData(oldp+12,(vlTOPp->top__DOT__testmodule_final_output),8);
            tracep->chgCData(oldp+13,((((IData)(vlTOPp->top__DOT__testmodule_final_sign) 
                                        << 7U) | (((IData)(vlTOPp->top__DOT__testmodule_final_exp) 
                                                   << 3U) 
                                                  | (IData)(vlTOPp->top__DOT__testmodule_output_man)))),8);
            tracep->chgBit(oldp+14,((4U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
            tracep->chgBit(oldp+15,(vlTOPp->top__DOT__testmodule_final_sign));
            tracep->chgBit(oldp+16,(((IData)(vlTOPp->top__DOT__testmodule_sign_op1) 
                                     ^ (IData)(vlTOPp->top__DOT__testmodule_sign_op2))));
            tracep->chgBit(oldp+17,((1U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
            tracep->chgCData(oldp+18,(vlTOPp->top__DOT__testmodule_man_op1),3);
            tracep->chgCData(oldp+19,((7U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                             >> 8U))),3);
            tracep->chgCData(oldp+20,(vlTOPp->top__DOT__testmodule_man_op2),3);
            tracep->chgCData(oldp+21,((7U & vlTOPp->top__DOT__testmodule_rg_operands[2U])),3);
            tracep->chgCData(oldp+22,(vlTOPp->top__DOT__testmodule_output_man),3);
            tracep->chgCData(oldp+23,((7U & ((4U & (IData)(vlTOPp->top__DOT__testmodule_final_man))
                                              ? ((IData)(1U) 
                                                 + 
                                                 ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                                                  >> 3U))
                                              : ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                                                 >> 3U)))),3);
            tracep->chgWData(oldp+24,(vlTOPp->top__DOT__testmodule_rg_operands),80);
            tracep->chgBit(oldp+27,((0x80000002U > 
                                     (0x80000000U ^ vlTOPp->top__DOT__count))));
            tracep->chgBit(oldp+28,(vlTOPp->top__DOT__testmodule_sign_op1));
            tracep->chgBit(oldp+29,((1U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                           >> 0xfU))));
            tracep->chgBit(oldp+30,(vlTOPp->top__DOT__testmodule_sign_op2));
            tracep->chgBit(oldp+31,((1U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                           >> 7U))));
            tracep->chgCData(oldp+32,(vlTOPp->top__DOT__testmodule_stage),3);
            tracep->chgCData(oldp+33,(((0x80000002U 
                                        > (0x80000000U 
                                           ^ vlTOPp->top__DOT__count))
                                        ? 1U : (7U 
                                                & ((4U 
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
            tracep->chgBit(oldp+34,((((((4U == (IData)(vlTOPp->top__DOT__testmodule_stage)) 
                                        | (3U == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                       | (2U == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                      | (1U == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                     | (0x80000002U 
                                        > (0x80000000U 
                                           ^ vlTOPp->top__DOT__count)))));
            tracep->chgBit(oldp+35,((5U == (IData)(vlTOPp->top__DOT__testmodule_stage))));
            tracep->chgCData(oldp+36,((7U & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__testmodule_stage)))),3);
            tracep->chgCData(oldp+37,((7U & ((IData)(1U) 
                                             + ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                                                >> 3U)))),3);
        }
        tracep->chgBit(oldp+38,(vlTOPp->CLK));
        tracep->chgBit(oldp+39,(vlTOPp->RST_N));
    }
}

void VmkTestbench::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VmkTestbench__Syms* __restrict vlSymsp = static_cast<VmkTestbench__Syms*>(userp);
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
