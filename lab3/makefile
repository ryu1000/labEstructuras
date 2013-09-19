OBJS1 = main1.cpp matriz1.o
OBJS2 = main2.cpp matriz2.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -pedantic $(DEBUG)
LFLAGS = -Wall $(DEBUG)
TARGETS = main1.exe main2.exe

all : $(TARGETS)

main1.exe : $(OBJS1)
	$(CC) $(LFLAGS) $(OBJS1) -o main1.exe

matriz1.o : matriz1.hh matriz1.cpp
	$(CC) $(CFLAGS) matriz1.cpp

main2.exe : $(OBJS2)
	$(CC) $(LFLAGS) $(OBJS2) -o main2.exe

matriz2.o : matriz2.hh matriz2.cpp
	$(CC) $(CFLAGS) matriz2.cpp

clean:
	rm -f *.o *.exe
