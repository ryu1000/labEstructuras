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
    M[0]=ORAinm; //irle agregando al arreglo M el contenido de la memoria
    M[1]=8'h00; 
    M[2]=HLT;

  end
  
endmodule

