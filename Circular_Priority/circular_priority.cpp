/*
 * circular_priority.cpp
 *
 *  Created on: Sep 16, 2020
 *   Author: Megha Sonavane
 */
#include<iostream>
using namespace std;
//declaring structure
struct Patient
{
	int id,priority;
	string name,city,disease;
};
//class
class Queue
{
private:
	int front,rear;
	Patient p[20];
public:
	Queue(){
		front=-1;
		rear=-1;
	}
	void enqueue(int);
	void dequeue(int);
	void display(int);
	void input(int);
};
//method to insert new record
void Queue::enqueue(int n)
{
	if((front+1)%n==((rear+1)%n)+1)
		cout<<"Overflow condition...";
	else
	{
		if(front==-1)
			front=0;
		rear=(rear+1)%n;
		input(rear);
		Patient temp=p[rear];
		if(rear>=front)
		{
			int i=rear-1;
			while((p[i].priority>temp.priority)&&i>=front)
			{
				p[i+1]=p[i];
				i--;
			}
			p[i+1]=temp;
		}
		else
		{
			int i=rear+1;
			while((p[i].priority<temp.priority)&&i<=n)
			{
				p[i-1]=p[i];
				i++;
			}
			p[i]=temp;
		}
		cout<<"Record added...."<<endl;
	}
}
//method to input
void Queue::input(int rear)
{
	cout<<"Enter details"<<endl;
	cout<<"Id:";
	cin>>p[rear].id;
	cin.ignore();
	cout<<"Name:";
	getline(cin,p[rear].name);
	cout<<"City:";
	getline(cin,p[rear].city);
	cout<<"Disease:";
	getline(cin,p[rear].disease);
	cout<<"Priority(1=Highest Priority 10=lowest priority):";
	cin>>p[rear].priority;
}
//to discharge a patient
void Queue::dequeue(int n)
{
	if(front==-1)
		cout<<"Underflow condition!!!"<<endl;
	else
	{
		int temp=front;
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%n;
		cout<<"Patient discharged...";
		cout<<"Details of discharged patient:"<<endl;
		cout<<"Id:"<<p[temp].id<<endl<<"Name:"<<p[temp].name<<endl<<"City:"<<p[temp].city<<endl;
	}
}
//method to display
void Queue::display(int n)
{
	if(front==-1)
	{
		cout<<"No records available...."<<endl;
	}
	else
	{
		if(front<=rear)
			for(int i=front;i<=rear;i++)
				cout<<p[i].priority<<"\t"<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
		else
		{
			for(int i=front;i<n;i++)
				cout<<p[i].priority<<"\t"<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
			for(int i=0;i<=rear;i++)
				cout<<p[i].priority<<"\t"<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
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

