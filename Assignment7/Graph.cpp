/*
 * Graph.cpp
 *
 *  Created on: 27-Feb-2019
 *      Author: f10
 */

#include<iostream>
#include<fstream>
#include<iomanip>
#include "Graph.h"
using namespace std;

Graph::Graph() {
	// TODO Auto-generated constructor stub
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			m[i][j]=-1;

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

		 	if(m[c2][c1]!=w)
		 		m[c1][c2]=w;
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


void Graph::swapdata(Sparse* a,Sparse* b)
{
	int temps,tempe,tempw;

	temps=a->start;
	a->start=b->start;
	b->start=temps;

	tempe=a->end;
	a->end=b->end;
	b->end=tempe;

	tempw=a->weight;
	a->weight=b->weight;
	b->weight=tempw;


}


void Graph::create_sparse()
{



	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(m[i][j]!=-1)
				{
					s[k].start=i;
					s[k].end=j;
					s[k].weight=m[i][j];
					k++;
				}

			}

		}


	cout<<setw(12)<<"SOURCE"<<"|"<<setw(12)<<"DESTINATION|"<<setw(12)<<"DISTANCE|\n";

	for(int i=0;i<k;i++)
	{
		cout<<setw(12)<<c[s[i].start]<<"|"<<setw(11)<<c[s[i].end]<<"|"<<setw(10)<<s[i].weight<<"|\n";
	}


}

void Graph::sort_sparse()
{
	for(int i=0;i<k-1;i++)
		{
			for(int j=i+1;j<k;j++)
			{
				if(s[i].weight>s[j].weight)
				{
					swapdata(&s[i],&s[j]);
				}
			}
		}


	cout<<"\n\n*** CONNECTED CITIES IN SORTED ORDER AS PER DISTANCE BETWEEN THEM *** \n\n";

	cout<<setw(12)<<"SOURCE"<<"|"<<setw(12)<<"DESTINATION|"<<setw(12)<<"DISTANCE|\n";

		for(int i=0;i<k;i++)
		{
			cout<<setw(12)<<c[s[i].start]<<"|"<<setw(11)<<c[s[i].end]<<"|"<<setw(10)<<s[i].weight<<"|\n";
		}
}


void Graph::kruskal()
{
	int T[20];
	for(int i=0;i<n;i++)
		T[i]=i;

	int cost=0;
	int x,y;

	cout<<"\n\n*** EDGES IN MINIMUM SPANNING TREE ARE *** : \n";
	cout<<setw(12)<<"SOURCE"<<"|"<<setw(12)<<"DESTINATION|"<<setw(12)<<"DISTANCE|\n";


	for(int i=0;i<k;i++)
	{
		x=T[s[i].start];
		y=T[s[i].end];

		if(T[s[i].start]!=T[s[i].end])
		{
			cost+=s[i].weight;
			//T[s[i].end]=T[s[i].start];

			for(int j=0;j<n;j++)
			{
				if(T[j]==y || T[j]==x)
					T[j]=x;
			}

			cout<<setw(12)<<c[s[i].start]<<"|"<<setw(11)<<c[s[i].end]<<"|"<<setw(10)<<s[i].weight<<"|\n";
		}
	}

	cout<<"*** MINIMUM COST IS : "<<cost;
}
