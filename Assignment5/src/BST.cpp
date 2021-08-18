/*
 * BST.cpp
 *
 *  Created on: Nov 6, 2020
 *      Author: hp
 */
#include<iostream>
#include<cstdlib>
#include "BST.h"

using namespace std;

BST::BST() {
	root=NULL;

}
//--------------------getRoot()method-----------------------
Node* BST::getRoot(){
	return root;
}
//-------------------creation of node------------------------
Node* BST::create(int num){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=num;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
//---------------------inserting node to tree-------------------
void BST::insert(int num){
	Node*newNode=create(num);
	if(root==NULL){
		root=newNode;
		return;
	}
	else
	{
		Node*current=root;
		Node*parent;
		while(current!=NULL){
			parent=current;
			//1.If data to be inserted is smaller that current data, move to left
			if(newNode->data<current->data)
				current=current->left;
			//2.If data to be inserted is greater than current data, move to right
			else if(newNode->data>current->data)
				current=current->right;
			//else data is already present
			else{
				//cout<<"\t*****Do not enter duplicate elements..****"<<endl;
				return;
			}
		}
	}
}
//----------------------------inorder traversal--------------------------------------
void BST::inorder(Node*ptr){
	if(root==NULL){
		cout<<"\t****Tree is empty...****"<<endl;
		return;
	}
	inorder(ptr->left);
	cout<<ptr->data<<" ";
	inorder(ptr->right);

}

BST::~BST() {
	// TODO Auto-generated destructor stub
}

