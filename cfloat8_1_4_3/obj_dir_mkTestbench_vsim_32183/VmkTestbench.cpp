// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VmkTestbench.h for the primary calling header

#include "VmkTestbench.h"
#include "VmkTestbench__Syms.h"

//==========

void VmkTestbench::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VmkTestbench::eval\n"); );
    VmkTestbench__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog_dir/mkTestbench.v", 29, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VmkTestbench::_eval_initial_loop(VmkTestbench__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog_dir/mkTestbench.v", 29, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VmkTestbench::_sequent__TOP__1(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_sequent__TOP__1\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->RST_N) {
        if ((4U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_final_output 
                = (((IData)(vlTOPp->top__DOT__testmodule_final_sign) 
                    << 7U) | (((IData)(vlTOPp->top__DOT__testmodule_final_exp) 
                               << 3U) | (IData)(vlTOPp->top__DOT__testmodule_output_man)));
        }
    } else {
        vlTOPp->top__DOT__testmodule_final_output = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((1U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_final_sign 
                = ((IData)(vlTOPp->top__DOT__testmodule_sign_op1) 
                   ^ (IData)(vlTOPp->top__DOT__testmodule_sign_op2));
        }
    } else {
        vlTOPp->top__DOT__testmodule_final_sign = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((2U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_final_exp 
                = (0xfU & ((IData)(vlTOPp->top__DOT__testmodule_exp_op1) 
                           + (IData)(vlTOPp->top__DOT__testmodule_exp_op2)));
        }
    } else {
        vlTOPp->top__DOT__testmodule_final_exp = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((3U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_output_man 
                = (7U & ((4U & (IData)(vlTOPp->top__DOT__testmodule_final_man))
                          ? ((IData)(1U) + ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                                            >> 3U))
                          : ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                             >> 3U)));
        }
    } else {
        vlTOPp->top__DOT__testmodule_output_man = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((1U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_sign_op1 = 
                (1U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                       >> 0xfU));
        }
    } else {
        vlTOPp->top__DOT__testmodule_sign_op1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((1U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_sign_op2 = 
                (1U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                       >> 7U));
        }
    } else {
        vlTOPp->top__DOT__testmodule_sign_op2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((2U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_exp_op1 = 
                (0xfU & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                         >> 0xbU));
        }
    } else {
        vlTOPp->top__DOT__testmodule_exp_op1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((2U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_exp_op2 = 
                (0xfU & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                         >> 3U));
        }
    } else {
        vlTOPp->top__DOT__testmodule_exp_op2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((3U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_final_man 
                = (0x3fU & ((IData)(vlTOPp->top__DOT__testmodule_man_op1) 
                            * (IData)(vlTOPp->top__DOT__testmodule_man_op2)));
        }
    } else {
        vlTOPp->top__DOT__testmodule_final_man = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((3U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_man_op1 = 
                (7U & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                       >> 8U));
        }
    } else {
        vlTOPp->top__DOT__testmodule_man_op1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((3U == (IData)(vlTOPp->top__DOT__testmodule_stage))) {
            vlTOPp->top__DOT__testmodule_man_op2 = 
                (7U & vlTOPp->top__DOT__testmodule_rg_operands[2U]);
        }
    } else {
        vlTOPp->top__DOT__testmodule_man_op2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->top__DOT__testmodule_stage__024EN) {
            vlTOPp->top__DOT__testmodule_stage = vlTOPp->top__DOT__testmodule_stage__024D_IN;
        }
    } else {
        vlTOPp->top__DOT__testmodule_stage = 0U;
    }
    if (vlTOPp->RST_N) {
        if ((0x80000002U > (0x80000000U ^ vlTOPp->top__DOT__count))) {
            vlTOPp->top__DOT__testmodule_rg_operands[0U] = 4U;
            vlTOPp->top__DOT__testmodule_rg_operands[1U] = 1U;
            vlTOPp->top__DOT__testmodule_rg_operands[2U] = 0x13c4U;
        }
    } else {
        vlTOPp->top__DOT__testmodule_rg_operands[0U] = 0U;
        vlTOPp->top__DOT__testmodule_rg_operands[1U] = 0U;
        vlTOPp->top__DOT__testmodule_rg_operands[2U] = 0U;
    }
    vlTOPp->top__DOT__count = ((IData)(vlTOPp->RST_N)
                                ? vlTOPp->top__DOT__count__024D_IN
                                : 0U);
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

VL_INLINE_OPT void VmkTestbench::_sequent__TOP__2(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_sequent__TOP__2\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("welcome to the project\n***************************************************************************\n");
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((1U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("DEBUGG ::: sign_op1 :%1# sign_op2 :%1#\n",
                      1,vlTOPp->top__DOT__testmodule_sign_op1,
                      1,(IData)(vlTOPp->top__DOT__testmodule_sign_op2));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((1U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("val of final sign : %1#\n",1,
                      vlTOPp->top__DOT__testmodule_final_sign);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((1U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("val of stage: %1#\n",3,vlTOPp->top__DOT__testmodule_stage);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((1U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((2U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("stage2\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((2U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("DEBUGG of prev stage ::: sign_op1 :%1# sign_op2 :%1# final_sign :%1#\n",
                      1,vlTOPp->top__DOT__testmodule_sign_op1,
                      1,(IData)(vlTOPp->top__DOT__testmodule_sign_op2),
                      1,vlTOPp->top__DOT__testmodule_final_sign);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((2U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("DEBUGG ::: exp_op1 :%2# exp_op2 :%2#\n",
                      4,vlTOPp->top__DOT__testmodule_exp_op1,
                      4,(IData)(vlTOPp->top__DOT__testmodule_exp_op2));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((2U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("val of final exp : %2#val of bias : %10#%10#\n",
                      4,vlTOPp->top__DOT__testmodule_final_exp,
                      32,vlTOPp->top__DOT__testmodule_rg_operands[0U],
                      32,vlTOPp->top__DOT__testmodule_rg_operands[0U]);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((2U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((3U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("stage3\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((3U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("DEBUGG of prev stage ::: exp_op1 :%2# exp_op2 :%2# final_exp%2#\n",
                      4,vlTOPp->top__DOT__testmodule_exp_op1,
                      4,(IData)(vlTOPp->top__DOT__testmodule_exp_op2),
                      4,vlTOPp->top__DOT__testmodule_final_exp);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((3U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("DEBUGG ::: man_op1 : %1# man_op2 : %1#\n",
                      3,vlTOPp->top__DOT__testmodule_man_op1,
                      3,(IData)(vlTOPp->top__DOT__testmodule_man_op2));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((3U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("final_man : %b\n",6,vlTOPp->top__DOT__testmodule_final_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(((3U == (IData)(vlTOPp->top__DOT__testmodule_stage)) 
                         & ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                            >> 2U)))) {
            VL_WRITEF("val aft rounding : %b\n",3,vlTOPp->top__DOT__testmodule_output_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(((3U == (IData)(vlTOPp->top__DOT__testmodule_stage)) 
                         & (~ ((IData)(vlTOPp->top__DOT__testmodule_final_man) 
                               >> 2U))))) {
            VL_WRITEF("val aft rounding : %b\n",3,vlTOPp->top__DOT__testmodule_output_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((3U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((4U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("stage4\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((4U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("DEBUGG of prev stage ::: man_op1 : %1# man_op2 : %1#output man : %1#\n",
                      3,vlTOPp->top__DOT__testmodule_man_op1,
                      3,(IData)(vlTOPp->top__DOT__testmodule_man_op2),
                      3,vlTOPp->top__DOT__testmodule_output_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((4U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("val of final output : %3#\n",
                      8,vlTOPp->top__DOT__testmodule_final_output);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((4U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((5U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("stage5\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((5U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("INTER VALUES sign : %1# exp : %2# mantissa : %1#\n",
                      1,vlTOPp->top__DOT__testmodule_final_sign,
                      4,(IData)(vlTOPp->top__DOT__testmodule_final_exp),
                      3,vlTOPp->top__DOT__testmodule_output_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((5U == (IData)(vlTOPp->top__DOT__testmodule_stage)))) {
            VL_WRITEF("displaying the output ::: sign%1# exp : %2# man : %1#\n",
                      1,(1U & ((IData)(vlTOPp->top__DOT__testmodule_final_output) 
                               >> 7U)),4,(0xfU & ((IData)(vlTOPp->top__DOT__testmodule_final_output) 
                                                  >> 3U)),
                      3,(7U & (IData)(vlTOPp->top__DOT__testmodule_final_output)));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((0x80000002U > (0x80000000U 
                                        ^ vlTOPp->top__DOT__count)))) {
            VL_WRITEF("Inside the method SEND\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((0x80000002U > (0x80000000U 
                                        ^ vlTOPp->top__DOT__count)))) {
            VL_WRITEF("val at operand1 is : %3# operand2 : %3# r mode : %10# exp_bias%10#\n",
                      8,(0xffU & (vlTOPp->top__DOT__testmodule_rg_operands[2U] 
                                  >> 8U)),8,(0xffU 
                                             & vlTOPp->top__DOT__testmodule_rg_operands[2U]),
                      32,vlTOPp->top__DOT__testmodule_rg_operands[1U],
                      32,vlTOPp->top__DOT__testmodule_rg_operands[0U]);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((0x80000006U < (0x80000000U 
                                        ^ vlTOPp->top__DOT__count)))) {
            VL_FINISH_MT("verilog_dir/mkTestbench.v", 458, "");
        }
    }
    if (VL_UNLIKELY(vlTOPp->RST_N)) {
        VL_WRITEF("hi dina\n");
    }
}

void VmkTestbench::_eval(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_eval\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

VL_INLINE_OPT QData VmkTestbench::_change_request(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_change_request\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VmkTestbench::_change_request_1(VmkTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_change_request_1\n"); );
    VmkTestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VmkTestbench::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VmkTestbench::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RST_N & 0xfeU))) {
        Verilated::overWidthError("RST_N");}
}
#endif  // VL_DEBUG
