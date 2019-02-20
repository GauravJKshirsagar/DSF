/*
 * queue.h
 *
 *  Created on: 26-Dec-2018
 *      Author: f10
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "linked.h"
#include "linked.cpp"


template<typename T>
class queue {

	linked<T>l;   //object of linked list adt declared here to access
				  //public functions of that class

public:
	queue();
	virtual ~queue();
	bool isempty();
	T peep();
	void enqueue(T);
	T dequeue();
	void priority_enqueue(int,string,string,int);
	void priority_deque();
	void display();

};

#endif /* QUEUE_H_ */
