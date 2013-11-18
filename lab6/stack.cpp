#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

template <class T>
void multibase(T n, T b){
	stack<T> st;
	int res;
	int quo;
	string mystr="";
	
	do {
		quo = n/b;
		res = n%b;
		st.push(res);
		n = quo;
	} while (quo != 0);
	
	//cout << st.size() << endl;
	
	while (!st.empty()){
		cout << st.top();
		st.pop();
	}
	
	cout << endl;
	
}

int main(){
	multibase(75,9);
	multibase(75,8);
	multibase(75,7);
	multibase(75,6);
	multibase(75,5);
	multibase(75,4);
	multibase(75,3);
	multibase(75,2);
	multibase(64,2);
	return 0; 
}
