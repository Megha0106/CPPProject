//============================================================================
// Name        : MST.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	cout<<"***Minimum spanning tree***"<<endl;
	Graph g;
	g.createGrapgh();
	g.displayGraph();
	int ch;
	do{
		cout<<endl<<"1:MST with Prim's Algoritm"<<endl<<"2:MST with Kruskal's Algorithm"<<endl<<"3:Display Original Graph"<<"0:Exit"<<endl;
		cout<<"Enter choice:";
		cin>>ch;
		switch(ch){
		case 1:
			g.prims();
			break;
		case 2:
			g.kruskals();
			break;
		case 3:
			g.displayGraph();
			break;
		case 0:
			cout<<"Thank You..";
			break;
		default:
			cout<<"Invalid choice.."<<endl;
		}
	}while(ch!=0);
	return 0;
}
