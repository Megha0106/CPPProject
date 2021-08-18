/*
 * Title: Program to enroll student in course and analyze data
 * Created on: Jul 26, 2020
 * Author: Megha Sonavane
 * Roll No:23355
 */
#include<iostream>
using namespace std;
//Defining a structure to store student's data
struct student
{
	char name[20];
	float sub1,sub2,sub3;
};
//function to enroll student's data
void enroll(student &s)
{
	cout<<"Enter name of student:";
	cin>>s.name;
	cout<<"Enter marks of 3 subjects:";
	cin>>s.sub1>>s.sub2>>s.sub3;
}
//function to analyze student's marks
float analyze(student &s)
{
	if((s.sub1>s.sub2)&&(s.sub1>s.sub3))
		return s.sub1;
	else if(s.sub2>s.sub3)
		return s.sub2;
	else
		return s.sub3;
}
//function to display student's name
void display(student &s)
{
	cout<<"\nName of student:"<<s.name;
	float large=analyze(s);
	cout<<"\nMaximum marks:"<<large;
}
int main()
{
	student s;//creating object of structure student
	enroll(s);//calling to enroll function
	display(s);//calling to display function
	return 0;
}





