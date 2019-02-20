//============================================================================
// Name        : Assignment5.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "btree.cpp"
#include "btree.h"
using namespace std;

int main()
{
	btree<string>b;
	string x;

	int ch; //CHOICE

		do{
			cout<<"\nMenu\n1:Insert\n2:Display\n3:Delete\n4:Search\n5:Mirror\n6:Level order display\n7:Exit";
			cout<<"\nEnter choice\n";
			cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter element to insert";
					cin>>x;
					b.insert(x);
					//b.insertNonRecursive(x);
					cout<<"Tree after insertion : ";
						cout<<"\nInorder Display : ";
					b.display();
						cout<<"\nPreorder Display : ";
					b.displayPreorder();
						cout<<"\nPostorder Display : ";
					b.displayPostorder();
						cout<<"\nLevel Order Display is : ";
					b.LevelOrderDisplay();
					break;

			case 2: cout<<"\nInorder Display : ";
						b.display();
					cout<<"\nPreorder Display : ";
						b.displayPreorder();
					cout<<"\nPostorder Display : ";
						b.displayPostorder();
					cout<<"\nLevel Order Display is : ";
						b.LevelOrderDisplay();
					break;

			case 3: cout<<"Enter element to delete";
					cin>>x;
					b.del(x);
					//b.delNonRecursive(x);
					break;

			case 4: cout<<"Enter element to search";
					cin>>x;
					//b.search(x);
					b.searchNonRecursive(x);
					break;

			case 5: //b.mirrorR();
					b.MirrorNonRecursive();
				    break;

			case 6: cout<<"Level Order Display is : ";
					b.LevelOrderDisplay();
					break;

			case 7: break;

		}
		}while(ch!=7);
		return 0;



}
