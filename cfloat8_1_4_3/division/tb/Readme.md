## verilog generation
```
$ make generate_verilog
```
## compile verilog
```
$ make compile -j
```
additionally, 
DUMP_EN=1 for generating FST waveforms

## simulation
```
$ make cocotb_sim
```
for running individual test cases
```
$ make cocotb_sim TESTCASE=<test_name>
```
