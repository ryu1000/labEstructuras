#include "24tree.hh" 

template <class k,class x>
twofourTree<k,x>::twofourTree(){
	root = NULL;
}

template <class k,class x>
twofourTree<k,x>::~twofourTree(){
}

template <class k,class x>
bool twofourTree<k,x>::search(k key){
	for(int i = 0;i<(int)root->node_keys.size();++i){
		if(key==root->node_keys[i]){
			return true;
		}
		else if(key<root->node_keys[i]){
			recursive_search(key,root->node_children[key]);
		}
	}	
}

template <class k,class x>
bool twofourTree<k,x>::recursive_search(k key,twofourNode<k,x>* child){
	for(int i = 0;i<(int)child->node_keys.size();++i){
		if(child->node_keys.empty()==true){
			return false;
		}
		else{
			if(key==child->node_keys[i]){
				return true;
			}
			else if(key<child->node_keys[i]){
				recursive_search(key,child->node_children[key]);
			}
		}
	}
}

template <class k,class x>
void twofourTree<k,x>::insert(k key,x value){
	bool res;
	res = search(key);
	if(res == true){
		cout << "attempt to duplicate key:" << endl;
		cout << "value not inserted" << endl;
	}
	else{
		
