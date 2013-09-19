OBJS1 = main1.cpp matriz1.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -pedantic $(DEBUG)
LFLAGS = -Wall $(DEBUG)
TARGETS = main1.exe

all : $(TARGETS)

main1.exe : $(OBJS1)
	$(CC) $(LFLAGS) $(OBJS1) -o main1.exe

matriz1.o : matriz1.h matriz1.cpp
	$(CC) $(CFLAGS) matriz1.cpp

clean:
	rm -f *.o *.exe
