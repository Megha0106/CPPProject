//============================================================================
// Name        : Assignment10.cpp
// Author      : Megha Sonavane
// Description : Student database using sequential file
//============================================================================

#include <iostream>
#include"FileOperation.h"
using namespace std;

int main() {
	FileOperation fileOp;
	int ch;
	do{
		cout<<"================MENUS================================="<<endl;
		cout<<"1:Create new database"<<endl<<"2:Add new record"<<endl<<"3:Display all record"<<endl<<"4:Search a record"<<endl;
		cout<<"5:Modify a record"<<endl<<"6:Delete a record"<<endl<<"0:Exit"<<endl;
		cout<<"Enter choice:";
		cin>>ch;
		cout<<"======================================================"<<endl;
		switch(ch){
		case 1:
			//create database
			fileOp.create();
			break;
		case 2:
			//adding new record
			fileOp.addnew();
			break;
		case 3:
			//display all records
			fileOp.display();
			break;
		case 4:
			//search a particular record
			fileOp.search();
			break;
		case 5:
			//modify record
			fileOp.modify();
			break;
		case 6:
			//delete record
			fileOp.delet();
			break;
		case 0:
			//exit
			cout<<"Thank you...";
			break;
		default:
			cout<<"Enter valid choice.."<<endl;
			break;
		}
	}while(ch!=0);
	return 0;
}
