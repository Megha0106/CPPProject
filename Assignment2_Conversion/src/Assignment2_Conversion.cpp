//============================================================================
// Name        : Assignment2_Conversion.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"StackAdt.h"
using namespace std;
//--------------------------class declaration-----------------------------------------

class Convert{

	StackAdt s;
public:
	bool isOperator(char);
	string toPostfix(string);
	string toPrefix(string);
	int precedence(char);
};
//-----------------------------definition of isOperator method---------------------------
bool Convert::isOperator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		return true;
	return false;
}
//----------------------------------definition to check precedence of operator----------------
int Convert::precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	return -1;
}
//--------------------------------------definition of method to convert expression into postfix-------------------
string Convert::toPostfix(string infix){
	string postfix="";
	int len=infix.length();
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Scan"<<"\t"<<"Stack"<<"\t"<<"Expression"<<endl;
	for(int i=0;i<len;i++)
	{
		//-----------1.If it is operand----------------------
		if(isalnum(infix[i]))
			postfix+=infix[i];
		//---------2.If it is (---------------------------
		else if(infix[i]=='(')
			s.push(infix[i]);
		//--------3.If it is )------------------------------
		else if(infix[i]==')')
		{
			while((s.peep()!='(')&&(!s.isEmpty()))
			{
				postfix+=s.pop();
			}
			if(s.peep()=='(')
				s.pop();
		}
		//-----------4.If it is operator
		else if(isOperator(infix[i]))
		{
			//----4.1.If stack is empty or contains ( at top---
			if((s.isEmpty())||(s.peep()=='('))
				s.push(infix[i]);
			//---4.2.If precedence of operator in expression is greater than that of operator in stack---
			else if(precedence(infix[i])>precedence(s.peep()))
				s.push(infix[i]);
			//---4.3. If the precedence of operator in expression is smaller than that of operator in stack---
			else{
				while((!s.isEmpty())&&( precedence(infix[i])<=precedence(s.peep())))
				{
					postfix+=s.pop();
				}
				s.push(infix[i]);
			}
		}
		//------------else the expression is invalid------------------------
		else{
			cout<<"\t***Invalid expression***"<<endl;
		}
		//-----------------display symbol scanned, current status of stack and expression------------------------
		cout<<infix[i]<<"\t";
		s.display();
		cout<<"\t"<<postfix<<endl;

	}
	while(!s.isEmpty())
		postfix+=s.pop();
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	return postfix;
}
//-------------------------------------------------definition of method to convert into prefix------------------------------
string Convert::toPrefix(string infix)
{
	string reverse="";
	string prefix="";
	int len=infix.length();
	for(int i=len-1;i>=0;i--)
	{
		if(infix[i]=='(')
			infix[i]=')';
		else if(infix[i]==')')
			infix[i]='(';
		reverse+=infix[i];
	}
	reverse=toPostfix(reverse);
	for(int i=reverse.length()-1;i>=0;i--)
		prefix+=reverse[i];
	return prefix;
}
//-------------------------------------------------driver function----------------------------------
int main() {

	Convert c;
	string infix,postfix,prefix;
	//StackAdt<char>s;
	cout<<"Enter infix expression:";
	cin>>infix;
	cout<<"\t******Postfix Conversion*****"<<endl;
	postfix=c.toPostfix(infix);
	cout<<"\t****Prefix Conversion****"<<endl;
	prefix=c.toPrefix(infix);
	cout<<"\tPostfix expression="<<postfix<<endl;
	cout<<"\tPrefix expression:"<<prefix;
	return 0;
}
