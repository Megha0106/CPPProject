//============================================================================
// Name        : Assignment6.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TBT.h"

using namespace std;

int main() {

	TBT tbt;
	int ch,n;
	bool flag;
	do{
		cout<<"=============================================================================="<<endl;
		cout<<"\t1:Insert into tree"<<endl<<"\t2:Inorder traversal of tree"<<endl<<"\t3:Preorder traversal"<<endl<<"\t0:Exit"<<endl;
		cout<<"\tEnter choice:";
		cin>>ch;
		cout<<"=============================================================================="<<endl;
		switch(ch){
		case 1:
			//======insertion in tree=========
			cout<<"\tEnter number:";
			cin>>n;
			flag=tbt.insert(n);
			if(flag)
				cout<<"\t***Inserted successfully***"<<endl;
			else
				cout<<"\t***"<<n<<" is alreay present in tree***"<<endl;
			break;
		case 2:
			//========inorder traversal======
			tbt.inorder();
			break;
		}
	}while(ch!=0);
	return 0;
}
