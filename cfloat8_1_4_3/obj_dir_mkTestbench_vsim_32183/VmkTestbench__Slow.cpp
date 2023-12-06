// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VmkTestbench.h for the primary calling header

#include "VmkTestbench.h"
#include "VmkTestbench__Syms.h"

//==========

VL_CTOR_IMP(VmkTestbench) {
    VmkTestbench__Syms* __restrict vlSymsp = __VlSymsp = new VmkTestbench__Syms(this, name());
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VmkTestbench::__Vconfigure(VmkTestbench__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VmkTestbench::~VmkTestbench() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void VmkTestbench::_initial__TOP__3(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_initial__TOP__3\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__count = 0xaaaaaaaaU;
    vlTOPp->top__DOT__testmodule_exp_op1 = 0xaU;
    vlTOPp->top__DOT__testmodule_exp_op2 = 0xaU;
    vlTOPp->top__DOT__testmodule_final_exp = 0xaU;
    vlTOPp->top__DOT__testmodule_final_man = 0x2aU;
    vlTOPp->top__DOT__testmodule_final_output = 0xaaU;
    vlTOPp->top__DOT__testmodule_final_sign = 0U;
    vlTOPp->top__DOT__testmodule_man_op1 = 2U;
    vlTOPp->top__DOT__testmodule_man_op2 = 2U;
    vlTOPp->top__DOT__testmodule_output_man = 2U;
    vlTOPp->top__DOT__testmodule_rg_operands[0U] = 0xaaaaaaaaU;
    vlTOPp->top__DOT__testmodule_rg_operands[1U] = 0xaaaaaaaaU;
    vlTOPp->top__DOT__testmodule_rg_operands[2U] = 0xaaaaU;
    vlTOPp->top__DOT__testmodule_sign_op1 = 0U;
    vlTOPp->top__DOT__testmodule_sign_op2 = 0U;
    vlTOPp->top__DOT__testmodule_stage = 2U;
}

void VmkTestbench::_settle__TOP__4(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_settle__TOP__4\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__count__024D_IN = ((IData)(1U) 
                                        + vlTOPp->top__DOT__count);
    vlTOPp->top__DOT__testmodule_stage__024D_IN = (
                                                   (0x80000002U 
                                                    > 
                                                    (0x80000000U 
                                                     ^ vlTOPp->top__DOT__count))
                                                    ? 1U
                                                    : 
                                                   (7U 
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
                                                           : 2U))))));
    vlTOPp->top__DOT__testmodule_stage__024EN = (((
                                                   ((4U 
                                                     == (IData)(vlTOPp->top__DOT__testmodule_stage)) 
                                                    | (3U 
                                                       == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                                   | (2U 
                                                      == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                                  | (1U 
                                                     == (IData)(vlTOPp->top__DOT__testmodule_stage))) 
                                                 | (0x80000002U 
                                                    > 
                                                    (0x80000000U 
                                                     ^ vlTOPp->top__DOT__count)));
}

void VmkTestbench::_eval_initial(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_eval_initial\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VmkTestbench::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::final\n"); );
    // Variables
    VmkTestbench__Syms* __restrict vlSymsp = this->__VlSymsp;
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VmkTestbench::_eval_settle(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_eval_settle\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

void VmkTestbench::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    RST_N = VL_RAND_RESET_I(1);
    top__DOT__count = VL_RAND_RESET_I(32);
    top__DOT__count__024D_IN = VL_RAND_RESET_I(32);
    top__DOT__testmodule_exp_op1 = VL_RAND_RESET_I(4);
    top__DOT__testmodule_exp_op2 = VL_RAND_RESET_I(4);
    top__DOT__testmodule_final_exp = VL_RAND_RESET_I(4);
    top__DOT__testmodule_final_man = VL_RAND_RESET_I(6);
    top__DOT__testmodule_final_output = VL_RAND_RESET_I(8);
    top__DOT__testmodule_final_sign = VL_RAND_RESET_I(1);
    top__DOT__testmodule_man_op1 = VL_RAND_RESET_I(3);
    top__DOT__testmodule_man_op2 = VL_RAND_RESET_I(3);
    top__DOT__testmodule_output_man = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(80, top__DOT__testmodule_rg_operands);
    top__DOT__testmodule_sign_op1 = VL_RAND_RESET_I(1);
    top__DOT__testmodule_sign_op2 = VL_RAND_RESET_I(1);
    top__DOT__testmodule_stage = VL_RAND_RESET_I(3);
    top__DOT__testmodule_stage__024D_IN = VL_RAND_RESET_I(3);
    top__DOT__testmodule_stage__024EN = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
