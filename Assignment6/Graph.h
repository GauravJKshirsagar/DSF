/*
 * Graph.h
 *
 *  Created on: 07-Feb-2019
 *      Author: gaurav
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <cstring>
using namespace std;

class Friendnode;

class DOB
	{
		int day;
		int month;
		int year;

public:
		friend class Headnode;
		friend class Graph;
	};


class Headnode
{
	int ID;
	string name;
	DOB birthdate;
	Headnode* down;
	Friendnode* right;
public:
	friend class Graph;
};


class Friendnode
{
	//string name;
	Headnode *user;
	int comments;
	Friendnode* next;
public:
	friend class Headnode;
	friend class Graph;

};

class Graph {

	Headnode* leader;
public:
	Graph();
	virtual ~Graph();
	Headnode* makeHeadnode(string,int);
	Friendnode* makeFriendnode(Headnode*);
	bool check_user(string);
	int friend_count(Headnode*);
	void max_friends();
	void comment_count(Headnode*,int*,Headnode**,Headnode**);
	void max_min_comments();
	void birthday_check();
	void BFS();
	void DFS();
	void insert_vertex();
	void insert_edge(string,string);
	void display();
};

#endif /* GRAPH_H_ */
