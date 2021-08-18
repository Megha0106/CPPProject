/*
 * StackAdt.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: hp
 */
#include<iostream>
#include<cstdlib>
#include "StackAdt.h"
using namespace std;

template <class T1>
StackAdt<T1>::StackAdt() {
	top=NULL;
}
template <class T1>
void StackAdt<T1>::push(T1 a)
{
	Node<T1>*ptr=new Node<T1>;
	ptr->data=a;
	ptr->next=NULL;
	if(top==NULL)
	{
		top=ptr;
	}
	else{
		ptr->next=top;
		top=ptr;
	}
	cout<<"Inserted successfully"<<endl;
}
template <class T1>
T1 StackAdt<T1>::pop(){

	int x=top->data;
	top=top->next;
	free(top->next);
	return x;
}
template <class T1>
void StackAdt<T1>::display(){
	Node<T1>*ptr=new Node<T1>;
	ptr=top;
	while(ptr!=NULL){
		cout<<"|"<<ptr->data<<"|"<<endl;
		ptr=ptr->next;
	}
}
template <class T1>
StackAdt<T1>::~StackAdt() {

}

