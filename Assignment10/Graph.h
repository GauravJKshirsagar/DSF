/*
 * Graph.h
 *
 *  Created on: 27-Feb-2019
 *      Author: gaurav
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include<string>
using namespace std;

class Graph {

	int m[20][20],n,k;
	string c[20];


public:
	Graph();
	virtual ~Graph();
	void create_graph();
	void display_graph();
	void prim();
};

#endif /* GRAPH_H_ */
