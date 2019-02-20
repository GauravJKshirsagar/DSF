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


bTreenode* btree::maketree(char x)
{
  bTreenode* p=NULL;
  p=new bTreenode;
  p->info=x;
  p->left=NULL;
  p->right=NULL;
  return p;

}


void btree::create_exp_tree_post()
{
	string post;
	stack<bTreenode*>s;
	cout<<"Enter postfix expression";
	cin>>post;

	int i=0;
	while(post[i]!='\0')
	{
		char x=post[i];

		if(isOperand(x))
		{
			bTreenode* temp=maketree(x);
			s.push(temp);
		}

		if(isOperator(x))
		{
			bTreenode* temp=maketree(x);
			temp->right=s.pop();
			temp->left=s.pop();
			s.push(temp);
		}

		i++;
	}

   root=s.pop();
}

void btree::create_exp_tree_pre()
{
	string post;
	stack<bTreenode*>s;
	cout<<"Enter prefix expression";
	cin>>post;

	int i=0;
	while(post[i]!='\0')
		i++;

	i--;
	while(i>=0)
	{
		char x=post[i];

		if(isOperand(x))
		{
			bTreenode* temp=maketree(x);
			s.push(temp);
		}

		if(isOperator(x))
		{
			bTreenode* temp=maketree(x);
			temp->left=s.pop();
			temp->right=s.pop();
			s.push(temp);
		}

		i--;
	}

   root=s.pop();
}


void btree::displayInorder()
{
	DisplayInorder(root);
}


void btree::DisplayInorder(bTreenode* p)
{
	if(p!=NULL)
	{
		DisplayInorder(p->left);
			std::cout<<p->info<<" ";
		DisplayInorder(p->right);
	}
}

void btree::displayPreorder()
{
	DisplayPreorder(root);
}


void btree::DisplayPreorder(bTreenode* p)
{
	if(p!=NULL)
	{
		std::cout<<p->info<<" ";
		DisplayPreorder(p->left);
		DisplayPreorder(p->right);


	}
}

void btree::displayPostorder()
{
	DisplayPostorder(root);
}


void btree::DisplayPostorder(bTreenode* p)
{
	if(p!=NULL)
	{
		DisplayPostorder(p->left);
		DisplayPostorder(p->right);
		std::cout<<p->info<<" ";
	}
}


void btree::displayInorderNonRecursive()
{
	bTreenode* p=root;

	stack<bTreenode*>s;

	if(p==NULL)
	{
		cout<<"Empty";
		return;
	}

	do
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}

		if(!s.isEmpty())
		{
			p=s.pop();
			cout<<p->info<<" ";


				p=p->right;
		}

	}while(p!=NULL || (!s.isEmpty()));


}


void btree::displayPreorderNonRecursive()
{
	stack<bTreenode*>s;
	bTreenode* p=root;
	if(p==NULL)
	{
		cout<<"Empty";
		return;
	}

	s.push(p);

	while(!s.isEmpty())
	{
		p=s.pop();
		cout<<p->info<<" ";


		if(p->right!=NULL)
			s.push(p->right);
		if(p->left!=NULL)
			s.push(p->left);


	}
}

void btree::displayPostorderNonRecursive()
{
	stack<bTreenode*>s;
	bTreenode* p=root;
	bTreenode* prev=NULL;

	if(p==NULL)
	  {
		 cout<<"Empty";
		 return;
	  }

	s.push(p);

	while((!s.isEmpty()))
	{

			p=s.pop();

			if(p->right==NULL && p->left==NULL)
			{
				prev=p;
				cout<<p->info<<" ";
			}
			else
			{
				if(p->right==prev || p->left==prev)
				{
					prev=p;
					cout<<p->info<<" ";
				}
				else
				{
					s.push(p);
					if(p->right!=NULL)
						s.push(p->right);
					if(p->left!=NULL)
						s.push(p->left);
				}
			}



	}

}


bool btree::isOperand(char x)
{
	if((x>='0' && x<='9')|| (x>='a' && x<='z')||(x>='A' && x<='Z'))
			return true;
	else
		return false;
}


bool btree::isOperator(char x)
{
	if(x=='^' || x=='*' || x=='/' || x=='+' || x=='-' || x=='%' || x=='(' || x== ')')
		return true;
	else
		return false;
}

