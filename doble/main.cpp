#include <iostream>
#include "doble.hh"

using namespace std;

int main(){
	float a;
	float b;
	a=110.154121354;
	b=doble(a);
	float c=b-a;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}
