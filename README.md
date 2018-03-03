# Reconfigurable-Arduino-Crypto-FPGA-Shield
Portland State University 2017 Capstone Project


### Running Cryptol with z3 for Ubuntu Server
+ Download binary for Cryptol and z3 using appropriate version (x32,x64)
+ If the correct search PATH is not set, when trying to run Cryptol, it may complain that it depends on z3 but z3 is not in the appropriate search path
+ The current search paths for your directory can be revealed using $ echo $PATH (this will list out all paths that the shell looks through to find executable files)
+ This can be resolved by navigating to the home directory ( $ cd ~/ ) and editing the .bash_profile file to set new search paths for the users bash terminal
+ This file may be hidden and can be revealed using $ ls -a  If it doesn't exist then just create the file using the editor of your choice i.e. $ vim ~/.bash_profile
+ Inside the .bash_profile, add the lines below and save the file

    PATH=$PATH:/user_name/Capstone/z3           ----> *directory where z3 binary is located*  
    export PATH  

+ You will need to tell the shell that you updated this path by using $ source ~/.bash_profile (you can also quit and restart the shell)
+ This should allow the shell to find the z3 executable, allowing Cryptol to run properly
