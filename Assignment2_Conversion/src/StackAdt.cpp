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
//----------------------Implementation of stack---------------------------------------------------------------------

StackAdt::StackAdt() {
	top=NULL;

}
//--------------------------------------definition of isEmpty-------------------------------------------------
bool StackAdt::isEmpty(){
	if(top==NULL)
		return true;
	return false;
}
//-----------------------------------definition of push method---------------------------------------------------
void StackAdt::push(char c)
{
	struct stack*ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->symbol=c;
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

char StackAdt::pop(){
	char c=top->symbol;
	top=top->next;
	return c;
}
//-----------------------------------definition of peek method--------------------------------------------------------------
char StackAdt::peep(){
	return top->symbol;
}
//-----------------------------------definition of display---------------------------------------------------------------
void StackAdt::display(){
	struct stack*temp;
	for(temp=top;temp!=NULL;temp=temp->next)
		cout<<temp->symbol;


}

StackAdt::~StackAdt() {
	// TODO Auto-generated destructor stub
}

