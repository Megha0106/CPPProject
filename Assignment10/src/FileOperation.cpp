/*
 * FileOperation.cpp
 * Author: Megha Sonavane
 */
#include<iostream>
#include<fstream>
#include "FileOperation.h"

FileOperation::FileOperation() {
	// TODO Auto-generated constructor stub

}
//===============definition of create()======================================
void FileOperation::create(){
	//Open file in write mode to crete new database
	fstream file("StudDB.dat", ios::out | ios::binary);
	cout<<"New database created..."<<endl;
	//add record to it
	addnew();
	file.close();
}
//===============Definition of AddNew()======================================
void FileOperation::addnew(){
	//read data to be added in student object
	student.input();
	//open file in append mode
	fstream file("StudDB.dat",ios::app | ios::binary);
	//----validating roll number---------
	int flag=1; //to validate roll number

	//open file in read mode with different pointer
	fstream file1("StudDB.dat",ios::in | ios::binary);
	Student s1; //to read records from file
	file1.read((char*)&s1,sizeof(s1));
	//read file till end
	while(!file1.eof())
	{
		//check if roll number is present
		if(s1.getRollNo()==student.getRollNo())
		{
			cout<<"Student with roll number"<<student.getRollNo()<<" already exist..."<<endl;
			flag=0;
			break;
		}
		//else read next record
		else
			file1.read((char*)&s1,sizeof(s1));
	}
	//if roll number is not exist already
	if(flag==1){
		//write to file
		file.write((char*)&student,sizeof(student));
		cout<<"Added successfully.."<<endl;
	}
	file.close();
}

//============definition of display()==========================================
void FileOperation::display(){
	//open file in read mode
	fstream file;
	file.open("StudDB.dat",ios::in | ios::binary);
	//if file not found
	if(!file)
	{
		cout<<"File not found"<<endl;
		exit(1);
	}
	else
	{
		//read first record
		file.read((char*)&student,sizeof(student));
		cout<<"RollNo\tName\tDivision\tAddress"<<endl;
		//display records till end of file
		while(!file.eof())
		{
			student.show(); //display cuurent record
			file.read((char*)&student,sizeof(student)); //read next record
		}
	}
	file.close();
}
//===========definition of search()==================================================
void FileOperation::search(){
	//open file in read mode
	fstream file("StudDB.dat", ios::in | ios::binary);
	//if file not found
	if(!file)
	{
		cout<<"File not found..";
		exit(1);
	}
	else{
		int key;
		bool flag=false;
		cout<<"Enter roll number to be search:";
		cin>>key;
		//read first record
		file.read((char*)&student,sizeof(student));
		//search till end of file
		while(!file.eof()){
			//if key is equal to current roll number
			if(student.getRollNo()==key)
			{
				cout<<"Record found.."<<endl;
				flag=true;//set flag
				cout<<"RollNo\tName\tDivision\tAddress"<<endl;
				student.show(); //display record
				break;
			}
			else //read next record
				file.read((char*)&student,sizeof(student));
		}
		//if roll number not found
		if(!flag)
			cout<<"Record not found.."<<endl;
	}
	file.close();
}
//=======definition of update()=================================
void FileOperation::modify(){
	int rno,flag=0;
	cout<<"Enter roll number of student:";
	cin>>rno;
	//open file in read mode
	fstream file("StudDB.dat", ios::in | ios::binary);
	//create new file for tempory data storage
	fstream newFile("newFile.dat", ios::app |ios::binary);
	//read records from file to search the rno
	if(!file)
	{
		cout<<"File not found.."<<endl;
	}
	else
	{
		file.read((char*)&student,sizeof(student));
		while(!file.eof())
		{
			//if current record is not that to be updated
			if(student.getRollNo()!=rno)
			{
				//write it to newFile
				newFile.write((char*)&student,sizeof(student));
			}
			//if current record is that is to be updated
			else
			{
				cout<<"Record found..."<<endl;
				flag=1;
				//update student details
				string nm,add,d;
				//input updated details
				cout<<"Enter updated details==>"<<endl;
				cin.ignore();
				cout<<"Name:";
				getline(cin,nm);
				cout<<"Address:";
				getline(cin,add);
				cout<<"Division:";
				getline(cin,d);
				//updatting details
				student.setName(nm);
				student.setAddress(add);
				student.setDivision(d);
				newFile.write((char*)&student,sizeof(student));
			}
			//read next record
			file.read((char*)&student,sizeof(student));
		}
		file.close();
		newFile.close();
		remove("StudDB.dat");
		rename("newFile.dat","StudDB.dat");
		if(flag==0)
		cout<<"Record not found..."<<endl;
	}

}
//=========definiiton of delet()=========================================
void FileOperation::delet(){
	int rno,flag=0;
	cout<<"Enter roll number of student to be deleted:";
	cin>>rno;
	//open file in read mode
	fstream file("StudDB.dat", ios::in | ios::binary);
	//create a new file for temporary storage
	fstream newFile("newFile.dat", ios::app | ios::binary);
	//read records from file
	file.read((char*)&student,sizeof(student));
	if(!file)
	{
		cout<<"File not found.."<<endl;
	}
	else{
		while(!file.eof())
		{
			//if current record is not to be deleted
			if(student.getRollNo()!=rno)
			{
				//write record to newFile
				newFile.write((char*)&student,sizeof(student));
			}
			else
			{
				cout<<"Record deleted.."<<endl;
				flag=1;
			}
			//read next record
			file.read((char*)&student,sizeof(student));
		}
		if(flag==0)
			cout<<"Record not found.."<<endl;
		file.close();
		newFile.close();
		remove("StudDB.dat");
		rename("newFile.dat","StudDB.dat");
	}


}
FileOperation::~FileOperation() {
	// TODO Auto-generated destructor stub
}

