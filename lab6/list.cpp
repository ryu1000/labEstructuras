#include <iostream>
#include <list>
#include <string>

using namespace std;

template <class T>
string palin(list<T> L){
	//bool bandera=true;
	if (L.size()==1)
		return "True";
	else{
		//cout<<primero<<"\t"<<ultimo<<endl;
		while(L.size()>1){
			T primero=L.front();
			T ultimo=L.back();
			if(primero!=ultimo){
				return "False";
			}
			L.pop_front();
			L.pop_back();
		}
		return "True";
	}
}

template <class T>
string findLastOf(list<T> L, T valor){
	int contador=0;
	int posicion=0;
	typename list<T>::iterator it;
	for(it=L.begin();it!=L.end();++it){
		contador++;
		if(valor==(*it))
			posicion=contador;
	}
	if(posicion!=0){
	return ("La ultima ocurrencia de "+to_string(valor)+" esta en la posicion "
			+to_string(posicion));
	}
	else
	return ("end()");
}

template <class T>
string sequentialSearch(list<T> L, T valor){
	int contador=0;
	int posicion=0;
	typename list<T>::iterator it;
	for(it=L.begin();it!=L.end();++it){
		contador++;
		if(valor==(*it)){
			posicion=contador;
			return ("La primera ocurrencia de "+to_string(valor)+
			" esta en la posicion "+to_string(posicion));
		}
	}
	return ("end()");
}

template <class T>
bool isOnList(list<T> L, T valor){
	int contador=0;
	typename list<T>::iterator it;
	for(it=L.begin();it!=L.end();++it){
		contador++;
		if(valor==(*it)){
			return true;
		}
	}
	return false;
}

template <class T>
void removeDup(list<T> L){
	bool flag;
	list<T> out;
	
	typename list<T>::iterator it;
	
	for(it=L.begin();it!=L.end();++it){
		
		//cout << "*it " << *it << endl;
		
		flag=isOnList(out,*it);
		
		//cout << "flag " << flag << endl;
		
		if(flag==false){
			out.push_back(*it);
		}
	}
	cout << "Lista original:" << endl;
	cout << endl;
	
	for(it=L.begin();it!=L.end();++it){
		cout << *it << endl;
	}
	
	cout << "\nLista modificada:" << endl;
	cout << endl;

	for(it=out.begin();it!=out.end();++it){
		cout << *it << endl;
	}
}

int main(){
	list<int> L,L2,L3,L4;
	string resultado;
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
	cout<<"resultado L "+resultado<<endl;
	resultado=palin(L2);
	cout<<"resultado L2 "+resultado<<endl;
	resultado=palin(L3);
	cout<<"resultado L3 "+resultado<<endl;
	resultado=palin(L4);
	cout<<"resultado L4 "+resultado<<endl;
	
	
	cout<<findLastOf(L,0)<<endl;
	cout<<findLastOf(L,5)<<endl;
	cout<<findLastOf(L4,2)<<endl;
	cout<<findLastOf(L4,9)<<endl;
	cout<<sequentialSearch(L4,0)<<endl;
	cout<<sequentialSearch(L4,9)<<endl;
	cout<<sequentialSearch(L4,5)<<endl;
	
	removeDup(L4);
}
