//============================================================================
// Name        : Assignment9.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Symboltable.h"
using namespace std;

int main() {

	Symboltable table;
	string x;
	int ch,flag;


	do
	{
		cout<<"\nMenu\n1:Create table without replacement\n2:Create table with replacement\n";
		cout<<"3:Insert Data\n4:Display table\n5:Search \n6:Delete\n7:Exit\n";
		cout<<"\nEnter choice\n";
		cin>>ch;

		switch(ch)
		{
			case 1: flag=0;
					cout<<"******** TABLE CREATED ***********\n";
					table.display_table();
					break;

			case 2: flag=1;
					cout<<"******** TABLE CREATED ***********\n";
					table.display_table();
					break;

			case 3: if(!flag)
						table.create_table_without_replacement();
					else
						table.create_table_with_replacement();

					table.display_table();

					break;

			case 4: table.display_table();
					break;

			case 5: cout<<"Enter mobile number of student to search : ";
					cin>>x;

					if(!flag)
						table.search_table_without_replacement(x);
					else
						table.search_table_without_replacement(x);
					break;

			case 6: cout<<"Enter mobile number of student to delete : ";
					cin>>x;

					if(!flag)
						table.delete_table_without_replacement(x);
					else
						table.delete_table_without_replacement(x);

					table.display_table();

					break;

			case 7: break;

		}

	}while(ch!=7);
}
