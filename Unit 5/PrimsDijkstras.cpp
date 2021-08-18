//============================================================================
// Name        : Prims.cpp
// Author      : Deepali
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct Edge
{ int U,V,wt;
};
class Graph
{
private:
	int weight[20][20];//{{0,1,5},{0,2,4},{0,3,6},{0,4,2},{1,3,2},{1,5,3},{2,4,3},{3,4,1},{3,5,2},{4,5,4}};
	int visited[20], d[20],p[20];
	int v,e;
	Edge edge[20];
public:
	Graph();
	void creategraph();
	void prim();
	void sortg();
	void kruskals();
	void dijktras();
};

Graph::Graph()
{

	v=6;
	e=10;
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			weight[i][j]=0;
}

void Graph::dijktras()
{
int i,j,k,u,min,current;
int s;
cout<<endl<<"Enter source";
cin>>s;
for (i=0;i<v;i++)
	{
	  visited[i] =0;
	  if(weight[s][i]!=0)
		  d[i] = weight[s][i];
	  else d[i] = 32767;
	  p[i]=s;
	}
cout<<"shortest path= 0";
current=s;
visited[current]=1;
d[s]=0;
cout<<endl<<"visited   distance and path status is :"<< endl<<"i , visited[i]     p[i]     , d[i]";
	for (i=0;i<v;i++)
	{	cout<<endl;
	    //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
	    cout<< endl<<"for I="<<i;
	    cout<<"Visited[i]"<<visited[i];
	    cout<<" p[i]= "<<p[i];
	   	cout<<" d[i]= "<<d[i];

	}

for(i=0;i<v-2;i++)
{
	min=32767;
	for(j=0;j<v;j++)
	{
		if (min>d[j] && visited[j]==0)
		{
			min=d[j];
			current=j;
		}
	}
	cout<<endl<<"Selected Vertex is "<<current;
	cout<<endl<<"Minimum is "<<min;

	visited[current]=1;
	for(k=0;k<v;k++)
	{
		if(visited[k]==0 && (d[current]+weight[current][k])<d[k])
		{
			if(weight[current][k]!=0)
			{
				d[k]=d[current]+weight[current][k];
			    p[k]=current;
			}
		}
	}
	cout<<endl<<"visited   distance and path status is :"<< endl<<"i , visited[i]     p[i]     , d[i]";
		for (int m=0;m<v;m++)
		{	cout<<endl;
		    //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
		    cout<< endl<<"for I="<<m;
		    cout<<"Visited[i]"<<visited[m];
		    cout<<" p[i]= "<<p[m];
		   	cout<<" d[i]= "<<d[m];

		}
}
cout<<endl<<"Shortest Path from Source to all destinations";
cout<<endl<<"Source is -->"<<s<<endl;
for(i=0;i<v;i++)
{
	if(i!=0) //if i!=source
	{
		cout<<endl<<"Vertex = "<<i<<", Distance = "<<d[i];
		cout<<"Path = "<<i;
		j=i;
		do
		{
			j=p[j];
			cout<<" <- "<<j;
		}while(j!=0); //j!=Source
	}

}

}
void Graph::sortg()
{
	int i,j;
    Edge temp;
	for(i=0;i<e-1;i++)
			{	for(j=0;j<e-1;j++)
				{	if(edge[j].wt>edge[j+1].wt)
					{
					        temp=edge[j+1];
					        edge[j+1]=edge[j];
							edge[j]=temp;

					}
				}
			}
		cout<<"Sorted List of edges"<<endl;
		for(int i=0;i<e;i++)
			cout<<edge[i].U<<", "<<edge[i].V<<", "<<edge[i].wt<<endl;
}
void Graph::kruskals()
{
	int i,j;
	 //Edge temp;
	cout<<"edge array is:"<<endl;
	for (i=0;i<e;i++)
			{
			 cout<<edge[i].U<<", "<<edge[i].V<<", "<<edge[i].wt<<endl;
			  }

	sortg(); // Sort the list of edges

	Edge t[15];
	int conn[10],k,r,p,Val,cnt=0;
	for (i=0;i<e;i++)
			conn[i]=0;
	 Val=1;
	 cnt=0;
	 j=0;
	       while(cnt<e-1 && j<e)
	       {	//both vertices are not visited
	    	 if(conn[edge[j].U]==0 && conn[edge[j].V]==0)
			{    cout<<"edge selected"<<edge[j].U<<", "<<edge[j].V<<", "<<edge[j].wt<<endl;
			     t[cnt]=edge[j];
			     conn[edge[j].U]=Val;
			     conn[edge[j].V]=Val;
			     Val++;
			     cnt++;
			}
	    	else if(conn[edge[j].U]!=conn[edge[j].V])//if conn value of both vertices is not equal
			{
			  cout<<"edge selected"<<edge[j].U<<", "<<edge[j].V<<", "<<edge[j].wt<<endl;

			  if(conn[edge[j].U]!=0 && conn[edge[j].V]!=0)//if both vertices are visited
			  {
			     t[cnt]=edge[j];
			     if(conn[edge[j].U]<conn[edge[j].V])//if connected value of first vertex is less
			     {
			    	 r=conn[edge[j].U];
				     p=conn[edge[j].V];
			     }
			     else //if connected value of second vertex is less
			     {   r=conn[edge[j].V];
				     p=conn[edge[j].U];
			     }
			     for(k=0;k<e;k++)//replace bigger connected value-p with small value-r
			     {
			    	 if(conn[k]==p)
				     conn[k]=r;
			     }
			     cnt++;
			   }
			   else if(conn[edge[j].U]==0 && conn[edge[j].V]!=0)//if first vertex is not visited & second is visited
			   {
			    	t[cnt]=edge[j];
			        conn[edge[j].U]=conn[edge[j].V];
			        cnt++;
			   }
			   else //if first vertex is visited & second is not visited
			   {
			    	t[cnt]=edge[j];
			        conn[edge[j].V]=conn[edge[j].U];
			        cnt++;
			    }

			}
			else //Both verticces has same connected value-reject edge--- forms cycle
				cout<<"edge Rejected"<< edge[j].U<<", "<<edge[j].V<<", "<<edge[j].wt<<endl;

		       j++;
	       }
	       cout<<"Krskals MST contains following edges::"<<endl;
	       int cost=0;
	       for(i=0;i<cnt;i++)
	       {	   cout<<t[i].U<<", "<<t[i].V<<", "<<t[i].wt<<endl;
	       cost=cost+t[i].wt;
	       }
	       cout<<endl<<"Total Cost of MST is "<<cost;
}
void Graph::creategraph()
{
	int i,a,b,w;

	cout<<"Enter number of vertices";
	cin>>v;
	cout<<"Enter number of edges";
	cin>>e;



	for ( i=0;i<v;i++)
	{
	  p[i] = visited[i] =0;
	  d[i] = 5000;
	}
	for (i=0;i<e;i++)
		{
		  cout<<"Enter edge a,b and weight w : ";
		  cin>>a>>b>>w;
		  weight[a][b]=w;
		  edge[i].U=a;
		  edge[i].V=b;
		  edge[i].wt=w;
		  //weight[b][a]=w;
		}
    cout<<"Matrix is"<<endl;
	for (i=0;i<v;i++)
	{	cout<<"  ";
		for (int j=0;j<v;j++)
			cout<<weight[i][j]<<"  ";
        cout<<endl;
	}
}


void Graph::prim()
{
	int current, totalvisited, mincost,i;
	current=0; d[current]=0;

	totalvisited =1;
	visited[current]=1;


	cout<<endl<<"visited   distance and path status is :"<< endl<<"i , visited[i]     p[i]     , d[i]";
	for (i=0;i<v;i++)
	{	cout<<endl;
	    //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
	    cout<< endl<<"for I="<<i;
	    cout<<"Visited[i]"<<visited[i];
	    cout<<" p[i]= "<<p[i];
	   	cout<<" d[i]= "<<d[i];

	}

	while(totalvisited!=v)
	{
	cout<<endl<<"total visited="<<totalvisited;


	for (i=0;i<v;i++)
		  {
			 if(weight[current][i]!=0)
			 if(visited[i]==0)
			 if(d[i]>weight[current][i])
			 {
				d[i] = weight[current][i];
				p[i] = current;
			 }
		  }
	  cout<<endl<<"visited   distance and path status is :"<< endl<<"i , visited[i]     p[i]     , d[i]";
	  	for (i=0;i<v;i++)
	  	{	cout<<endl;
	  	    //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
	  	    cout<< endl<<"for I="<<i;
	  	    cout<<"Visited[i]"<<visited[i];
	  	    cout<<" p[i]= "<<p[i];
	  	   	cout<<" d[i]= "<<d[i];

	  	}
	 mincost= 32767;
	 cout<<endl<<"finding minimum cost";
	 for (i=0;i<v;i++)
	 {
		if(visited[i] ==0)
		if (d[i] <mincost)
		{
			mincost = d[i];
			current = i;
		}

	 }
	 cout<< endl<<"for I="<<i;
	 cout<<"mincost= "<<mincost;
	 cout<<"current= "<<current;


	 visited[current] = 1;
	 totalvisited++;

	 cout<<endl<<"current= "<<current<<"  Total Visited== "<<totalvisited;
	 //for(int j=0;j<3;j++)

	}   /*end of while loop */
	mincost =0;
	for (i=0;i<v;i++)
	     mincost += d[i];

	cout<<"Minimum cost = ";
	cout<<mincost;
	cout<<"Minimum span tree is";
	cout<<endl<<"After Manip visited   distance and path status is :";
	cout<<endl<<"i , visited[i]     p[i]     , d[i]";
		for (i=0;i<v;i++)
		{	cout<<endl;
		    cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
		}



}   /*end of prim */
int main()
{
Graph g;
g.creategraph();
cout<<endl<<"Dijkstras Algorithm "<<endl;
g.dijktras();
/*cout<<endl<<"Prims Algorithm "<<endl;
g.prim();
cout<<endl<<"Kruskals Algorithm "<<endl;
g.kruskals();*/
return 0;
}

