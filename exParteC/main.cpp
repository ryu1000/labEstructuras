#include "abtree.hpp"

int main(){
	ABTree<2,4,int> T;
	bool s1 = T.search(12);
	cout << s1 << endl;
	bool s2 = T.search(5);
	cout << s2 << endl;
	bool s3 = T.search(3);
	cout << s3 << endl;
	return 0;
}
	
