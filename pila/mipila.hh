#include <string>
#include <iostream>

#ifndef CLASEPILA
#define CLASEPILA

using namespace std;

typedef struct S_celda{
	int dato;
	S_celda *proximo;
} T_celda;

class MiPila{
	private:
	
	T_celda *primer_elemento;
	
	public:
	
	MiPila();
	~MiPila();
	bool push(int);
	int pull();
};

#endif
