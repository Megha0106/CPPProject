/*
 * StackAdt.h
 *
 *  Created on: Oct 19, 2020
 *      Author: hp
 */

#ifndef STACKADT_H_
#define STACKADT_H_
template <typename T1>
struct Node{
	T1 data;
	Node*next;
};
template <class T1>
class StackAdt {
	T1 *top;
public:

	StackAdt();
	void push(T1);
	T1 pop();
	void display();
	virtual ~StackAdt();
};

#endif /* STACKADT_H_ */
