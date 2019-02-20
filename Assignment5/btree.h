/*
 * btree.h
 *
 *  Created on: 30-Jan-2019
 *      Author: f10
 */
//#include <iostream>
#ifndef BTREE_H_
#define BTREE_H_
#include "queue.h"
#include "queue.cpp"


#include "stack.h"
#include "stack.cpp"


template<typename T>
struct bTreenode
{
	T info;
	bTreenode*left;
	bTreenode*right;
};

template<typename T>
class btree {

	bTreenode<T>*root;
	bTreenode<T>*mirror;
	bTreenode<T>*glass;
public:

	btree();
	virtual ~btree();
	bTreenode<T>* maketree(T);
	void insert(T);
	void insertNonRecursive(T);
	bTreenode<T>* Insert(bTreenode<T>*,T);
	void search(T x);
	bool search(bTreenode<T>*,T x);
	void searchNonRecursive(T x);
	void LevelOrderDisplay();
	void display();
	void Display(bTreenode<T>*);
	void displayPreorder();
	void DisplayPreorder(bTreenode<T>* p);
	void displayPostorder();
	void DisplayPostorder(bTreenode<T>* p);
	void mirrorR();
	bTreenode<T>* MirrorR(bTreenode<T>*,bTreenode<T>*);
	void MirrorNonRecursive();
	bTreenode<T>* MinSuccessor(bTreenode<T>*);
	void del(T x);
	bTreenode<T>* delRecursive(bTreenode<T>*,T);
	void delNonRecursive(T);





};

#endif /* BTREE_H_ */
