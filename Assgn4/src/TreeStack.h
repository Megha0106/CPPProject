/*
 * TreeStack.h
 *
 *  Created on: Oct 27, 2020
 *      Author: Megha Sonavane
 */

#ifndef TREESTACK_H_
#define TREESTACK_H_
using namespace std;
struct TreeNode{
	char symbol;
	struct TreeNode*left,*right;
};
class TreeStack {
	int top;
	TreeNode*s[10];
public:
	TreeStack();
	bool isEmpty();
	int getTop();
	void Push(TreeNode*);
	TreeNode* pop();
	TreeNode* peek();
	virtual ~TreeStack();
};

#endif /* TREESTACK_H_ */
