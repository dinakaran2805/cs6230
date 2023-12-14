# Division

## RTL:

### stage1:
1. change operands to 1.xxx * 2**y format
2. make denominator less than numerator
3. sign calculation
4. check operand is denormal or not

### stage2 to stage6:
1. each iteration of division stage

### stage7:
1. normalise the numbers within range
2. round 0 to 0.125 numbers
3. underflow calculation

### stage8:
1. final rounding
2. overflow, gradual underflow, zero flags calculation


## Verification:

### reference model:
1. cfloat to decimal
2. division, normalisation and rounding
3. decimal to cfloat

### testbench:
1. generation of inputs
2. sequencer which takes inputs and sends to driver as well as gets the expected result from reference model
3. driver sends inputs to rtl
4. output monitor gets the output and sends to scoreboard
5. scoreboard compares expected result and dut result

Note - here sequencer and scoreboard runs independent and parallel with other

## Synthesis:

Area = 5415.77 um2

at 200MHz,
setup slack = +1.860 ns
hold slack = -0.2597 ns

at 100MHz,
setup slack = +6.023178 ns
hold slack = + 0.2667 ns

