/*
 * whiteSpace.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
int main()
{
	string name[5];

	for(int i=0;i<5;i++)
	{
		cout<<"Enter name:";
		getline(cin,name[i]);
	}
	cout<<"Enter search key:";
	string key;
	getline(cin,key);
	int low=0,high=5,mid;;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(name[mid].find(key))
			cout<<"Found"<<name[mid];
		else if(name[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}



