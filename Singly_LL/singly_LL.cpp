/*
 * singly_LL.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: hp
 */
#include<iostream>
#include<cstdlib>
using namespace std;
class Student_class
{
private:
	struct student{
		int rno;
		char name[20];
		double sgpa;
		struct student*next;
	};
	struct student* head;
public:
	Student_class()
	{
		head=NULL;
	}
	bool isEmpty();
	void input(struct student*);
	void insert_begin();
	void insert_middle();
	void insert_end();
	void delete_begin();
	void delete_middle();
	void delete_end();
	void display();
};
//------------------definition to check list is empty-----------------------
bool Student_class::isEmpty()
{
	if(head==NULL)
		return true;
	return false;
}
//-----------------------definition of insert at beginning------------------------------------
void Student_class::insert_begin(){
	struct student *ptr=(struct student*)malloc(sizeof(struct student));
	input(ptr);
	if(isEmpty()) //if it is first node
	{
		ptr->next=NULL;
		head=ptr;
	}
	else{
		ptr->next=head;
		head=ptr;
	}
	cout<<"\t****Inserted successfully****"<<endl;
}
//-----------------------------------------definition of insert at end----------------------------------
void Student_class::insert_end()
{
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	input(ptr);
	if(isEmpty()) //if it is first node
	{
		ptr->next=NULL;
		head=ptr;
		cout<<"\t***List is empty...node is inserted at first..***"<<endl;
	}
	else{
		ptr->next=NULL;
		struct student*temp=head; //for locating last node in list
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
	}
	cout<<"\t****Inserted successfully****"<<endl;
}
//------------------------------------definition to insert at middle-------------------------
void Student_class::insert_middle(){
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	int temp_rno; //to store roll number of student temporary
	cout<<"Enter roll number of student after which new student to be added:"<<endl;
	cin>>temp_rno;
	struct student*temp=head;//for locating student
	while(temp->rno!=temp_rno&&temp!=NULL)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"Not present"<<endl;
	}
	else
	{
		input(ptr);
		ptr->next=temp->next;
		temp->next=ptr;
		cout<<"\t****Inserted successfully****"<<endl;
	}
}
//---------------------------------------------definition of input-----------------------------
void Student_class::input(struct student*ptr)
{
	cout<<"\t***Enter details:***"<<endl;
	cout<<"Roll no:";
	cin>>ptr->rno;
	cout<<"Name:";
	cin>>ptr->name;
	cout<<"SGPA:";
	cin>>ptr->sgpa;
}
//----------------------------------------------definition of delete at first-------------------
void Student_class::delete_begin(){
	if(isEmpty())
		cout<<"***List is empty***"<<endl;
	else
	{
		struct student *ptr=(struct student*)malloc(sizeof(struct student));
		ptr=head;
		head=head->next;
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<ptr->rno<<endl;
		cout<<"\tName:"<<ptr->name<<endl;
		free(ptr);
	}
}
//----------------------------------------------definition of delete at end----------------------
void Student_class::delete_end(){
	if(isEmpty())
		cout<<"***List is empty***"<<endl;
	else{
		struct student *ptr=(struct student*)malloc(sizeof(struct student));
		struct student*temp=(struct student*)malloc(sizeof(struct student)); //to store deleted element
		ptr=head;
		while(ptr->next->next!=NULL){
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=NULL;
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<temp->rno<<endl;
		cout<<"\tName:"<<temp->name<<endl;
		free(temp);
	}
}
//------------------------------------------definition of delete specific element-----------------
void Student_class::delete_middle()
{
	int key;
	if(isEmpty())
		cout<<"***List is empty***"<<endl;
	else{
		cout<<"Enter roll number of student:"<<endl;
		cin>>key;
		struct student*temp=(struct student*)malloc(sizeof(struct student));//to store deleted element
		struct student*ptr=(struct student*)malloc(sizeof(struct student));//to store deleted element
		ptr=head;
		while(ptr->next->rno!=key){
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<temp->rno<<endl;
		cout<<"\tName:"<<temp->name<<endl;
		free(temp);
	}
}
//---------------------------------definition of display----------------------------------------
void Student_class::display()
{
	if(isEmpty())
		cout<<"***List is empty***"<<endl;
	else{
		struct student*ptr=head;
		while(ptr!=NULL)
		{
			cout<<ptr->rno<<"\t"<<ptr->name<<"\t"<<ptr->sgpa<<endl;
			ptr=ptr->next;
		}
	}
}
//----------------------------------------------driver function--------------------------------------
int main()
{
	Student_class s;
	int choice,ch;
	do
	{
		cout<<"--------------------------------------------------------------"<<endl;
		cout<<"1:Insert"<<endl<<"2:Delete"<<endl<<"3:Display"<<endl<<"4:Exit"<<endl;
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice) //to select main operations
		{
		case 1:
			//insertion
			cout<<"\t1:Insert at beginning"<<endl<<"\t2:Insert after specific"<<endl<<"\t3:Insert at end"<<endl<<"\tEnter choice:";
			cin>>ch;
			switch(ch) //for insertion operation
			{
			case 1:
				s.insert_begin();
				break;
			case 2:
				s.insert_middle();
				break;
			case 3:
				s.insert_end();
				break;
			default:
				cout<<"Enter valid choice..."<<endl;
			}
			break;
		case 2:
			//deletion
			cout<<"\t1:Delete at beginning"<<endl<<"\t2:Delete specific element"<<endl<<"\t3:Delete at end"<<endl<<"\tEnter choice:";
			cin>>ch;
			switch(ch) //for deletion operation
			{
			case 1:
				s.delete_begin();
				break;
			case 2:
				s.delete_middle();
				break;
			case 3:
				s.delete_end();
				break;
			}
			break;
		case 3:
			//display
			cout<<"-----------------------------------------------------------------------------"<<endl;
			s.display();
			cout<<"-------------------------------------------------------------------------------"<<endl;
			break;
		}
	}while(choice!=4);
	return 0;
}


