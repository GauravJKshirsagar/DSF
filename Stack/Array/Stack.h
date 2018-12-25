/*
 * Stack.h
 *
 *  Created on: 22-Dec-2018
 *      Author: gaurav
 */

#ifndef STACK_H_
#define STACK_H_
#include <iostream>

template<typename T>
class Stack {
	T *stack=NULL;
	int top;


public:
	Stack();
	virtual ~Stack();
	bool isEmpty();
	bool isFull();
	T pop();
	T peep();
	void push(T);
};

#endif /* STACK_H_ */
