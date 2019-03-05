/*
 * Graph.cpp
 *
 *  Created on: 27-Feb-2019
 *      Author: gaurav
 */


#include<iostream>
#include<fstream>
#include<iomanip>
#include "Graph.h"
# define infinite 32767
using namespace std;

Graph::Graph() {
	// TODO Auto-generated constructor stub
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			m[i][j]=infinite;

	k=0,n=0;
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::create_graph()
{
	/*int ch,c1,c2,w;
	cout<<"Enter no of cities";
	cin>>n;

	do{
		cout<<"Enter connectivity and weight";
		cin>>c1>>c2>>w;

		if(m[c2][c1]!=w)
			m[c1][c2]=w;


		cout<<"Do you wish to continue(1/0)";
		cin>>ch;

	}while(ch);*/

	int ch,c1,c2,w;
	ifstream fin;

	 fin.open("data.txt");

	 fin>>n;

	 while(fin)
	 	 {
		 	 fin>>c1;
		 	 fin>>c2;
		 	 fin>>w;

		 	m[c1][c2]=w;
		 	m[c2][c1]=w;

	 	 }

	 fin.close();


	 fin.open("C.txt");

	 int i=0;

		while(i<n)
		{
			fin>>c[i];
			i++;
		}

		 fin.close();

	cout<<"NETWORK CREATE SUCCESSFULLY";
}

void Graph::display_graph()
{
	int j=0;

		cout<<setw(10)<<"|";
		while(j<n)
		{
			cout<<setw(10)<<c[j]<<"|";
			j++;
		}

		cout<<"\n";

		for(int i=0;i<n;i++)
		{
			cout<<setw(9)<<c[i]<<"|";


			for(int j=0;j<n;j++)
			{
				cout<<setw(10)<<m[i][j]<<"|";
			}
			cout<<"\n";
		}
}

/*
void Graph::prim()
{
	int *visited=new int[n];
	for(int i=0;i<n;i++)
		visited[i]=0;

	int cost=0;
	int min=infinite,min_vertex1,min_vertex2;
	int vcount=0;

	visited[0]=1;

	while(vcount!=n-1)
	{
		min=infinite;

		for(int i=0;i<n;i++)
		{
			if(visited[i]==1)
				{
					for(int j=0;j<n;j++)
						{
							if(m[i][j]!=-1 && m[i][j]<min && visited[j]!=1)
							{
								min=m[i][j];
								min_vertex1=i;
								min_vertex2=j;
							}
						}


				}

		}

		cout<<min_vertex1<<" "<<min_vertex2<<" "<<min<<"\n";

		cost+=min;
		visited[min_vertex2]=1;
		vcount++;

	}


	cout<<" Minimum cost is : "<<cost;

}

*/

void Graph::prim()
{
int visited[n];
int distance[n];
int parent[n];
int current;

		for(int i=0;i<n;i++)
		{
			visited[i]=0;
			parent[i]=0;
			distance[i]=infinite;
		}

	int cost=0,min_vertex;
	int min=infinite,min_vertex1,min_vertex2;
	int vcount=0;

	//distance[0]=0;
	//visited[0]=1;

	current=0;
	visited[current]=1;

	while(vcount!=n-1)
		{

			min=infinite;

			for(int i=0;i<n;i++)
			{
				if(visited[i]==0)
				{
					if(m[current][i]<=distance[i])
					{
						distance[i]=m[current][i];
						parent[i]=current;
					}
				}


			}

			for(int i=0;i<n;i++)
			 {
				if(visited[i]==0 && distance[i]<=min)
				{
					min=distance[i];
					current=i;
				}
			 }

			visited[current]=1;



			vcount++;

		}


	min=0;

	cout<<"\n\n*** EDGES IN MINIMUM SPANNING TREE ARE *** : \n";
	cout<<setw(12)<<"SOURCE"<<"|"<<setw(12)<<"DESTINATION|"<<setw(12)<<"DISTANCE|\n";


	for(int i=0;i<n;i++)
	{

		if(distance[i]!=infinite && i!=parent[i])
		{
			cout<<setw(12)<<c[i]<<"|"<<setw(11)<<c[parent[i]]<<"|"<<setw(10)<<m[i][parent[i]]<<"|\n";
			min=min+distance[i];
		}

	}

	cout<<"*** MINIMUM COST IS : "<<min;

}
