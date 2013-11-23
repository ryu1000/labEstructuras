#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int array[] = {0,1,1,2,2,2,3};
	vector<int> v (7);
	
	copy(array,array+7,v.begin());
	
	vector<int>::iterator p1;
	vector<int>::iterator p2;
	vector<int>::iterator find;
	
	p1 = v.begin();
	p2 = v.end();
	
	while(p1!=p2){
		//cout << "*p1 = " << *p1 << " y *p2 = " << *(p2-1) << endl;
		find = adjacent_find(p1,p2);
		//cout <<*find << endl;
		if (find!=p1 && find!=v.end()){
			cout << *(find-1) << endl;
			cout << *find << " " << *(find+1) << " ";
			//cout << "caso 1"<<endl;
			p1+=3; 
		}
		else if (find==p1 && find!=v.end()){
			cout << endl;
			cout << *find << " " << *(find+1) << " ";
			//cout << "caso 2"<<endl;
			p1+=2;
		}
		else if (find==v.end()){
			if (*p1==*(p1-1)){
				cout << *p1;
				//cout << "caso 3"<<endl;
			}
			else{
				cout << endl;
				cout << *p1 << endl;
				//cout << "caso 4"<<endl;
			}
			p1+=1;
		}
	}
	
	
	//for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
	//cout <<*it << endl;
	
	cout << endl;
	
	return 0;
}
		
		
