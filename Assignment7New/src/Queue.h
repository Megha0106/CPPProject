/*
 * Queue.h
 *
 *  Created on: Nov 11, 2020
 *      Author: hp
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "BST.h"


class Queue {

	Node* queue[10];

public:
	int front,rear;
	Queue();
	void enqueue(Node*);
	void dequeue();
	Node* getfront();
	bool isEmpty();
	virtual ~Queue();
};

#endif /* QUEUE_H_ */
