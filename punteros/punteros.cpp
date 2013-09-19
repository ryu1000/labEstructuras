#include <iostream>

using namespace std;

void square ( int n ) {
	n = n*n ;
	cout << "Segun la funcion void square ( int n ) el valor de numero es: " << n <<endl ;
}

void square ( int *ptr_n ) {
	*ptr_n = *ptr_n * *ptr_n;
	cout << "Segun la funcion void square ( int *ptr_n ) el valor de numero es: " << *ptr_n << endl ;
}

int main ( void ) {
	int numero = 10 , *ptr_num ;

	// Paso de parametros por valor
	cout << "El valor de la variable numero antes de la funcion void square ( int ) es : " <<numero<<endl ;
	square ( numero ) ;
	cout << "El valor de la variable numero despues de la funcion void square ( int )   es : " <<numero<<endl ;

	// Paso de parametros por referencia
	cout << " \nEl valor de la variable numero antes de la funcion void square (* int ) es : " <<numero<<endl ;
	square (&numero ) ;
	cout << "El valor de la variable numero despues de la funcion void square (* int ) es : " <<numero<<endl ;

	// Se puede manejar con punteros
	ptr_num=&numero ;
	cout << "\nEl valor de la variable numero antes de la funcion void square (* int ) es : " <<*ptr_num <<endl ;
	square ( ptr_num ) ;
	cout << "El valor de la variable numero despues de la funcion void square (* int ) es : " <<*ptr_num <<endl ;
}
