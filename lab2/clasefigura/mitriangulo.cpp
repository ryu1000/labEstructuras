#include "mitriangulo.hh"

MiTriangulo::MiTriangulo():MiFigura("triangulo"){}

bool MiTriangulo::girarHorizontal(){
	
	cout << "Se gira " << nombre << " horizontalmente" << endl;
	return true;
}

bool MiTriangulo::girarVertical(){
	
	cout << "Se gira " << nombre << " verticalmente" << endl;
	return true;
}
