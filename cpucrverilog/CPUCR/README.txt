#### clock.v ####

el modulo "clock" tiene solamente 1 salida llamada clk

#### memfinal.v ####

el modulo "memoria" recibe 3 parametros:

 -Direccion: bus de entrada de 16 bits
 -Datos: bus bidireccional de 8 bits
 -LE: linea de lectura/escritura (creo que en alto es lectura)

#### CPUCR_8bits_alterada.v ####

el modulo "CPUCR" tiene los siguientes parametros:

 Entradas:

 -CLK: reloj
 -INT: interrupcion
 -SDMA: acceso directo a memoria
 -RPS: reposicion
 -WAIT: espere

 Salidas:

 -BD: bus de datos libre
 -CB: ciclo de busqueda
 -CM: ciclo de memoria
 -LE: lectura/escritura
 -HALT: halt
 -INTOK: intok
 -M: memoria

 Buses:
 
 -BUSDIR: bus de direcciones (16 bits)
 -BUSDAT: bus de datos (8 bits)
