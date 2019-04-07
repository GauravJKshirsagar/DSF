/*
 * Symboltable.h
 *
 *  Created on: 20-Mar-2019
 *      Author: f10
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include<string>
using namespace std;


struct student
{
	int no;
	string name;
	string mobile;
	int chain;

};

class Symboltable {

	student s[10];

public:
	Symboltable();
	virtual ~Symboltable();
	void display_table();
	int index_calculation(string);


	void create_table_without_replacement();
	int search_table_without_replacement(string);
	void delete_table_without_replacement(string);

	void create_table_with_replacement();
	void search_table_with_replacement(string);
	void delete_table_with_replacement(string);
};

#endif /* SYMBOLTABLE_H_ */
