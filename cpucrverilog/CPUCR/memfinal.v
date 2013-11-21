// -- Memoria principal
// -- Sistema CPUCR

module memoria(Direccion,Datos,LE);

  input [15:0] Direccion;   // Direccion del bus de direcciones del sistema
  input LE;                 // Señal de Lectura / Escritura
  inout [7:0] Datos;        // Bus de datos bidireccional
  
  reg [7:0] M[0:65535];      //memoria de 65536

  assign  Datos  =  LE ?  M[Direccion] : 8'bZ;
  `include "Dec_Inst.v"//aca estan todos los mneumonicos

  always @ ( negedge LE)
  if (~LE)
      M[Direccion] <= Datos;
  
  initial
  begin
	//irle agregando al arreglo M el contenido de la memoria
    M[0]=LDAinm; 
    M[1]=8'h06; 
    M[2]=ORA; 
    M[3]=8'h00; 
    M[4]=8'h20; 
    M[5]=JMP;
    M[6]=8'h0B;
    M[7]=8'h00;
    M[8]=STA; 
    M[9]=8'h00; 
    M[10]=8'h10; 
    M[11]=HLT; 
    M[8192]=8'h05;
  end
  
endmodule

