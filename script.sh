#!/bin/sh
LD_LIBRARY_PATH=/home/afif/Downloads/Halide/build/src #replace this with <path/to/libHalide.so>
LD_HEADER_PATH=/home/afif/Downloads/Halide/build/include  #replace this with <path/to/Halide.h>


#Compile Halide program using g++
sudo g++ saxpy*.cpp -g -I $LD_HEADER_PATH -L $LD_LIBRARY_PATH -lHalide -lpthread -ldl -o saxpy_halide -std=c++11


#Run Halide program
sudo LD_LIBRARY_PATH=$LD_LIBRARY_PATH ./saxpy_halide


#Compile C program using gcc
sudo gcc saxpy.c -o saxpy_c

#Run C program
sudo ./saxpy_c

#Compare the two output files
diff -s results_Halide.txt results_C.txt

#For Windows
#FC results_Halide.txt results_C.txt
