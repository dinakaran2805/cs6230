// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMKTESTBENCH_H_
#define _VMKTESTBENCH_H_  // guard

#include "verilated_heavy.h"

//==========

class VmkTestbench__Syms;
class VmkTestbench_VerilatedVcd;


//----------

VL_MODULE(VmkTestbench) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(RST_N,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ top__DOT__testmodule_exp_op1;
    CData/*3:0*/ top__DOT__testmodule_exp_op2;
    CData/*3:0*/ top__DOT__testmodule_final_exp;
    CData/*5:0*/ top__DOT__testmodule_final_man;
    CData/*7:0*/ top__DOT__testmodule_final_output;
    CData/*0:0*/ top__DOT__testmodule_final_sign;
    CData/*2:0*/ top__DOT__testmodule_man_op1;
    CData/*2:0*/ top__DOT__testmodule_man_op2;
    CData/*2:0*/ top__DOT__testmodule_output_man;
    CData/*0:0*/ top__DOT__testmodule_sign_op1;
    CData/*0:0*/ top__DOT__testmodule_sign_op2;
    CData/*2:0*/ top__DOT__testmodule_stage;
    CData/*2:0*/ top__DOT__testmodule_stage__024D_IN;
    CData/*0:0*/ top__DOT__testmodule_stage__024EN;
    IData/*31:0*/ top__DOT__count;
    IData/*31:0*/ top__DOT__count__024D_IN;
    WData/*79:0*/ top__DOT__testmodule_rg_operands[3];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__CLK;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VmkTestbench__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VmkTestbench);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VmkTestbench(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VmkTestbench();
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
    static void _eval_initial_loop(VmkTestbench__Syms* __restrict vlSymsp);
    void __Vconfigure(VmkTestbench__Syms* symsp, bool first);
  private:
    static QData _change_request(VmkTestbench__Syms* __restrict vlSymsp);
    static QData _change_request_1(VmkTestbench__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VmkTestbench__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VmkTestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VmkTestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(VmkTestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VmkTestbench__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(VmkTestbench__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(VmkTestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
