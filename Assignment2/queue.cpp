/*
 * queue.cpp
 *
 *  Created on: 26-Dec-2018
 *      Author: f10
 */

#include "queue.h"
#include "linked.h"


template<typename T>
queue<T>::queue() {
	// TODO Auto-generated constructor stub

}

template<typename T>
queue<T>::~queue() {
	// TODO Auto-generated destructor stub
}

template<typename T>
bool queue<T>::isempty()  //Return true if queue is empty else false
{
   if(l.isempty())
	   return true;
   return false;

}


template<typename T>
	T queue<T>::peep()	//Return front element of queue
{
  return(l.display_first());
}

template<typename T>
	void queue<T>::enqueue(T x)
{
  l.insert_last(x);
}

template<typename T>
	void queue<T>::priority_enqueue(int prio,string name,string id,int age)  //Add new element in queue from rear end
{
  l.ins_last_p(prio,name,id,age);

}

template<typename T>
	T queue<T>::dequeue()
{
   T x=l.display_first();
   l.delete_first();
   return x;

}

template<typename T>
	void queue<T>::priority_deque() //Delete element from queue as per priority
{

	l.delete_middle();

}

template<typename T>
	void queue<T>::display() //Delete element from queue as per priority
{

	l.display();

}
