/*
 * DAF.h
 *
 *  Created on: 07-Apr-2019
 *      Author: gaurav
 */

#ifndef DAF_H_
#define DAF_H_

#include<iostream>
using namespace std;

struct student{
	char name[20];
	//string name;
	int roll_no;
	//string dept;
	char dept[5];
	int marks;
	int chain;
};

class DAF{

	student sg;
	student sp;

public:
	DAF();
	virtual ~DAF();
	inline int index_calc(int);
	void init();
	void create();
	void display();
	void add_record();
	int search_record(int);
	int modify_record(int);
};

#endif /* DAF_H_ */
