/*
 * linked.cpp
 *
 *  Created on: 19-Dec-2018
 *      Author: f10
 */


#include<iostream>
#include "linked.h"


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
	head->next=temp;
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
	while(temp!=NULL)
	{
		std::cout<<temp->data<<"\n";
		temp=temp->next;
	}
}


template<typename T>
void linked<T>::delete_first()
{
   node<T>*temp=head->next;
   delete(head);
   head=temp;

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
template<typename T>
T linked<T>::display_first()
{
	return(head->data);
}




