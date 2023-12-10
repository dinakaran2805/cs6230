// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("/home/dina/cs6230/cfloat8_1_4_3/testbench/cfloat8_mul.v", 34, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("/home/dina/cs6230/cfloat8_1_4_3/testbench/cfloat8_mul.v", 34, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cfloat8_mul__DOT__CLK = vlTOPp->CLK;
    vlTOPp->cfloat8_mul__DOT__RST_N = vlTOPp->RST_N;
    vlTOPp->cfloat8_mul__DOT__send_data_input = vlTOPp->send_data_input;
    vlTOPp->cfloat8_mul__DOT__EN_send = vlTOPp->EN_send;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_send = vlTOPp->EN_send;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__output_man__024EN) {
            vlTOPp->cfloat8_mul__DOT__output_man = vlTOPp->cfloat8_mul__DOT__output_man__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__output_man = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__normalized_count__024EN) {
            vlTOPp->cfloat8_mul__DOT__normalized_count 
                = vlTOPp->cfloat8_mul__DOT__normalized_count__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__normalized_count = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__final_bias__024EN) {
            vlTOPp->cfloat8_mul__DOT__final_bias = vlTOPp->cfloat8_mul__DOT__final_bias__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__final_bias = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__sign_op1__024EN) {
            vlTOPp->cfloat8_mul__DOT__sign_op1 = vlTOPp->cfloat8_mul__DOT__sign_op1__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__sign_op1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__sign_op2__024EN) {
            vlTOPp->cfloat8_mul__DOT__sign_op2 = vlTOPp->cfloat8_mul__DOT__sign_op2__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__sign_op2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__final_sign__024EN) {
            vlTOPp->cfloat8_mul__DOT__final_sign = vlTOPp->cfloat8_mul__DOT__final_sign__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__final_sign = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__rounded_man__024EN) {
            vlTOPp->cfloat8_mul__DOT__rounded_man = vlTOPp->cfloat8_mul__DOT__rounded_man__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__rounded_man = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__final_output__024EN) {
            vlTOPp->cfloat8_mul__DOT__final_output 
                = vlTOPp->cfloat8_mul__DOT__final_output__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__final_output = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__normalized_man__024EN) {
            vlTOPp->cfloat8_mul__DOT__normalized_man 
                = vlTOPp->cfloat8_mul__DOT__normalized_man__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__normalized_man = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__man_op1__024EN) {
            vlTOPp->cfloat8_mul__DOT__man_op1 = vlTOPp->cfloat8_mul__DOT__man_op1__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__man_op1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__man_op2__024EN) {
            vlTOPp->cfloat8_mul__DOT__man_op2 = vlTOPp->cfloat8_mul__DOT__man_op2__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__man_op2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__rg_operands__024EN) {
            vlTOPp->cfloat8_mul__DOT__rg_operands = vlTOPp->cfloat8_mul__DOT__rg_operands__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__rg_operands = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__exp_op2__024EN) {
            vlTOPp->cfloat8_mul__DOT__exp_op2 = vlTOPp->cfloat8_mul__DOT__exp_op2__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__exp_op2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__exp_op1__024EN) {
            vlTOPp->cfloat8_mul__DOT__exp_op1 = vlTOPp->cfloat8_mul__DOT__exp_op1__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__exp_op1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__final_exp__024EN) {
            vlTOPp->cfloat8_mul__DOT__final_exp = vlTOPp->cfloat8_mul__DOT__final_exp__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__final_exp = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__stage__024EN) {
            vlTOPp->cfloat8_mul__DOT__stage = vlTOPp->cfloat8_mul__DOT__stage__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__stage = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->cfloat8_mul__DOT__final_man__024EN) {
            vlTOPp->cfloat8_mul__DOT__final_man = vlTOPp->cfloat8_mul__DOT__final_man__024D_IN;
        }
    } else {
        vlTOPp->cfloat8_mul__DOT__final_man = 0U;
    }
    vlTOPp->cfloat8_mul__DOT__final_sign__024D_IN = 
        ((IData)(vlTOPp->cfloat8_mul__DOT__sign_op1) 
         ^ (IData)(vlTOPp->cfloat8_mul__DOT__sign_op2));
    vlTOPp->cfloat8_mul__DOT__receive = vlTOPp->cfloat8_mul__DOT__final_output;
    vlTOPp->cfloat8_mul__DOT__rounded_value___05Fh3724 
        = (7U & ((IData)(1U) + ((IData)(vlTOPp->cfloat8_mul__DOT__normalized_man) 
                                >> 3U)));
    vlTOPp->cfloat8_mul__DOT__exp_op1__024D_IN = (0xfU 
                                                  & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                                     >> 0x10U));
    vlTOPp->cfloat8_mul__DOT__exp_op2__024D_IN = (0xfU 
                                                  & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                                     >> 8U));
    vlTOPp->cfloat8_mul__DOT__final_bias__024D_IN = 
        (0xfU & vlTOPp->cfloat8_mul__DOT__rg_operands);
    vlTOPp->cfloat8_mul__DOT__man_op1__024D_IN = (7U 
                                                  & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                                     >> 0xdU));
    vlTOPp->cfloat8_mul__DOT__man_op2__024D_IN = (7U 
                                                  & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                                     >> 5U));
    vlTOPp->cfloat8_mul__DOT__sign_op1__024D_IN = (1U 
                                                   & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                                      >> 0x14U));
    vlTOPp->cfloat8_mul__DOT__sign_op2__024D_IN = (1U 
                                                   & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                                      >> 0xcU));
    vlTOPp->cfloat8_mul__DOT__hidden_bit_op2___05Fh1359 
        = (0U != (IData)(vlTOPp->cfloat8_mul__DOT__exp_op2));
    vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2 
        = (0xfU & ((IData)(vlTOPp->cfloat8_mul__DOT__exp_op1) 
                   + (IData)(vlTOPp->cfloat8_mul__DOT__exp_op2)));
    vlTOPp->cfloat8_mul__DOT__hidden_bit_op1___05Fh1358 
        = (0U != (IData)(vlTOPp->cfloat8_mul__DOT__exp_op1));
    vlTOPp->cfloat8_mul__DOT__final_output__024D_IN 
        = (((IData)(vlTOPp->cfloat8_mul__DOT__final_sign) 
            << 7U) | (((IData)(vlTOPp->cfloat8_mul__DOT__final_exp) 
                       << 3U) | (IData)(vlTOPp->cfloat8_mul__DOT__rounded_man)));
    vlTOPp->cfloat8_mul__DOT__x___05Fh1971 = (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlTOPp->cfloat8_mul__DOT__final_exp)));
    vlTOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2 
        = (7U & ((IData)(1U) + (IData)(vlTOPp->cfloat8_mul__DOT__stage)));
    vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage5 = 
        (5U == (IData)(vlTOPp->cfloat8_mul__DOT__stage));
    vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1 = 
        (1U == (IData)(vlTOPp->cfloat8_mul__DOT__stage));
    vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3 = 
        (3U == (IData)(vlTOPp->cfloat8_mul__DOT__stage));
    vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2 = 
        (2U == (IData)(vlTOPp->cfloat8_mul__DOT__stage));
    vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage4 = 
        (4U == (IData)(vlTOPp->cfloat8_mul__DOT__stage));
    vlTOPp->cfloat8_mul__DOT__x___05Fh1900 = (0x1fU 
                                              & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                                 >> 1U));
    vlTOPp->cfloat8_mul__DOT__x___05Fh3260 = (0x3fU 
                                              & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                                 << (IData)(vlTOPp->cfloat8_mul__DOT__final_exp)));
    vlTOPp->cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55 
        = (7U & ((IData)(1U) + ((0x20U & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                                 ? 0U : ((0x10U & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                                          ? 1U : ((8U 
                                                   & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                                                   ? 2U
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                                                    ? 3U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                                                     ? 4U
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                                                      ? 5U
                                                      : 6U))))))));
    vlTOPp->receive = vlTOPp->cfloat8_mul__DOT__receive;
    vlTOPp->cfloat8_mul__DOT__rounded_man__024D_IN 
        = (7U & ((4U & (IData)(vlTOPp->cfloat8_mul__DOT__normalized_man))
                  ? (IData)(vlTOPp->cfloat8_mul__DOT__rounded_value___05Fh3724)
                  : ((IData)(vlTOPp->cfloat8_mul__DOT__normalized_man) 
                     >> 3U)));
    vlTOPp->cfloat8_mul__DOT__inter_mantissa2___05Fh1427 
        = (((IData)(vlTOPp->cfloat8_mul__DOT__hidden_bit_op2___05Fh1359) 
            << 3U) | (IData)(vlTOPp->cfloat8_mul__DOT__man_op2));
    vlTOPp->cfloat8_mul__DOT__inter_mantissa1___05Fh1426 
        = (((IData)(vlTOPp->cfloat8_mul__DOT__hidden_bit_op1___05Fh1358) 
            << 3U) | (IData)(vlTOPp->cfloat8_mul__DOT__man_op1));
    vlTOPp->cfloat8_mul__DOT__final_output__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage5;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5 = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage5;
    vlTOPp->cfloat8_mul__DOT__final_sign__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1;
    vlTOPp->cfloat8_mul__DOT__sign_op1__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1;
    vlTOPp->cfloat8_mul__DOT__sign_op2__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1 = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage1;
    vlTOPp->cfloat8_mul__DOT__final_man__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3;
    vlTOPp->cfloat8_mul__DOT__man_op1__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3;
    vlTOPp->cfloat8_mul__DOT__man_op2__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3 = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage3;
    vlTOPp->cfloat8_mul__DOT__exp_op1__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2;
    vlTOPp->cfloat8_mul__DOT__exp_op2__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2;
    vlTOPp->cfloat8_mul__DOT__final_bias__024EN = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2 = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage2;
    vlTOPp->cfloat8_mul__DOT__normalized_man__024EN 
        = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage4;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4 = vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_stage4;
    vlTOPp->cfloat8_mul__DOT__count_temp___05Fh2059 
        = vlTOPp->cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55;
    vlTOPp->cfloat8_mul__DOT__NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL___05FETC___05F_d30 
        = (0xffU & ((IData)(vlTOPp->cfloat8_mul__DOT__inter_mantissa1___05Fh1426) 
                    * (IData)(vlTOPp->cfloat8_mul__DOT__inter_mantissa2___05Fh1427)));
    vlTOPp->cfloat8_mul__DOT__rounded_man__024EN = 
        ((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5) 
         & (vlTOPp->cfloat8_mul__DOT__rg_operands >> 4U));
    vlTOPp->cfloat8_mul__DOT__final_exp__024EN = (((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
                                                   & (1U 
                                                      != 
                                                      (3U 
                                                       & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                                          >> 6U)))) 
                                                  | (IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2));
    vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FSEL_1 
        = ((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
           & (1U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                           >> 6U))));
    vlTOPp->cfloat8_mul__DOT__x___05Fh3146 = (0x3fU 
                                              & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                                 << (IData)(vlTOPp->cfloat8_mul__DOT__count_temp___05Fh2059)));
    vlTOPp->cfloat8_mul__DOT__x___05Fh3220 = (0xfU 
                                              & ((IData)(vlTOPp->cfloat8_mul__DOT__final_exp) 
                                                 - (IData)(vlTOPp->cfloat8_mul__DOT__count_temp___05Fh2059)));
    vlTOPp->cfloat8_mul__DOT___0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_ETC___05F_d57 
        = ((IData)(vlTOPp->cfloat8_mul__DOT__count_temp___05Fh2059) 
           < (IData)(vlTOPp->cfloat8_mul__DOT__final_exp));
    vlTOPp->cfloat8_mul__DOT__final_man__024D_IN = 
        (0xfU & (IData)(vlTOPp->cfloat8_mul__DOT__NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL___05FETC___05F_d30));
    vlTOPp->cfloat8_mul__DOT__IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___05F_d60 
        = ((IData)(vlTOPp->cfloat8_mul__DOT___0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_ETC___05F_d57)
            ? (IData)(vlTOPp->cfloat8_mul__DOT__x___05Fh3146)
            : (IData)(vlTOPp->cfloat8_mul__DOT__x___05Fh3260));
    vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_1 
        = (((2U == (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                          >> 6U))) | (3U == (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                                   >> 6U))))
            ? (IData)(vlTOPp->cfloat8_mul__DOT__x___05Fh1971)
            : ((IData)(vlTOPp->cfloat8_mul__DOT___0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_ETC___05F_d57)
                ? (IData)(vlTOPp->cfloat8_mul__DOT__x___05Fh3220)
                : 0U));
    vlTOPp->cfloat8_mul__DOT__normalized_man__024D_IN 
        = (0x3fU & ((0x80U & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                     ? (IData)(vlTOPp->cfloat8_mul__DOT__x___05Fh1900)
                     : ((0x40U & (IData)(vlTOPp->cfloat8_mul__DOT__final_man))
                         ? (IData)(vlTOPp->cfloat8_mul__DOT__final_man)
                         : (IData)(vlTOPp->cfloat8_mul__DOT__IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___05F_d60))));
    vlTOPp->cfloat8_mul__DOT__final_exp__024D_IN = 
        ((IData)(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FSEL_1)
          ? (IData)(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_1)
          : (IData)(vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("welcome to the project\n***************************************************************************\n");
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1)) {
            VL_WRITEF("DEBUGG ::: sign_op1 :%1# sign_op2 :%1#\n",
                      1,vlTOPp->cfloat8_mul__DOT__sign_op1,
                      1,(IData)(vlTOPp->cfloat8_mul__DOT__sign_op2));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1)) {
            VL_WRITEF("val of final sign : %1#\n",1,
                      vlTOPp->cfloat8_mul__DOT__final_sign);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1)) {
            VL_WRITEF("val of stage: %1#\n",3,vlTOPp->cfloat8_mul__DOT__stage);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1)) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)) {
            VL_WRITEF("stage2\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)) {
            VL_WRITEF("DEBUGG of prev stage ::: sign_op1 :%1# sign_op2 :%1# final_sign :%1#\n",
                      1,vlTOPp->cfloat8_mul__DOT__sign_op1,
                      1,(IData)(vlTOPp->cfloat8_mul__DOT__sign_op2),
                      1,vlTOPp->cfloat8_mul__DOT__final_sign);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)) {
            VL_WRITEF("DEBUGG ::: exp_op1 :%2# exp_op2 :%2#\n",
                      4,vlTOPp->cfloat8_mul__DOT__exp_op1,
                      4,(IData)(vlTOPp->cfloat8_mul__DOT__exp_op2));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)) {
            VL_WRITEF("val of final exp : %2#val of bias : %2#%2#\n",
                      4,vlTOPp->cfloat8_mul__DOT__final_exp,
                      4,(0xfU & vlTOPp->cfloat8_mul__DOT__rg_operands),
                      4,(0xfU & vlTOPp->cfloat8_mul__DOT__rg_operands));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)) {
            VL_WRITEF("DINA DEBUGGG : val of final_exp : %b\n",
                      4,vlTOPp->cfloat8_mul__DOT__final_exp);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3)) {
            VL_WRITEF("stage3\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3)) {
            VL_WRITEF("DEBUGG of prev stage ::: exp_op1 :%2# exp_op2 :%2# final_exp%2#\n",
                      4,vlTOPp->cfloat8_mul__DOT__exp_op1,
                      4,(IData)(vlTOPp->cfloat8_mul__DOT__exp_op2),
                      4,vlTOPp->cfloat8_mul__DOT__final_exp);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3)) {
            VL_WRITEF("DEBUGG ::: man_op1 : %1# man_op2 : %1#\n",
                      3,vlTOPp->cfloat8_mul__DOT__man_op1,
                      3,(IData)(vlTOPp->cfloat8_mul__DOT__man_op2));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3)) {
            VL_WRITEF("final_man : %b\n",8,vlTOPp->cfloat8_mul__DOT__final_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3)) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4)) {
            VL_WRITEF("val of final man : %b \n",8,
                      vlTOPp->cfloat8_mul__DOT__final_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
                          & (1U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                          >> 6U)))) 
                         & ((2U == (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                          >> 6U))) 
                            | (3U == (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                            >> 6U))))))) {
            VL_WRITEF("the value of the hidden product is 10 or 11 . The exact value is : %b\n",
                      2,(3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                               >> 6U)));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY((((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
                          & (1U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                          >> 6U)))) 
                         & ((2U == (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                          >> 6U))) 
                            | (3U == (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                            >> 6U))))))) {
            VL_WRITEF("before shifting : %bafter shifting : %b \n",
                      6,(0x3fU & (IData)(vlTOPp->cfloat8_mul__DOT__final_man)),
                      6,(IData)(vlTOPp->cfloat8_mul__DOT__normalized_man));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(((((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
                           & (1U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                           >> 6U)))) 
                          & (2U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                          >> 6U)))) 
                         & (3U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                         >> 6U)))))) {
            VL_WRITEF("latest DEBUGG : count_temp  : %bfinal_exp : %b \n",
                      4,vlTOPp->cfloat8_mul__DOT__count_temp___05Fh2059,
                      4,(IData)(vlTOPp->cfloat8_mul__DOT__final_exp));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(((((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
                           & (1U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                           >> 6U)))) 
                          & (2U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                          >> 6U)))) 
                         & (3U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                         >> 6U)))))) {
            VL_WRITEF("DEBUGG MSB count zeros : %b final exp : %b\n",
                      3,vlTOPp->cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55,
                      4,(IData)(vlTOPp->cfloat8_mul__DOT__final_exp));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(((((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
                           & (1U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                           >> 6U)))) 
                          & (2U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                          >> 6U)))) 
                         & (3U != (3U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_man) 
                                         >> 6U)))))) {
            VL_WRITEF("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4)) {
            VL_WRITEF("value of normalized man : %b\n",
                      6,vlTOPp->cfloat8_mul__DOT__normalized_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4)) {
            VL_WRITEF("stage4\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4)) {
            VL_WRITEF("val of final output : %3#\n",
                      8,vlTOPp->cfloat8_mul__DOT__final_output);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4)) {
            VL_WRITEF("DEBUGG of prev stage ::: man_op1 : %1# man_op2 : %1#output man : %b\n",
                      3,vlTOPp->cfloat8_mul__DOT__man_op1,
                      3,(IData)(vlTOPp->cfloat8_mul__DOT__man_op2),
                      6,vlTOPp->cfloat8_mul__DOT__normalized_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4)) {
            VL_WRITEF("***************************************************************************\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5)) {
            VL_WRITEF("stage5\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5)) {
            VL_WRITEF("value of rounded man : %b\n",
                      3,vlTOPp->cfloat8_mul__DOT__rounded_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5)) {
            VL_WRITEF("INTER VALUES sign : %1# exp : %2# mantissa : %1#\n",
                      1,vlTOPp->cfloat8_mul__DOT__final_sign,
                      4,(IData)(vlTOPp->cfloat8_mul__DOT__final_exp),
                      3,vlTOPp->cfloat8_mul__DOT__rounded_man);
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage5)) {
            VL_WRITEF("displaying the output ::: sign%1# exp : %2# man : %1#\n",
                      1,(1U & ((IData)(vlTOPp->cfloat8_mul__DOT__final_output) 
                               >> 7U)),4,(0xfU & ((IData)(vlTOPp->cfloat8_mul__DOT__final_output) 
                                                  >> 3U)),
                      3,(7U & (IData)(vlTOPp->cfloat8_mul__DOT__final_output)));
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->EN_send)) {
            VL_WRITEF("Inside the method SEND\n");
        }
    }
    if (vlTOPp->RST_N) {
        if (VL_UNLIKELY(vlTOPp->EN_send)) {
            VL_WRITEF("val at operand1 is : %3# operand2 : %3# r mode : %1# exp_bias%2#\n",
                      8,(0xffU & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                  >> 0xdU)),8,(0xffU 
                                               & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                                                  >> 5U)),
                      1,(1U & (vlTOPp->cfloat8_mul__DOT__rg_operands 
                               >> 4U)),4,(0xfU & vlTOPp->cfloat8_mul__DOT__rg_operands));
        }
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cfloat8_mul__DOT__rg_operands__024EN = vlTOPp->EN_send;
    vlTOPp->cfloat8_mul__DOT__rg_operands__024D_IN 
        = vlTOPp->send_data_input;
    vlTOPp->cfloat8_mul__DOT__stage__024EN = (((((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4) 
                                                 | (IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3)) 
                                                | (IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)) 
                                               | (IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1)) 
                                              | (IData)(vlTOPp->EN_send));
    vlTOPp->cfloat8_mul__DOT__stage__024D_IN = ((IData)(vlTOPp->EN_send)
                                                 ? 1U
                                                 : 
                                                ((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage4)
                                                  ? (IData)(vlTOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2)
                                                  : 
                                                 ((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage3)
                                                   ? (IData)(vlTOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2)
                                                   : 
                                                  ((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage2)
                                                    ? (IData)(vlTOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2)
                                                    : 
                                                   ((IData)(vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_stage1)
                                                     ? (IData)(vlTOPp->cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2)
                                                     : 2U)))));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RST_N & 0xfeU))) {
        Verilated::overWidthError("RST_N");}
    if (VL_UNLIKELY((send_data_input & 0xffe00000U))) {
        Verilated::overWidthError("send_data_input");}
    if (VL_UNLIKELY((EN_send & 0xfeU))) {
        Verilated::overWidthError("EN_send");}
}
#endif  // VL_DEBUG
