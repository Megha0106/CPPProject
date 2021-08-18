/*
 * circualeQueue.cpp
 *
 *  Created on: Sep 9, 2020
 *  Author: Megha Sonavane
 */

#include<iostream>
using namespace std;
struct Patient
{
	int id;
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
	bool validation(int);
};
//definition to add new patient
void Queue::enqueue(int n)
{
	if((front+1)%n==((rear+1)%n)+1)
	{
		cout<<"Overflow condition!!!!"<<endl;
		return;
	}
	if(front==-1) //if it is first element to be inserted
		front=0;

	rear=(rear+1)%n; //increment rear pointer

	//Input details at rear position
	cout<<"Enter details:";
	bool validate; //to validate patient id
	do{
		cout<<"Id:";
		cin>>p[rear].id;
		validate=validation(rear); //validation of id
	}while(!validate);
	cin.ignore();
	cout<<"Name:";
	getline(cin,p[rear].name);
	cout<<"City:";
	getline(cin,p[rear].city);
	cout<<"Disease:";
	getline(cin,p[rear].disease);
	cout<<"Record added....."<<endl;
}
//validation of patient id
bool Queue::validation(int i)
{
	for(int j=i-1;j>=front;j--)
	{
		if(p[rear].id==p[j].id)
		{
			cout<<"Id should be unique"<<endl;
			return false;
		}
	}
	return true;
}
//definition to discharge a patient
void Queue::dequeue(int n)
{
	if(front==-1)
	{
		cout<<"Underflow condition!!!"<<endl;
		return;
	}
	int temp=front;//to display record of discharged patient
	if(front==rear)
		front=rear=-1;//if queue has only 1 element
	//normal deletion
	else
		front=(front+1)%n;
	cout<<"Patient discharged...."<<endl;
	//display details of discharged patient
	cout<<"Details of discharged patient:"<<endl;
	cout<<"Id:"<<p[temp].id<<endl<<"Name:"<<p[temp].name<<endl<<"City:"<<p[temp].city<<endl;
}
//definition for display
void Queue::display(int n)
{
	if(front==-1)
	{
		cout<<"No records available"<<endl;
		return;
	}

	else if(front>rear)
	{
		cout<<"Id\tName\t\tCity\tDisease"<<endl;
		for(int i=front;i<n;i++)
			cout<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
		for(int i=0;i<=rear;i++)
			cout<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
	}
	else
	{
		cout<<"Id\tName\t\tCity\tDisease"<<endl;
		for(int i=front;i<=rear;i++)
			cout<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
	}
}
//driver function
int main()
{
	Queue queue;
	int n;
	do
	{
		cout<<"Enter valid number of patients:";
		cin>>n;
	}while(n<1||n>20);
	int choice;
	do
	{
		cout<<"--------------------"<<endl;
		cout<<"1:Admit new Patient"<<endl<<"2:Discharge patient"<<endl<<"3:Display all patients"<<endl<<"4:Exit"<<endl;
		cout<<"Enter choice:";
		cin>>choice;
		cout<<"--------------------"<<endl;
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
			cout<<"Thank you...";
			break;
		}
	}while(choice!=4);
	return 0;
}

