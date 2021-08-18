/*
 * StackAdt.h
 *
 *  Created on: Oct 19, 2020
 *      Author: hp
 */

#ifndef STACKADT_H_
#define STACKADT_H_

using namespace std;
//-----------------structure definition-------------------------
struct stack{
	char symbol;
	struct stack*next;
};
//---------------------class declaration---------------------------

class StackAdt {
	stack*top;
public:
	StackAdt();
	bool isEmpty();
	void push(char);
	char pop();
	char peep();
	void display();
	~StackAdt();
};

#endif /* STACKADT_H_ */
