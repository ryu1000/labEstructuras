OBJS = main.cpp doble.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

doble.o: doble.hh doble.cpp
	$(CC) $(CFLAGS) doble.cpp

clean:
	rm -f *.o $(TARGET)
