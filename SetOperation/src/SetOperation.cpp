//============================================================================
// Name        : SetOperation.cpp
// Author      : SE XI-1
// Description : Set Operations
//============================================================================

#include <iostream>
#include "Set.h"
using namespace std;

int main() {
	Set s1,s2,result;
	//input set elements
	s1.input(1);
	s2.input(2);

	int ch,choice;
	do{
		cout<<"===================MENUS===================="<<endl;
		cout<<"\t1:Display sets"<<endl<<"\t2:Union"<<endl<<"\t3:Intesection"<<endl<<"\t4:Difference"<<endl<<"\t5:Symmetric Difference"<<endl<<"\t6:Add new element"<<endl<<"\t0:Exit"<<endl;
		cout<<"\tEnter choice:";
		cin>>choice;
		cout<<"============================================"<<endl;
		switch(choice){
		case 1:
			//display set elements
			cout<<"\tSet1:"<<endl;
			s1.display();
			cout<<"\tSet2:"<<endl;
			s2.display();
			break;
		case 2:
			cout<<"\tUnion of sets:"<<endl;
			result.set_union(s1,s2);
			result.display();
			break;
		case 3:
			cout<<"\tIntersection of sets:"<<endl;
			result.set_intersection(s1,s2);
			result.display();
			break;
		case 4:
			cout<<"\t1:Set1-Set2 "<<endl<<"\t2:Set2-Set1"<<endl<<"\tEnter:";
			cin>>ch;
			if(ch==1){
				result.set_difference(s1,s2);
				cout<<"\tSet1-Set2:"<<endl;
				result.display();
			}
			else if(ch==2){
				result.set_difference(s2,s1);
				cout<<"\tSet2-Set1:"<<endl;
				result.display();
			}
			else
				cout<<"\tInvalid choice"<<endl;

			break;
		case 5:
			result.set_symmeticDiff(s1,s2);
			cout<<"\tSymmetric difference:"<<endl;
			result.display();
			break;
		case 6:
			cout<<"\tEnter set 1 or 2: ";
			cin>>ch;
			if(ch==1)
				s1.addNew();
			else if(ch==2)
				s2.addNew();
			else
				cout<<"\tInvalid set"<<endl;
			break;
		case 0:
			cout<<"\tThank you..."<<endl;
			break;
		}

	}while(choice!=0);

	return 0;
}
