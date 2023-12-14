SIM=verilator
TOPLEVEL_LANG ?= verilog

PWD=$(shell pwd)

#export PYTHONPATH := $(PWD)/../model:$(PYTHONPATH)

ifeq ($(TOPLEVEL_LANG),verilog)
  VERILOG_SOURCES =$(PWD)/cfloat8_mul.v
 

else
  $(error "A valid value (verilog) was not provided for TOPLEVEL_LANG=$(TOPLEVEL_LANG)")
endif

EXTRA_ARGS = --trace --trace-structs
TOPLEVEL := cfloat8_mul
MODULE   := cfloat8_mul_tb

include $(shell cocotb-config --makefiles)/Makefile.sim
