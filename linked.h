/*
 * linked.h
 *
 *  Created on: 19-Dec-2018
 *      Author: f10
 */

#ifndef linked_H_
#define linked_H_

template<typename T>
 struct node
	{
		T data;
	    node<T>* next;
	};

template<typename T>
class linked {

	 node <T>* head;

public:
    node<T>* getnode(T);
	linked();
	virtual ~linked();
	bool isempty();
	void insert_first(T);
	void insert_last(T);
	void insert_middle(int,T);
	void display();
	T display_first();
	void delete_first();
	void delete_last();


};

#endif /* linked_H_ */
