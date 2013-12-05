CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main.exe : main.o main.cpp
	$(CC) $(LFLAGS) main.o -o main.exe

main.o : abtree.hpp main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o *.exe
