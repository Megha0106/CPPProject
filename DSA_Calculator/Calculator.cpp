/*
 * Title: Simple calculator
 * Created on: Jul 26, 2020
 * Author: Megha Sonavane
 * Roll No:23355
 */
#include<iostream>
#include<cmath>
using namespace std;
//function for addition
int add(int num1,int num2)
{
	return num1+num2;
}
//function for subtraction
int subtract(int num1,int num2)
{
	return num1-num2;
}
//function for multiplication
int multiply(float num1,float num2)
{
	float result=num1*num2;
	return(round(result));//result will be rounded by built in function
}
//function for division
float division(float num1,float num2)
{
	return(num1/num2);
}
int main()
{
	int choice,num1,num2,result;
	float num3,num4;
	do
	{
		//display menus to user
		cout<<"\n1:Addition\n2:Subtraction\n3:Multiplication\n4:Division\n5:Exit";
		cout<<"\nEnter choice:";//Enter choice of user
		cin>>choice;
		//switch user's choice
		switch(choice)
		{
			case 1:
				cout<<"\nEnter 2 numbers to be added:";
				cin>>num1>>num2;
				result=add(num1,num2);//calling addition function
				cout<<"\nAddition="<<result;
				break;
			case 2:
				cout<<"\nEnter 2 numbers to be subtract:";
				cin>>num1>>num2;
				result=subtract(num1,num2);//calling subtraction function
				cout<<"\nSubtraction="<<result;
				break;
			case 3:
				cout<<"\nEnter numbers to be multiply:";
				cin>>num3>>num4;
				result=multiply(num3,num4);//calling multiplication function
				cout<<"\nMultiplication="<<result;
				break;
			case 4:
				cout<<"\nEnter dividend and divisor:";
				cin>>num3>>num4;
				float quotient=division(num3,num4);//calling division function
				int rem=remainder(num3,num4);//calculate remainder using built in function
				cout<<"\nQuotient="<<quotient;
				cout<<"\nRemainder="<<rem;
				break;
		}
	}while(choice!=5);//if user's choice is 5,then exit the loop
	return 0;
}
