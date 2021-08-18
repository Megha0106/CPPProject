/*
 * Heap.cpp
 *  Created on: Nov 28, 2020
 *  Author: Megha Sonavane
 */
#include<iostream>
#include "Heap.h"
using namespace std;

Heap::Heap() {
	// TODO Auto-generated constructor stub

}
//============build heap=============================
void Heap::buildHeap(int arr[],int n){
	for(int i=n/2;i>=0;i--)
		heapify(arr,n,i);
}
//============Heapify method===========================
void Heap::heapify(int arr[],int n,int i)
{
	int largest=i;
	//for left
	int left=2*i+1;
	//for right
	int right=2*i+2;

	if(left<n && arr[left]>arr[largest])
		largest=left;
	if(right<n && arr[right]>arr[largest])
		largest=right;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
//=================heap sort====================================
void Heap::heapSort(int arr[],int n){
	int pass=1;
	for(int i=n-1;i>=0;i--){
		swap(arr[i],arr[0]);
		heapify(arr,i,0);
		cout<<endl<<"Pass "<<pass<<endl;
		display(arr,n);

		pass++;
	}
}
//=============display heap=====================================
void Heap::display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

Heap::~Heap() {
	// TODO Auto-generated destructor stub
}

