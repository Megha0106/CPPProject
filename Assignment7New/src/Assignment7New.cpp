//============================================================================
// Name        : Assignment7New.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BST.h"
#include "Queue.h"
//#include "BST.cpp"
using namespace std;

int main() {

	BST bst;
	Node* temp,*cpy;
	int ch,num;
	bool flag;

	cout<<"\tBinary Search Tree";
	do{
		cout<<endl<<"===================================================================================================================="<<endl;
		cout<<"\t1:Insert node into tree"<<endl<<"\t2:Delete "<<endl<<"\t3:Searching"<<endl<<"\t4:Traversal"<<endl<<"\t5:Depth of tree"<<endl;
		cout<<"\t6:Create mirror image"<<endl<<"\t7:Create copy"<<endl<<"\t8:Display all perent nodes with child"<<endl<<"\t9:Display leaf nodes"<<endl<<"\t10:Display tree level wise"<<endl<<"\t0:Exit"<<endl<<"\tEnter choice:";
		cin>>ch;
		cout<<endl<<"======================================================================================================================"<<endl;
		switch(ch)
		{
		case 1:
			//===============================Insertion into tree=========================================================================
			cout<<"\tEnte number:";
			cin>>num;
			flag=bst.insert(num);
			if(flag)
				cout<<"\t***Inserted successfully***"<<endl;
			else
				cout<<"\t***Do not enter duplicate numbers***"<<endl;
			break;
		case 4:
			//=====================================Traversal of tree===========================================================
			if(bst.getRoot()==NULL)
			{
				cout<<"\t***Tree is empty****";
				continue;
			}
			cout<<"\t\t1:Inorder"<<endl<<"\t\t2:Preorder"<<endl<<"\t\t3:Postorder"<<endl<<"\t\tEnter choice:";
			cin>>num;
			//inorder traversal
			if(num==1)
			{
				cout<<"\t\t::Inorder traversal::";
				bst.inorder(bst.getRoot());
			}
			//preorder traversal
			else if(num==2)
			{
				cout<<"\t\t::Preorder traversal::";
				bst.preorder(bst.getRoot());
			}
			//postorder traversal
			else{
				cout<<"\t\t::Postorder traversal::";
				bst.postorder(bst.getRoot());
			}
			break;
		case 3:
			//===============================searhing in tree==============================================
			cout<<"\tEnter number to be search:";
			cin>>num;
			flag=bst.search(bst.getRoot(),num);
			if(flag)
				cout<<"\t"<<num<<" is present is tree"<<endl;
			else
				cout<<"\t"<<num<<" is not present in tree"<<endl;
			break;
		case 2:
			//=================================deletion in tree==============================================
			cout<<"\tEnter number to be deleted:";
			cin>>num;
			temp=bst.deleteNode(bst.getRoot(),num);
			 //if deleted successfully, root will be returned
			if(temp==bst.getRoot())
				cout<<"\t"<<num<<" is deleted"<<endl;
			else
				cout<<"\t"<<num<<" is not present"<<endl;
			break;
		case 5:
			//==================================depth of tree=====================================
			cout<<"\tDepth of tree:"<<bst.treeDepth(bst.getRoot());
			break;
		case 6:
			//==============================creation of mirror image====================================
			if(bst.getRoot()==NULL){
				cout<<"\t****Tree is empty****"<<endl;
				continue;
			}
			bst.mirrorImg(bst.getRoot());
			cout<<"\t***Mirror Image created***";
			break;
		case 7:
			//==============================create copy============================================
			if(bst.getRoot()==NULL)
			{
				cout<<"\t***Tree is empty***"<<endl;
				continue;
			}
			cpy=bst.createCopy(bst.getRoot());
			cout<<"\t***Copy is created***";
			break;
		case 8:
			//=============================display parent node with child==========================
			if(bst.getRoot()==NULL)
			{
				cout<<"\t***Tree is empty***"<<endl;
				continue;
			}
			bst.printParentChild(bst.getRoot());
			break;
		case 9:
			//===================Print leaf nodes======================================================
			cout<<"\tLeaf Nodes:";
			bst.printLeafNode(bst.getRoot());
			break;
		case 10:
			//=======================display tree level wise===============================================
			if(bst.getRoot()==NULL){
				cout<<"\t***Empty tree"<<endl;
				continue;
			}
			bst.printLevelWise();
			break;
		case 0:
			cout<<"\tThank you"<<endl;
			break;
		default:
			cout<<"\t***Invalid choice.....***"<<endl;
		}
	}while(ch!=0);
	return 0;
}
