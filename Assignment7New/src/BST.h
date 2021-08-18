/*
 * BST.h
 *
 *  Created on: Nov 8, 2020
 *      Author: hp
 */

#ifndef BST_H_
#define BST_H_

struct Node{
	int data;
	Node*left,*right;
};

class BST {
	Node*root;
public:
	BST();
	Node* create(int);
	bool insert(int);
	Node* getRoot();
	Node* deleteNode(Node*,int);
	void inorder(Node*);
	void preorder(Node*);
	void postorder(Node*);
	bool search(Node*,int);
	Node* findMin(Node*);
	int treeDepth(Node*);
	void mirrorImg(Node*);
	Node* createCopy(Node*);
	void printLeafNode(Node*);
	void printParentChild(Node*);
	void printLevelWise();
	virtual ~BST();
};

#endif /* BST_H_ */
