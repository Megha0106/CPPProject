/*
 * Set.cpp
 *
 *  Created on: Dec 30, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;

class Set
{
int a[15],n;
public:
Set(){}
Set(int n)
{
this->n=n;
}
void get();
void sort();
void show();
void operator +(Set);
void operator -(Set);
void operator <(Set); //superset
void operator >(Set); //subset
};
void Set :: operator <(Set s2)
{
Set s3;
}
void Set::get()
{
cout<<"\n\nEnter the Set Values : ";
for(int i=0;i<n;i++)
cin>>a[i];
sort();
}
void Set ::sort()
{
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(a[i]>a[j])
{
int t=a[i];
a[i]=a[j];
a[j]=t;
}
}
void Set::show()
{
for(int i=0;i<n;i++,cout<<"\t")
cout<<a[i];
}
void Set::operator +(Set s2)
{
// int unions[30];
Set s3;
int i=0,j=0,k;
for(k=0;i<n && j<s2.n;k++)
{
if(a[i]==s2.a[j])
{
s3.a[k]=a[i++];
j++;
}
else if(a[i]<s2.a[j])
s3.a[k]=a[i++];
else
s3.a[k]=a[j++];
}
while(i<n)
s3.a[k++]=a[i++];
while(j<s2.n)
s3.a[k++]=s2.a[j++];
cout<<"\n\n\t\tA U B\n\n\t";
s3.n=k;
s3.show();
}
void Set :: operator -(Set s2)
{
Set s3;
int i=0,j=0,k;
for(k=0;i<n && j<s2.n;)
{
if(a[i]==s2.a[j])
{
s3.a[k++]=a[i];
j++;
i++;
}
if(a[i]<s2.a[j])
j++;
else
i++;
}
cout<<"\n\n\t\tA INTERSECTION B\n\n\t";
s3.n=k;
s3.show();
}
int main()
{

int n,n1;
cout<<"\n\n\t\tSET OPERATIONS\n\n";
cout<<"\n\tEnter No.of elements in Set A & B : ";
cin>>n>>n1;
Set s1(n),s2(n1),s3;
s1.get();
s2.get();

cout<<"\n\n\t\tSet A\n\n\t";
s1.show();
cout<<"\n\n\t\tSet B \n\n\t";
s2.show();
s1+s2; //union
s1-s2;//intersection
return 0;
}



