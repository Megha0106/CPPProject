/*
 * Circular_ll.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: hp
 */
#include<iostream>
#include<cstdlib>
using namespace std;
//class declaration
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
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	input(ptr);
	if(isEmpty()) //if it is first node in list
	{
		head=ptr;
		ptr->next=ptr;
	}
	else{
		struct student*temp=head;
		while(temp->next!=head)
			temp=temp->next;
		ptr->next=head;
		head=ptr;
		temp->next=head;
	}
	cout<<"\t****Inserted successfully****"<<endl;
}
//---------------------------------------------definition of insert at end--------------------
void Student_class::insert_end(){
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	input(ptr);
	if(isEmpty()) //if it is first node in list
	{
		head=ptr;
		ptr->next=ptr;
		cout<<"\t***List is empty...node is inserted at first..***"<<endl;
	}
	else{
		struct student*temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=ptr;
		ptr->next=head;

	}
	cout<<"\t****Inserted successfully****"<<endl;
}
void Student_class::insert_middle(){
	if(isEmpty())
		cout<<"\t***List is empty***"<<endl;
	else{
		int key; //to store roll number of student temporary
		cout<<"Enter roll number of student after which new student to be added:"<<endl;
		cin>>key;
		struct student*temp=head;
		while(temp->rno!=key&&temp->next!=head)
			temp=temp->next;
		if(temp->rno==key) //if key is at last node, it is needed to insert after it also
		{
			struct student*ptr=(struct student*)malloc(sizeof(struct student));
			input(ptr);
			ptr->next=temp->next;
			temp->next=ptr;
		}
		else
			cout<<"\t***Student with roll number "<<key<<" is not in list***"<<endl;
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
	ptr->next=NULL;
}
//----------------------------------------------definition of delete at first-------------------
void Student_class::delete_begin(){
	if(isEmpty())
		cout<<"\t***List is empty***"<<endl;
	else{
		struct student*ptr=head; //node to be deleted
		//if list contains single node
		if(ptr->next==head){
			head=NULL;
		}
		else
		{
			struct student*temp=head;// to traverse to last node
			while(temp->next!=head)
				temp=temp->next;
			head=head->next;
			temp->next=head;
		}
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
		cout<<"****List is empty***"<<endl;
	else{
		struct student*ptr=head; //for node to be deleted
		//if list contains single element
		if(ptr->next==head)
			head=NULL;
		else{
			struct student*temp=head; //to traverse to the second last node
			while(temp->next->next!=head)
				temp=temp->next;
			ptr=temp->next;
			temp->next=head;
		}
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<ptr->rno<<endl;
		cout<<"\tName:"<<ptr->name<<endl;
		free(ptr);
	}
}
//------------------------------------------definition of delete specific element-----------------
void Student_class::delete_middle(){
	if(isEmpty())
		cout<<"****List is empty****"<<endl;
	else{
		struct student*ptr=head;//for node to be deleted
		int key;
		cout<<"Enter roll number of student to be deleted:"<<endl;
		cin>>key;
		//if list contains single node
		if(ptr->next==head)
		{
			//check if is key
			if(ptr->rno==key)
				head=NULL;
			else{
				cout<<"Student with roll number "<<key<<" is not in list"<<endl;
				return;
			}
		}
		//if list has more than one node
		else{
			struct student*temp=head; //to traverse to the last node of node to be deleted
			while(temp->next->rno!=key)
				temp=temp->next;
			ptr=temp->next;
			temp->next=ptr->next;
		}
		cout<<"\t----------------------------"<<endl;
		cout<<"\tDetails of deleted student:"<<endl;
		cout<<"\tRoll no:"<<ptr->rno<<endl;
		cout<<"\tName:"<<ptr->name<<endl;
		free(ptr);

	}
}
//---------------------------definition of display method----------------
void Student_class::display(){
	if(isEmpty())
		cout<<"***List is empty***"<<endl;
	else{
		struct student*ptr=head;
		do{
			cout<<ptr->rno<<"\t"<<ptr->name<<"\t"<<ptr->sgpa<<endl;
			ptr=ptr->next;
		}while(ptr!=head);
	}
}
//----------------------------driver function-------------------------------
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


