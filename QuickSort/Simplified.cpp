/*
 * Simplified.cpp
 *
 *  Created on: Sep 5, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void quick_sort(int a[],int left,int right)
{
	static int pass=0;
	static int n=right+1;
	if(left>=right)
		return;
	int i=left;
	int j=right+1;
	int pivot=a[left];
	while(1)
	{
		do
		{
			i++;
		}while(a[i]<pivot);
		do{
			j--;
		}while(a[j]>pivot);
		if(i>=j)
			break;
		else
			swap(&a[i],&a[j]);
	}
	a[left]=a[j];
	a[j]=pivot;
	cout<<endl<<"Pass "<<++pass<<":"<<endl;
	for(int k=0;k<n;k++)
		cout<<a[k]<<"\t";
	quick_sort(a,left,j-1);
	quick_sort(a,j+1,right);

}
int main()
{
	int n,a[10];
	cout<<"Enter size of array:";
	cin>>n;
	cout<<"Enter elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	quick_sort(a,0,n-1);
	cout<<"After sorting:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}



