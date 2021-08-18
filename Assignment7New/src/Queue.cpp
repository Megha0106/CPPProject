/*
 * Queue.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: hp
 */
#include<iostream>
#include "Queue.h"
#include<cstdlib>
using namespace std;

Queue::Queue() {
	// TODO Auto-generated constructor stub
	front=-1;
	rear=-1;
}
//------------------definition of enqueue----------------------------
void Queue::enqueue(Node* newNode){

	rear=rear+1;
	queue[rear]=newNode;
	if(front==-1)
		front=0;
}
//------------------definition of getFront---------------------------
Node* Queue::getfront(){
	//cout<<queue[front]->data;
	return queue[front];
}
//-----------------definition of dequeue--------------------------------
void Queue::dequeue(){
	front=front-1;
}

//------------------definition of isEmpty------------------------------
bool Queue::isEmpty(){
	if(front==-1)
		return true;
	if(front>rear)
		return true;
	return false;


}
Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

