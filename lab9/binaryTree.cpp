#include <iostream>
#include <cstdlib>
#include "binaryTree.hh"

using namespace std;

template <class T>
binaryTreeType<T>::binaryTreeType()
{
root = NULL;
}

template <class T>
bool binaryTreeType<T>::isEmpty() const
{
return (root == NULL);
}

template <class T>
void binaryTreeType<T>::inorderTraversal() const
{
inorder(root);
}

template <class T>
void binaryTreeType<T>::preorderTraversal() const
{
preorder(root);
}

template <class T>
void binaryTreeType<T>::postorderTraversal() const
{
postorder(root);
}

template <class T>
int binaryTreeType<T>::treeHeight() const
{
return height(root);
}

template <class T>
int binaryTreeType<T>::treeNodeCount() const
{
return nodeCount(root);
}

template <class T>
int binaryTreeType<T>::treeLeavesCount() const
{
return leavesCount(root);
}

template <class T>
void binaryTreeType<T>::
inorder(binaryTreeNode<T> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template <class T>
void binaryTreeType<T>::
preorder(binaryTreeNode<T> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class T>
void binaryTreeType<T>::
postorder(binaryTreeNode<T> *p) const
{
	if (p != NULL)
	{
	postorder(p->llink);
	postorder(p->rlink);
	cout << p->info << " ";
	}
}

template <class T>
int binaryTreeType<T>::
height(binaryTreeNode<T> *p) const
{
if (p == NULL)
return 0;
else
return 1 + max(height(p->llink), height(p->rlink));
}

template <class T>
int binaryTreeType<T>::max(int x, int y) const
{
if (x >= y)
return x;
else
return y;
}

//falta nodeCount y leavesCount

template <class T>
int binaryTreeType<T>::leavesCount(binaryTreeNode<T> *p) const{
	if(p == NULL)      
		return 0;
	if(p->llink == NULL && p->rlink==NULL)     
		return 1;           
	else
		return getLeafCount(p->llink)+getLeafCount(p->rlink);     
}
	

template <class T>
void binaryTreeType<T>::copyTree
(binaryTreeNode<T>* &copiedTreeRoot,
binaryTreeNode<T>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new binaryTreeNode<T>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
} //end copyTree

template <class T>
void binaryTreeType<T>::destroy(binaryTreeNode<T>* &p)
{
if (p != NULL)
	{
	destroy(p->llink);
	destroy(p->rlink);
	delete p;
	p = NULL;
	}
}

template <class T>
void binaryTreeType<T>::destroyTree()
{
destroy(root);
}

//copy constructor
template <class T>
binaryTreeType<T>::binaryTreeType
(const binaryTreeType<T>& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

//destructor
template <class T>
binaryTreeType<T>::~binaryTreeType()
{
destroy(root);
}

//overloading the assignment operator
template <class T>
const binaryTreeType<T>& binaryTreeType<T>::operator=
(const binaryTreeType<T>& otherTree)
{
	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL) //if the binary tree is not empty,
						  //destroy the binary tree
			destroy(root);
		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else
return *this;
}
