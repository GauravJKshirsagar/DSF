/*
 * linked.cpp
 *
 *  Created on: 19-Dec-2018
 *      Author: f10
 */


#include<iostream>
#include<iomanip>
#include "linked.h"
using namespace std;


template<typename T>
linked<T>::linked() {
	// TODO Auto-generated constructor stub
 head=NULL;
}

template<typename T>
linked<T>::~linked() {
	// TODO Auto-generated destructor stub
}

template<typename T>
bool linked<T>::isempty()
{
	if(head==NULL)
		return true;
	return false;
}
template<typename T>
node<T>* linked<T>::getnode(T x)
{
  node<T>* temp=new node<T>;
  temp->data=x;
  temp->next=NULL;
  return temp;
}

template<typename T>
void linked<T>::insert_first(T x)
{
 node<T>* temp=getnode(x);
 temp->next=head;
 head=temp;
}

template<typename T>
void linked<T>::insert_last(T x)
{
	node<T>* temp=getnode(x);
	node<T>*p=head;
	if(head==NULL)
	{
		head=temp;
		return;
	}

	while(p->next!=NULL)
		p=p->next;

	p->next=temp;
}

template<typename T>
void linked<T>::insert_middle(int pos,T x)
{

int count=1;
node<T>* temp=head->next;
node<T>* prev=head;
node<T>* ins=getnode(x);

if(pos==1)
	return(this->insert_first(x));

while(count<(pos-1) && temp!=NULL)
	{
		prev=prev->next;
		temp=temp->next;
	}

prev->next=ins;
ins->next=temp;

}


template<typename T>
void linked<T>::display()
{
	node<T>* temp=head;
	cout<<"| Patient Name | Patient ID | Priority | Age |"<<endl;

	while(temp!=NULL)
	{
		cout<<"|"<<setw(14)<<temp->name<<"|"<<setw(12)<<temp->ID<<"|"<<setw(10)<<temp->priority<<"|"<<setw(5)<<temp->age<<"|\n";
		temp=temp->next;
	}
}


template<typename T>
void linked<T>::delete_first()
{
   node<T>*temp=head->next;
   node<T>*temp2=head;
   disp(temp2);
   delete(temp2);
   head=temp;

}

template<typename T>
T linked<T>::display_first()
{
	return(head->data);
}


template<typename T>
void linked<T>::delete_last()
{
	node<T>*temp=head->next;
	node<T>* prev=head;

	while(temp->next!=NULL)
	{
		temp=temp->next;
		prev=prev->next;
	}

	prev->next=NULL;
	delete(temp);

}

/*
 * template<typename T>
void linked<T>::delete_middle()
{
	if(head==NULL)
		{
			cout<<"All patients treated ";
			return;
		}
	if(head->next==NULL)
		{
			return(delete_first());
		}

	node<T>*temp=head;
	node<T>* prev=NULL;

	while(temp!=NULL)
	{
		if(temp->priority==1) //indicates serious patient to be treated first
		{
			if(temp==head)
				return(delete_first());
			prev->next=temp->next;
			disp(temp);
			delete(temp);
			return;
		}

	temp=temp->next;
	if(prev==NULL)
		prev=head;
	else
		prev=prev->next;

	}

	temp=head;
	prev=NULL;


	while(temp!=NULL)
		{
			if(temp->priority==2) //medium illness priority
			{
				if(temp==head)
					return(delete_first());
				prev->next=temp->next;
				disp(temp);
				delete(temp);
				return;
			}

			temp=temp->next;
			if(prev==NULL)
					prev=head;
				else
					prev=prev->next;
		}

	return(delete_first()); //Remaining patients as per normal queue concept of delete first



}*/

template<typename T>
void linked<T>::delete_middle()
{
	if(head==NULL)
		{
			cout<<"All patients treated ";
			return;
		}
	if(head->next==NULL)
		{
			return(delete_first());
		}

	node<T>*temp=head;
	node<T>* prev=NULL;

	int MIN=head->priority; //Store minimum priority
	node<T>*tempMIN=head;
	node<T>* prevMIN=NULL;


	while(temp!=NULL)
	{
		if(temp->priority<MIN) //indicates serious patient to be treated first
		{
			MIN=temp->priority;
			tempMIN=temp;
			prevMIN=prev;

		}

	temp=temp->next;
	if(prev==NULL)
		prev=head;
	else
		prev=prev->next;

	}

	prevMIN->next=tempMIN->next;
	disp(tempMIN);
	delete(tempMIN);
	return;



	//return(delete_first()); //Remaining patients as per normal queue concept of delete first
}

template<typename T>
void linked<T>::ins_last_p(int prio,string name,string id,int age)
{
	node<T>* temp=new node<T>;
	temp->priority=prio;
	temp->name=name;
	temp->ID=id;
	temp->age=age;

	temp->next=NULL;


		node<T>*p=head;
		if(head==NULL)
		{
			head=temp;
			return;
		}

		while(p->next!=NULL)
			p=p->next;

		p->next=temp;

}


template<typename T>
void linked<T>::disp(node<T>* temp)
{
	cout<<"Next Patient to be treated in queue is ";
	cout<<temp->name<<endl;
	cout<<"Patient ID:"<<temp->ID<<endl;
	cout<<"Priority of patient"<<temp->priority<<endl;
	cout<<"Age of Patient"<<temp->age;



}

