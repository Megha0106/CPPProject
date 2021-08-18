/*
 * test.cpp
 *
 *  Created on: Aug 26, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;

//total number of elements in the queue
#define n 5

//structure of students
struct stud
{
	int roll;
	string name;
	int marks;
};

//class cqueue
class cqueue
{
	//array of structure
	stud s[n];
	//rear and front
	int rear;
	int front;

public:
	//default constructor
	cqueue()
	{
		//initializing values of rear and front to -1
		rear=-1;
		front=-1;
	}
	//member functions
	void input(int x);
	bool isfull();
	bool isempty();
	void enqueue();
	void dequeue();
	void display();
	void display_roll();
};

//method to take input
void cqueue::input(int x)
{
	cin.ignore();
	cout<<"\n\tEnter name::";
	getline(cin,s[x].name);
	cout<<"\tEnter roll::";
	cin>>s[x].roll;
	cout<<"\tEnter marks::";
	cin>>s[x].marks;

}

//queue full condition
bool cqueue::isfull()
{
	if(front==(rear+1)%n)
	{
		return true;
	}
	return false;
}

//queue empty condition
bool cqueue::isempty()
{
	if(front == -1)
	{
		return true;
	}
	return false;
}


//enqueue method
void cqueue::enqueue()
{
	//if queue is full , returned
	if(isfull())
	{
		cout<<"\n\t***Overflow*\n";
		return;
	}
	//rear and front set to 0 if at -1
	if(rear==-1 and front==-1)
	{
		rear=front=0;
	}

	//rear is incremented in circular manner
	else
	{
		rear=(rear+1)%n;
	}

	//inputs
	input(rear);
	//display of roll number in horizontal manner
	display_roll();
}

//dequeue method
void cqueue::dequeue()
{
	//if queue is empty , returned
	if(isempty())
	{
		cout<<"\n\t***Underflow*\n";
		return;
	}

	//if rear==front , boundaries are explicitely set to -1
	if(rear==front)
	{
		front=rear=-1;
	}

	//else front is incremented in circular manner
	else
	{
		front=(front+1)%n;
	}
	display_roll();

}

//display of roll numbers in horizontal manner
void cqueue::display_roll()
{
	if(front<=rear)
	{
		int i=front;
		cout<<endl<<"\t";
		while(i!=rear)
		{
			cout<<"| "<<s[i].roll<<" |";
			i++;
		}
		cout<<"| "<<s[i].roll<<" |\n";
	}
	else
	{
		int i=0;
		cout<<endl<<"\t";
		while(i<n)
		{
			if(i<=rear or i>=front)
			{
				cout<<"| "<<s[i].roll<<" |";
			}
			else
			{
				cout<<"|   |";
			}
			i++;
		}
		cout<<endl;
	}

	cout<<"\n\trear::"<<rear<<endl;
	cout<<"\tfront::"<<front<<endl;

}

//display method
void cqueue::display()
{
	if(isempty())
	{
		cout<<"\n\t*Queue is already empty*\n";
		return;
	}

	if(front<=rear)
	{
		int i=front;
		cout<<endl<<"\t";
		while(i!=rear)
		{
			cout<<"\n\t------------------\n";
			cout<<"\tName::"<<s[i].name<<endl;
			cout<<"\tRoll::"<<s[i].roll<<endl;
			cout<<"\tMarks::"<<s[i].marks<<endl;
			cout<<"\t------------------\n";

			i++;
		}
		cout<<"\n\t------------------\n";
		cout<<"\tName::"<<s[i].name<<endl;
		cout<<"\tRoll::"<<s[i].roll<<endl;
		cout<<"\tMarks::"<<s[i].marks<<endl;
		cout<<"\t------------------\n";

	}
	else
	{

		int i=0;
		cout<<endl<<"\t";
		while(i<n)
		{
			if(i<=rear or i>=front)
			{
				cout<<"\n\t------------------\n";
				cout<<"\tName::"<<s[i].name<<endl;
				cout<<"\tRoll::"<<s[i].roll<<endl;
				cout<<"\tMarks::"<<s[i].marks<<endl;
				cout<<"\t------------------\n";


			}

			i++;
		}
		cout<<endl;
	}


}



//main method

int main()
{

	//object of class queue
	cqueue c;


	while(true)
	{
		//menu
		cout<<"\n\tMENU::\n";
		cout<<"\t1)Enqueue\n";
		cout<<"\t2)Dequeue\n";
		cout<<"\t3)Display\n";
		cout<<"\t4)Exit\n";

		int choice;
		cout<<"\n\tEnter choice::";
		cin>>choice;

		//switch
		switch(choice)
		{
			//enqueue
			case 1:
			{
				c.enqueue();
				break;
			}

			//dequeue
			case 2:
			{
				c.dequeue();
				break;
			}

			//display
			case 3:
			{
				c.display();
				break;
			}
			case 4:
				exit(1);
			break;
		}
	}


}


