//============================================================================
// Name        : Assignment10.cpp
// Author      : 
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
			cout<<"\nMenu\n1:Create a network of cities\n2:Display\n3:Create MST using Prim's Algo\n4:Exit";
			cout<<"\nEnter choice\n";
			cin>>ch;
		switch(ch)
		{
			case 1: g.create_graph();
					break;

			case 2: g.display_graph();
					break;

			case 3: g.prim();
					break;

			case 4:
					break;
		}
		}while(ch!=4);
		return 0;
	}

