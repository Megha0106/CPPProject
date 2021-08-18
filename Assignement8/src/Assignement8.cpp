//============================================================================
// Name        : Assignement8.cpp
// Author      : Megha Sonavane
// Description :Dijkstra's algorithm
//============================================================================

#include <iostream>
#include"Graph.h"
using namespace std;

int main() {
	cout<<"***Shortest Path Finding***"<<endl;
	Graph g;
	//creation of graph
	g.createGraph();
	//display graph
	g.display();
	//find shortest path
	g.dijkstra();
	return 0;
}
