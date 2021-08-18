/*
 * Student.cpp
 * Author: Megha Sonavane
 */
#include<iostream>
#include "Student.h"
using namespace std;
Student::Student() {
	// TODO Auto-generated constructor stub

}
//===================definition of input()===========================
void Student::input(){
	cout<<"Enter details of student:"<<endl;
	cout<<"Roll No:";
	cin>>rollNo;
	cin.ignore();
	cout<<"Name:";
	getline(cin,name);
	cout<<"Division:";
	getline(cin,div);
	cout<<"Address:";
	getline(cin,address);
}
//=================definition of show()===============================
void Student::show(){
	cout<<rollNo<<"\t"<<name<<"\t"<<div<<"\t"<<address<<endl;

}
//=========definition of getRollNo()=======================================
int Student::getRollNo(){
	return this->rollNo;
}
//=========definition of setRollNo()======================================
void Student::setRollNo(int rno)
{
	this->rollNo=rno;
}
//=====definition of setName()=========================================
void Student::setName(string nm)
{
	this->name=nm;
}
//=====definition of setAddress()===========================================
void Student::setAddress(string add){
	this->address=add;
}
//====definition of setDivision()==============================================
void Student::setDivision(string d){
	this->div=d;
}
Student::~Student() {
	// TODO Auto-generated destructor stub
}

