/*
 * btree.h
 *
 *  Created on: 16-Jan-2019
 *      Author: f10
 */

#ifndef BTREE_H_
#define BTREE_H_
#include "stack.h"
#include "stack.cpp"

//template<typename T>
struct bTreenode
{
	char info;
	bTreenode*left;
	bTreenode *right;
};

//template<typename T>
class btree {

	bTreenode* root;

public:

	btree();
	virtual ~btree();
	bTreenode* maketree(char);
	bool isOperand(char);
	bool isOperator(char);

	void create_exp_tree_post();
	void create_exp_tree_pre();

	void displayInorder();
	void DisplayInorder(bTreenode* p);
	void displayPreorder();
	void DisplayPreorder(bTreenode* p);
	void displayPostorder();
	void DisplayPostorder(bTreenode* p);

	void displayInorderNonRecursive();
	void displayPreorderNonRecursive();
    void displayPostorderNonRecursive();



};

#endif /* BTREE_H_ */
