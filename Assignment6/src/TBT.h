/*
 * TBT.h
 *
 *  Created on: Nov 25, 2020
 *      Author: hp
 */

#ifndef TBT_H_
#define TBT_H_

struct Node{
	int data;
	Node* left;
	Node*right;
	bool lThread;
	bool rThread;
};
class TBT {

	Node*root;
public:
	TBT();
	Node* getNode(int key);
	bool insert(int key);
	void inorder();
	Node* leftmost(Node*);
	void preorder();
	virtual ~TBT();
};

#endif /* TBT_H_ */
