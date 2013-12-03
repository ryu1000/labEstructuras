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
    M[1]=8'h00; 
    M[2]=TAP;            
    M[3]=CLI;  
    M[4]=PHS;
    M[5]=HLT;
    /*M[6]=STA;
    M[7]=8'h00;
    M[8]=8'h10;
    M[9]=HLT;
	*/


  end
  
endmodule



