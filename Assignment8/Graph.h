/*
 * Graph.h
 *
 *  Created on: 28-Feb-2019
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
	void Single_source_to_multiple_destination(string);
	void Single_source_to_single_destination(string,string);
	void multiple_source_to_multiple_destination();

};
#endif /* GRAPH_H_ */
