all: vector.o list.o stack.o

	g++ -Wall -o vector.exe vector.o
	g++ -Wall -o list.exe list.o
	g++ -Wall -o stack.exe stack.o

vector.o : vector.cpp

	g++ -Wall -std=c++11 -c vector.cpp

list.o : list.cpp

	g++ -Wall -std=c++11 -c list.cpp

stack.o: stack.cpp

	g++ -Wall -c stack.cpp
