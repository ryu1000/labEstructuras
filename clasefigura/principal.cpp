#include "circulo.hh"
#include "mitriangulo.hh"

int main(){
	
	MiCirculo mi_circulo; // Se crea un objeto
	MiFigura *mi_figura=&mi_circulo; // Se define un puntero al objeto
	cout << "Aqui se maneja todo como un puntero base" << endl;
	
	mi_figura->mover();
	mi_figura->borrar();
	mi_figura->area();
	
	cout << "\nAqui se maneja directamente el objeto" << endl;
	
	mi_circulo.mover();
	mi_circulo.borrar();
	mi_circulo.area();
	
	MiTriangulo triangulo;
	MiFigura *pt_triangulo=&triangulo;
	
	triangulo.girarHorizontal();
	triangulo.girarVertical();
	
	cout << "Manejando triangulo con un puntero" << endl;
	
	pt_triangulo->girarHorizontal();
	pt_triangulo->girarVertical();
}
