#include "24tree.hpp"

int main(){
	twofourTree<int,int> T;
	bool s1,s2;
	T.insert(0,40);
	T.insert(1,30);
	s1 = T.search(0);
	s2 = T.search(1);
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
	
