/*
 * QuickSort.cpp
 *
 *  Created on: Sep 2, 2020
 *      Author: hp
 */
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int t = *a;
	 *a = *b;
  *b = t;
}
int partition(int a[],int low,int high)
{
	int pivot=a[high];
	int i=(low-1);
	//int temp;
	for(int j=low;j<=high-1;j++)
	{
		if(a[j]<pivot)
		{
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}

void quick_sort(int a[],int low,int high)
{
	int pi;
	if(low<high)
	{
		pi=partition(a,low,high);
		quick_sort(a,low,pi-1);
		quick_sort(a,pi+1,high);
	}
}



int main()
{
	int a[10],n;
	cout<<"Enter size of array:";
	cin>>n;
	cout<<"Enter elements:"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	quick_sort(a,0,n-1);
	cout<<"After sorting:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}



