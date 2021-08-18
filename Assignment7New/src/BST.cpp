/*
 * BST.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: hp
 */

#include<iostream>
#include<cstdlib>
#include<queue>

#include "BST.h"

using namespace std;

BST::BST() {
	// TODO Auto-generated constructor stub
	root=NULL;
}

//--------------------------definition of creation of node-------------------------------
Node* BST::create(int num){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=num;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
//-------------------------definition of method to insert new node------------------------
bool BST::insert(int num){
	Node* newNode=create(num);
	if(root==NULL)
		root=newNode;
	else{
		Node*temp=root,*parent;
		while(temp!=NULL){
			parent=temp;
			if(temp->data == newNode->data)
				return false;
			if(newNode->data < temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(newNode->data < parent->data)
			parent->left=newNode;
		else
			parent->right=newNode;
	}
	return true;
}
//---------------------------------definition of getRoot method--------------------------------------
Node* BST::getRoot(){
	return root;
}
//---------------------------------definition of inorder traversal----------------------------------
void BST::inorder(Node* temp){
	if(temp==NULL)
		return;
	inorder(temp->left);
	cout<<temp->data<<" || ";
	inorder(temp->right);
}
//---------------------------------definition of preorder traversal------------------------------------
void BST::preorder(Node*temp){
	if(temp==NULL)
		return;
	cout<<temp->data<<" || ";
	preorder(temp->left);
	preorder(temp->right);
}
//---------------------------------definition of postorder travesal-------------------------------------
void BST::postorder(Node*temp){
	if(temp==NULL)
		return;
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" || ";
}
//---------------------------------definition of search -------------------------------------------------
bool BST::search(Node*temp,int num){
	while(temp!=NULL)
	{
		if(num < temp->data)
			temp=temp->left;
		else if(num > temp->data)
			temp=temp->right;
		else
			return true;
	}
	return false;
}
//-------------------------------definition of delete--------------------------------------------------------
Node* BST::deleteNode(Node*T,int num){

	if(T==NULL)
		return T;
	//if num is smaller than temp node
	if(num < T->data)
		T->left=deleteNode(T->left,num);
	//if num is greater than temp node
	else if(num > T->data)
		T->right=deleteNode(T->right,num);
	//
	else{
		Node*temp=T;
		//if node to be deleted is leaf node or node with one child
		if(T->left==NULL){
			T=T->right;
			free(temp);
			return T;
		}
		else if(T->right==NULL){
			T=T->left;
			free(temp);
			return T;
		}
		//if node has 2 children
		temp=findMin(T->right);
		T->data=temp->data;
		T->right=deleteNode(T->right,temp->data);


	}

	return T;
}
//------------------------definition of function to find min value------------------------------------------------------
Node* BST::findMin(Node*temp){
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}
//----------------------------definition of depth method-----------------------------------------------------------------
int BST::treeDepth(Node*temp){
	if(temp==NULL)
		return 0;
	return 1+ max(treeDepth(temp->left),treeDepth(temp->right));
}
//-----------------------definition of mirror image method-----------------------------------------------------------
void BST::mirrorImg(Node*temp){
	if(temp==NULL)
		return;
	Node*T=temp->left;
	temp->left=temp->right;
	temp->right=T;
	mirrorImg(temp->left);
	mirrorImg(temp->right);
}
//-----------------------definition of crete copy method----------------------------------------------------------
Node* BST::createCopy(Node* temp){
	if(temp==NULL)
		return NULL;
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=temp->data;
	newNode->left=createCopy(newNode->left);
	newNode->right=createCopy(newNode->right);
	return newNode;
}
//----------------------definition to display leaf nodes-----------------------------------------------------------
void BST::printLeafNode(Node*temp){
	if(temp==NULL)
		return;
	if(temp->left==NULL && temp->right==NULL)
		cout<<temp->data<<" ";
	if(temp->left!=NULL)
		printLeafNode(temp->left);
	if(temp->right!=NULL)
		printLeafNode(temp->right);

}
//---------------------definition of display parent child-----------------------------------------------------------
void BST::printParentChild(Node*temp){
	if(temp==NULL)
		return;
	if(temp->left || temp->right)
	{
		cout<<"\tParent:"<<temp->data;
		cout<<"Child:";
		if(temp->left)
			cout<<temp->left->data<<" ";
		if(temp->right)
			cout<<temp->right->data<<" "<<endl;
		printParentChild(temp->left);
		printParentChild(temp->right);
	}
}
//---------------------------definition of level wise display-------------------------------------------------------------
void BST::printLevelWise(){
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		Node* current=q.front();
		q.pop();
		if(current==NULL){
			q.push(NULL);
			cout<<"\n";
		}
		else{
			if(current->left)
				q.push(current->left);
			if(current->right)
				q.push(current->right);
			cout<<current->data<<" ";
		}
	}

}
BST::~BST() {
	// TODO Auto-generated destructor stub
}

