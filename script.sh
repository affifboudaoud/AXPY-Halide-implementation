#!/bin/sh
g++ saxpy*.cpp -g -I /home/afif/Downloads/Halide/build/include -L /home/afif/Downloads/Halide/build/src -lHalide -lpthread -ldl -o saxpy_halide -std=c++11

LD_LIBRARY_PATH=/home/afif/Downloads/Halide/build/src ./saxpy_halide

gcc saxpy.c -o saxpy_c

./saxpy_c

diff -s results_Halide.txt results_C.txt

