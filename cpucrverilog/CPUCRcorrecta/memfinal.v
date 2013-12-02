// -- Memoria principal
// -- Sistema CPUCR

module memoria(Direccion,Datos,LE);

  input [15:0] Direccion;   // Direccion del bus de direcciones del sistema
  input LE;                 // Señal de Lectura / Escritura
  inout [7:0] Datos;        // Bus de datos bidireccional
  output [7:0] Mwire;
  output [7:0] Mwire2;
  
  assign Mwire = M[4096];
  assign Mwire2 = M[0];
  
  reg [7:0] M[0:65535];      //memoria de 65536

  assign  Datos  =  LE ?  M[Direccion] : 8'bZ;
  `include "Dec_Inst.v"//aca estan todos los mneumonicos

  always @ ( negedge LE)
  if (~LE)
      M[Direccion] <= Datos;
  
  initial
  begin
    
    M[0]=CLA; //irle agregando al arreglo M el contenido de la memoria
    M[1]=TAP;
    M[2]=PHS;
    M[3]=LDA;
    M[4]=8'h00;
    M[5]=8'hFF;
    M[6]=HLT;


/*
	M[8'h10]=8'h45;
	M[0]=LDA;
	M[1]=8'h10;
	M[2]=8'h00;
*/
  end
  
endmodule

