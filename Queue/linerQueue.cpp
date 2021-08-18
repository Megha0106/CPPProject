/*
 * linerQueue.cpp
 *
 *  Created on: Sep 7, 2020
 *      Author: hp
 */
/*
#include<iostream>
using namespace std;
struct student
{
	int roll;
	string name;
	double SGPA;
};
class Queue
{
private:
	int front,rear;
	student s[10];
public:
	//constructor
	Queue()
	{
		front=-1;
		rear=-1;
	}
	//member functions
	void enqueue(int);
	void dequeue(int);
	void display(int);
};
//definition of enqueue
void Queue::enqueue(int n)
{
	if(rear==n-1)
	{
		cout<<"Overflow condition!!!"<<endl;
	}
	else
	{
		if(front==-1)
			front=0;
		rear++;
		cout<<"Enter details"<<endl;
		cout<<"Roll number:";
		cin>>s[rear].roll;
		cout<<"Name:";
		cin>>s[rear].name;
		cout<<"SGPA:";
		cin>>s[rear].SGPA;
	}
}
//definition of dequeue
void Queue::dequeue(int n)
{
	if(front==-1||front==rear+1)
		cout<<"Underflow condition!!!"<<endl;
	else
	{
		front++;
		cout<<"Record deleted"<<endl;
	}
}
//definition of display
void Queue::display(int n)
{
	if(front==-1||front==rear+1)
	{

		cout<<"Empty array"<<endl;
		return;
	}
	cout<<"RollNo.\tName\tSGPA"<<endl;
	for(int i=front;i<=rear;i++)
	{
		cout<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].SGPA<<endl;
	}
}
//driver function
int main()
{

	Queue queue;
	int n;
	cout<<"Enter number of students:";
	cin>>n;

	int choice;
	do{
		cout<<"------------------------------------------"<<endl;
		cout<<"1:Insert in queue"<<endl<<"2:Delete element in queue"<<endl<<"3:Display all records"<<endl<<"4:Exit:";
		cin>>choice;
		cout<<"------------------------------------------"<<endl;
		switch(choice)
		{
		case 1:
			queue.enqueue(n);
			break;
		case 2:
			queue.dequeue(n);
			break;
		case 3:
			queue.display(n);
			break;
		case 4:
			cout<<"Thank you....";
			break;
		}
	}while(choice!=4);
	return 0;
}*/



