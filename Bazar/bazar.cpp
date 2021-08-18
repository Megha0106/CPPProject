/*
 * bazar.cpp
 *
 *  Created on: Aug 10, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
struct itemList //structure for items
	{
		char item_name[10];
		double price;
	};
	struct data //structure for customer's data
	{
		int cust_no;
		char name[20];
		itemList s[5];
		double total;
	};
//class declaration
class Bazar
{
public:
		void input(data *);
		double total_calculation(itemList[]);
		void display(data);
};
//definition of input()
void Bazar::input(data *d)
{
	cout<<"Customer no:";
	cin>>d->cust_no;
	cout<<"Customer's name:";
	cin>>d->name;
	cout<<"Details for item list"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Item "<<i+1<<"Name:";
		cin>>d->s[i].item_name;
		cout<<"Price:";
		cin>>d->s[i].price;

	}
}
//method definition to calculate total
double Bazar::total_calculation(itemList item [5])
{
	double total=0;
	for(int i=0;i<5;i++)
	{
		total+=item[i].price;
	}
	return total;
}
//method definition to display
void Bazar::display(data d)
{
	cout<<"Customer No:"<<d.cust_no<<endl;
	cout<<"Customer Name:"<<d.name<<endl;
	cout<<"Item List:"<<endl;
	cout<<"Item name\tPrice"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<d.s[i].item_name<<"\t\t"<<d.s[i].price<<endl;
	}
	cout<<endl<<"Total Price:Rs."<<d.total<<endl;
}

//main method
int main()
{
	int n,i;
	cout<<"Enter number of customers:"<<endl;
	cin>>n;
	struct data d[n];
	Bazar b[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter details of customer "<<i+1<<endl;
		b[i].input(&d[i]);
		double total=b[i].total_calculation(d[i].s);
		d[i].total=total;
	}
	cout<<"Customer details"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Customer "<<i+1<<":"<<endl;
		b[i].display(d[i]);
	}
	return 0;
}




