/*
 * btree.h
 *
 *  Created on: 16-Jan-2019
 *      Author: f10
 */

#ifndef BTREE_H_
#define BTREE_H_

struct bTreenode
{
	int info;
	bTreenode *left;
	bTreenode *right;
};

class btree {

	bTreenode* root;
	bTreenode* copy;

public:

	btree();
	virtual ~btree();
	bTreenode* maketree(int);
	void create();
	bTreenode* Insert(bTreenode*);
	void insert();
	void insert_non_recursive();
	void display();
	void Display(bTreenode* p);
	int depthOftree();
	int DepthOftree(bTreenode* p);
	void display_leaf_node();
	void Display_leaf_node(bTreenode* p);
	void create_a_copy();
	bTreenode* Create_a_copy(bTreenode* p);


};

#endif /* BTREE_H_ */
