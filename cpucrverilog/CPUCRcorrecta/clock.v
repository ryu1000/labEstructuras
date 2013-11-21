module clock(clk);

output clk;

reg clk;

initial
  #1 clk=0;

always
  #5 clk=~clk;

endmodule


