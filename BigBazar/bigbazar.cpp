/*
 * bigbazar.cpp
 *
 *  Created on: Aug 11, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
#define SIZE 3

struct Market
{
	char name[50];
	long long  int number;
	int item[SIZE][2];
	int qty[SIZE];
	int count;
	int total;

};

void bill(Market c1);

int list[SIZE][2];

int main()
{


	int i=0;
	cout << "Enter the items that are available in the market\n";
	for(i=0;i<SIZE;i++)
	{
		cout << "Enter the code\n";
		cin >> list[i][0];
		cout << "Enter the price \n";
		cin >> list[i][1];
	}


	struct Market C1;

	bill(C1);



}

void bill(Market c1)
{
	int i = 0,choice  = 0,j=0;
	c1.count = 0;
	c1.total = 0;

	cout << "You can purchase these items from Big Bazzar\n" << endl;
	cout << "Code 	  Price  \n";
	for(i=0;i<SIZE;i++)
	{
		cout << list[i][0]<< "		" << list[i][1] << endl;
	}

	cout << "Dear Customer,please enter your name\n";
	cin.ignore(1);
	cin.getline(c1.name,49);
	cout << "Enter the moblie number \n";
	cin >> c1.number;
	i=0;

	while(i == 0)
	{
		cout << "You can do one of the following\n";
		cout << "1.Buy a product\n";
		cout << "2.Create the bill\n";

		cout << "Enter your choice \n";
		cin >> choice;

		switch(choice)
		{
			case 1 : cout << "Enter the code \n";
					 cin >> c1.item[j][0];
					 cout << "Enter the quantity \n";
					 cin >> c1.qty[j];

					 for(int k=0;k<SIZE;k++)
					 {
					 	if(c1.item[j][0] == list[k][0])
					 	{
					 		c1.item[j][1] = list[k][1];
					 		c1.count = c1.count + 1;
					 		c1.total = c1.total + list[k][1]*c1.qty[j];
					 		j++;

						}


						//break;
					 }
					 break;

			case 2 : i = 2;
			          break;
		}

	}


	cout << endl << endl << "Name = " << c1.name << endl;
	cout << "Number = " << c1.number << endl;
	cout << "Code 	  Price 	Quantity \n";
	for(i=0;i<c1.count;i++)
	{
		cout << c1.item[i][0] << "	   " << c1.item[i][1] << "  	 "<< c1.qty[i] << endl;
	}
	cout << "\nTotal no of items = " << c1.count << endl;
	cout << "Total amount to be paid is = " << c1.total << endl;
	cout << "Thank you for shopping with us \n";
	cout << "Please do visit Big Bazzar again\n";


}



