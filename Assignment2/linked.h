/*
 * linked.h
 *
 *  Created on: 19-Dec-2018
 *      Author: f10
 */

#ifndef linked_H_
#define linked_H_
#include<string>
using namespace std;

template<typename T>
 struct node   //Contains details of every patient
	{
		T data;
		string name;
		string ID;
		int priority;
		int age;
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
	void delete_middle();
	void ins_last_p(int,string,string,int);
	void disp(node<T>*);


};

#endif /* linked_H_ */
