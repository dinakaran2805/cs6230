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
        self.dut = dut
        
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

        self.stop = 0
        self.l_op1 = []
        self.l_op2 = []

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

    async def input_sequencer(self, dut):

        self.rm_output = []
        bias = 0
        for a in self.l_op1:
            for b in self.l_op2:
                await self.input_driver(dut, a, b, bias)
                try:
                    rm_result, rm_status = div_rm(a, b, bias)
                except:
                    rm_result, rm_status = ["python", "exception"]
                self.rm_output.append([rm_result, rm_status])
        
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

        return str(result), str(status)
    
    async def comparison(self, dut, dut_output, rm_output):
        print("DUT :", dut_output)
        print("RM  :", rm_output)
        assert dut_output == rm_output

    async def scoreboard(self, dut):
        for i in range(len(self.l_op1)*len(self.l_op2)):
        #while True:
            dut_result, dut_status = await self.output_monitor(dut)
            if (self.rm_output[i] == [dut_result, dut_status]):
                self.dut._log.info("PASS")
            else:
                self.dut._log.info("FAIL : RM = %s DUT = %s", self.rm_output[i], [dut_result, dut_status])

        self.stop = 1
        self.dut._log.info("STOP")

    async def TB(self, dut, op1, op2, bias):
        await self.start(dut)
        
        rm_result, rm_status = div_rm(op1, op2, bias)
        rm_output = [rm_result, rm_status]

        await self.input_driver(dut, op1, op2, bias)
        dut_result, dut_status = await self.output_monitor(dut)
        dut_output = [(dut_result), (dut_status)]

        await self.comparison(dut, dut_output, rm_output) 

    async def pipeline_TB(self, dut):
        await self.start(dut)
        cocotb.start_soon(self.input_sequencer(dut))
        cocotb.start_soon(self.scoreboard(dut))

        while True:
            if (self.stop == 1) and (self.valid.value == 0):
                break
            await RisingEdge(self.clk)

    def input_generation(self, dut):
        input_list = []
        for s in range(0,1):
            for e in range(1,16):
                for m in range (1,8):
                    input_list.append(f'{s:01b}' + f'{e:04b}' + f'{m:03b}')
                        #print(input_list)
                        #print
        self.l_op1 = input_list
        self.l_op2 = input_list

@cocotb.test()
async def test_pipeline(dut):
    tb = top_TB(dut)

    tb.l_op1 = ["00000111", "00100100"]
    tb.l_op2 = ["01111111", "10011100"]
    await tb.pipeline_TB(dut)


@cocotb.test()
async def regression(dut):
    tb = top_TB(dut)
    tb.input_generation(dut)
    await tb.pipeline_TB(dut)

@cocotb.test()
async def test_dd_1(dut):
    tb = top_TB(dut)
    op1 = "00000100"
    op2 = "00000010"
    bias = 1
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

