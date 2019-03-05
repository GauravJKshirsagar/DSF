//============================================================================
// Name        : Assignment8.cpp
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
	string x1,x2;


		do{
			cout<<"\nMenu\n1:Create a network of cities\n2:Display Graphically \n";
			cout<<"3:Single source to multiple destination\n";
			cout<<"4:Single source to single destination\n";
			cout<<"5:Multiple source to multiple destination\n";
			cout<<"6:Exit\n";
			cout<<"\nEnter choice\n";
			cin>>ch;
		switch(ch)
		{
			case 1: g.create_graph();
					break;

			case 2: g.display_graph();
					break;

			case 3: cout<<"Enter name of source city : ";
					cin>>x1;
					g.Single_source_to_multiple_destination(x1);
					break;

			case 4: cout<<"Enter name of source city : ";
					cin>>x1;
					cout<<"Enter name of destination city : ";
					cin>>x2;
					g.Single_source_to_single_destination(x1,x2);
					break;

			case 5:	g.multiple_source_to_multiple_destination();
					break;

			case 6:
					break;


		}
		}while(ch!=6);
		return 0;
	}
