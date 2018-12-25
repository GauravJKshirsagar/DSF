/*
 * Stack.cpp
 *
 *  Created on: 22-Dec-2018
 *      Author: gaurav
 */

#include "Stack.h"
#define MAX 50
template<typename T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	stack =new T[MAX];
	top=-1;
}

template<typename T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
	delete[]stack;
}
template<typename T>
bool Stack<T>::isEmpty()
{
	if(top==-1)
		return true;
	return false;
}

template<typename T>
T Stack<T>::pop()
{
	T m=stack[top--];
	return m;
}

template<typename T>
T Stack<T>::peep()
{
	return stack[top];
}

template<typename T>
void Stack<T>::push(T x)
{
	stack[++top]=x;
}

template<typename T>
bool Stack<T>::isFull()
{
	if(top==MAX-1)
		return true;
	return false;

}
