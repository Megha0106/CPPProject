//============================================================================
// Name        : Assignment9.cpp
// Author      : Megha Sonavane
// Description : Heap Sort
//============================================================================

#include <iostream>
#include "Heap.h"
#define MAX 20
using namespace std;

int main() {
	Heap h;
	int n,ch;
	int arr[MAX];
	cout<<"Heap Data Struture"<<endl;
	do{
		cout<<"Enter number of elememts(Max 20):";
		cin>>n;
	}while(n<1||n>20);

	cout<<"Enter "<<n<<" elements:";
	for(int i=0;i<n;i++)
		cin>>arr[i];

	do{
		cout<<endl<<"==================================================================="<<endl;
		cout<<"\t1:Heapify"<<endl<<"\t2:Heap Sort"<<endl<<"\t3:Insert new element to array"<<endl<<"\t0:Exit"<<endl;
		cout<<"\tEnter choice:";
		cin>>ch;
		cout<<"==================================================================="<<endl;
		switch(ch){
		case 1:
			//========Build heap===================
			h.buildHeap(arr,n);
			h.display(arr,n);
			break;
		case 2:
			//======Heap sort=======================
			h.buildHeap(arr,n); //build heap
			h.heapSort(arr,n); //sort heap
			break;
		case 3:
			//=======insert new element to heap=====
			if(n==20)
				cout<<"Sorry..no space available..."<<endl;
			else{
				int data;
				cout<<"\tEnter element:";
				cin>>data;
				arr[n]=data;
				n=n+1;
				cout<<"\tElement inserted..."<<endl;
			}

			break;
		case 0:
			cout<<"\tThank you...";
			break;
		default:
			cout<<"\tInvalid choice.."<<endl;
		}
	}while(ch!=0);
	return 0;
}
