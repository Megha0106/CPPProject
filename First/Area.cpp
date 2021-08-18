/*
 * Area.cpp
 *
 *  Created on: Aug 5, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
//declaring class
/*class Circle
{
private:
	//data members
	double radius;
	//member functions
public:
	void input_C()
	{
		cout<<"Enter radius of circle:"<<endl;
		cin>>radius;
	}
	double area_C()
	{
		return 3.14*radius*radius;
	}
	double circumference()
	{
		return 2*3.14*radius;
	}
};*/
class Rectangle
{
private:
	//structure for dimensions
	struct dimension
	{
		float lenght;
		float breadth;
	}d;
	double area_R();
	double perimeter();
public:
	void input_R(int);

};
//definition of member functions outside class
void Rectangle::input_R(int i)
{
	cout<<"Enter length and breadth of rectangle"<<i<<":";
	cin>>d.lenght>>d.breadth;
	cout<<"Area of square:"<<area_R()<<endl;
	cout<<"Perimeter of square:"<<perimeter()<<endl<<endl;
}
double Rectangle::area_R()
{
	return d.lenght*d.breadth;
}
double Rectangle::perimeter()
{
	return 2*(d.lenght+d.breadth);
}

//main function
int main()
{
	//object creation for square
	Rectangle r[3];
	for(int i=0;i<3;i++)
	r[i].input_R(i+1);
	return 0;
}


