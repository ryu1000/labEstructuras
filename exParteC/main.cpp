#include "abtree.hpp"

int main(){
	ABTree<2,4,int> T;
	for(int i=0;i<=20;++i){
		cout << i << "," << T.search(i) << endl;
	}
	return 0;
}
	
