/*
 * Statement1.cpp
 *
 *  Created on: Sep 14, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
int occurence(string,string);
int main()
{
	string str,search_str;
	cout<<"Enter string of bits:";
	cin>>str;
	cout<<"Enter number for 0 to 7:";
	cin>>search_str;
	int count=occurence(str,search_str);
	cout<<"Total occurrence:"<<count;
	return 0;
}

int occurence(string str,string search_str)
{
	int count=0;
	int m=str.length();
	int n=search_str.length();
	for(int i=0;i<m;i++)
	{
		if(str.substr(i,n)==search_str)
			count++;
	}
	return count;
}



