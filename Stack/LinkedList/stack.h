/*
 * stack.h
 *
 *  Created on: 21-Dec-2018
 *      Author: f10
 */

#ifndef STACK_H_
#define STACK_H_
#include "linked.h"
#include "linked.cpp"

template<typename T>
class stack {
	linked<T>l;

public:
	stack();
	virtual ~stack();
	bool isEmpty();
	T pop();
	T peep();
	void push(T);

};

#endif /* STACK_H_ */
