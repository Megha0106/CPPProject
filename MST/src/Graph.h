/*
 * Graph.h
 *
 *  Created on: Nov 30, 2020
 *      Author: hp
 */
#include<iostream>
#ifndef GRAPH_H_
#define GRAPH_H_

struct Edge{
	int u,v,wt;
};
class Graph {
	Edge edge[20];
	int weight[20][20];
	int dist[20];
	int path[20];
	int vn,en;
public:
	Graph();
	void createGrapgh();
	void displayGraph();
	void prims();
	void kruskals();
	void sort();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
