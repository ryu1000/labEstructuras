#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readFile(const char* filename, vector<float> &x){
	float data;
	string line;
	ifstream f("vector.txt");

	while (getline(f,line))
    {
      data=stof(line);
      //cout<<data<<endl;
      x.push_back(data);
	}
    f.close();
}

template <class T>
void join(vector<T> &x, vector<T> &y){
	int i=0;
	for(vector<float>::iterator it=y.begin(); it!=y.end();++it){
		x.push_back(y[i]);
		i++;
	}
}
    
int main(){
	vector<float> v1,v2;
	readFile("vector.txt",v1);
	readFile("vector.txt",v2);
	
	int i=0;
	for(vector<float>::iterator it=v1.begin(); it!=v1.end();++it){
		cout<<v1[i]<<endl;
		i++;
	}
		
	cout<<"*******************************"<<endl;
	
	join(v1,v2);

	
	i=0;
	for(vector<float>::iterator it=v1.begin(); it!=v1.end();++it,++i){
		cout<<v1[i]<<endl;
	}
	
	cout<<"*******************************"<<endl;
	
	while(v1.size()>0){
		cout<<v1.back()<<endl;
		v1.pop_back();
	}
	
	return 0;
}
