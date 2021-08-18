/*
 * TBT.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: hp
 */
#include<iostream>
#include<cstdlib>
#include "TBT.h"
using namespace std;

TBT::TBT() {
	// TODO Auto-generated constructor stub
	root=NULL;

}
//=================definition of getNode()================================
Node* TBT::getNode(int key){
	Node* T=new Node;
	T->data=key;
	T->lThread=true;
	T->rThread=true;
	return T;
}
//===============definition of insert()===================================
bool TBT::insert(int key){

	//if tree is not empty
	Node* parent=root;
	Node*ptr=root;
	while(ptr!=NULL){
		if(key==ptr->data)
		{
			return false;
		}
		parent=ptr;
		if(key < ptr->data)
		{
			if(ptr->lThread==false)
				ptr=ptr->left;
			else
				break;
		}
		else{
			if(ptr->rThread==false)
				ptr=ptr->right;
			else
				break;
		}

	}
	Node* newN=getNode(key);
	if(parent==NULL){
		root=newN;
		newN->left=NULL;
		newN->right=NULL;
	}
	else if(key<parent->data){
		newN->left=parent->left;
		newN->right=parent;
		parent->lThread=false;
		parent->left=newN;
	}
	else{
		newN->left=parent;
		newN->right=parent->right;
		parent->rThread=false;
		parent->right=newN;
	}
	return true;
}
//==============definition of leftmost()========================
Node* TBT::leftmost(Node* n){
	 if (n == NULL)
	       return NULL;

	    while (n->left != NULL)
	        n = n->left;

	    return n;
}
//=============inorder traversal================================
void TBT::inorder(){

	struct Node *cur = leftmost(root);
	    while (cur != NULL)
	    {
	       cout<<cur->data<<" ";

	        // If this node is a thread node, then go to
	        // inorder successor
	        if (cur->rThread)
	            cur = cur->right;
	        else // Else go to the leftmost child in right subtree
	            cur = leftmost(cur->right);
	    }
}
TBT::~TBT() {
	// TODO Auto-generated destructor stub
}

