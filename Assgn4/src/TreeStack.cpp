/*
 * TreeStack.cpp
 *
 *  Created on: Oct 27, 2020
 *      Author: Meghas Sonavane
 */
#include<iostream>
#include "TreeStack.h"

TreeStack::TreeStack() {
	top=-1;

}
void TreeStack::Push(TreeNode* T){
	top=top+1;
	s[top]=T;

}
bool TreeStack::isEmpty(){
	if(top==-1)
		return true;
	return false;
}
TreeNode* TreeStack::pop(){
	TreeNode* T=new TreeNode;
	T=s[top];
	top=top-1;
	return T;

}
TreeNode* TreeStack::peek(){
	return s[top];
}
int TreeStack::getTop(){
	return top;
}

TreeStack::~TreeStack() {
	// TODO Auto-generated destructor stub
}

