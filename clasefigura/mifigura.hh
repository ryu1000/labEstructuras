#include <string>
#include <iostream>

#ifndef CLASE_FIGURA
#define CLASE_FIGURA

using namespace std;

class MiFigura {
	
	protected:
		string nombre;

	public:
		MiFigura( string miNombre );
		virtual ~MiFigura(void);
		bool dibujar(void);
		bool mover(void);
		bool borrar(void);
		virtual bool area(void) {
			cout << "Esto calculara el area de la figura " << endl;
			return true;
		}
		virtual bool perimetro(void) {
			cout << "Esto calculara el perimetro de la figura " << endl;
			return true;
		}
		virtual bool girarHorizontal(){
			cout << "Esto gira horizontal" << endl;
			return true;
		}
		virtual bool girarVertical(){
			cout << "Esto gira vertical" << endl;
			return true;
		}
};

#endif 
