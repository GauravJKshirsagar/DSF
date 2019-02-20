/*
 * stack.cpp
 *
 *  Created on: 21-Dec-2018
 *      Author: f10
 */

#include "stack.h"
#include "linked.h"
//#include "linked.cpp"
using namespace std;

template<typename T>
stack<T>::stack() {
	// TODO Auto-generated constructor stub

}

template<typename T>
stack<T>::~stack() {
	// TODO Auto-generated destructor stub
}

template<typename T>
bool stack<T>::isEmpty()
{
   if(l.isempty())
	   return true;
   else
	   return false;
}


template<typename T>
T stack<T>::pop()
{
	T k=l.display_first();
	l.delete_first();
	return k;
}


template<typename T>
T stack<T>::peep()
{
   return(l.display_first());
}


template<typename T>
void stack<T>::push(T x)
{
	l.insert_first(x);
}
