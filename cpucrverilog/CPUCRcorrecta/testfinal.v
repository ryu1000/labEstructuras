       // -- Sistema CPUCR
// -- IE-503 Estructura de computadores digitales

`timescale 1ns / 1ps

module Sistema_CPUCR;
// variables para el reloj

wire clk;

// variables para la memoria

wire LE;
wire [15:0] Direccion;
wire  [7:0] data;

// variables para la CPUCR

reg RPS;
reg INT;
reg SDMA;

wire M;
wire CB;
wire HALT;
wire INTOK;
wire BD; 

// ====== instanciacion de los modulos ======
clock clkcpu(clk);
memoria memcpu(Direccion,data,LE);
CPUCR cpu(clk,RPS,LE,M,CB,CM,HALT,INT,INTOK,SDMA,BD,Direccion,data);

// ==========================================

  initial
  begin
   $dumpfile("test.vcd");
    $dumpvars;
    #0 RPS = 1; INT = 1; SDMA = 1;
    #15 RPS = 0;
    #20 RPS = 1;
    #500 $finish; //tiempo total de simulacion
  end

endmodule
