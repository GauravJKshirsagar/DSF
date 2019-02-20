//============================================================================
// Name        : Assignment3.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "btree.h"     //INCLUDED BINARY TREE HEADER FILE
//#include "btree.cpp"
using namespace std;

int main() {

	btree b; //OBJECT OF TREE DECLARED HERE

	int ch; //CHOICE

	do{
		cout<<"\nMenu\n1:Create\n2:Insert\n3:Display\n4:Depth of Tree\n5:Display leaf nodes\n6:Create a copy of Tree\n7:Exit";
		cout<<"\nEnter choice\n";
		cin>>ch;
	switch(ch)
	{
		case 1: b.create();
				cout<<"Tree after creation : ";
				b.display();
				break;

		case 2: //b.insert();
				b.insert_non_recursive();
				cout<<"Tree after insertion : ";
				b.display();
				break;

		case 3: cout<<"Tree is : ";
				b.display();
				break;

		case 4: cout<<"Depth of Tree is : ";
				cout<<b.depthOftree();
				break;

		case 5: cout<<"Leaf nodes are : ";
				b.display_leaf_node();
				break;

		case 6: cout<<"Copy of tree is created : ";
				b.create_a_copy();
				break;

		case 7: break;

	}
	}while(ch!=7);
	return 0;
}
