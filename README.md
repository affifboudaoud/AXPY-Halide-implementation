# AXPY-Halide-implementation
This is my implementation of the BLAS routine: saxpy which given two vectors a and b and a constant cst calculates: c=cst*a+b

To do this we simply define a Hadile Func that has a variable x (the index on the vectors) and calculate the value of the previously mentioned expression.

This could be efficiently parallelized since this task is embarrassingly parallelizable. A parallel implementation could be added in the future.

File structure:

* `saxpy.c` :  C code containing the implementation of the routine. This code also writes the results of a test case to a txt file for comparaison.
* `saxpy.cpp`: C++ Code containing the Halide implementation of the routine. This code also writes the results of a test case to a txt file for comparaison.
* `script.sh`: A shell script to compile and run both programs and compare results using the diff command. 
* `Installation_logs`: File containing installation logs of LLVM and Halide.
     .* `logs.txt`: logs of the installation using the `script` command.
     .* Screen captures during the installation.



To run the code do the following:
1. Open the `script.sh` file and replace the environment variables:

      * `LD_LIBRARY_PATH` with the path to libHalide.so
      * `LD_HEADER_PATH` with the path to Halide.h header file
2. If running on windows: replace the diff command in `script.sh` with `FC`
2. Run the script using the command: `bash script.sh`
