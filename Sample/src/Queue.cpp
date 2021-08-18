/*
 * Queue.cpp
 *
 *  Created on: Dec 13, 2020
 *      Author: hp
 */
#include<iostream>
#include "Queue.h"
using namespace std;
Queue::Queue() {
	// TODO Auto-generated constructor stub
	front=rear=-1;
	n=20;

}

bool Queue::isEmpty(){
	if(front==-1)
		return true;
	return false;
}
bool Queue::isFull(){
	if(((front+1)%n)==((rear+1)%n)+1)
		return true;
	return false;
}
void Queue::addRecord(){
	if(isFull()){
		cout<<"Overflow condition !!!"<<endl;
		return;
	}
	else{
		if(front==-1)
			front=0;
		rear=(rear+1)%n;
		cin.ignore();
		cout<<"Enter name:";
		getline(cin,c[rear].name);
		cout<<"Enter id:";
		cin>>c[rear].id;
		cout<<"Enter mobile number:";
		cin>>c[rear].mblNo;
		cout<<"Record added..."<<endl;
	}

}
void Queue::deleteRecord(){
	if(isEmpty())
	{
		cout<<"Underflow condition!!!"<<endl;
		return;
	}
	else{
		Customer temp=c[front];
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%n;
		cout<<"Record deleted..."<<endl;
	}
}
void Queue::display(){
	if(isEmpty()){
		cout<<"Queue is empty.."<<endl;
		return;
	}
	else{
		if(front<rear){
			for(int i=front;i<=rear;i++){
				cout<<c[i].id<<"\t"<<c[i].name<<endl;
			}
		}
		else{
			for(int i=front;i<n;i++)
				cout<<c[i].id<<"\t"<<c[i].name<<endl;
			for(int i=0;i<=rear;i++)
				cout<<c[i].id<<"\t"<<c[i].name<<endl;
		}
	}
}


Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

