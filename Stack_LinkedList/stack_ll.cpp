/*
 * stack_ll.cpp
 *
 *  Created on: Sep 23, 2020
 *      Author: Megha Sonavane
 */
#include<iostream>
#include <cstdlib>
using namespace std;
struct student
{
	int rno;
	string name;
	int credit[5];
	int grade[5];
	double sgpa;
	struct student* next;
};
//class declaration
class Student_Class
{
private:
	struct student* top;
public:
	Student_Class(){
		top=NULL;
	}
	void push();
	void input(student*);
	void pop();
	void display();
};
//----------------------definition of push--------------------------------------
void Student_Class::push(){
	struct student *ptr=(struct student*)malloc(sizeof(struct student));
	input(ptr);
	if(top==NULL)
	{
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	cout<<"Successfully inserted....."<<endl;
}
//------------------------------------input method-------------------------------
void Student_Class::input(student*ptr){
	cout<<"Enter details of student->"<<endl;
	cout<<"Roll Number:";
	cin>>ptr->rno;
	cin.ignore();
	cout<<"Name:";
	getline(cin,ptr->name);
	cout<<"SGPA:";
	cin>>ptr->sgpa;
	ptr->next=NULL;
}
//-----------------------------------definition of pop-------------------------------------
void Student_Class::pop()
{
	if(top==NULL)
		cout<<"Underflow condition...."<<endl;
	else{
		struct student*ptr=new struct student;
		ptr=top;
		top=top->next;
		free(ptr);
		cout<<"Deleted successfully..."<<endl;
	}
}
//--------------------------------definition of display--------------------------------------
void Student_Class::display()
{
	if(top==NULL)
		cout<<"No records available..."<<endl;
	else
	{
		struct student*ptr=new struct student;
		ptr=top;
		cout<<"Roll No.\tName\tSGPA"<<endl;
		while(ptr!=NULL)
		{
			cout<<ptr->rno<<"\t"<<ptr->name<<"\t"<<ptr->sgpa<<endl;
			ptr=ptr->next;
		}
	}
}
//--------------------------------driver function-----------------------------------------------------
int main()
{
	Student_Class s;
	int ch;
	do
	{
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"1:Push"<<endl<<"2:Pop"<<endl<<"3:Display"<<endl<<"4:Exit"<<endl;
		cout<<"Enter choice:";
		cin>>ch;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		switch(ch)
		{
		case 1:
			s.push();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.display();
			break;
		case 4:
			cout<<"Thank you..."<<endl;
			break;
		}
	}while(ch!=4);
	return 0;
}



