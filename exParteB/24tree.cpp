#include "24tree.hh" 

template <class k,class x>
twofourTree<k,x>::twofourTree(){
	root = NULL;
	root->parent_node=root;
}

template <class k,class x>
twofourTree<k,x>::~twofourTree(){
}

template <class k,class x>
bool twofourTree<k,x>::search(k key){
	if(root->node_keys.empty()==true){
		lastVisited = root;
		return false;
	}
	else{
		for(int i = 0;i<(int)root->node_keys.size();++i){
			if(key==root->node_keys[i]){
				lastVisited = root;
				return true;
			}
			else if(key<root->node_keys[i]){
				recursive_search(key,root->node_children[key]);
			}
		}	
	}
}

template <class k,class x>
bool twofourTree<k,x>::recursive_search(k key,twofourNode<k,x>* child){
	lastVisited = child;
	if(child->node_keys.empty()==true){
		return false;
	}
	else{
		for(int i = 0;i<(int)child->node_keys.size();++i){
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
	twofourNode<k,x>* parent;
	res = search(key);
	if(res == true){
		cout << "attempt to duplicate key:" << endl;
		cout << "value not inserted" << endl;
	}
	else{
		parent = getParent(lastVisited);
		insertKey(key,parent);
		insertValue(key,value,parent);
		insertChild(key,lastVisited,parent);
	}
}

template <class k,class x>
twofourNode<k,x>* twofourTree<k,x>::getParent(twofourNode<k,x>* child){
	twofourNode<k,x>* parent;
	parent = child->parent_node;
	return parent;
}

template <class k,class x>
void twofourTree<k,x>::insertKey(k key,twofourNode<k,x>* node){
	node->node_keys.push_back(key);
	sort(node->node_keys.begin(),node->node_keys.end());
}

template <class k,class x>
void twofourTree<k,x>::insertValue(k key,x value,twofourNode<k,x>* node){
	node->node_values.insert(pair<k,x>(key,value));
}

template <class k,class x>
void twofourTree<k,x>::insertChild(k key,twofourNode<k,x>* child,twofourNode<k,x>* node){
	node->node_children.insert(pair<k,twofourNode<k,x>* >(key,child));
}
