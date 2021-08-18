/*
 * Heap.h
 * Created on: Nov 28, 2020
 * Author: Megha Sonavane
 */

#ifndef HEAP_H_
#define HEAP_H_

class Heap {
public:
	Heap();
	void buildHeap(int[],int);
	void heapSort(int[],int);
	void heapify(int[],int,int);
	void display(int[],int);
	virtual ~Heap();
};

#endif /* HEAP_H_ */
