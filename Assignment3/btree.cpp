/*
 * btree.cpp
 *
 *  Created on: 16-Jan-2019
 *      Author: f10
 */
#include<iostream>
#include "btree.h"
using namespace std;

btree::btree() {
	// TODO Auto-generated constructor stub
	root=NULL;

}

btree::~btree() {
	// TODO Auto-generated destructor stub
}

bTreenode* btree::maketree(int x) //ALLOCATE MEMORY FOR NODE OF TREE AND INITIALIZE
{								 //DATA PART
  bTreenode* p=NULL;
  p=new bTreenode;
  p->info=x;
  p->left=NULL;
  p->right=NULL;
  return p;

}
void btree::create()
{
	root=Insert(root);
}

void btree::insert()
{
     root=Insert(root);
}


bTreenode* btree::Insert(bTreenode* p)
{
	if(p==NULL)
	{
		int x;
		std::cout<<"Enter data";
		std::cin>>x;
		p=maketree(x);
		return p;
	}

	else
	{
	bTreenode* Q=p;  //Q is used for traversing

	std::cout<<"Where to insert\n1:Left\n2:Right\n";
	int choice;
	std::cin>>choice;   //WHEN choice is 1 traverse to left
						//when choice is 2 traverse to right

	if(choice==1)
		Q->left=Insert(Q->left);
	if(choice==2)
		Q->right=Insert(Q->right);
	}

return p;

}

void btree::insert_non_recursive()
{
	bTreenode* p=root;   //p will be used for traversing
	int x;              //Store entered data

	if(p==NULL)
	{
		cout<<"Enter data";
		cin>>x;
		root=maketree(x);      //create new tree node and initialize with x
		return;
	}

	while(p!=NULL)
	{
		std::cout<<"Where to insert\n1:Left\n2:Right\n";
		int choice;
		std::cin>>choice;

		if(choice==1)
		{
			if(p->left==NULL)
			{
				cout<<"Enter data";
				cin>>x;
				p->left=maketree(x);
				return;
			}
			else
			p=p->left;
		}

		else if(choice==2)
		{
			if(p->right==NULL)
				{
					cout<<"Enter data";
					cin>>x;
					p->right=maketree(x);
					return;
				}
			else
				p=p->right;

		}
	}

	return;
}

void btree::display()
{
	Display(root);
}

void btree::Display(bTreenode* p)
{
	if(p!=NULL)
	{
		Display(p->left);
			std::cout<<p->info<<" ";
		Display(p->right);
	}
}

int btree::depthOftree()
{
	return(DepthOftree(root));
}

int btree::DepthOftree(bTreenode* p)
{
	if(p==NULL)
		return -1;
	else
	{
		int l=DepthOftree(p->left);
		int r=DepthOftree(p->right);

		if(l>r)
			return(1+l);
		else
			return(1+r);
	}


}

void btree::display_leaf_node()
{
	Display_leaf_node(root);

}


void btree::Display_leaf_node(bTreenode* p)
{

	if(p!=NULL)
	{
		Display_leaf_node(p->left);
			if(p->left==NULL && p->right==NULL)
				std::cout<<p->info<<" ";
		Display_leaf_node(p->right);
	}
}

void btree::create_a_copy()
	{
		copy=Create_a_copy(root);
		Display(copy);
	}

bTreenode* btree::Create_a_copy(bTreenode* p)
	{
		if(p==NULL)
			return p;

			bTreenode* copynode=new bTreenode;
			copynode->info=p->info;
			copynode->left=Create_a_copy(p->left);
			copynode->right=Create_a_copy(p->right);


		return copynode;

	}
