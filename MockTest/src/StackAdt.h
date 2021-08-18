/*
 * StackAdt.h
 *
 *  Created on: Nov 4, 2020
 *      Author: Megha Sonavane(23355)
 */

#ifndef STACKADT_H_
#define STACKADT_H_
//structure for stack as linked list
template<typename T>
struct Node{
	T symbol;
	Node<T>*next;
};
//class declaration
template<class T>
class StackAdt {
	Node<T>*top;
public:
	StackAdt();
	bool isEmpty();
	void push(T);
	T pop();
	T peep();
	void display();
	virtual ~StackAdt();
};

#endif /* STACKADT_H_ */
