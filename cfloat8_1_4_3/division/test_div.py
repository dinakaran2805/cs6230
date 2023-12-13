from div_ref_model import *
import cocotb
import logging as _log
from cocotb.decorators import coroutine
from cocotb.triggers import Timer, RisingEdge, FallingEdge
from cocotb.binary import BinaryValue
from cocotb.result import TestFailure
from cocotb.clock import Clock

#def generate_inputs():

class top_TB(object):

    def __init__(self, dut):
        self.clk     = getattr(dut, "CLK")
        self.rst     = getattr(dut, "RST_N")
        
        self.op1     = getattr(dut, "send_op1")
        self.op2     = getattr(dut, "send_op2")
        self.bias    = getattr(dut, "send_bias")
        self.inp_en  = getattr(dut, "EN_send")
        self.inp_rdy = getattr(dut, "RDY_send")
        self.result  = getattr(dut, "res")
        #self.res_rdy = getattr(dut, "RDY_res")
        self.status  = getattr(dut, "status")
        #self.sts_rdy = getattr(dut, "RDY_status")
        self.valid   = getattr(dut, "valid")

    async def start(self, dut):
        cocotb.start_soon(Clock(self.clk, 1, units='ns').start())
        self.rst.value = 0
        await FallingEdge(self.clk)
        self.rst.value = 1
        await RisingEdge(self.clk)

    async def input_driver(self, dut, op1, op2, bias):

        await RisingEdge(self.clk)
        while True:
            if self.inp_rdy.value == 1:
                break
            await RisingEdge(self.clk)

        self.inp_en.value = 1
        self.op1.value = int(op1,2)
        self.op2.value = int(op2,2)
        self.bias.value = bias

        await RisingEdge(self.clk)
        self.inp_en.value = 0

    async def output_monitor(self, dut):
        await RisingEdge(self.clk)
        while True:
            if self.valid.value :
                break
            await RisingEdge(self.clk)

        result = self.result.value
        status = self.status.value

        return result, status

    async def scoreboard(self, dut, dut_output, rm_output):
        print("DUT :", dut_output)
        print("RM  :", rm_output)
        assert dut_output == rm_output


    async def TB(self, dut, op1, op2, bias):
        await self.start(dut)
        
        rm_result, rm_status = div_rm(op1, op2, bias)
        rm_output = [rm_result, rm_status]

        await self.input_driver(dut, op1, op2, bias)
        dut_result, dut_status = await self.output_monitor(dut)
        dut_output = [str(dut_result), str(dut_status)]

        await self.scoreboard(dut, dut_output, rm_output) 


@cocotb.test()
async def test_dd_1(dut):
    tb = top_TB(dut)
    op1 = "00000100"
    op2 = "00000010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

@cocotb.test()
async def test_nn_1(dut):
    tb = top_TB(dut)
    op2 = "00010010"
    op1 = "00001010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

@cocotb.test()
async def test_nd_1(dut):
    tb = top_TB(dut)
    op2 = "00010010"
    op1 = "00000010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

@cocotb.test()
async def test_dn_1(dut):
    tb = top_TB(dut)
    op2 = "00000010"
    op1 = "00001010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

@cocotb.test()
async def test_dd_2(dut):
    tb = top_TB(dut)
    op2 = "00000100"
    op1 = "00000010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

@cocotb.test()
async def test_nn_2(dut):
    tb = top_TB(dut)
    op1 = "00010010"
    op2 = "00001010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

@cocotb.test()
async def test_nd_2(dut):
    tb = top_TB(dut)
    op1 = "00010010"
    op2 = "00000010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

@cocotb.test()
async def test_dn_2(dut):
    tb = top_TB(dut)
    op1 = "00000010"
    op2 = "00001010"
    bias = 0
    await tb.TB(dut, op1, op2, bias)

