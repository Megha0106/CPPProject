/*
 * Graph.cpp
 *
 *  Created on: Dec 15, 2020
 *      Author: hp
 */
#include<iostream>
#include "Graph.h"
using namespace std;
Graph::Graph() {
	// TODO Auto-generated constructor stub

	cout<<"Enter number of verices:";
	cin>>V;
	cout<<"Enter number of edegs:";
	cin>>E;

	for(int i=0;i<V;i++)
	{
		dist[i]=0;
		for(int j=0;j<V;j++)
			weight[i][j]=0;
	}

}

void Graph::create(){
	int a,b,w;
	cout<<"Enter dept for following vertices:"<<endl;
	for(int i=0;i<V;i++){
		cout<<"Vertex "<<i<<":";
		cin>>str[i];
	}
	cout<<"You entered:"<<endl;
	for(int i=0;i<V;i++)
		cout<<i<<": "<<str[i]<<endl;
	cout<<"Enter edges and weight:"<<endl;
	for(int i=0;i<E;i++){
		cout<<"Enter vertex 1 vertex2 weight:";
		cin>>a>>b>>w;
		weight[a][b]=w;
		weight[b][a]=w;
	}

}

void Graph::display(){
	cout<<"Graph is:"<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<weight[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void Graph::prims(){
	int visited[V];
	int totalV=0;
	int current;

	for(int i=0;i<V;i++){
		visited[i]=0;
		dist[i]=5000;
		path[i]=0;
	}
	current=0;
	visited[0]=1;
	totalV=1;
	dist[current]=0;
	while(totalV!=V){

		for(int i=0;i<V;i++){
			if(weight[current][i]!=0){
				if(visited[i]==0){
					if(weight[current][i]< dist[i]){
						dist[i]=weight[current][i];
						path[i]=current;
					}
				}
			}
		}
		//display
		cout<<"Current vertex:"<<current<<endl;
		cout<<"Vertex\t<<Dist\tPath"<<endl;
		for(int i=0;i<V;i++){
			cout<<i<<"\t"<<dist[i]<<"\t"<<path[i]<<endl;
		}
		//find minimum dist
		int minCost=32766;
		for(int i=0;i<V;i++){
			if(visited[i]==0){
				if(dist[i]< minCost){
					minCost=dist[i];
					current=i;
				}
			}
		}
		cout<<"Selected Vertex:"<<current<<endl;
		cout<<"Distance:"<<minCost;
		totalV++;
	}
	//display MST
	cout<<"====================================================================================="<<endl;
	cout<<"DEPT\tPath\tDist"<<endl;
	for(int i=0;i<V;i++){
		cout<<str[i]<<"\t"<<str[path[i]]<<"\t"<<dist[i]<<endl;
	}

}
Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

