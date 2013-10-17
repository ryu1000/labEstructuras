OBJS = principal.cpp mifigura.o circulo.o mitriangulo.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
TARGET = principal

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

mifigura.o : mifigura.hh mifigura.cpp
	$(CC) $(CFLAGS) mifigura.cpp

circulo.o : mifigura.hh circulo.hh circulo.cpp
	$(CC) $(CFLAGS) circulo.cpp

mitriangulo.o : mifigura.hh mitriangulo.hh mitriangulo.cpp
	$(CC) $(CFLAGS) mitriangulo.cpp
	
clean:
	rm -f *.o $(TARGET)
