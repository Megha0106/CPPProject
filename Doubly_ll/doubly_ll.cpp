/*
 * doubly_ll.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: hp
 */
#include<iostream>
#include<cstdlib>
using namespace std;
//class declaration
class Student_class{
private:
	struct student{
		int rno;
		char name[20];
		double sgpa;
		struct student*next;
		struct student*previous;
	};
	struct student*head;
public:
	Student_class(){
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
//-------------------definition to insert at beginning------------------------
void Student_class::insert_begin(){
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	input(ptr);
	if(isEmpty())
	{
		head=ptr;
	}
	else{
		ptr->next=head;
		head=ptr;
	}
	cout<<"\t****Inserted successfully****"<<endl;
}
//-----------------------definition to insert at end-------------------------
void Student_class::insert_end(){
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	input(ptr);
	if(isEmpty())
	{
		cout<<"***List is empty...record is inserted at beginning***"<<endl;
		head=ptr;
	}
	else{
		struct student*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->previous=temp;
	}
	cout<<"\t****Inserted successfully****"<<endl;
}
//-------------------------definition of insert at middle-------------------
void Student_class::insert_middle(){
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	int key; //to store roll number of student temporary
	cout<<"Enter roll number of student after which new student to be added:"<<endl;
	cin>>key;
	struct student*temp=head;//for locating student
	while(temp->rno!=key&&temp!=NULL);
	{
		temp=temp->next;
	}
	if(temp==NULL)
		cout<<"***Student with roll number "<<key<<" is not in list***"<<endl;
	else{
		input(ptr);
		ptr->next=temp->next;
		ptr->previous=temp;
		temp->next->previous=ptr;
		temp->next=ptr;
		cout<<"\t****Inserted successfully****"<<endl;
	}
}
//------------------------definition of delete at beginning----------------
void Student_class::delete_begin(){
	if(isEmpty())
	{
		cout<<"***List is empty***"<<endl;
	}
	else{
		struct student*ptr=(struct student*)malloc(sizeof(struct student));
		ptr=head;
		head=head->next;
		head->previous=NULL;
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<ptr->rno<<endl;
		cout<<"\tName:"<<ptr->name<<endl;
		free(ptr);
	}
}
//-----------------------definition of delete at end------------------------
void Student_class::delete_end(){
	if(isEmpty())
	{
		cout<<"***List is empty***";
	}
	else{
		struct student*ptr=(struct student*)malloc(sizeof(struct student));
		ptr=head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->previous->next=NULL;
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<ptr->rno<<endl;
		cout<<"\tName:"<<ptr->name<<endl;
		free(ptr);
	}
}
//-----------------------definition of delete specific--------------------
void Student_class::delete_middle(){
	if(isEmpty())
	{
		cout<<"***List is empty***"<<endl;
	}
	else{
		int key;
		cout<<"Enter roll number of student to be deleted:"<<endl;
		cin>>key;
		struct student*ptr=(struct student*)malloc(sizeof(struct student));
		ptr=head;
		while(ptr->rno!=key)
		{
			cout<<"Rno:"<<ptr->rno<<endl;
			ptr=ptr->next;
		}
		ptr->next->previous=ptr->previous;
		ptr->previous->next=ptr->next;
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<ptr->rno<<endl;
		cout<<"\tName:"<<ptr->name<<endl;
		free(ptr);
	}
}
//-----------------------definition of display------------------------------
void Student_class::display(){
	if(isEmpty())
	{
		cout<<"***List is empty***"<<endl;
	}
	else{
		struct student*ptr=head;
		while(ptr!=NULL){
			cout<<ptr->rno<<"\t"<<ptr->name<<"\t"<<ptr->sgpa<<endl;
			ptr=ptr->next;
		}
	}
}
//---------------------definition of input method----------------------------
void Student_class::input(struct student*ptr)
{
	cout<<"\t***Enter details:***"<<endl;
	cout<<"Roll no:";
	cin>>ptr->rno;
	cout<<"Name:";
	cin>>ptr->name;
	cout<<"SGPA:";
	cin>>ptr->sgpa;
	ptr->previous=NULL;
	ptr->next=NULL;
}
//-------------------------driver function-----------------------------------------------
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
				/*
			case 2:
				s.insert_middle();
				break;*/
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


