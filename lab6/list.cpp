#include <iostream>
#include <list>

using namespace std;

template <class T>
bool palin(const list<T> &L){
	if (L.size()==1)
		return true;
	else{
		T primero;
		T ultimo;
		primero=L.pop_front();
		ultimo=L.pop_back();		

int main(){
	list<int> L;
	for(int i=0;i<=5;++i)
		L.push_back(i);
	for(int i=5;i<=0;--i)
		L.push_back(i);
}
