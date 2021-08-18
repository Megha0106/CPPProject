//============================================================================
// Name        : Dijkstra.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Graph.h"
using namespace std;

int main() {
	Graph g;
	g.createGraph();
	g.display();
	g.dijkstra();
	return 0;
}
