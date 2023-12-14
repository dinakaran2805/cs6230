TOP_MODULE:=mk_cfloat8_div
TOP_FILE:=cfloat8_1_4_3_div.bsv

CXXFLAGS = -I include -std=c++11 -O3 -I/home/shakti/anaconda3/envs/spy/include/python3.6m -I/home/shakti/anaconda3/envs/spy/include/python3.6m  -Wno-unused-result -Wsign-compare -march=nocona -mtune=haswell -ftree-vectorize -fPIC -fstack-protector-strong -O3 -pipe  -fdebug-prefix-map==/usr/local/src/conda/- -fdebug-prefix-map==/usr/local/src/conda-prefix -fuse-linker-plugin -ffat-lto-objects -flto-partition=none -flto -DNDEBUG -fwrapv -O3 -Wall
VERILATOR_FLAGS = --stats -O3 -CFLAGS -O3 -LDFLAGS "-static" --x-assign fast --x-initial fast \
--noassert sim_main.cpp --bbox-sys -Wno-STMTDLY -Wno-UNOPTFLAT -Wno-WIDTH \
-Wno-lint -Wno-COMBDLY -Wno-INITIALDLY --autoflush $(coverage) $(trace) --threads $(THREADS) \
-DBSV_RESET_FIFO_HEAD -DBSV_RESET_FIFO_ARRAY
BSVINCDIR:=.:%/Libraries:.
BSVCOMPILEOPTS:= -check-assert  -keep-fires -opt-undetermined-vals -remove-false-rules -remove-empty-rules -remove-starved-rules -show-range-conflict
BSVLINKOPTS:=-parallel-sim-link 8 -keep-fires
VERILOGDIR:=./verilog/
BSVBUILDDIR:=./bsv_build/
BSVOUTDIR:=./bin
BSC_DIR := $(shell which bsc)
BSC_VDIR:=$(subst /bin/bsc,/,${BSC_DIR})bin/../lib/Verilog
BSC_VIVADODIR:=$(subst /bin/bsc,/,${BSC_DIR})bin/../lib/Verilog.Vivado


TOPLEVEL_LANG=verilog
SIM=verilator
PWD=$(shell pwd)
#TESTCASE=exe_code
DUMP_EN ?= 0
CVG_EN ?= 0

ifeq ($(TOPLEVEL_LANG),verilog)
  VERILOG_SOURCES =$(PWD)/verilog/*.v
else
  $(error "A valid value (verilog) was not provided for TOPLEVEL_LANG=$(TOPLEVEL_LANG)")
endif

EXTRA_ARGS = -O3 --x-assign fast --x-initial fast --bbox-sys -Wno-STMTDLY -Wno-UNOPTFLAT -Wno-WIDTH -Wno-lint -Wno-COMBDLY -Wno-INITIALDLY --autoflush --threads -DBSV_RESET_FIFO_HEAD -DBSV_RESET_FIFO_ARRAY -DBSV_NO_INITIAL_BLOCKS
ifeq ($(DUMP_EN),1)
    EXTRA_ARGS += --trace-fst --trace-structs
endif

ifeq ($(CVG_EN),1)
    EXTRA_ARGS += --coverage
endif

TOPLEVEL := $(TOP_MODULE)
MODULE   := test_div

include $(shell cocotb-config --makefiles)/Makefile.sim

.PHONY: cocotb_sim
cocotb_sim: 
	@make sim

.PHONY: compile
compile:
	@make sim_build/Vtop

generate_verilog:
	@echo Compiling $(TOP_MODULE) in verilog ...
	@mkdir -p $(VERILOGDIR);
	@mkdir -p $(BSVBUILDDIR);
	@echo "old_define_macros = $(define_macros)" > old_vars
	bsc -u -verilog -elab -remove-dollar -vdir $(VERILOGDIR) -bdir $(BSVBUILDDIR)\
	$(define_macros) -D verilog=True $(BSVCOMPILEOPTS) $(VERILOG_FILTER) \
	-p $(BSVINCDIR) -g $(TOP_MODULE) $(TOP_FILE)  || (echo "BSC COMPILE ERROR"; exit 1)
