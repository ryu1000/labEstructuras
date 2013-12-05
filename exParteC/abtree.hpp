#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>

using namespace std;

template <int A,int B,class T>
struct ABNode{
	vector<T> node_keys;
	map<T,ABNode<A,B,T>* > node_children;
	ABNode<A,B,T>* parent_node;
};

template <int A,int B,class T>
class ABTree{
	public:
		bool search(T);
		void insert(T);
		ABTree();
		~ABTree();
	
	private:
		ABNode<A,B,T>* root;
		bool recursive_search(T,ABNode<A,B,T>*);
		void split(ABNode<A,B,T>*);
		ABNode<A,B,T>* getParent(ABNode<A,B,T>*);
		ABNode<A,B,T>* lastVisited;
		void insertKey(T,ABNode<A,B,T>*);
		void insertChild(T,ABNode<A,B,T>*,ABNode<A,B,T>*);
};

template <int A,int B,class T>
ABTree<A,B,T>::ABTree(){
	root = new ABNode<A,B,T>;
	root->parent_node=root;
	cout << A << "-" << B << " tree created" << endl;
	
	T imax = std::numeric_limits<T>::max(); //sentry key
	
	ABNode<A,B,T>* nodo1 = new ABNode<A,B,T>;
	ABNode<A,B,T>* nodo2 = new ABNode<A,B,T>;
	ABNode<A,B,T>* nodo3 = new ABNode<A,B,T>;
	ABNode<A,B,T>* nodo4 = new ABNode<A,B,T>;
	ABNode<A,B,T>* nodo5 = new ABNode<A,B,T>;
	ABNode<A,B,T>* nodo6 = new ABNode<A,B,T>;
	ABNode<A,B,T>* nodo7 = new ABNode<A,B,T>;
	
	//nodo raiz
	root->node_keys.push_back(12);
	root->node_keys.push_back(imax);
	root->node_children.insert(pair<T,ABNode<A,B,T>*>(12,nodo1));
	root->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,nodo2));
	
	//nodo 1
	nodo1->node_keys.push_back(5);
	nodo1->node_keys.push_back(10);
	nodo1->node_keys.push_back(imax);
	nodo1->node_children.insert(pair<T,ABNode<A,B,T>*>(5,nodo3));
	nodo1->node_children.insert(pair<T,ABNode<A,B,T>*>(10,nodo4));
	nodo1->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,nodo5));
	
	//nodo 2
	nodo2->node_keys.push_back(15);
	nodo2->node_keys.push_back(imax);
	nodo2->node_children.insert(pair<T,ABNode<A,B,T>*>(15,nodo6));
	nodo2->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,nodo7));
	
	//nodo 3
	nodo3->node_keys.push_back(3);
	nodo3->node_keys.push_back(4);
	nodo3->node_keys.push_back(imax);
	nodo3->node_children.insert(pair<T,ABNode<A,B,T>*>(3,new ABNode<A,B,T>));
	nodo3->node_children.insert(pair<T,ABNode<A,B,T>*>(4,new ABNode<A,B,T>));	
	nodo3->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,new ABNode<A,B,T>));
	
	//nodo 4
	nodo4->node_keys.push_back(6);
	nodo4->node_keys.push_back(7);
	nodo4->node_keys.push_back(8);
	nodo4->node_keys.push_back(imax);
	nodo4->node_children.insert(pair<T,ABNode<A,B,T>*>(6,new ABNode<A,B,T>));
	nodo4->node_children.insert(pair<T,ABNode<A,B,T>*>(7,new ABNode<A,B,T>));
	nodo4->node_children.insert(pair<T,ABNode<A,B,T>*>(8,new ABNode<A,B,T>));
	nodo4->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,new ABNode<A,B,T>));
	
	//nodo 5
	nodo5->node_keys.push_back(11);
	nodo5->node_keys.push_back(imax);
	nodo5->node_children.insert(pair<T,ABNode<A,B,T>*>(11,new ABNode<A,B,T>));
	nodo5->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,new ABNode<A,B,T>));
	
	//nodo 6
	nodo6->node_keys.push_back(13);
	nodo6->node_keys.push_back(14);
	nodo6->node_keys.push_back(imax);
	nodo6->node_children.insert(pair<T,ABNode<A,B,T>*>(13,new ABNode<A,B,T>));
	nodo6->node_children.insert(pair<T,ABNode<A,B,T>*>(14,new ABNode<A,B,T>));
	nodo6->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,new ABNode<A,B,T>));
	
	//nodo 7
	nodo7->node_keys.push_back(17);
	nodo7->node_keys.push_back(imax);
	nodo7->node_children.insert(pair<T,ABNode<A,B,T>*>(17,new ABNode<A,B,T>));
	nodo7->node_children.insert(pair<T,ABNode<A,B,T>*>(imax,new ABNode<A,B,T>));	
}

template <int A,int B,class T>
ABTree<A,B,T>::~ABTree(){
	cout << A << "-" << B << " tree destroyed" << endl;
}

template <int A,int B,class T>
bool ABTree<A,B,T>::search(T key){
	if(root->node_keys.empty()==true){
		lastVisited = root;
		return false;
	}
	else{
		int i = 0;
		while(true){
			if(key==root->node_keys[i]){
				lastVisited = root;
				return true;
			}
			else if(key<root->node_keys[i]){
				int child_key = root->node_keys[i];
				return(recursive_search(key,root->node_children[child_key]));
			}
			i++;
		}	
	}
}

template <int A,int B,class T>
bool ABTree<A,B,T>::recursive_search(T key,ABNode<A,B,T>* child){
	lastVisited = child;
	if(child->node_keys.empty()==true){
		return false;
	}
	else{
		int i=0;
		while(true){
			if(key==child->node_keys[i]){
				return true;
			}
			else if(key<child->node_keys[i]){
				int child_key = child->node_keys[i];
				return(recursive_search(key,child->node_children[child_key]));
			}
			i++;
		}
	}
}

template <int A,int B,class T>
void ABTree<A,B,T>::insert(T key){
	bool res;
	ABNode<A,B,T>* parent;
	res = search(key);
	if(res == true){
		cout << "attempt to duplicate key:" << endl;
		cout << "value not inserted" << endl;
	}
	else{
		parent = getParent(lastVisited);
		insertKey(key,parent);
		insertChild(key,lastVisited,parent);
	}
}

template <int A,int B,class T>
ABNode<A,B,T>* ABTree<A,B,T>::getParent(ABNode<A,B,T>* child){
	ABNode<A,B,T>* parent;
	parent = child->parent_node;
	return parent;
}

template <int A,int B,class T>
void ABTree<A,B,T>::insertKey(T key,ABNode<A,B,T>* node){
	node->node_keys.push_back(key);
	sort(node->node_keys.begin(),node->node_keys.end());
}

template <int A,int B,class T>
void ABTree<A,B,T>::insertChild(T key,ABNode<A,B,T>* child,ABNode<A,B,T>* node){
	node->node_children.insert(pair<T,ABNode<A,B,T>* >(key,child));
}
