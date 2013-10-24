#include <iostream>
#include <list>

using namespace std;

template <class T>
bool palin(const list<T> &L){
	if (L.size()==1)
		return true;
	else{
		while(L.size()!=1){
			T primero=L.pop_front();
			T ultimo=L.pop_back();
			/*if(primero=!ultimo)
				return false;*/
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
