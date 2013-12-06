//CPUCR sintetizable
//Diseñadores:
//			Esteban Ortiz Cubero 
//			Warren Alvarado
// I Semestre 2005

`timescale 1ns/10ps
`define MSB8 7 //Buses de 8bits
`define MSB16 15 //Buses de 16bits

module CPUCR(CLK,RPS,LE,M,CB,CM,WAIT,HALT,INT,INTOK,SDMA,BD,BUSDIR,BUSDAT);
	input CLK,INT,SDMA,RPS,WAIT; //Reloj;Interrupcion;
								 //Acceso directo a memoria;Reposicion;
								 //Espere 
	output BD,CB,CM,LE,HALT,INTOK,M;//Bus de datos;Ciclo de busqueda;
									//Ciclo de memoria;Lectura/escritura;
									//Halt;INTOK;memoria
	//************************BUSES*************************************
	output [`MSB16:0] BUSDIR;
	inout [`MSB8:0] BUSDAT;
	
	wire CLK,RPS,HALT;
	wire [`MSB8:0] BUSDAT,A,P,S;
	wire [`MSB8:0] RI,PB;
	wire [`MSB8:0] EstPresente, ProxEst;
	wire [`MSB16:0] PC,BUSDIR;
	`include "estados.v"
	`include "Dec_Inst.v"
	
	reg_RI RI1(CLK,CB,BUSDAT,RI,RPS,EstPresente,INT);  
	reg_Est_Presente EP1(CLK,EstPresente,ProxEst,RPS);	
	reg_CB CB1(CLK,EstPresente,RPS,CB,CM,BD,ProxEst,INTOK,SDMA);
	reg_ProxEst PE1(CLK,RI,EstPresente,ProxEst,RPS,SDMA,INT);
	acumulador A1(CLK,RI,EstPresente,A,BUSDAT,RPS,S,P,LE);
	reg_PC PC1(CLK,RI,RPS,EstPresente,PC,BUSDAT,S,BUSDIR,P,LE,PB,SDMA,INT);
	reg_M M1(CLK,ProxEst,RI,M,RPS,SDMA);
	reg_LE LE1(CLK,EstPresente,RI,LE,RPS,SDMA);
	reg_P PP(CLK,EstPresente,RI,RPS,P,A);
	reg_HLT HL1(EstPresente,RPS,CLK,HALT);
	assign BUSDAT=(!LE&&INT&&((RI==STAind)||(RI==PHA)||(RI==STA))) ? A :8'bz;
	assign BUSDAT=(!LE&&(RI==PHS)) ? S: 8'bz; 
	assign BUSDAT=(!LE&&((RI==JSR)||(RI==JSRind))) ? PB:8'bz;
	assign BUSDAT=(!LE&&(RI==OUT)) ? A:8'bz;
	assign BUSDAT=(!LE&&!INT) ? PB:8'bz;
endmodule

//********************Registro de instruccion***************************
module reg_RI(CLK,CB,BUSDAT,RI,RPS,EstPresente,INT);
	input CLK,CB,RPS,INT;
	input [`MSB8:0] BUSDAT,EstPresente;
	output [`MSB8:0] RI;
	reg [`MSB8:0] RI;
	`include "estados.v"

	always @(negedge CLK)
		begin
			if (RPS)
				begin
					if(CB) RI<=BUSDAT;
					else RI <= RI;
				end
			else RI<=8'b0;
		end
endmodule


//*******************Registro Estado Presente****************************

module reg_Est_Presente(CLK,EstPresente,ProxEst,RPS);
	input CLK,RPS;
	input [`MSB8:0] ProxEst;
	output [`MSB8:0] EstPresente;
	reg [`MSB8:0] EstPresente;
	always @(negedge CLK)
		begin
			if(RPS) EstPresente<=ProxEst;
			else EstPresente<=8'b0;
		end
endmodule

//*******************Registro Ciclo de Busqueda****************************

module reg_CB(CLK, EstPresente,RPS,CB,CM,BD,ProxEst,INTOK,SDMA);
	input CLK,RPS,SDMA;
	input [`MSB8:0] EstPresente,ProxEst;
	output CB,CM,BD,INTOK;
	reg CB,CM,BD,INTOK;
	`include "estados.v"
	always @(negedge CLK)
		begin
			if(RPS)
				begin
					if(ProxEst==Estado_1) CB<=1'b1;
					else CB<=1'b0;
				end
			else CB<=1'b0;
		end
	always @(negedge CLK) begin  
			if(!SDMA&&((ProxEst==Estado_15)||(ProxEst==Estado_16))) CM<=1'bz;
			else if (!RPS) CM<=1'b0;
			else if ((ProxEst==Estado_1)&&(EstPresente==Estado_16)) CM<=1'b1;
			else if (ProxEst==Estado_30) CM<=CM; //Se agrego esta linea para que CM se detenga en HLT
			else CM<=~(CM);
			
			
			if ((ProxEst==Estado_15)||(ProxEst==Estado_16)) BD<=1'b1;
			else BD<=1'b0;
			if ((EstPresente==Estado_21)||(EstPresente==Estado_22)||(EstPresente==Estado_23)||(EstPresente==Estado_24)) INTOK<=1'b1;
			else INTOK<=1'b0;

		end
	
endmodule

//**************Registro de Proximo Estado ************

module reg_ProxEst(CLK,RI,EstPresente,ProxEst,RPS,SDMA,INT);
	input CLK,RPS,INT,SDMA;
	input [`MSB8:0] RI,EstPresente;
	output [`MSB8:0] ProxEst;
	reg [`MSB8:0] ProxEst;
	`include "estados.v"
	`include "Dec_Inst.v"
	always @(EstPresente)
		begin
			if(!RPS) ProxEst<=8'b1;
			else 
			begin
				case(EstPresente)
				 Estado_0: ProxEst<=Estado_1;
				 Estado_1: begin
				 		if(!INT) ProxEst<=Estado_17;
						else if(!SDMA) ProxEst<=Estado_15;
						else ProxEst<=Estado_2;
					   end
				 Estado_2: begin
				 	    case(RI)
					      LDAinm,ADDinm,SUBinm,ANDinm,ORAinm,BCC,BCS,BEQ,BNE,BMI,BPL,PHA,PLS,BVC,BVS: ProxEst<=Estado_3;
					      STA,LDA,AND,SUB,ORA,ADD,JMP,PLA,PHS,JSR,JSRind,INP,OUT: ProxEst<=Estado_3;
					      TAP,TPA,CLA,INA,DCA,ROL,ROR,CLC,SEC,SEI,CLI,NOP,CPA: ProxEst<=Estado_1;
					      LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind,RTS,RTI: ProxEst<=Estado_3;
					      HLT: ProxEst<=Estado_30;
					      default: ProxEst<=Estado_31;
					    endcase
					   end
				Estado_3: begin
					   ProxEst<=Estado_4;
					  end
				Estado_4: begin
					   case (RI)
					     STA,LDA,AND,SUB,ORA,ADD,JMP,JSR,JSRind,RTS,INP,OUT: ProxEst<=Estado_5;
					     LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind,RTI: ProxEst<=Estado_5;
					   default: ProxEst<=Estado_1;
					   endcase
					  end
				Estado_5: begin
					   ProxEst<=Estado_6;
					  end
				Estado_6: begin
					    case(RI)
					      JMP,RTS,INP,OUT,RTI: ProxEst<=Estado_1;
					    default: ProxEst<=Estado_7;
					    endcase
					  end
				Estado_7: ProxEst<=Estado_8;
				Estado_8: begin
					    case(RI)
					      LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind: ProxEst<=Estado_9;
					      JSR,JSRind: ProxEst<=Estado_9;
					      default: ProxEst<=Estado_1;
					    endcase
					  end
				Estado_9: begin
					    ProxEst<=Estado_10;
					  end
				Estado_10: begin
					    case(RI)
					    	JMPind,JSR: ProxEst<=Estado_1;						
					       default: ProxEst<=Estado_11;
					    endcase
					  end 
			        Estado_11: begin
					    ProxEst<=Estado_12;
					  end
				Estado_12: begin
					    case(RI)
					      JSRind: ProxEst<=Estado_13;
					      default:ProxEst<=Estado_1;
					    endcase
					  end
				Estado_13: begin
					    ProxEst<=Estado_14;
					   end
				Estado_14: begin
					    ProxEst<=Estado_1;
					   end
				Estado_15: begin //Estados del SDMA
					    ProxEst<=Estado_16;
					   end

				Estado_16: begin
						if(!SDMA)  ProxEst<=Estado_15;
						else ProxEst<=Estado_1;
					   end
				Estado_17: begin
					       ProxEst<=Estado_18;
					   end
				Estado_18: begin
					       ProxEst<=Estado_19;
					   end
				Estado_19: begin
					       ProxEst<=Estado_20;
					   end
				Estado_20: begin
					       ProxEst<=Estado_21;
					   end
				Estado_21: begin
					       ProxEst<=Estado_22;
					   end
				Estado_22: begin
					       ProxEst<=Estado_23;
					   end
				Estado_23: begin
					       ProxEst<=Estado_24;
					   end
				Estado_24: begin
					       ProxEst<=Estado_25;
					   end
				Estado_25: begin
					       ProxEst<=Estado_1;
					   end

				Estado_30: ProxEst<=Estado_30;
				Estado_31: ProxEst<=Estado_31;
				 default: ProxEst<=Estado_31;
				endcase
			end			
		end
endmodule


//*****************Acumulador*****************
module acumulador(CLK,RI,EstPresente,A,BUSDAT,RPS,S,P,LE);
	input CLK,RPS,LE;
	input [`MSB8:0] EstPresente,RI,P;
	input [`MSB8:0] BUSDAT;
	output [`MSB8:0] A;
	output [`MSB8:0] S; //**N*VIZC
	reg [`MSB8:0] A;
	reg BC,BN,BZ,BI,BV,Temp,Temp1;
	reg [`MSB8:0] S;
	
	`include "estados.v"
	`include "Dec_Inst.v"
	always @(negedge CLK)
		begin
			BZ<= ~|A;
			BN<= A[7];
			  case(EstPresente)
			    Estado_0: BI<=1'b1;
			    Estado_1: begin
			    	       A<=A;
				       Temp<=A[7];
				       if ((RI == ADD) || (RI == ADDinm) || (RI == ADDind))
				             BV <= Temp^Temp1 ? 1'b0:Temp^A[7];
				       if (RI == DCA)
				             BV <= Temp ? ~A[6]:1'b0;
				       if (RI == INA)
				             BV <= Temp ? 1'b0:A[7];
				       if ((RI == SUB) || (RI == SUBinm) || (RI == SUBind))
					     BV <= Temp^Temp1 ? Temp^A[7]:1'b0;
				      end
			    Estado_2: case(RI)
			    	      	CLA: A<=8'b0;
					INA: {BC,A}<=A+1;
					DCA: {BC,A}<=A-1;
					ROL:begin
					     BC<=A[7];
					     A<={A[6:0],BC};
					    end
					ROR:begin
					     BC<=A[0];
					     A<={BC,A[7:1]};
					    end
					CLC: BC<=1'b0;
					SEC: BC<=1'b1;
					SEI: BI<=1'b1;
					CLI: BI<=1'b0;
					TPA: A<=P;
					CPA: A<=~A;
					default:begin 
						  A<=A;
						  BC<=BC;
						  BI<=BI;
						end
				      endcase
			    Estado_3: A<=A;
			    Estado_4: begin
			    	      Temp1<=BUSDAT[7];
			    	      case(RI)
			    	        LDAinm: A<=BUSDAT;
					ADDinm: {BC,A}<=A+BUSDAT;
					SUBinm: {BC,A}<=A-BUSDAT; // cambiar operador por -
					ANDinm: A<=A&BUSDAT;
					ORAinm: A<=A|BUSDAT;
					PLA: A<=BUSDAT;
					PLS: begin
					     	A<=A;
						{BV,BI,BZ,BC}<=BUSDAT[3:0];
						BN<=BUSDAT[5];
					     end
					default: begin 
						   A<=A;
						   BC<=BC;
						 end
				      endcase
				      end
			    Estado_5: A<=A;
			    Estado_6: case(RI)
			    		INP:A<=BUSDAT;
			    		default: A<=A;
				      endcase
			    Estado_7: A<=A;
			    Estado_8: begin
			    	      Temp1<=BUSDAT[7];
			    	      case(RI)
			    		LDA: A<=BUSDAT;
					AND: A<=A&BUSDAT;
					SUB: {BC,A}<=A-BUSDAT;
					ORA: A<=A|BUSDAT;
					ADD: {BC,A}<=A+BUSDAT;
				        default: begin
						   A<=A;
						   BC<=BC;
						 end
				      endcase
				      end
			    Estado_9: A<=A;
			    Estado_10: A<=A;
			    Estado_11: A<=A;
			    Estado_12: begin
			    	       Temp1<=BUSDAT[7];
			    	       case(RI)
				       LDAind: A<=BUSDAT;
				       ADDind: A<=A+BUSDAT;
				       SUBind: A<=A-BUSDAT;
				       ANDind: A<=A&BUSDAT;
				       ORAind: A<=A|BUSDAT; // se cambio & por |
				       default: begin
						   A<=A;
						   BC<=BC;
						 end
			   	       endcase
				       end
			    default: begin
			   	       A<=A;
				       BC<=BC;
				       BI<=BI;
				       BV<=BV;
				     end
			  endcase
			  S={1'b0,1'b0,BN,1'b0,BV,BI,BZ,BC};
		end
endmodule

//************** Contador de programa *************

module reg_PC(CLK,RI,RPS,EstPresente,PC,BUSDAT,S,RDR,P,LE,PB,SDMA,INT);
	input CLK, RPS,LE,SDMA,INT;
	input [`MSB8:0] EstPresente,RI,S,P;
	input [`MSB8:0] BUSDAT;
	output [`MSB16:0] PC, RDR;
	output [`MSB8:0] PB;
	reg [`MSB16:0] PC, RDR; //Registro de direccion
	reg [`MSB8:0] PB; //Parte baja de la direccion
	
	`include "estados.v"
	`include "Dec_Inst.v"

	always @(negedge CLK)
	 begin
		if(!RPS) begin 
			   PC<=16'b0;
			   RDR<=16'b0;
			   PB<=8'b0;
			end
		else begin
		  case(EstPresente)
		    Estado_0: begin
		    		PC<=16'b0;
				RDR<=16'b0;
			      end
		    Estado_1: begin
				PC<=PC;
				RDR<=(!SDMA&&INT) ? 16'bz:RDR;
			      end
		    Estado_2: begin
		    		case(RI)
				 CPA,LDAinm,ADDinm,TAP,TPA,CLA,INA,DCA,SUBinm,ANDinm,ORAinm,INP,OUT: begin
				 								PC<=PC+1; //Le agregamos +1
												RDR<=RDR+1; // le agregamos +1
				 							     end
				 ROL,ROR,BCC,BCS,CLC,SEC,SEI,CLI,NOP,BNE,BEQ,BMI,BPL,STA,LDA,AND,SUB,ORA,ADD,JMP,BVS,BVC: begin
				 						    PC<=PC+1; ///Le agregamos un +1
										    RDR<=RDR+1; //Le agregamos un +1
									          end
				PHA,PHS: begin
				     	PC<=PC;
					RDR<={8'hFF,P};
				     end
				PLA: begin
				        PC<=PC+16'b1;
					RDR<={8'hFF,P-8'b1};
				     end
				PLS:begin
				    	PC<=PC;
					RDR<={8'hFF,P-8'b1};
				    end
				LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind: begin
					  PC<=PC+16'b1;
					  RDR<=RDR+16'b1;
					end
				JSR,JSRind: begin
				     	PC<=PC+16'h3;
					RDR<={8'hFF,P};
				     end
				RTS,RTI:begin
					PC<=PC;
					RDR<={8'hFF,P-8'b1};
				    end

			        default: begin
				 		PC<=PC;
						RDR<=RDR;
					  end 
				endcase
			      end
		    Estado_3: begin
		    	       case(RI)
			         LDAinm,ADDinm,SUBinm,ANDinm,ORAinm,STA,LDA,AND,SUB,ORA,ADD,JMP,PLA: begin
				 							  PC<=PC;
											  RDR<=RDR;
										         end
				BCC,BCS,BPL,BMI,BEQ,BNE,BVC,BVS: begin
				       PC<=PC+16'b1;
				       RDR<=RDR;
				     end
				PHA,PLS,PHS: begin       
				       PC<=PC+16'b1;
				       RDR<=RDR;
				     end
				LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind,RTS,INP,OUT,RTI: begin
					  PC<=PC;
					  RDR<=RDR;
					end
				JSR,JSRind: begin
			   	     	PC<=PC;
					RDR<=RDR;
					PB<=PC[15:8];
				     end
				 default: begin
				 		PC<=PC+16'b1;
						RDR<=RDR+16'b1;
						PB<=PB;
					  end
			       endcase
			      end
		    Estado_4: begin
		    		case(RI)
				PHA,PHS,PLS: begin
				       PC<=PC;
				       RDR<=PC;
				       PB<=BUSDAT;
				     end
				PLA: begin
				       PC<=PC;
				       RDR<=PC;
				     end
				STA,LDA,AND,SUB,ORA,ADD,JMP: begin
				     	PC<=PC+16'b1;
					RDR<=RDR+16'b1;
					PB<=BUSDAT;
				     end
				INP,OUT: begin
					PC<=PC+16'b1;
					RDR<={8'hff,BUSDAT};
				     end
				BCC: begin
					case(S[0])
					1'b1: begin
						PC<=PC;
						RDR<=RDR+16'b1;
					     end
					1'b0: begin
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
						RDR<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					     end
					endcase
				end
				BCS:begin
				    	case(S[0])
					1'b1:begin
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
						RDR<=BUSDAT[7] ? PC +  {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					     end
					1'b0:begin
						PC<=PC;
					        RDR<=RDR+16'b1;
					     end
					endcase
				    end
				BNE: begin
					case(S[1])
					1'b1: begin
						PC<=PC;
						RDR<=RDR+16'b1;
					      end
					1'b0: begin
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					        RDR<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					      end
					endcase	
				    end
				BEQ:begin
                                        case(S[1])
					1'b1: begin
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
						RDR<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					      end
                                        1'b0: begin
						PC<=PC;
						RDR<=RDR+16'b1;
					      end
                                        endcase
				    end		
				BMI:begin
				        case(S[5])
                                        1'b1: begin
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'h00,BUSDAT};
						RDR<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC +  {8'h00,BUSDAT};
					      end
                                        1'b0:begin 
						PC<=PC;
						RDR<=RDR+16'b1;
					     end
                                        endcase
                                    end
				BPL: begin
                                        case(S[5])
                                        1'b1: begin 
						PC<=PC;
						RDR<=RDR+16'b1;
					      end
                                        1'b0: begin
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
						RDR<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC +  {8'b0,BUSDAT};
					      end
                                        endcase
                                     end
				BVC: begin
					case(S[3])
					1'b1: begin
						PC<=PC;
						RDR<=RDR+16'b1;
					      end
					1'b0: begin 
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					        RDR<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					      end
				        endcase
				     end
				BVS:begin
				    	case(S[3])
					1'b1:begin
						PC<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
						RDR<=BUSDAT[7] ? PC + {8'hFF,BUSDAT} : PC + {8'b0,BUSDAT};
					     end
					1'b0:begin
						PC<=PC;
					        RDR<=RDR+16'b1;
					     end
					endcase
				    end

				LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind: begin
					  PC<=PC+16'b1;
					  RDR<=RDR+16'b1;
					  PB<=BUSDAT;
					end
				JSR,JSRind: begin
					PC<=PC;
					RDR<={8'hFF,P};
					PB<=PB;
				     end
				RTS:begin
				      	PC<=PC;
					RDR<={8'hFF,P};
					PB<=BUSDAT;
				    end
				RTI:begin
				    	PC<=PC;
					RDR<={8'hFF,P-8'b1};
					PB<=BUSDAT;
				    end
				default: begin 
					   PC<=PC+16'b1;
					   RDR<=RDR+16'b1;
					   PB<=PB;
					 end
				endcase
			      end
		    Estado_5: begin 
		    	      	case(RI)
					STA,LDA,AND,SUB,ORA,ADD,INP,OUT: begin
						PC<=PC;
						RDR<=RDR;
					     end
					LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind: begin
						  PC<=PC;
						  RDR<=RDR;
						end
					JSR,JSRind: begin
					     	PC<=PC;
						RDR<=RDR;
						PB<=PC[7:0];
					     end
					default: begin
						   PC<=PC;
						   RDR<=RDR;
						   PB<=PB;
						 end
				endcase
			      end

		    Estado_6: begin
		    	        case(RI)
					STA,LDA,AND,SUB,ORA,ADD: begin
						PC<=PC+16'b1;
						RDR<={BUSDAT,PB};
					     end
					JMP: begin
					       PC<={BUSDAT,PB};
					       RDR<={BUSDAT,PB};
					     end
					LDAind,ADDind,SUBind,ANDind,ORAind,STAind,JMPind: begin
						  PC<=PC+16'b1;
						  RDR<={BUSDAT,PB};
						end
					JSR,JSRind: begin
					       PC<=PC-16'h2;
					       RDR<=PC-16'h2;
					     end
					RTS,RTI:begin
					       PC<={BUSDAT,PB};
					       RDR<={BUSDAT,PB};
					    end
					INP,OUT:begin
						PC<=PC;
						RDR<=PC;
					    end
					default: begin
						   PC<=PC;
						   RDR<=RDR;
						 end
				endcase
			      end

		    Estado_7: begin
		    		case(RI)
					STA,LDA,AND,SUB,ORA,ADD: begin
						PC<=PC;
						RDR<=RDR;
					     end
					default: begin
						   PC<=PC;
						   RDR<=RDR;
						 end
				endcase
		    	      end
		    Estado_8: begin
		    	       	case(RI)
					STA,LDA,AND,SUB,ORA,ADD: begin
						PC<=PC;
						RDR<=PC;
					     end
					     //se agrego la instruccion ANDind a este caso
					LDAind,SUBind,ADDind,ORAind,STAind,ANDind: begin
						  PC<=PC;
						  RDR<=RDR+16'b1;
						  PB<=BUSDAT;
						end
					JSR,JSRind: begin
					     	PC<=PC+16'b1;
						RDR<=RDR+16'b1;
						PB<=BUSDAT;
					     end
					default: begin
						   PC<=PC;
						   RDR<=RDR;
						 end
				endcase
			      end
		    Estado_9: begin
		    	        PC<=PC;
				RDR<=RDR;
			      end
		    Estado_10: begin
		    	         case(RI)
				 JMPind,JSR,JSRind: begin
				 	   PC<={BUSDAT,PB};
					   RDR<={BUSDAT,PB};
					 end
				 default: begin
				 	   PC<=PC;
					   RDR<={BUSDAT,PB};
					  end
				 endcase
			       end
		    Estado_11: begin
				   PC<=PC;
				   RDR<=RDR;
			      end
		    Estado_12: begin
		    	         case(RI)
				 JSRind: begin
				 	  PB<=BUSDAT;
					  PC<=PC;
					  RDR<=RDR+16'b1;
				 	 end
				 default: begin 
				   PC<=PC;
				   RDR<=PC; 
				   PB<=PB;
				 end
				 endcase
			       end
		    Estado_13: begin
				   PC<=PC;
				   RDR<=RDR;
			      end
		    Estado_14: begin
		    	       	   PC<={BUSDAT,PB};
				   RDR<={BUSDAT,PB};
				   PB<=PB;
			       end
		    Estado_15: begin
		    	       	PC<=PC;
				RDR<=!SDMA ? 16'bz:PC;
				PB<=PB;
			       end
		    Estado_16: begin
		    	       	PC<=PC;
				RDR<= !SDMA ? 16'bz:PC;
				PB<=PB;
			       end
		    Estado_17: begin
		    	          PC<=PC;
				  RDR<={8'hFF,P};
				  PB<=PC[15:8];
			       end
		    Estado_18: begin
		    	      	 PC<=PC;
				 PB<=PB;
				 RDR<=RDR;
			      end
		   Estado_19: begin
		    	      	 PC<=PC;
				 RDR<={8'hFF,P};
				 PB<=PC[7:0];
			      end 
		   Estado_20: begin
		    	      	 PC<=PC;
				 RDR<=RDR;
				 PB<=PB;
			      end 
	           Estado_21: begin
		    	      	 PC<=PC;
				 RDR<=16'hFF00;
				 PB<=PB;
			      end 		      
		   Estado_22: begin
		    	      	 PC<=PC;
				 RDR<=RDR;
				 PB<=BUSDAT;
			      end 
	           Estado_23: begin
		    	      	 PC<=PC;
				 RDR<=16'hFF01;
				 PB<=PB;
			      end
		   Estado_24: begin
		   		PC<=PC;
				RDR<=RDR;
				PB<=PB;
		   	      end
		   Estado_25: begin
		    	      	 PC<={BUSDAT,PB};
				 RDR<={BUSDAT,PB};
				 PB<=PB;
			      end 

		    default: begin
		    		PC<=PC;
				RDR<=RDR;
				PB<=PB;
			     end
		  endcase
		end
	 end
endmodule

module reg_M(CLK,ProxEst,RI,M,RPS,SDMA);
	input CLK,RPS,SDMA;
	input [`MSB8:0] ProxEst,RI;
	output M;
	reg M;
	`include "estados.v"
	`include "Dec_Inst.v"

	always @(negedge CLK) begin
	  if(!RPS) M<=1'b0;
	  else begin
	  	case(ProxEst)
		  Estado_0: M<=1'b1;
		  Estado_1: M<=1'b1;
		  Estado_5:case(RI)
		  	     INP,OUT:M<=1'b0;
			     default: M<=1'b1;
			   endcase
		  Estado_6:case(RI)
		  	     INP,OUT:M<=1'b1;
			     default: M<=1'b1;
			   endcase
		  Estado_15: M <=1'bz;
		  Estado_16: M<= !SDMA ? 1'bz : 1'b1;
		  default: M<=1'b1;
		endcase
	  end
	end
endmodule

module reg_LE(CLK,EstPresente,RI,LE,RPS,SDMA);
        input CLK,RPS,SDMA;
        input [`MSB8:0] EstPresente,RI;
        output LE;
        reg LE;
        `include "estados.v"
        `include "Dec_Inst.v"
        always @(negedge CLK) begin
          if(!RPS) LE<=1'b1;
          else begin
          	case(EstPresente)
		 Estado_0: LE<=1'b1;
		 Estado_1: LE<=1'b1;
		 Estado_3: case(RI)
		 	     PHA,PHS: LE<=1'b0;
			     JSR: LE<=1'b0;
			     default: LE<=1'b1;
			   endcase
		 Estado_5: case(RI)
		 	     JSR,OUT:LE<=1'b0;
			     default: LE<=1'b1;
			   endcase
		 Estado_7: case(RI)
		 	     STA: LE<=1'b0;
			     default: LE<=1'b1;
			   endcase
		Estado_11: case(RI)
		 	     STAind: LE<=1'b0;
			     default: LE<=1'b1;
			   endcase
		Estado_15: LE<=1'bz;
		Estado_16: LE<=!SDMA ? 1'bz:1'b1;
		Estado_18: LE<=1'b0;
		Estado_20: LE<=1'b0;
		 default: LE<=1'b1;
		endcase
	       end
	end
endmodule

module reg_P(CLK,EstPresente,RI,RPS,P,A);
	input RPS,CLK;
	input [`MSB8:0] EstPresente,RI,A;
	output [`MSB8:0] P;
	reg [`MSB8:0] P;	
	`include "estados.v"
	`include "Dec_Inst.v"
	always@(negedge CLK)begin
		if(!RPS) P<=8'bx;
		else 
		begin
			case(EstPresente)
			  Estado_1: begin
			  		case(RI)
					TAP: P<=P;
					default: P<=P;
					endcase
			  	    end
			  Estado_2: begin
			  	    	case(RI)
					TAP: P<=A;
					RTS,RTI:P<=P-8'b1;
					default:P<=P;
					endcase
				    end
			  Estado_3:begin
			  	   	case(RI)
					 JSR: P<=P+8'b1;
					 RTS: P<=P-8'b1;
					 default:P<=P;
					endcase
				   end
			  Estado_4: begin
			   		case(RI)
					  PHA,PHS: P<=P+8'b1;
					  PLS,PLA,RTI: P<=P-8'b1;
					  default: P<=P;
					endcase
			  	    end
			  Estado_6: begin
			  	    	case(RI)
					  JSR: P<=P+8'b1;
					  RTS: P<=P-8'b1;
					  default: P<=P;
					endcase
				    end
		 	  Estado_18: begin
			  	     	P<=P+8'b1;
				     end
			  Estado_21: begin
			  		P<=P+8'b1;
			  	     end
			  default: P<=P;
			endcase
		end
	end
endmodule

module reg_HLT(EstPresente,RPS,CLK,HALT);
	input RPS,CLK;
	input [`MSB8:0] EstPresente;
	output HALT;
	reg HALT;
	`include "estados.v"
	`include "Dec_Inst.v"
	always@(negedge CLK) begin
		if(!RPS) HALT<=1'b0;
		 else begin
	     		case(EstPresente)
	     	 	Estado_30:HALT<=1'b1;
			Estado_31:HALT<=~HALT;
	         	default: HALT<=1'b0;
	         	endcase
		end
	end
endmodule
