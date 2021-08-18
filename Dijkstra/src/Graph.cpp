/*
 * Graph.cpp
 *
 *  Created on: Dec 2, 2020
 *      Author: hp
 */
#include<iostream>
#include "Graph.h"
using namespace std;
Graph::Graph() {
	// TODO Auto-generated constructor stub
	cout<<"Enter 1:Directed graph"<<endl<<"0:Undirected graph::";
	cin>>directed;
	cout<<"Enter number of vertices:";
	cin>>vn;
	cout<<"Enter number of edges:";
	cin>>en;
	for(int i=0;i<vn;i++)
		for(int j=0;j<vn;j++)
			weight[i][j]=0;

}
//=============create graph=========================
void Graph::createGraph(){
	int a,b,w;
	if(directed==0)
	{
		for(int i=0;i<en;i++){
			cout<<"Enter vertices and weight:";
			cin>>a>>b>>w;
			weight[a][b]=w;
			weight[b][a]=w;
		}
	}
	else
	{
		for(int i=0;i<en;i++){
			cout<<"Enter vertices and weight:";
			cin>>a>>b>>w;
			weight[a][b]=w;
		}
	}

}
//=========display graph==========================
void Graph::display(){
	cout<<"Graph matix is:";
	for(int i=0;i<vn;i++){
		cout<<endl;
		for(int j=0;j<vn;j++){
			cout<<weight[i][j]<<" ";
		}
	}
}
//================dijkstra algorithm==============
void Graph::dijkstra(){
	int visited[vn];
	int src,current;
	cout<<endl<<"Enter source vertex:";
	cin>>src;

	//find initial distance from source to all vertices
	for(int i=0;i<vn;i++){
		if(weight[src][i]!=0)
			dist[i]=weight[src][i];
		else
			dist[i]=32767;
		path[i]=src;
		visited[i]=0;
	}
	//display initial distances from source
	cout<<"Vertex\tPath\tDistance"<<endl;
	for(int i=0;i<vn;i++){
		cout<<i<<"\t"<<path[i]<<"\t"<<dist[i]<<endl;
	}
	//take source as current vertex and make it visited
	current=src;
	visited[current]=1;


	for(int j=0;j<vn-2;j++){
		int mindist=32767;
		//find minimum distance from current to all other vertices
		for(int i=0;i<vn;i++){
			if(visited[i]==0 && dist[i]<mindist){
				mindist=dist[i];
				current=i;
			}
		}
		//display selected vertex i.e. in current
		cout<<endl<<"Selected vertex:"<<current;
		cout<<endl<<"Cost:"<<mindist<<endl;
		//make current as visited
		visited[current]=1;


		//find shortest path from current
		for(int i=0;i<vn;i++){
			if(visited[i]==0 && (dist[current]+weight[current][i]) < dist[i]){
				if(weight[current][i]!=0){
					dist[i]=dist[current]+weight[current][i];
					path[i]=current;
				}

			}
		}
		cout<<endl<<"Current status:"<<endl;
				cout<<"Vertex\tVisted\tpath\tDistance"<<endl;
				for(int i=0;i<vn;i++){
					cout<<i<<"\t"<<visited[i]<<"\t"<<path[i]<<"\t"<<dist[i]<<endl;
				}
	}
	//display shortest path
	cout<<endl<<"Shortest path from source to all verices:"<<endl;
	for(int i=0;i<vn;i++){
		if(i!=0){
			cout<<endl<<"Vertex:"<<i<<" Distance:"<<dist[i]<<" Path:"<<i;
			int j=i;
					do
					{
						j=path[j];
						cout<<" <- "<<j;
					}while(j!=src); //j!=Source
		}
	}

}
Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

