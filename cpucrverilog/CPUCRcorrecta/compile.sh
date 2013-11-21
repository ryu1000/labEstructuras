#!/bin/bash

iverilog -o salida.o testfinal.v clock.v memfinal.v cpucrCorrecta.v
vvp salida.o
gtkwave test.vcd
