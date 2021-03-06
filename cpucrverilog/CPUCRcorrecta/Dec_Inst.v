
////////////C�digos de las Instrucciones en 8 bits////////////
//Instrucciones con direccionamiento INMEDIATO
 //Yalas
 parameter LDAinm = 8'b00000000, //S�, funciona.
 ADDinm = 8'b00100000, //
 SUBinm = 8'b00110000, //
 ANDinm = 8'b01000000, //
 ORAinm = 8'b01010000, //
//Instrucciones con direccionamiento ABSOLUTO
//Falta JSR
 LDA = 8'b00000001, //No funco pero ahora si 
 STA = 8'b00010001,
 ADD = 8'b00100001,
 SUB = 8'b00110001,
 AND = 8'b01000001,
 ORA = 8'b01010001,
 JMP = 8'b01100001,
 JSR = 8'b01110001,
//Instrucciones con direccionamiento RELATIVO
//Falta BVS y BVC
 BEQ = 8'b00000010,
 BNE = 8'b00010010,
 BCS = 8'b00100010,
 BCC = 8'b00110010,
 BMI = 8'b01000010,
 BPL = 8'b01010010,
 BVS = 8'b01100010,
 BVC = 8'b01110010,
//Instrucciones con direccionamiento INDIRECTO
//Nolas
 LDAind = 8'b00000011,
 STAind = 8'b00010011,
 ADDind = 8'b00100011,
 SUBind = 8'b00110011,
 ANDind = 8'b01000011,
 ORAind = 8'b01010011,
 JSRind = 8'b01110011,
 JMPind = 8'b01100011,
//Instrucciones con direccionamiento IMPLICITO
//Yalas
 SEC = 8'b00100100,
 CLC = 8'b00110100,
 SEI = 8'b01000100,
 CLI = 8'b01010100,
//Instrucciones con direccionamiento ACUMULADOR
//Falta PLA
 CLA = 8'b00000101,
 CPA = 8'b00010101,
 INA = 8'b00100101,
 DCA = 8'b00110101,
 ROL = 8'b01000101,
 ROR = 8'b01010101,
 PLA = 8'b01100101,
 PHA = 8'b01110101,
//Instrucciones con direccionamiento CONTROL
//Falta RTI, RTS, PHS
 TPA = 8'b00000110,
 TAP = 8'b00010110,
 RTI = 8'b00100110,
 RTS = 8'b00110110,
 HLT = 8'b01000110,
 NOP = 8'b01010110,
 PLS = 8'b01100110,
 PHS = 8'b01110110,
//Instrucciones para ENTRADA/SALIDA
//Nolas
 INP = 8'b00000111,
 OUT = 8'b00010111;

`define ActualizarNZ ((RI == ADD) || (RI == ADDinm) || (RI == ADDind) || (RI == AND) || (RI == ANDinm) || (RI == ANDind) || (RI == CLA) || (RI == CPA) || (RI == DCA) || (RI == INA) || (RI == INP) || (RI == LDA) || (RI == LDAinm) || (RI == LDAind) || (RI == PLA) || (RI == ORA) || (RI == ORAinm) || (RI == ORAind) || (RI == ROL) || (RI == ROR) || (RI == SUB) || (RI == SUBinm) || (RI == SUBind) || (RI == TPA)) 
