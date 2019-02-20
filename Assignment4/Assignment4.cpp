//============================================================================
// Name        : Assignment4.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
#include "btree.h"
//using namespace std;


//+*+A*bcef


int main() {

	btree b;

	int ch;

	do{
		cout<<"\nMenu\n1:Create exp tree from prefix\n2:Create tree from post\n3:Display Recursive\n4:Display NonRecursive\n5:exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
	switch(ch)
	{
		case 1:
				b.create_exp_tree_pre();
				break;

		case 2: b.create_exp_tree_post();
				break;

		case 3: cout<<"\nInorder Display : ";
					b.displayInorder();
				cout<<"\nPreorder Display : ";
				    b.displayPreorder();
				cout<<"\nPostorder Display : ";
					b.displayPostorder();
				break;

		case 4: cout<<"\nInorder Non-Recursive Display : ";
					b.displayInorderNonRecursive();
				cout<<"\nPreorder Non-Recursive Display : ";
					b.displayPreorderNonRecursive();
				cout<<"\nPostorder Non-Recursive Display : ";
					b.displayPostorderNonRecursive();
				break;

		case 5:
				break;

		case 6:
				break;

		case 7: break;

	}
	}while(ch!=6);
	return 0;
}
