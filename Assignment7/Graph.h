/*
 * Graph.h
 *
 *  Created on: 27-Feb-2019
 *      Author: f10
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include<string>
using namespace std;

class Sparse {

	int start;
	int end;
	int weight;

public:
	friend class Graph;
};



class Graph {

	int m[20][20],n,k;
	string c[20];
	Sparse s[20];

public:
	Graph();
	virtual ~Graph();
	void create_graph();
	void display_graph();
	void create_sparse();
	void sort_sparse();
	void swapdata(Sparse*,Sparse*);
	void kruskal();
};



#endif /* GRAPH_H_ */
