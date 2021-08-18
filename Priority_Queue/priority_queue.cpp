/*
 * priority_queue.cpp
 *
 *  Created on: Sep 16, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
//structure declaration
struct Patient
{
	int patien_id;
	string name;
	string city;
	string disease;
	int priority;
};
//class
class Queue
{
private:
	Patient p[20];
	int front,rear;
public:
	Queue(){
		front=-1;
		rear=-1;
	}
	//methods declaration
	void enqueue(int);
	void dequeue(int);
	void display(int);
	void input(int);
};
//method to insert in queue
void Queue::enqueue(int n)
{
	if(rear==n-1||front==rear+1)
		cout<<"Overflow condition!!!"<<endl;
	else
	{
		if(front==-1)
			front=0;
		rear++;
		input(rear);
		Patient temp=p[rear];
		int i=rear-1;
		while((p[i].priority>temp.priority)&&i>=front)
		{
			p[i+1]=p[i];
			i--;
		}
		p[i+1]=temp;
		cout<<"Record added..."<<endl;
	}
}
//method to input
void Queue::input(int rear)
{
	cout<<"Enter details"<<endl;
	cout<<"Id:";
	cin>>p[rear].patien_id;
	cin.ignore();
	cout<<"Name:";
	getline(cin,p[rear].name);
	cout<<"City:";
	getline(cin,p[rear].city);
	cout<<"Disease:";
	getline(cin,p[rear].disease);
	cout<<"Priority(1=Highest Priority 10=lowest priority):";
	cin>>p[rear].priority;

}//method to delete
void Queue::dequeue(int n)
{
	if(front==-1)
		cout<<"Underflow condition!!!!"<<endl;
	else
	{
		int temp=front;
		front++;
		cout<<"Patient discharged...";
		cout<<"Details are:";
		cout<<"Id:"<<p[temp].patien_id<<endl;
		cout<<"Name:"<<p[temp].name<<endl;
		cout<<"City"<<p[temp].city<<endl;
	}
}
//method to display
void Queue::display(int n)
{
	if(front==-1)
		cout<<"No records available..."<<endl;
	else
	{
		cout<<"Priority\tId\tName\tCity\tDisease"<<endl;
		for(int i=front;i<=rear;i++)
		{
				cout<<p[i].priority<<"\t"<<p[i].patien_id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
		}
	}
}
int main()
{
	Queue queue;
	int n,ch;
	cout<<"Enter total number of patients:";
	cin>>n;
	do
	{
		cout<<"-----------------------------------------------"<<endl;
		cout<<"1:Admit new Patient"<<endl<<"2:Discharge a patient"<<endl<<"3:Display all patients"<<endl<<"4:Exit"<<endl;
		cout<<"Enter choice:";
		cin>>ch;
		cout<<"------------------------------------------------"<<endl;
		switch(ch)
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
	}while(ch!=4);
	return 0;
}
