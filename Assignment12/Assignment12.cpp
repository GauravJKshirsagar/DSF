//============================================================================
// Name        : Assignment 12
// Author      : Gaurav Kshirsagar
// Batch       : F-10
// Class       : SE-10
// Roll No     : 23228
//============================================================================

#include <iostream>
#include "DAF.h"
using namespace std;

int main() {

	DAF s;
	int ch,n,i,roll;





	do
	{

			cout<<"\nMenu\n1:Create New Database \n2:Display records\n3:Add Record(s)\n4:Search Record\n5:Modify Record\n6:Exit\n";
			cout<<"\nEnter choice : ";
			cin>>ch;


	switch(ch)
	{

	case 1: s.init();
			cout<<"\n*** Database Created  Successfully*** \n";
			s.display();
			break;

	case 2: s.display();
			break;

	case 3: cout<<"Enter no of records you want to add :";
			cin>>n;
			for(i=1;i<=n;i++)
				s.create();

			cout<<"\n*** Records Added Successfully*** \n";
			s.display();
			break;

	case 4: s.display();
			cout<<"Enter roll no of student to search record: ";
			cin>>roll;
			s.search_record(roll);
			break;


	case 5: s.display();
			cout<<"Enter roll no of student to modify record: ";
				cin>>roll;
				if(s.modify_record(roll)!=-1)
				{
					cout<<"*** Record Successfully Modified ***\n";
					s.display();
				}


		    break;

	case 6:
			break;

	}

	}while(ch!=6);


	return 0;
}
