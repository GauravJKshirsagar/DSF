//============================================================================
// Name        : Assignment7.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Graph.h"

int main()
{
	Graph g;
	int ch;


		do{
			cout<<"\nMenu\n1:Create a network of cities\n2:Display\n3:Create MST using Kruskal\n4:Exit";
			cout<<"\nEnter choice\n";
			cin>>ch;
		switch(ch)
		{
			case 1: g.create_graph();
					break;

			case 2: g.display_graph();
					break;

			case 3:	g.create_sparse();
					g.sort_sparse();
					g.kruskal();
					break;

			case 4: //EXIT CASE
					break;


		}
		}while(ch!=4);
		return 0;
	}
