# include "mipila.hh"

int main (){
	MiPila mi_pila;
	float cuenta=0;
	float resultado;
	
	for( float i=1; i<10000000; ++i ){
		mi_pila.push(i);
		cuenta+=1;
	}
	
	while(cuenta>=1){
	resultado=mi_pila.pull();
	cuenta-=1;
	}

	cout << "El valor al fondo de la pila es: " << resultado;
	cout << endl;
	
	return 0;
}

