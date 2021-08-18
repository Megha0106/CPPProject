//============================================================================
// Name        : Sample.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Queue.h"
using namespace std;

int main() {
	Queue que;
	int ch;
	do{
		cout<<"1:Add new record"<<endl<<"2:Delete record"<<endl<<"3:Display "<<endl<<"0:Exit"<<endl;
		cout<<"Enter choice:";
		cin>>ch;
		switch(ch){
		case 1:
			que.addRecord();
			break;
		case 2:
			que.deleteRecord();
			break;
		case 3:
			que.display();
			break;
		case 0:
			cout<<"Thank you..."<<endl;
			break;
		}
	}while(ch!=0);
	return 0;
}
