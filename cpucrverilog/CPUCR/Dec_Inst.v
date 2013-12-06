
////////////Códigos de las Instrucciones en 8 bits////////////
//Instrucciones con direccionamiento INMEDIATO
 //Yalas
 
 //****************** Este bloque esta listo ************************
 
 parameter LDAinm = 8'b00000000, //Sí, funciona. // esta en el documento
 ADDinm = 8'b00100000, // Si funca // esta en el documento
 SUBinm = 8'b00110000, // No funco pero ya si // esta en el documento
 ANDinm = 8'b01000000, // Si funca // esta en el documento
 ORAinm = 8'b01010000, // Si funca // esta en el documento
 
 //******************************************************************




 //****************** Este bloque esta listo ************************
 
//Instrucciones con direccionamiento ABSOLUTO
//Falta JSR
 LDA = 8'b00000001, //No funco pero ahora si // esta en el documento
 STA = 8'b00010001, //No funco pero ahora si // esta en el documento
 ADD = 8'b00100001, //Si funca :D // esta en el documento
 SUB = 8'b00110001, //Si funca :D :D // esta en el documento
 AND = 8'b01000001, // Si funciona ^^ // esta en el documento
 ORA = 8'b01010001, // Si funciona ^^ // esta en el documento
 JMP = 8'b01100001, // Si funciona ^^ // esta en el documento
 JSR = 8'b01110001, // Siii :D funciona // esta en el documento
 
 //******************************************************************



//********************** Este bloque esta listo **********************
 
//Instrucciones con direccionamiento RELATIVO
//Falta BVS y BVC
 BEQ = 8'b00000010, //Sip ^^ // esta en el documento
 BNE = 8'b00010010, //Siip // esta en el documento
 BCS = 8'b00100010, //Sip! // esta en el documento
 BCC = 8'b00110010, //Siempre saltaba... pero ya lo arreglé :D // esta en el documento
 BMI = 8'b01000010, // esta en el documento
 BPL = 8'b01010010, //Siip! // esta en el documento
 BVS = 8'b01100010, //sisisisi. // esta en el documento
 BVC = 8'b01110010, //yeei :D no más saltos(?) // esta en el documento

//********************************************************************




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




//***************** Este bloque esta listo ***************************

//Instrucciones con direccionamiento IMPLICITO
//Yalas
 SEC = 8'b00100100, //Sip // esta en el documento
 CLC = 8'b00110100, //Sí funciona n.n // esta en el documento
 SEI = 8'b01000100, //Sip // esta en el documento
 CLI = 8'b01010100, //Sip // esta en el documento

//********************************************************************




//*********************** Este bloque esta listo *********************

//Instrucciones con direccionamiento ACUMULADOR
//Falta PLA
 CLA = 8'b00000101, //No funco pero ahora si // esta en el documento
 CPA = 8'b00010101, // esta en el documento
 INA = 8'b00100101, //No funcionó pero ahora sí // esta en el documento
 DCA = 8'b00110101, //Si funciona ^^ // esta en el documento
 ROL = 8'b01000101, //Sip! // esta en el documento
 ROR = 8'b01010101, //Sip! // esta en el documento
 PLA = 8'b01100101, // en el documento
 PHA = 8'b01110101, // Siii :D funciona // esta en el documento

//*******************************************************************





//*********************** Este bloque esta listo ********************

//Instrucciones con direccionamiento CONTROL
//Falta RTI, RTS, PHS
 TPA = 8'b00000110, // en el documento
 TAP = 8'b00010110, // Siii :D funciona // esta en el documento
 RTI = 8'b00100110, // No hay que probar esta !!
 RTS = 8'b00110110, // Funciona // esta en el documento
 HLT = 8'b01000110, // NO Funciona, ahora si // esta en el documento
 NOP = 8'b01010110, //Funciona! // esta en el documento
 PLS = 8'b01100110, // Si funciona // esta en el documento
 PHS = 8'b01110110, // Si funciona // esta en el documento

//*******************************************************************





//Instrucciones para ENTRADA/SALIDA
//Nolas
 INP = 8'b00000111, 
 OUT = 8'b00010111;

`define ActualizarNZ ((RI == ADD) || (RI == ADDinm) || (RI == ADDind) || (RI == AND) || (RI == ANDinm) || (RI == ANDind) || (RI == CLA) || (RI == CPA) || (RI == DCA) || (RI == INA) || (RI == INP) || (RI == LDA) || (RI == LDAinm) || (RI == LDAind) || (RI == PLA) || (RI == ORA) || (RI == ORAinm) || (RI == ORAind) || (RI == ROL) || (RI == ROR) || (RI == SUB) || (RI == SUBinm) || (RI == SUBind) || (RI == TPA)) 
