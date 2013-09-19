OBJS1 = main1.cpp matriz1.o
OBJS2 = main2.cpp matriz2.o
OBJS3 = main3.cpp matriz3.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -pedantic $(DEBUG)
LFLAGS = -Wall $(DEBUG)
TARGETS = main1.exe main2.exe main3.exe

all : $(TARGETS)

main1.exe : $(OBJS1)
	$(CC) $(LFLAGS) $(OBJS1) -o main1.exe

matriz1.o : matriz1.hh matriz1.cpp
	$(CC) $(CFLAGS) matriz1.cpp

main2.exe : $(OBJS2)
	$(CC) $(LFLAGS) $(OBJS2) -o main2.exe

matriz2.o : matriz2.hh matriz2.cpp
	$(CC) $(CFLAGS) matriz2.cpp

main3.exe : $(OBJS3)
	$(CC) $(LFLAGS) $(OBJS3) -o main3.exe

matriz3.o : matriz3.hh matriz3.cpp
	$(CC) $(CFLAGS) matriz3.cpp

clean:
	rm -f *.o *.exe
