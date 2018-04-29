# Reconfigurable-Arduino-Crypto-FPGA-Shield
Portland State University 2018 Capstone Project

### Running Speed Benchmark for OpenSSL
+ $ openssl speed aes-128-cbc
+ This will run the    
      __AES_cbc_encrypt(unsigned char*, unsigned char*, (size_t) block_size, struct AES_KEY, vector(16), ENCRYPT)__            
function for up to 3 seconds for each block_size (16, 256, 1024, 8192) input.  It will then spit out the # of blocks that  
it was able to encrypt in 3 seconds for each size.
+ After running this on OpenSSL on ubuntu school server: *17482011 cbc's in 3 seconds* for a block size of 16.
+ Running on derivative created by us in AES128 folder on school server: *17561789 cbc's in 3 seconds* for block size of 16.
    - This number was generated using the average of 20 trials w/ random inputs and keys for 3 seconds each.
    - The slight difference (79,778 iterations) is likely due to the variability of tasks running on a large server.   
    - The purpose of this was to simplify some of the functionality in the OpenSSL benchmark library for use on our embedded
    boards so that we can create our own benchmarks on the embedded systems.  
        - Also to generate similar functionality and similar results to the OpenSSL speed benchmark shown above.
+ Added an hacrypto version of the AES128 benchmark that uses the __AES_cbc_encrypt()__ function above.   

### Running Cryptol with z3 for Ubuntu Server
+ Download binary for Cryptol and z3 using appropriate version (x32,x64)
+ If the correct search PATH is not set, when trying to run Cryptol, it may complain that it depends on z3 but z3 is not in the appropriate search path
+ The current search paths for your directory can be revealed using $ echo $PATH (this will list out all paths that the shell looks through to find executable files)
+ This can be resolved by navigating to the home directory ( $ cd ~/ ) and editing the .bash_profile file to set new search paths for the users bash terminal
+ This file may be hidden and can be revealed using $ ls -a  
If it doesn't exist then just create the file using the editor of your choice i.e. $ vim ~/.bash_profile
+ Inside the .bash_profile, add the lines below and save the file

    PATH=$PATH:/user_name/Capstone/z3           ----> *directory where z3 binary is located*  
    export PATH  

+ You will need to tell the shell that you updated this path by using $ source ~/.bash_profile (you can also quit and restart the shell)
+ This should allow the shell to find the z3 executable, allowing Cryptol to run properly
