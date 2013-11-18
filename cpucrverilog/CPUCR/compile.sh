#!/bin/bash

iverilog -o salida.o testfinal.v clock.v memfinal.v CPUCR_8bits_alterada.v
vvp salida.o
gtkwave test.vcd
