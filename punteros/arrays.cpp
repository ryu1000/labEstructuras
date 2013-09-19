#include <iostream>

using namespace std;

void cambiar(int array[]){
	for(int i=0;i<10;++i){
		array[i]*=10;
	}
}

int main ( void ) {
	int *ptr_arreglo ;
	int arreglo [] = { 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 } ;

	// Arreglos vs punteros
	cout << "\n\n\nEl arreglo contiene los datos: " <<endl ;
	for ( int i=0; i<10; ++i ){
		cout << i << "-) " << arreglo[i] << endl ;
	}
	cout << "\n\n\nEl arreglo, despues de la funcion cambiar, "; 
	cout << "contiene los datos: " <<endl ;
	cambiar( arreglo ) ;
	for ( int i=0; i<10; ++i ) {
		cout << i << "-) " << arreglo[i] << endl ;
	}
	cout << "\n\n\n" ;
	
	// Y que tal con un puntero
	ptr_arreglo = arreglo ;
	//arreglo = ptr_arreglo ;
	cout << "\n\n\nEl arreglo contiene los datos: " <<endl ;
	for ( int i=0; i<10; ++i ){
		cout << i << "-) " << arreglo[i] << endl ;
	}
	cout << "\n\n\nEl arreglo, despues de la funcion cambiar, "; 
	cout << "contiene los datos: " <<endl ; 
	cambiar( ptr_arreglo ) ;
	for ( int i=0; i<10; ++i ) {
		cout << i << "-) " << ptr_arreglo[i] << endl ;
	}
	cout << "\n\n\n" ;
}
	
