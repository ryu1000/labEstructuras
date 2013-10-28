#include <iostream>
#include <list>

using namespace std;

template <class T>
bool palin(const list<T> &L){
	bool bandera=true;
	if (L.size()==1)
		return true;
	else{
		while(L.size()!=1){
			T primero=L.front();
			T ultimo=L.back();
			if(primero=!ultimo){
				bandera=false;
				break;
			}
			L.pop_front();
			L.pop_back();
		}
		return true;
	}
}

int main(){
	list<int> L;
	for(int i=0;i<=5;++i)
		L.push_back(i);
	for(int i=5;i<=0;--i)
		L.push_back(i);
	palin(L);
}
