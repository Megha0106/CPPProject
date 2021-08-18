/*
 * StackAdt.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Megha Sonavane(23355)
 */
#include<iostream>
#include "StackAdt.h"

using namespace std;
template<typename T>
StackAdt<T>::StackAdt() {
	top=NULL;
}
//--------------------------------------definition of isEmpty-------------------------------------------------
template<typename T>
bool StackAdt<T>::isEmpty(){
	if(top==NULL)
		return true;
	return false;
}
//-----------------------------------definition of push method---------------------------------------------------
template<class T>
void StackAdt<T>::push(T symbol)
{
	Node<T>*ptr=new Node<T>;
	ptr->symbol=symbol;
	ptr->next=NULL;
	//if it is first node
	if(top==NULL)
	{
		top=ptr;
	}
	else{
		ptr->next=top;
		top=ptr;
	}
}
//------------------------------------definition of pop method--------------------------------------------------------------
template<class T>
T StackAdt<T>::pop(){
	T c=top->symbol;
	top=top->next;
	return c;
}
//-----------------------------------definition of peep method--------------------------------------------------------------
template<class T>
T StackAdt<T>::peep(){
	return top->symbol;
}
//-----------------------------------definition of display---------------------------------------------------------------
template<class T>
void StackAdt<T>::display(){
	Node<T>*temp;
	temp=top;
	while(temp!=NULL){
		cout<<temp->symbol;
		temp=temp->next;
	}

}
template<class T>
StackAdt<T>::~StackAdt() {
	// TODO Auto-generated destructor stub
}

