#include "mipila.hh"

MiPila::MiPila(){
	primer_elemento=new T_celda;
	primer_elemento->proximo=0;
}

MiPila::~MiPila(){
	delete primer_elemento;
}

bool MiPila::push(int x){
	T_celda *ptaux;
	ptaux=new T_celda;
	
	ptaux->dato=x;
	ptaux->proximo=primer_elemento;
	primer_elemento=ptaux;	
	
	return true;
}

int MiPila::pull(){
	T_celda *ptaux;
	int valor;
	
	ptaux=primer_elemento;
	primer_elemento=ptaux->proximo;
	valor=ptaux->dato;
	delete ptaux;
	
	return valor;
}
	
	
