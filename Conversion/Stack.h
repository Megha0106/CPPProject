/*
 * Stack.h
 *
 *  Created on: Oct 18, 2020
 *      Author: hp
 */

#ifndef STACK_H_
#define STACK_H_

/*
 * Stack.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
class Stack{

public:
	string stack;
	int top;
	bool isEmpty();
	void push(char);
	char pop();
	Stack()
	{
		top=-1;
	}
};
bool Stack::isEmpty(){
	if(top==-1)
		return true;
	return false;
}
void Stack::push(char c)
{
	top=top+1;
	stack[top]=c;
}
char Stack::pop(){
	char c=stack[top];
	top=top-1;
	return c;
}







#endif /* STACK_H_ */
