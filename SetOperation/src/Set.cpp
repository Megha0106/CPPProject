/*
 * Set.cpp
 *Created on: Dec 31, 2020
 *Author: SE XI-1
 */
#include<iostream>
#include "Set.h"
using namespace std;

Set::Set() {
	// TODO Auto-generated constructor stub



}
//==============definition of input method==============================
void Set::input(int num){

	//validation for set size
	do{
		cout<<"\tEnter number of elements of set "<<num<<":";
		cin>>n;
	}while(n<0 || n>20);

	cout<<"\tEnter elements of set "<<num<<":"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\tEnter "<<i+1<<"th element:";
		cin>>set[i];
		//validating unique elements
		for(int j=i-1;j>=0;j--){
			if(set[i]==set[j])
			{
				cout<<"\t***Enter unique elemets***"<<endl;
				i--;
				break;
			}
		}
	}
	cout<<"=============================================================="<<endl;
}
//===============definition of display method============================
void Set::display(){
	cout<<"\t{";
	for(int i=0;i<n;i++)
		cout<<set[i]<<",";
	cout<<"}"<<endl;
}
//==============definition of addNew method========================
void Set::addNew(){
	if(n==19){
		cout<<"\tSorry,...Can't add more elements"<<endl;
	}
	int num;
	cout<<"\tEnter element to be added:";
	cin>>num;
	for(int i=0;i<n;i++){
		if(set[i]==num){
			cout<<"\t***Already exist***"<<endl;
			return;
		}
	}
	set[n++]=num;
	cout<<"\tElement added"<<endl;
}
//==============definition of union method==========================
void Set::set_union(Set s1,Set s2){
	n=s1.n;
	//copy all elements of first set
	for(int i=0;i<s1.n;i++){
		set[i]=s1.set[i];
	}
	int j;
	for(int i=0;i<s2.n;i++){ //to access element of set2
		for(j=0;j<s1.n;j++){ //to access elements of set1
			if(s2.set[i]==s1.set[j]) //compare element of set2 with all elements of set1
				break; //if already present, break loop
		}
		if(j==s1.n) //if j reaches to end of set1 then i'th element is not present in set1
			set[n++]=s2.set[i]; //add it to resultant set
	}

}
//==============definition of intersection method==========================
void Set::set_intersection(Set s1,Set s2){
	n=0;
	for(int i=0;i<s1.n;i++){//to access elements of set1
		for(int j=0;j<s2.n;j++){//to access elements of set2
			if(s1.set[i]==s2.set[j]){
				set[n++]=s1.set[i];
			}

		}

	}
}
//==============definition of difference method============================
void Set::set_difference(Set s1,Set s2){
	n=0;
	int j;
	for(int i=0;i<s1.n;i++){//to access elements of set1
		for(j=0;j<s2.n;j++){//to access elements of set2
			if(s1.set[i]==s2.set[j]) //compare elements of set1 with all elements of set2
				break;//if elements are common, break the loop
		}
		//if elements are not common add it to resultant set
		if(j==s2.n)
			set[n++]=s1.set[i];
	}
}
//==============definition of symmetric difference method============================
void Set::set_symmeticDiff(Set s1,Set s2){
	Set temp;
	temp.set_difference(s2,s1); //set2-set1
	s1.set_difference(s1,s2);//set1-set2
	n=0;
	//copy set1-set2 in resultant set
	for(int i=0;i<s1.n;i++){
		set[n++]=s1.set[i];
	}
	//copy set2-set1 in resultant set
	for(int i=0;i<temp.n;i++){
		set[n++]=temp.set[i];
	}

}
Set::~Set() {
	// TODO Auto-generated destructor stub
}

