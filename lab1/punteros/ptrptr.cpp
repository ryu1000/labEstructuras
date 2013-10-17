#include <iostream>
using namespace std ;
#define SIZE 25

void dar_memoria_puntero ( int *mi_arreglo ) {
	mi_arreglo=new int[ SIZE ] ;
	for( int i=0; i<SIZE ; i++ ) {
		mi_arreglo[ i ]= i ;
	}
	cout << "Segun la funcion dar_memoria_puntero el arreglo contiene: " <<endl ;
	for( int i=0; i<SIZE ; i++ ) {
		cout << i << "-) " << mi_arreglo[ i ] << endl ;
	}
}

void dar_memoria_doble_puntero ( int **mi_arreglo ) {
	(*mi_arreglo)=new int[ SIZE ] ;
	for( int i=0; i<SIZE ; i++ ) {
		( *mi_arreglo )[ i ]= i ;
	}
	cout << "Segun la funcion dar_memoria_doble_puntero el arreglo contiene " <<endl ;
	for( int i=0; i<SIZE ; i ++ ) {
		cout << i << "-) " <<(* mi_arreglo )[ i ] << endl ;
	}
}

int main(){
	int *ptr_arreglo ;
	// Prueba de necesidad de dobles punteros
	/*dar_memoria_puntero ( ptr_arreglo ) ;
	cout << "\n\n\nDespues de la funcion dar_memoria_puntero el arreglo contiene " <<endl ;
	for( int i=0; i<SIZE ; i++ ) {
		cout << i << "-) " << ptr_arreglo[i] << endl ;
	}*/
	dar_memoria_doble_puntero (&ptr_arreglo) ;
	cout << "\nDespues de la funcion dar_memoria_doble_puntero el arreglo contiene " <<endl ;
	for( int i=0; i<SIZE ; i++ ) {
		cout << i << "-) " << ptr_arreglo[ i ] << endl ;
	}
}
