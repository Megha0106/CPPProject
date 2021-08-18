/*
 * Graph.h
 *
 *  Created on: Dec 15, 2020
 *      Author: hp
 */

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph {
	int weight[20][20];
	int dist[20];
	int path[20];
	std::string str[20];
	int V,E;
public:
	Graph();
	void create();
	void display();
	void prims();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
