# Microblaze Configuration


### Add all the synthesizable .v files in the project manager in Microblaze.
+ Go to the synthesis toolbox and change hierarchy settings to -flatten hierarchy.
+ The synthesis timing settings can be changed.

### Digital Clock Frequency
+ With the Digital Clock Manager, set the start frequency as the default frequency of the board (select the board part number at the beginning of the setup process in Vivado).
+ The end frequency is the maximum clock frequency mentioned in the FPGA’s data sheet.
+ Increment in steps of 1KHz and observe the minimum and maximum frequency at which the cipher text is displayed correctly. This range is decided by looking at the timing violations.

### Displaying cipher text and troubleshooting 
+ The Tx module is included in the top module. For creating a Rx module, the Tx module can be mirrored using Vivado Microblaze Mirror taskbar. 
  - Mirroring helps in enabling one module at a time. 
  - This ensure there is no increase in the timing since all these instructions are performed in one clock cycle. 
+ If two instructions have to execute at the same time using two different modules (Rx and Tx), a priority counter can be used (Microblaze Timing Manager) to set the Rx or the Tx module as the first top module. 
  - In this project, we configured the Tx as the first top module to ensure that the cipher text is completely displayed (128 bits) before the next input is taken thus preventing timing issues and incorrect data from being displayed. 
+ The cipher text is displayed on the tcl console once you manually change the baud rate (115,200) under monitor settings in the project manager.
+ To ensure the the encrypted data is corrected, a comparison can be done with a file containing all the correct cipher text concurrently. 
+ On Microblaze tcl console or the serial monitor, a single character “.”,”,” and “-” is often used to display if a value is correct or incorrect. 
  - The character will not be printed if the cipher text displayed is incorrect. 
  - An automatic software breakpoint will appear and the project will need to be compiled again after the cause for the timing violation is fixed.

### Generate reports
+ The version of Microblaze used did not allow us to generate and save reports however the results appeared on the interactive gui. 
+ The information about the timing, area and power tab were noted down during this process. We used the details obtained from this monitor to find the number of slices, LUTs, BRAMs and maximum throughput. 

### To optimize the performance 
+ Use the switch mode option : Changes from using Block RAM to Distributed RAM.
+ In the implemented design: physical hardware components can be changed (dedicated menory resources, flip flops, latches and multiplexers). 
+ Improve the timing on the critical path (This is the main cause for timing violations).





