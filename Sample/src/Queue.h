/*
 * Queue.h
 *
 *  Created on: Dec 13, 2020
 *      Author: hp
 */

#ifndef QUEUE_H_
#define QUEUE_H_

struct Customer{
	std::string name;
	int id;
	int mblNo;
};
class Queue {
	Customer c[20];
	int n;
	int front,rear;
public:
	Queue();
	void addRecord();
	void deleteRecord();
	bool isEmpty();
	bool isFull();
	void display();
	virtual ~Queue();
};

#endif /* QUEUE_H_ */
