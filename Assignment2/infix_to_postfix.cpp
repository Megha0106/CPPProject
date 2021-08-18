/*
 * infix_to_postfix.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
class Conversion{
private:
	string stack;
	int top;
public:
	Conversion(){
		top=-1;
	}
	void push(char);
	char pop();
	int precedence(char);
	string convert(string);
};
//----------------------------------definition of push----------------------------------------------------------
void Conversion::push(char c){
	top=top+1;
	stack[top]=c;
}
//------------------------------------definition of pop--------------------------------------------------------
char Conversion::pop(){
	char c=stack[top];
	top=top-1;
	return c;
}
//--------------------------------------definition to check precedence--------------------------------------
int Conversion::precedence(char c){
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return -1;
}
//-------------------------------------definition of conversion----------------------------------------
string Conversion::convert(string infix){
	string postfix="";
	int len=infix.length();
	int ip,sp;//to store precedence of operators
	cout<<len;//length of given infix expression
	for(int i=0;i<len;i++) //
	{
		//---------------1.If it is operand----------------
		if(isalpha(infix[i])){
			postfix+=infix[i];
		}
		//--------------2.if it is (-----------------------
		else if(infix[i]=='(')
			push(infix[i]);
		//---------------3.if is is )----------------------
		else if(infix[i]==')')
		{
			while(stack[top]!='('&&stack[top]!=-1)
			{
				postfix+=pop();
			}
			if(stack[top]=='('){
				pop();
			}

		}
		//--------------4.it is operator----------------------
		else{
			ip=precedence(infix[i]); //precedence of operator in expression
			sp=precedence(stack[top]); //precedence of operator at top of stack
			//------if is first operator
			if(top==-1||stack[top]=='('){
				push(infix[i]);
			}

			//-------if precedence of operator in expression is greater than that of operator in stack
			else if(ip>sp)
			{
				push(infix[i]);
			}

			//-------if precedence of operator in stack is greater than or equal to that of operator in expression
			else{
					while((ip<=sp)&&(top!=-1)){
						postfix+=pop();
						sp=precedence(stack[top]); //updating value of precedence of operator
				}
				push(infix[i]);
			}
		}
	}
	//------------------------remove all the elements from stack------------------------------------
	while(top!=-1)
		postfix+=pop();
	return postfix;
}
//-----------------------------------------driver function-------------------------------------------------------
int main(){
	Conversion c;
	string infix;
	cout<<"Enter infix expression:";
	getline(cin,infix);
	string postfix=c.convert(infix);
	cout<<"Postfix from main="<<postfix;
	return 0;
}



