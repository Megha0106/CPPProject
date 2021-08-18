/*Title: Student database
 * student.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
//class declaration
class Student_class
{
public:
	//data members
	struct student
	{
		int roll_no,total;
		string name;
		long mbl_no;
		int marks[5];
		float percentage;
	}s[50];
	//method declaration
	void input(int);
	bool validate(int);
	void display(int);
	int topper(int);
	int insert(int);
	int delete_Stud(int);
	int search(int,int);
	void update(int);
	void sort_percentage(int);
	void sort_name(int);
};
//definition of input()
void Student_class::input(int i)
{
		cout<<"Enter details of student"<<i+1<<":"<<endl;
		bool index;
		do
		{
			cout<<"Roll_no.:";
			cin>>s[i].roll_no;
			index=validate(i);

		}while(!index);

		cout<<"Name:";
		cin>>s[i].name;
		cout<<"Mobile no:";
		cin>>s[i].mbl_no;
		s[i].total=0;
		cout<<"Enter marks of 5 subjects:"<<endl;
		for(int j=0;j<5;j++)
		{
			cout<<"Subject "<<j+1<<":";
			cin>>s[i].marks[j];
			s[i].total+=s[i].marks[j];
		}
		s[i].percentage=s[i].total/5;

}
//definition of validate
bool Student_class::validate(int i)
{
	for(int j=i-1;j>=0;j--)
	{
		if(s[i].roll_no==s[j].roll_no)
		{
			cout<<"Roll number should be unique"<<endl;
			return false;
		}

	}
	return true;
}
//definition of display
void Student_class::display(int i)
{
		cout<<endl<<"Details of student "<<i+1<<"->"<<endl;
		cout<<"Roll No.->"<<s[i].roll_no<<endl;
		cout<<"Name->"<<s[i].name<<endl;
		cout<<"Mobile No.->"<<s[i].mbl_no<<endl;
		cout<<"Marks->"<<endl;
		for(int j=0;j<5;j++)
			cout<<"Subject "<<j+1<<"->"<<s[i].marks[j]<<endl;
		cout<<"Total->"<<s[i].total<<endl;
		cout<<"Percentage->"<<s[i].percentage<<endl<<endl;
}
//definition of topper method
int Student_class::topper(int n)
{
	int topper_index=0;
	for(int i=1;i<n;i++)
	{
		if(s[topper_index].percentage<s[i].percentage)
			topper_index=i;
	}
	return topper_index;

}
//definition of insert method
int Student_class::insert(int n)
{
	int index;
	cout<<"Enter the index where you want to add student:";
	cin>>index;
	if(index>=50)
	{
		cout<<"Index is out of bounds"<<endl;
		return n;
	}
	else
	{
		index--;
		for(int i=n;i>index;i--)
		{
			s[n]=s[n-1];
		}
		input(index);
		cout<<"Student inserted successfully"<<endl;
	}
	return n+1;
}
//definition of delete method
int Student_class::delete_Stud(int n)
{
	int rno;
	cout<<"Enter roll number of student to be deleted:";
	cin>>rno;
	int index=search(rno,n);
	if(index==-1)
		cout<<"Student with roll number "<<rno<<" not found"<<endl;
	else
	{
		for(int i=index;i<(n-1);i++)
			s[i]=s[i+1];
		cout<<"Student deleted successfully"<<endl;
		n--;
	}
	return n;
}
//definition of search
int Student_class::search(int rno,int n)
{
	for(int i=0;i<n;i++)
		if(s[i].roll_no==rno)
			return i;
	return -1;
}
//definition of update
void Student_class::update(int n)
{
	int rno;
	cout<<"Enter roll number of student whose marks are to be update:";
	cin>>rno;
	int index=search(rno,n);
	if(index==-1)
		cout<<"Student with roll number "<<rno<<" not found"<<endl;
	else
	{
		cout<<"Enter marks of 5 subjects:"<<endl;
		s[index].total=0;
		for(int i=0;i<5;i++)
		{
			cout<<"Subject "<<i+1<<"->";
			cin>>s[index].marks[i];
			s[index].total+=s[index].marks[i];
		}
		s[index].percentage=s[index].total/5;
		cout<<"Student details are updated"<<endl;
	}
}
//definition of sort function according to percentage
void Student_class::sort_percentage(int n)
{
	student temp;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(s[i].percentage>s[j].percentage)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
	cout<<"List sorted successfully"<<endl;
}
void Student_class::sort_name(int n)
{
	student temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(s[i].name<s[j].name)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
	cout<<"List sorted successfully"<<endl;
}
//main function
int main()
{
	Student_class obj;
	int n,choice,index,rno;
	cout<<"Enter number of students:";
	cin>>n;
	for(int i=0;i<n;i++)
		obj.input(i);
	do
	{
		//display menus to user
		cout<<"------------------------"<<"MENU"<<"-------------------"<<endl;
		cout<<"1:Display\n2:Display topper\n3:Search a student\n4:Insert new record\n5:Delete record\n6:Update student's marks\n7:Sort student's list\n8:Exit"<<endl;
		cout<<"Enter choice:";//enter choice of user
		cin>>choice;
		cout<<endl<<"------------------------------------------------------"<<endl;
		switch(choice)  //switch choice of user
		{
		case 1:
			for(int i=0;i<n;i++)
			obj.display(i);
			break;

		case 2:
			index=obj.topper(n);
			cout<<endl<<"Details of topper student:";
			obj.display(index);
			break;
		case 3:
			cout<<"Enter roll number of student to be search:";
			cin>>rno;
			index=obj.search(rno,n);
			if(index==-1)
				cout<<"Student not found"<<endl;
			else
			{
				cout<<"Student found"<<endl;
				obj.display(index);
			}
			break;
		case 4:
			n=obj.insert(n);
			break;
		case 5:
			n=obj.delete_Stud(n);
			break;
		case 6:
			obj.update(n);
			break;
		case 7:
			int ch;
			cout<<"Enter"<<endl<<"1:Sort according to percentage\n2:Sort according to name of student:"<<endl;
			cin>>ch;
			if(ch==1)
				obj.sort_percentage(n);
			else
				obj.sort_name(n);
			break;
		case 8:
			cout<<"Thank you"<<endl;
			break;
		default:
			cout<<"Enter valid choice";
		}
	}while(choice!=8);
	return 0;
}



