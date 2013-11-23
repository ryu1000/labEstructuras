#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>

#define SIZE 50

using namespace std;

int main(){
	int enteros[SIZE];
	vector<int> venteros (SIZE);
	vector<int>::iterator it;
	
	srand(time(NULL));
	
	for(int i = 0;i<SIZE;++i){
		enteros[i] = 10 + rand() % 11;
	}
	
	copy(enteros, enteros+SIZE,venteros.begin());
	
	cout << "vector contains:"<< endl;
    for (vector<int>::iterator it = venteros.begin(); it!=venteros.end(); ++it)
		cout << *it << endl;
	
	cout<<endl;
	
	sort(venteros.begin(),venteros.end());
	
	cout << "sorted vector contains:"<< endl;
    for (vector<int>::iterator it = venteros.begin(); it!=venteros.end(); ++it)
		cout << *it << endl;
	
	cout<<endl;
	
	sort(venteros.begin(),venteros.end(),greater<int>());
	
	for (vector<int>::iterator it = venteros.begin(); it!=venteros.end(); ++it)
		cout << *it << endl;
	
	////////////////////// find adjacent ///////////////////////
	
	cout << endl;
	
	int par_anterior;
	int inicio = 1;	
	vector<int>::iterator p1;
	vector<int>::iterator p2;
	vector<int>::iterator find;
	
	p1 = venteros.begin();
	p2 = venteros.end();
	
	while(p1!=p2){
		find = adjacent_find(p1,p2); 
		
		if (find!=p1 && find!=venteros.end()){
			cout << *(find-1) << endl;
			cout << *find << " " << *(find+1) << " ";
			//cout << "caso 1 ";
			p1+=3;
			par_anterior = *find;
			inicio = 0; 
		}
		else if (find==p1 && find!=venteros.end()){
			//cout << "\n*find= " << *find << "y par_anterior= " << par_anterior << endl;
			if (inicio == 0 && *find != par_anterior)
				cout << endl;
			cout << *find << " " << *(find+1) << " ";
			//cout << "caso 2 ";
			p1+=2;
			par_anterior = *find;
			inicio = 0;
		}
		else if (find==venteros.end()){
			if (*p1==*(p1-1)){
				cout << *p1;
				//cout << "caso 3 ";
			}
			else{
				cout << endl;
				cout << *p1 << endl;
				//cout << "caso 4 ";
			}
			p1+=1;
		}
	}
	
	cout << endl;
	
	///////////////////////////////////////////////////////////////
	
	return 0;
}
