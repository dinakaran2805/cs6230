// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cfloat8_mul__DOT__CAN_FIRE_send = 1U;
    vlTOPp->cfloat8_mul__DOT__CAN_FIRE_RL_trial = 1U;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_RL_trial = 1U;
    vlTOPp->cfloat8_mul__DOT__RDY_send = 1U;
    vlTOPp->cfloat8_mul__DOT__RDY_receive = 1U;
    vlTOPp->cfloat8_mul__DOT__exp_op1 = 0xaU;
    vlTOPp->cfloat8_mul__DOT__exp_op2 = 0xaU;
    vlTOPp->cfloat8_mul__DOT__final_bias = 0xaU;
    vlTOPp->cfloat8_mul__DOT__final_exp = 0xaU;
    vlTOPp->cfloat8_mul__DOT__final_man = 0xaaU;
    vlTOPp->cfloat8_mul__DOT__final_output = 0xaaU;
    vlTOPp->cfloat8_mul__DOT__final_sign = 0U;
    vlTOPp->cfloat8_mul__DOT__man_op1 = 2U;
    vlTOPp->cfloat8_mul__DOT__man_op2 = 2U;
    vlTOPp->cfloat8_mul__DOT__normalized_count = 0xaU;
    vlTOPp->cfloat8_mul__DOT__normalized_man = 0x2aU;
    vlTOPp->cfloat8_mul__DOT__output_man = 2U;
    vlTOPp->cfloat8_mul__DOT__rg_operands = 0xaaaaaU;
    vlTOPp->cfloat8_mul__DOT__rounded_man = 2U;
    vlTOPp->cfloat8_mul__DOT__sign_op1 = 0U;
    vlTOPp->cfloat8_mul__DOT__sign_op2 = 0U;
    vlTOPp->cfloat8_mul__DOT__stage = 2U;
    vlTOPp->cfloat8_mul__DOT__normalized_count__024D_IN = 0U;
    vlTOPp->cfloat8_mul__DOT__normalized_count__024EN = 0U;
    vlTOPp->cfloat8_mul__DOT__output_man__024D_IN = 0U;
    vlTOPp->cfloat8_mul__DOT__output_man__024EN = 0U;
    vlTOPp->RDY_send = vlTOPp->cfloat8_mul__DOT__RDY_send;
    vlTOPp->RDY_receive = vlTOPp->cfloat8_mul__DOT__RDY_receive;
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cfloat8_mul__DOT__CLK = vlTOPp->CLK;
    vlTOPp->cfloat8_mul__DOT__RST_N = vlTOPp->RST_N;
    vlTOPp->cfloat8_mul__DOT__send_data_input = vlTOPp->send_data_input;
    vlTOPp->cfloat8_mul__DOT__EN_send = vlTOPp->EN_send;
    vlTOPp->cfloat8_mul__DOT__WILL_FIRE_send = vlTOPp->EN_send;
    vlTOPp->cfloat8_mul__DOT__rg_operands__024D_IN 
        = vlTOPp->send_data_input;
    vlTOPp->cfloat8_mul__DOT__rg_operands__024EN = vlTOPp->EN_send;
    vlTOPp->RDY_send = vlTOPp->cfloat8_mul__DOT__RDY_send;
    vlTOPp->RDY_receive = vlTOPp->cfloat8_mul__DOT__RDY_receive;
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
    vlTOPp->cfloat8_mul__DOT__hidden_bit_op1___05Fh1358 
        = (0U != (IData)(vlTOPp->cfloat8_mul__DOT__exp_op1));
    vlTOPp->cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2 
        = (0xfU & ((IData)(vlTOPp->cfloat8_mul__DOT__exp_op1) 
                   + (IData)(vlTOPp->cfloat8_mul__DOT__exp_op2)));
    vlTOPp->cfloat8_mul__DOT__hidden_bit_op2___05Fh1359 
        = (0U != (IData)(vlTOPp->cfloat8_mul__DOT__exp_op2));
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
    vlTOPp->cfloat8_mul__DOT__inter_mantissa1___05Fh1426 
        = (((IData)(vlTOPp->cfloat8_mul__DOT__hidden_bit_op1___05Fh1358) 
            << 3U) | (IData)(vlTOPp->cfloat8_mul__DOT__man_op1));
    vlTOPp->cfloat8_mul__DOT__inter_mantissa2___05Fh1427 
        = (((IData)(vlTOPp->cfloat8_mul__DOT__hidden_bit_op2___05Fh1359) 
            << 3U) | (IData)(vlTOPp->cfloat8_mul__DOT__man_op2));
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

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    RST_N = VL_RAND_RESET_I(1);
    send_data_input = VL_RAND_RESET_I(21);
    EN_send = VL_RAND_RESET_I(1);
    RDY_send = VL_RAND_RESET_I(1);
    receive = VL_RAND_RESET_I(8);
    RDY_receive = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CLK = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__RST_N = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__send_data_input = VL_RAND_RESET_I(21);
    cfloat8_mul__DOT__EN_send = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__RDY_send = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__receive = VL_RAND_RESET_I(8);
    cfloat8_mul__DOT__RDY_receive = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__exp_op1 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__exp_op1__024D_IN = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__exp_op1__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__exp_op2 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__exp_op2__024D_IN = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__exp_op2__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__final_bias = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__final_bias__024D_IN = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__final_bias__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__final_exp = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__final_exp__024D_IN = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__final_exp__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__final_man = VL_RAND_RESET_I(8);
    cfloat8_mul__DOT__final_man__024D_IN = VL_RAND_RESET_I(8);
    cfloat8_mul__DOT__final_man__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__final_output = VL_RAND_RESET_I(8);
    cfloat8_mul__DOT__final_output__024D_IN = VL_RAND_RESET_I(8);
    cfloat8_mul__DOT__final_output__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__final_sign = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__final_sign__024D_IN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__final_sign__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__man_op1 = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__man_op1__024D_IN = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__man_op1__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__man_op2 = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__man_op2__024D_IN = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__man_op2__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__normalized_count = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__normalized_count__024D_IN = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__normalized_count__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__normalized_man = VL_RAND_RESET_I(6);
    cfloat8_mul__DOT__normalized_man__024D_IN = VL_RAND_RESET_I(6);
    cfloat8_mul__DOT__normalized_man__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__output_man = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__output_man__024D_IN = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__output_man__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__rg_operands = VL_RAND_RESET_I(21);
    cfloat8_mul__DOT__rg_operands__024D_IN = VL_RAND_RESET_I(21);
    cfloat8_mul__DOT__rg_operands__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__rounded_man = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__rounded_man__024D_IN = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__rounded_man__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__sign_op1 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__sign_op1__024D_IN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__sign_op1__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__sign_op2 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__sign_op2__024D_IN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__sign_op2__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__stage = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__stage__024D_IN = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__stage__024EN = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CAN_FIRE_RL_stage1 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CAN_FIRE_RL_stage2 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CAN_FIRE_RL_stage3 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CAN_FIRE_RL_stage4 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CAN_FIRE_RL_stage5 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CAN_FIRE_RL_trial = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__CAN_FIRE_send = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__WILL_FIRE_RL_stage1 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__WILL_FIRE_RL_stage2 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__WILL_FIRE_RL_stage3 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__WILL_FIRE_RL_stage4 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__WILL_FIRE_RL_stage5 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__WILL_FIRE_RL_trial = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__WILL_FIRE_send = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_1 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2 = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__MUX_final_exp__024write_1___05FSEL_1 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL___05FETC___05F_d30 = VL_RAND_RESET_I(8);
    cfloat8_mul__DOT__IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___05F_d60 = VL_RAND_RESET_I(6);
    cfloat8_mul__DOT__x___05Fh1900 = VL_RAND_RESET_I(6);
    cfloat8_mul__DOT__x___05Fh3146 = VL_RAND_RESET_I(6);
    cfloat8_mul__DOT__x___05Fh3260 = VL_RAND_RESET_I(6);
    cfloat8_mul__DOT__count_temp___05Fh2059 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__inter_mantissa1___05Fh1426 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__inter_mantissa2___05Fh1427 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__x___05Fh1971 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__x___05Fh3220 = VL_RAND_RESET_I(4);
    cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55 = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT__rounded_value___05Fh3724 = VL_RAND_RESET_I(3);
    cfloat8_mul__DOT___0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_ETC___05F_d57 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__hidden_bit_op1___05Fh1358 = VL_RAND_RESET_I(1);
    cfloat8_mul__DOT__hidden_bit_op2___05Fh1359 = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
