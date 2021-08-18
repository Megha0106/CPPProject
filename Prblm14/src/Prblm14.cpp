//============================================================================
// Name        : Prblm14.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct Passenger{
	string name;
	int ticket_no;
	double rs;
	string src,dest;
};
class BusTicket{
private:
	Passenger p[20];
	int front,rear;
public:
	BusTicket(){
		front=rear=-1;
	}
	void enqueue(int);
	void dequeue(int);
	void display(int);
	bool overflow(int);
	bool underflow(int);

};
bool BusTicket::overflow(int n){
	if((front+1)%n==(rear+1)%n+1)
		return true;
	return false;
}
void BusTicket::enqueue(int n){
	if(!overflow(n)){

	}
	else{
		cout<<"Overflow Condition!!!"<<endl;
	}
}
int main() {

	BusTicket b;
	int n,ch;
	do{
		cout<<"Enter total number of passenger(less than 20):";
		cin>>n;
	}while(n<0||n>20);
	do{
		cout<<"1:To add new passanger\n2:To remove passanger\n3:Display all passenges"<<endl;
		cout<<"Enter choice:"<<endl;
		cin>>ch;
		switch(ch){
		case 1:
			b.enqueue(n);
			break;
		case 2:
			b.dequeue(n);
			break;
		case 3:
			break;
		}
	}while(ch!=5);
	return 0;
}
