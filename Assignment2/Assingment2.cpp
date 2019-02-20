//============================================================================
// Name        : cpp.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

class Patients
{
		queue<int>q;  //Queue object declared here
		string name;
		string id;
		int prio;
		int age;

public:
		void input(); //Function for accepting incoming patient details
		void treat_next_patient();
		void display();	 //Function for displaying details of next patient to be treated

};

void Patients::input()
{
		cout<<"Enter Name of Patient: ";
		cin>>name;
		cout<<"Enter ID of Patient: ";
		cin>>id;
		cout<<"Enter priority of Patient \n1:Serious ill\n2.Medium illness\n3.General Patient\n";
		cin>>prio;
	    do{
		cout<<"Enter age of Patient"; //Check if valid age of patient is entered
		cin>>age;
	    }while(age<0 || age>150);


		q.priority_enqueue(prio,name,id,age);  //Add patient to queue according to priority


}

void Patients::treat_next_patient()    // displaying details of next patient to be treated
{
	q.priority_deque();

}

void Patients::display()
{
	 q.display();   //Display list of all patients in queue
}


int main() {

		int ch;
		Patients p;  //Object p to all functions of patients class

			do
			{
				cout<<"\nMenu\n1.Add Patients to queue\n2.Treat next patient\n3.Display all patients\n4:Exit\n";
				cout<<"Enter your Choice : ";
				cin>>ch;
				switch(ch)
				{
				case 1: p.input();
						break;

				case 2: p.treat_next_patient();
						break;

				case 3: p.display();
						break;

				case 4: break;

				}

			}while(ch!=4);





	return 0;
}
