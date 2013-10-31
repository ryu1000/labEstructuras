#include <iostream>
#include <list>

using namespace std;

template <class T>
bool palin(list<T> &L){
	//bool bandera=true;
	if (L.size()==1)
		return true;
	else{
		//cout<<primero<<"\t"<<ultimo<<endl;
		while(L.size()>1){
			T primero=L.front();
			T ultimo=L.back();
			if(primero!=ultimo){
				return false;
			}
			L.pop_front();
			L.pop_back();
		}
		return true;
	}
}

int main(){
	list<int> L,L2,L3,L4;
	bool resultado;
	for(int i=0;i<=5;++i){
		L.push_back(i);
		//cout<<i<<endl;
	}
	for(int i=5;i>=0;--i){
		L.push_back(i);
		//cout<<i<<endl;
	}
	for(int i=0;i<=5;++i){
		L2.push_back(i);
		//cout<<i<<endl;
	}
	L3.push_back(1);
	
	L4.push_back(0);
	L4.push_back(1);
	L4.push_back(2);
	L4.push_back(3);
	L4.push_back(4);
	L4.push_back(5);
	L4.push_back(4);
	L4.push_back(3);
	L4.push_back(2);
	L4.push_back(1);
	L4.push_back(0);	
	
	resultado=palin(L);
	cout<<"resultado L "<<resultado<<endl;
	resultado=palin(L2);
	cout<<"resultado L2 "<<resultado<<endl;
	resultado=palin(L3);
	cout<<"resultado L3 "<<resultado<<endl;
	resultado=palin(L4);
	cout<<"resultado L4 "<<resultado<<endl;
}
