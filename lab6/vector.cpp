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
    
int main(){
	vector<float> v;
	readFile("vector.txt",v);
	int i=0;
	for(vector<float>::iterator it=v.begin(); it!=v.end();++it){
		cout<<v[i]<<endl;
		i++;
	}
	return 0;
}
