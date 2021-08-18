/*
 * BST.h
 *
 *  Created on: Nov 6, 2020
 *      Author: hp
 */

#ifndef BST_H_
#define BST_H_
//structute declaration
struct Node
{
	int data;
	Node*left,*right;
};
class BST {
	Node*root;
public:
	BST();
	Node*create(int);
	void insert(int);
	Node*getRoot();
	Node* deleteNode(int);
	void inorder(Node*);
	virtual ~BST();
};

#endif /* BST_H_ */
