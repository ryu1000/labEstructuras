// -- Memoria principal
// -- Sistema CPUCR

module memoria(Direccion,Datos,LE);

  input [15:0] Direccion;   // Direccion del bus de direcciones del sistema
  input LE;                 // Se�al de Lectura / Escritura
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
    M[0]=CLC;
    M[1]=LDAinm; 
    M[2]=8'h06; 
    M[3]=ROR;            
    M[4]=STA;  
    M[5]=8'h00;
    M[6]=8'h10;
    M[7]=HLT;
	


  end
  
endmodule



