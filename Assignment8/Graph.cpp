/*
 * Graph.cpp
 *
 *  Created on: 28-Feb-2019
 *      Author: gaurav
 */

#include<iostream>
#include<fstream>
#include<iomanip>
# define infinite 32767
#include "Graph.h"
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
	 		//cout<<c[i]<<"\n";
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

void Graph::Single_source_to_multiple_destination(string x)
{
	int visited[n];
	int distance[n];
	int source,z;


	//initialize source index
	for(z=0;z<n;z++)
	{
		if(c[z]==x)
		{
			source=z;
			break;
		}

	}

	if(z==n)
	{
		cout<<"City name invalid ! Please enter again";
		return;
	}

	//Start actual algorithm

		for(int i=0;i<n;i++)
		{
			visited[i]=0;
			distance[i]=infinite;
		}

	int min_vertex;
	int min=infinite;
	int vcount=0;

	distance[source]=0;
	//visited[0]=1;

	while(vcount!=n-1)
		{

			min=infinite;

			for(int i=0;i<n;i++)
			{
				if(distance[i]<min && visited[i]==0)
				{
					min=distance[i];
					min_vertex=i;
				}

			}

			visited[min_vertex]=1;

			for(int j=0;j<n;j++)
			{
				if(visited[j]!=1 &&((distance[min_vertex]+m[min_vertex][j])<distance[j]))
				{
					distance[j]=distance[min_vertex]+m[min_vertex][j];
				}
			}


			vcount++;

		}


	cout<<"\n\n ***  SHORTEST DISTANCES are as follows : \n\n";
	cout<<setw(12)<<"SOURCE"<<"|"<<setw(12)<<"DESTINATION|"<<setw(12)<<"DISTANCE|\n";

	for(int i=0;i<n;i++)
	{
		if(i!=source)
			cout<<setw(12)<<c[source]<<"|"<<setw(11)<<c[i]<<"|"<<setw(10)<<distance[i]<<"|\n";
	}

}

void Graph::Single_source_to_single_destination(string x1,string x2)
{
	int visited[n];
		int distance[n];
		int source,dest,z;


		//initialize source index
		for(z=0;z<n;z++)
		{
			if(c[z]==x1)
			{
				source=z;
				break;
			}
		}
		if(z==n)
		{
			cout<<"Source City name invalid ! Please enter again";
			return;
		}

		for(z=0;z<n;z++)
		{
			if(c[z]==x2)
			{
				dest=z;
				break;
			}
		}
		if(z==n)
		{
			cout<<"Source City name invalid ! Please enter again";
			return;
		}

		//Start actual algorithm

			for(int i=0;i<n;i++)
			{
				visited[i]=0;
				distance[i]=infinite;
			}

		int min_vertex;
		int min=infinite;
		int vcount=0;

		distance[source]=0;
		//visited[0]=1;

		while(vcount!=n-1)
			{

				min=infinite;

				for(int i=0;i<n;i++)
				{
					if(distance[i]<min && visited[i]==0)
					{
						min=distance[i];
						min_vertex=i;
					}

				}

				visited[min_vertex]=1;

				for(int j=0;j<n;j++)
				{
					if(visited[j]!=1 &&((distance[min_vertex]+m[min_vertex][j])<distance[j]))
					{
						distance[j]=distance[min_vertex]+m[min_vertex][j];
					}
				}


				vcount++;

			}


		cout<<"\n\n ***  SHORTEST DISTANCE is as follows : \n\n";
		cout<<setw(12)<<"SOURCE"<<"|"<<setw(12)<<"DESTINATION|"<<setw(12)<<"DISTANCE|\n";

		for(int i=0;i<n;i++)
		{
			if(i!=source  && i==dest)
				cout<<setw(12)<<c[source]<<"|"<<setw(11)<<c[i]<<"|"<<setw(10)<<distance[i]<<"|\n";
		}

}

void Graph::multiple_source_to_multiple_destination()
{
	for(int i=0;i<n;i++)
		Single_source_to_multiple_destination(c[i]);
}
