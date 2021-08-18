/*
 * infix_to_postfix.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: hp
 */
#include<iostream>
#include "Stack.h"
using namespace std;
//------------------class declaration------------------------------------
class Exp_Convert{
	Stack s;
public:
	string infixToPostfix(string);
	bool isOperator(char);
	int precedence(char);
};
//-------------------------------definition of isOperator---------------------------------------------------------------------------------
bool Exp_Convert::isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		return true;
	return false;
}
//------------------------------definition to check precedence----------------------------------------------------------------------------
int Exp_Convert::precedence(char c)
{
	if(c=='^')
		return 3;
	if(c=='*'||c=='/')
		return 2;
	if(c=='+'||c=='-')
		return 1;
	return -1;
}
//-------------------------definition to convert infix to postfix----------------------------------------------------------------------
string Exp_Convert::infixToPostfix(string infix)
{
	string postfix="";
	int len=infix.length();
	int ip,sp;
	for(int i=0;i<len;i++)
	{
		//---------------1.If it is operand----------------
				if(isalpha(infix[i])){
					postfix+=infix[i];
				}
				//--------------2.if it is (-----------------------
				else if(infix[i]=='(')
					s.push(infix[i]);
				//---------------3.if is is )----------------------
				else if(infix[i]==')')
				{
					while(s.stack[s.top]!='('&&(!s.isEmpty()))
					{
						postfix+=s.pop();
					}
					if(s.stack[s.top]=='('){
						s.pop();
					}

				}
				//--------------4.it is operator----------------------
				else if(isOperator(infix[i])){
					ip=precedence(infix[i]); //precedence of operator in expression
					sp=precedence(s.stack[s.top]); //precedence of operator at top of stack
					//------if is first operator
					if(s.top==-1||s.stack[s.top]=='('){
						s.push(infix[i]);
					}

					//-------if precedence of operator in expression is greater than that of operator in stack
					else if(ip>sp)
					{
						s.push(infix[i]);
					}

					//-------if precedence of operator in stack is greater than or equal to that of operator in expression
					else{
							while((ip<=sp)&&(!s.isEmpty())){
								postfix+=s.pop();
								sp=precedence(s.stack[s.top]); //updating value of precedence of operator
						}
						s.push(infix[i]);
					}
				}
				else{
					cout<<"***Invalid expression***";
					exit(0);
				}
	}
	while(!s.isEmpty())
		postfix+=s.pop();
	return postfix;
}
int main()
{
	Exp_Convert obj;
	string infix;
	cout<<"Enter infix expression:";
	cin>>infix;
	string postfix=obj.infixToPostfix(infix);
	cout<<"Postfix="<<postfix;
	return 0;
}



