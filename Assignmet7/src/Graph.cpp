
#include<iostream>
#include "Graph.h"
using namespace std;
Graph::Graph() {
	// TODO Auto-generated constructor stub
	do{
		cout<<"Enter number of vertice:";
		cin>>vn;
		cout<<"Enter number of edges:";
		cin>>en;
	}while(vn<1 || vn>20 || en<1 ||en>20);

	for(int i=0;i<vn;i++)
	{
		for(int j=0;j<en;j++)
		{
			weight[i][j]=0;
		}
	}

}
//==============definition of create graph===========================
void Graph::createGrapgh(){
	int a,b,w;
	cout<<"Enter department for following vartices:"<<endl;
	for(int i=0;i<vn;i++)
	{
		cout<<"Vertex "<<i<<":";
		cin>>str[i];
	}
	cout<<"===================================================================="<<endl;
	cout<<"You entered:"<<endl;
	for(int i=0;i<vn;i++)
		cout<<i<<":"<<str[i]<<endl;
	cout<<"===================================================================="<<endl;
	cout<<"Enter edges in graph::"<<endl;
	for(int i=0;i<en;i++){
		cout<<"Enter verices and weight:";
		cin>>a>>b>>w;
		edge[i].u=a;
		edge[i].v=b;
		edge[i].wt=w;
		weight[a][b]=w;
		weight[b][a]=w;
	}
}
//========prims algorithm==========================================
void Graph::prims(){
	int totalVisited=0;
	int visited[vn];
	//initialize default values
	for(int i=0;i<vn;i++){
		dist[i]=5000;
		visited[i]=0;
		path[i]=0;
	}
	//display initial contents
	cout<<"Vertex\tDist\tVisited";
	for(int i=0;i<vn;i++){
		cout<<endl;
		cout<<i<<"\t";
		cout<<dist[i]<<"\t";
		cout<<visited[i]<<" ";
	}
	//start from 0th vertex
	int current=0;
	visited[0]=1;
	totalVisited=1;
	dist[current]=0;

	//repeate till all verices are visited
	while(totalVisited!=vn){

		cout<<endl<<"=========================================="<<endl;
		cout<<"Current Vertex:"<<current<<endl;
		cout<<"Total Visited:"<<totalVisited<<endl;
		//find distance from current vertex to all other connected vertices which are not visited
		for(int i=0;i<vn;i++){
			if(weight[current][i]!=0){
				if(visited[i]==0)
				{
					//if current distance is smaller than previous, replace it
					if(weight[current][i]<dist[i]){
						dist[i]=weight[current][i];
						path[i]=current;
					}
				}
			}
		}
		//display distance from current to all other verices
		cout<<"From"<<current<<endl;
		cout<<"Vertex\tDist\tVisited";
		for(int i=0;i<vn;i++){
			cout<<endl;
			cout<<i<<"\t";
			cout<<dist[i]<<"\t";
			cout<<visited[i]<<" ";
		}
		int minCost=32767;
		//find minimum distance from available
		for(int i=0;i<vn;i++){
			if(visited[i]==0){
				if(dist[i]<minCost){
					minCost=dist[i];
					current=i;
				}
			}
		}

		//marks the visited of current as 1
		visited[current]=1;
		totalVisited++;
		//display selected vertex and its cost
		cout<<endl<<"Selected vertex:"<<current<<endl;
		cout<<"Mincost:"<<minCost<<endl;

		cout<<"Vertex\tDist\tVisited";
		for(int i=0;i<vn;i++){
			cout<<endl;
			cout<<i<<"\t";
			cout<<dist[i]<<"\t";
			cout<<visited[i]<<" ";
		}
	}
	//display mst
	int cost=0;
	cout<<endl<<"=================================================================";
	cout<<endl<<"Minimum Spanning tree is:"<<endl;
	cout<<"Department\tPath\tDistance"<<endl;
	for(int i=0;i<vn;i++)
	{
		cout<<endl;
		cout<<str[i]<<"\t\t";
		cout<<str[path[i]]<<"\t";
		cout<<dist[i]<<"\t";
		cost+=dist[i];
	}
	cout<<endl<<"Total Cost="<<cost<<endl;
}
//=========kruskals algorithm=====================================
void Graph::kruskals(){
	cout<<"Eges are:"<<endl;
	cout<<"U V Weight"<<endl;
	for(int i=0;i<en;i++)
		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].wt<<endl;
	//cout<<"After sorting:"<<endl;
	sort();
	int connt[en];
	int val=1,s,l;
	int cnt=0;
	int j=0;
	Edge temp[20];
	cout<<endl<<"================================================================="<<endl;
	while(cnt<en-1 && j<en){
		//if both vertices are not visited
		if(connt[edge[j].u]==0 && connt[edge[j].v]==0){
			cout<<"Edge selected:"<<edge[j].u<<" "<<edge[j].v<<" "<<edge[j].wt<<endl;
			temp[cnt]=edge[j];
			connt[edge[j].u]=connt[edge[j].v]=val;
			val++;
			cnt++;
		}
		//if both vertices have different connection value
		else if(connt[edge[j].u]!=connt[edge[j].v]){
			cout<<"Edge selected:"<<edge[j].u<<" "<<edge[j].v<<" "<<edge[j].wt<<endl;
			temp[cnt]=edge[j];
			//if both vertices are visited
			if(connt[edge[j].u]!=0 && connt[edge[j].v]!=0){

				//replace smaller connt value among both with grater one
				//if first vertex is having less connt value
				if(connt[edge[j].u] < connt[edge[j].v])
				{
					s=connt[edge[j].u];
					l=connt[edge[j].v];
				}
				//if connt value of second is less
				else{
					s=connt[edge[j].v];
					l=connt[edge[j].u];
				}
				//replace large value with smaller
				for(int i=0;i<en;i++){
					if(connt[i]==l)
						connt[i]=s;
				}
				cnt++;
			}
			//if only first vertex is visited
			else if(connt[edge[j].u]!=0 && connt[edge[j].v]==0){
				connt[edge[j].v]=connt[edge[j].u];
				cnt++;
			}
			//if only second vertex is visited
			else{
				connt[edge[j].u]=connt[edge[j].v];
				cnt++;
			}
		}
		//if both vertices have same connt values, reject it
		else
			cout<<"Edge Rejected:"<<edge[j].u<<" "<<edge[j].v<<" "<<edge[j].wt<<endl;
		j++;
	}
	cout<<endl<<"================================================================="<<endl;
	cout<<"Minimum spanning tree with kruskal's algorithm:"<<endl;
	int cost=0;
	cout<<"Dept1\tDept2\tWeight"<<endl;
	for(int i=0;i<cnt;i++){
		cout<<str[temp[i].u]<<"\t"<<str[temp[i].v]<<"\t"<<temp[i].wt<<endl;
		cost+=temp[i].wt;
	}
	cout<<endl<<"Total cost:"<<cost;
}
//========definition of sort=======================================
void Graph::sort(){
	bool swapped=false;
	for(int i=0;i<en;i++){
		for(int j=0;j<en-i-1;j++){
			if(edge[j].wt > edge[j+1].wt){
				swap(edge[j],edge[j+1]);
				swapped=true;
			}
		}
		if(!swapped)
			break;
	}
}
//=======display graph==============================================
void Graph::displayGraph(){
	cout<<endl<<"Matrix is:"<<endl;
	for(int i=0;i<vn;i++){
		cout<<" ";
		for(int j=0;j<vn;j++){
			cout<<weight[i][j]<<" ";
		}
		cout<<endl;
	}
}
Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

