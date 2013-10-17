#include "mifigura.hh"

MiFigura::MiFigura( string miNombre ) {
	this->nombre = miNombre; // this es el equivalente a self en Python
	cout << "Ejecutando el Constructor de MiFigura\n\n" << endl;
}

MiFigura::~MiFigura(void) {
	cout << "El Destructor de " << nombre << " dice adios " << endl;
}

bool MiFigura::dibujar() {
	cout << "dibujando " << nombre << endl;
	return true;
}

bool MiFigura::mover() {
	cout << "moviendo " << nombre << endl;
	return true;
}

bool MiFigura::borrar() {
	cout << "borrando " << nombre << endl ;
	return true;
}
