#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <class k,class x>
struct twofourNode{
	vector<k> node_keys;
	map<k,x> node_values;
	map<k,twofourNode<k,x>* > node_children;
	twofourNode<k,x>* parent_node;
};

template <class k,class x>
class twofourTree{
	public:
		bool search(k);
		void insert(k,x);
		twofourTree();
		~twofourTree();
	
	private:
		twofourNode<k,x>* root;
		bool recursive_search(k,twofourNode<k,x>*);
		void split(twofourNode<k,x>*);
		twofourNode<k,x>* getParent(twofourNode<k,x>*);
		twofourNode<k,x>* lastVisited;
		void insertKey(k,twofourNode<k,x>*);
		void insertValue(k,x,twofourNode<k,x>*);
		void insertChild(k,twofourNode<k,x>*,twofourNode<k,x>*);
};
