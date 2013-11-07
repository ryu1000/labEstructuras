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
	
	cout << st.size() << endl;
	
	for (int i = 0; i <= (int)st.size(); ++i){
		cout << st.top();
		st.pop();
	}
	
	
}

int main(){
	multibase(75,8);
	return 0; 
}
