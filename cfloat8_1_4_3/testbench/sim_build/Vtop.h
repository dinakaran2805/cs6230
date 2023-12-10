// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(RST_N,0,0);
    VL_IN8(EN_send,0,0);
    VL_OUT8(RDY_send,0,0);
    VL_OUT8(receive,7,0);
    VL_OUT8(RDY_receive,0,0);
    VL_IN(send_data_input,20,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ cfloat8_mul__DOT__CLK;
        CData/*0:0*/ cfloat8_mul__DOT__RST_N;
        CData/*0:0*/ cfloat8_mul__DOT__EN_send;
        CData/*0:0*/ cfloat8_mul__DOT__RDY_send;
        CData/*7:0*/ cfloat8_mul__DOT__receive;
        CData/*0:0*/ cfloat8_mul__DOT__RDY_receive;
        CData/*3:0*/ cfloat8_mul__DOT__exp_op1;
        CData/*3:0*/ cfloat8_mul__DOT__exp_op1__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__exp_op1__024EN;
        CData/*3:0*/ cfloat8_mul__DOT__exp_op2;
        CData/*3:0*/ cfloat8_mul__DOT__exp_op2__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__exp_op2__024EN;
        CData/*3:0*/ cfloat8_mul__DOT__final_bias;
        CData/*3:0*/ cfloat8_mul__DOT__final_bias__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__final_bias__024EN;
        CData/*3:0*/ cfloat8_mul__DOT__final_exp;
        CData/*3:0*/ cfloat8_mul__DOT__final_exp__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__final_exp__024EN;
        CData/*7:0*/ cfloat8_mul__DOT__final_man;
        CData/*7:0*/ cfloat8_mul__DOT__final_man__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__final_man__024EN;
        CData/*7:0*/ cfloat8_mul__DOT__final_output;
        CData/*7:0*/ cfloat8_mul__DOT__final_output__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__final_output__024EN;
        CData/*0:0*/ cfloat8_mul__DOT__final_sign;
        CData/*0:0*/ cfloat8_mul__DOT__final_sign__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__final_sign__024EN;
        CData/*2:0*/ cfloat8_mul__DOT__man_op1;
        CData/*2:0*/ cfloat8_mul__DOT__man_op1__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__man_op1__024EN;
        CData/*2:0*/ cfloat8_mul__DOT__man_op2;
        CData/*2:0*/ cfloat8_mul__DOT__man_op2__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__man_op2__024EN;
        CData/*3:0*/ cfloat8_mul__DOT__normalized_count;
        CData/*3:0*/ cfloat8_mul__DOT__normalized_count__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__normalized_count__024EN;
        CData/*5:0*/ cfloat8_mul__DOT__normalized_man;
        CData/*5:0*/ cfloat8_mul__DOT__normalized_man__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__normalized_man__024EN;
        CData/*2:0*/ cfloat8_mul__DOT__output_man;
        CData/*2:0*/ cfloat8_mul__DOT__output_man__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__output_man__024EN;
        CData/*0:0*/ cfloat8_mul__DOT__rg_operands__024EN;
        CData/*2:0*/ cfloat8_mul__DOT__rounded_man;
        CData/*2:0*/ cfloat8_mul__DOT__rounded_man__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__rounded_man__024EN;
        CData/*0:0*/ cfloat8_mul__DOT__sign_op1;
        CData/*0:0*/ cfloat8_mul__DOT__sign_op1__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__sign_op1__024EN;
        CData/*0:0*/ cfloat8_mul__DOT__sign_op2;
        CData/*0:0*/ cfloat8_mul__DOT__sign_op2__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__sign_op2__024EN;
        CData/*2:0*/ cfloat8_mul__DOT__stage;
        CData/*2:0*/ cfloat8_mul__DOT__stage__024D_IN;
        CData/*0:0*/ cfloat8_mul__DOT__stage__024EN;
        CData/*0:0*/ cfloat8_mul__DOT__CAN_FIRE_RL_stage1;
        CData/*0:0*/ cfloat8_mul__DOT__CAN_FIRE_RL_stage2;
        CData/*0:0*/ cfloat8_mul__DOT__CAN_FIRE_RL_stage3;
        CData/*0:0*/ cfloat8_mul__DOT__CAN_FIRE_RL_stage4;
        CData/*0:0*/ cfloat8_mul__DOT__CAN_FIRE_RL_stage5;
        CData/*0:0*/ cfloat8_mul__DOT__CAN_FIRE_RL_trial;
        CData/*0:0*/ cfloat8_mul__DOT__CAN_FIRE_send;
        CData/*0:0*/ cfloat8_mul__DOT__WILL_FIRE_RL_stage1;
        CData/*0:0*/ cfloat8_mul__DOT__WILL_FIRE_RL_stage2;
    };
    struct {
        CData/*0:0*/ cfloat8_mul__DOT__WILL_FIRE_RL_stage3;
        CData/*0:0*/ cfloat8_mul__DOT__WILL_FIRE_RL_stage4;
        CData/*0:0*/ cfloat8_mul__DOT__WILL_FIRE_RL_stage5;
        CData/*0:0*/ cfloat8_mul__DOT__WILL_FIRE_RL_trial;
        CData/*0:0*/ cfloat8_mul__DOT__WILL_FIRE_send;
        CData/*3:0*/ cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_1;
        CData/*3:0*/ cfloat8_mul__DOT__MUX_final_exp__024write_1___05FVAL_2;
        CData/*2:0*/ cfloat8_mul__DOT__MUX_stage__024write_1___05FVAL_2;
        CData/*0:0*/ cfloat8_mul__DOT__MUX_final_exp__024write_1___05FSEL_1;
        CData/*7:0*/ cfloat8_mul__DOT__NOT_exp_op1_5_EQ_0_2_3_CONCAT_man_op1_4_5_MUL___05FETC___05F_d30;
        CData/*5:0*/ cfloat8_mul__DOT__IF_0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_ETC___05F_d60;
        CData/*5:0*/ cfloat8_mul__DOT__x___05Fh1900;
        CData/*5:0*/ cfloat8_mul__DOT__x___05Fh3146;
        CData/*5:0*/ cfloat8_mul__DOT__x___05Fh3260;
        CData/*3:0*/ cfloat8_mul__DOT__count_temp___05Fh2059;
        CData/*3:0*/ cfloat8_mul__DOT__inter_mantissa1___05Fh1426;
        CData/*3:0*/ cfloat8_mul__DOT__inter_mantissa2___05Fh1427;
        CData/*3:0*/ cfloat8_mul__DOT__x___05Fh1971;
        CData/*3:0*/ cfloat8_mul__DOT__x___05Fh3220;
        CData/*2:0*/ cfloat8_mul__DOT__IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_final_ma_ETC___05F_d55;
        CData/*2:0*/ cfloat8_mul__DOT__rounded_value___05Fh3724;
        CData/*0:0*/ cfloat8_mul__DOT___0_CONCAT_IF_final_man_3_BIT_5_3_THEN_0_ELSE_IF_ETC___05F_d57;
        CData/*0:0*/ cfloat8_mul__DOT__hidden_bit_op1___05Fh1358;
        CData/*0:0*/ cfloat8_mul__DOT__hidden_bit_op2___05Fh1359;
        IData/*20:0*/ cfloat8_mul__DOT__send_data_input;
        IData/*20:0*/ cfloat8_mul__DOT__rg_operands;
        IData/*20:0*/ cfloat8_mul__DOT__rg_operands__024D_IN;
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__CLK;
    CData/*0:0*/ __Vm_traceActivity[1];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__6(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
