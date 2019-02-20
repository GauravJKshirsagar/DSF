//============================================================================
// Name        : Assignment6.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph g;

	int ch;
	int ch2;
	string name;
	string name_f;

		do{
			cout<<"\nMenu\n1:Add Users\n2.Add friends\n3:Display\n4.Max_friends\n5:Min/max comments\n6:Birthday This month\n7:Exit";
			cout<<"\nEnter choice\n";
			cin>>ch;
		switch(ch)
		{
			case 1:
					do
					{
						g.insert_vertex();
						cout<<"Do you wish to add more users ?(1/0)";
						cin>>ch2;

					}while(ch2);
					break;

			case 2: do
					{
						cout<<"Enter name of user to add friends : ";
						cin>>name;
						if(!g.check_user(name))
							{
								cout<<"Sorry , User not found !";
								break;
							}

						cout<<"Enter name of friend to add : ";
						cin>>name_f;

						if(!g.check_user(name_f))
							{
								cout<<"Sorry , Friend not found ! ";
							}
						else
							{

								g.insert_edge(name,name_f);
								g.insert_edge(name_f,name);
							}


						cout<<"Do you wish to add more friends ?(1/0)";
						cin>>ch2;

					}while(ch2);
					break;

			case 3: g.display();
					break;

			case 4: g.max_friends();
					break;

			case 5: g.max_min_comments();
					break;

			case 6: g.birthday_check();
					break;

			case 7:
					break;
		}
		}while(ch!=7);
		return 0;
	}
