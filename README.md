# CFLOAT8_1_4_3 MULTIPLICATION AND DIVISION
This repository contains design , testbench and netlist for cfloat8 1_4_3 data type in the respective directories.

MULTIPLICATION : 

DESIGN:
Multiplication operation is designed in 5 stages . In the 1st stage , the sign of the product is calculated. In 2nd stage , exponent value is calculated
and in the 3 stage, the mantissa is calculated. After calculating the mantissa, the value is normalized in case of denormalized or normalized value. This is
done in the 4th stage. In the final stage, rounding mode calculation is done. It supports round to nearest. Then the final normalization for the exponent 
is calculated. It contains two methods , one to send the input into the design and one to receive the output.

TESTBENCH:
The testbench is written in cocotb , a python based verification methodology. It contains input driver , output monitor , reference model and scoreboard . 
Valid inputs are given to the DUT and the output is monitored . Similarly the input is given to the reference model and the output is monitored . Now the DUT
output and reference model output are asserted in the scoreboard. If the assertion passes, then the test is passed , else failed. The reference model has the 
same functionality of the design.

SYNTHESIS:
Synthesis is done using YOSYS. A synthesis script is written and the required lib files and contraints is present in the synthesis folder. The final netlist is 
also present in the same folder.

STEPS TO RUN:

TO compile BSV code : make all_vsim
To run the testbench : make (in testbench folder)
To run the synthesis : yosys cfloat8.ys (in synthesis folder)

Run the commands in the respective folders.
