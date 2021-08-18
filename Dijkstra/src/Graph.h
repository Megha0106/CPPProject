/*
 * Graph.h
 *
 *  Created on: Dec 2, 2020
 *      Author: hp
 */

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph {
	int weight[20][20];
	int directed;
	int dist[20];
	int path[20];
	int vn,en;
public:
	Graph();
	void createGraph();
	void dijkstra();
	void display();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
