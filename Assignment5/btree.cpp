/*
 * btree.cpp
 *
 *  Created on: 30-Jan-2019
 *      Author: f10
 */

#include<iostream>
#include "btree.h"
//#include "queue.h"
//#include "stack.h"
using namespace std;


template<typename T>
btree<T>::btree() {
	// TODO Auto-generated constructor stub
	root=NULL;
	glass=NULL;

}

template<typename T>
btree<T>::~btree() {
	// TODO Auto-generated destructor stub
}

template<typename T>
bTreenode<T>* btree<T>::maketree(T x)  //Initialize pointers
	{
		bTreenode<T>* p=NULL;
		p=new bTreenode<T>;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	  	return p;
	}

template<typename T>
void btree<T>::insertNonRecursive(T x)
{
	if(root==NULL)
	{
		root=maketree(x);
		return;
	}

	bTreenode<T>* p=root;  //use p for traversing

	while(p!=NULL)
	{
		if(x<p->info)
		{
			if(p->left==NULL)
			{
				p->left=maketree(x);
				return;
			}
			p=p->left;
		}
		else if(x>p->info)
		{
			if(p->right==NULL)
			{
				p->right=maketree(x);
				return;
			}
			p=p->right;
		}
	}


	return;
}


template<typename T>
void btree<T>::insert(T x)
    {
		root=Insert(root,x);
		return;
	}

template<typename T>
bTreenode<T>* btree<T>::Insert(bTreenode<T>* p,T x)
	{
		if(p==NULL)
		{
			p=maketree(x);
			return p;
		}
		else if(x<p->info)
			p->left=Insert(p->left,x);
		else if(x>p->info)
			p->right=Insert(p->right,x);

		return p;
	}

template<typename T>
void btree<T>::display()
{

	if(root==NULL)
	{
		cout<<"TRee empty";
		return;
	}
	else
    Display(root);
}

template<typename T>
void btree<T>::Display(bTreenode<T>* p) //Recursive inorder display
{


	if(p!=NULL)
	{
		Display(p->left);
			std::cout<<p->info<<" ";
		Display(p->right);
	}


}

template<typename T>
void btree<T>::displayPreorder()
{
	DisplayPreorder(root);
}

template<typename T>
void btree<T>::DisplayPreorder(bTreenode<T>* p)
{
	if(p!=NULL)
	{
		std::cout<<p->info<<" ";
		DisplayPreorder(p->left);
		DisplayPreorder(p->right);


	}
}

template<typename T>
void btree<T>::displayPostorder()
{
	DisplayPostorder(root);
}

template<typename T>
void btree<T>::DisplayPostorder(bTreenode<T>* p)
{
	if(p!=NULL)
	{
		DisplayPostorder(p->left);
		DisplayPostorder(p->right);
		std::cout<<p->info<<" ";
	}
}


template<typename T>
void btree<T>::search(T x)
{
	if(search(root,x))
		cout<<"Number found";
	else
		cout<<"Number not found";

}


template<typename T>
bool btree<T>::search(bTreenode<T>* p,T x)
{
	if(p==NULL)
		return false;
	else if(x==p->info)
		        return true;
	else if(x<p->info)
	{
		if(search(p->left,x))
			return true;
	}

	else if(x>p->info)
	{
			if(search(p->right,x))
				return true;
	}


   return false;
}

template<typename T>
void btree<T>::LevelOrderDisplay()
{
 queue<bTreenode<T>*>q;

  if(root==NULL)
  	  {
	  	  cout<<"Tree is empty";
	  	  return;
  	  }

  bTreenode<T>* p=NULL;

  q.enqueue(root);

 while(!q.isempty())
  {
	  p=q.dequeue();

	  cout<<p->info<<" ";

	  if(p->left!=NULL)
		  q.enqueue(p->left);

	  if(p->right!=NULL)
		  q.enqueue((p->right));

  }


}

template<typename T>
void btree<T>::searchNonRecursive(T x)
{
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return;
	}

	bTreenode<T>*p=root;

	while(p)
	{
		if(p->info==x)
			{
				cout<<"Element found";
				return;
			}

		if(x<p->info)
			{
				p=p->left;
			}
		else if(x>p->info)
			{

				p=p->right;
			}

	}

	cout<<"Number not found";

}





template<typename T>
void btree<T>::mirrorR()
{
	if(root==NULL)
			cout<<"Tree is empty";
    glass=MirrorR(root,glass);

    cout<<"MIRROR IS : \n";
    cout<<"\nInorder Display : ";
    Display(glass);
    cout<<"\nPreorder Display : ";
    DisplayPreorder(glass);
    cout<<"\nPostorder Display : ";
    DisplayPostorder(glass);

}

template<typename T>
bTreenode<T>* btree<T>::MirrorR(bTreenode<T>*p,bTreenode<T>*q)
{


	q=maketree(p->info);

	if(p->left!=NULL)
	q->right=MirrorR(p->left,q->right);
	if(p->right!=NULL)
	q->left=MirrorR(p->right,q->left);

	return q;
}




template<typename T>
void btree<T>::MirrorNonRecursive()
{
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return;
	}

	stack<bTreenode<T>*>s1;
	stack<bTreenode<T>*>s2;

	s1.push(root);
			bTreenode<T>* glass = new bTreenode<T> ;
			glass=maketree(root->info);
			s2.push(glass);

			while( !s1.isEmpty() ){
				bTreenode<T>* cur = s1.pop();
				bTreenode<T>* newCur = s2.pop();

				if(cur->right != NULL)
				{
					s1.push(cur->right);
					newCur->left = new bTreenode<T>;
					newCur->left=maketree(cur->right->info);
					s2.push(newCur->left);
				}

				if(cur->left != NULL)
				{
					s1.push(cur->left);
					newCur->right = new bTreenode<T>;
					newCur->right=maketree(cur->left->info);
					s2.push(newCur->right);
				}
			}



   cout<<"Mirror Tree is : \n";
   Display(glass);
}


template<typename T>
void btree<T>::del(T x)
{
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return;
	}


     root=delRecursive(root,x);
     Display(root);
}

template<typename T>
bTreenode<T>* btree<T>::MinSuccessor(bTreenode<T>* p)
{
	while(p->left!=NULL)
		p=p->left;

	return p;
}

template<typename T>
bTreenode<T>* btree<T>::delRecursive(bTreenode<T>* p,T x)
{
	if(x<p->info)         //IF key is smaller then key lies in left subtree
		p->left=delRecursive(p->left,x);
	else if(x>p->info)	 //IF key is larger then key lies in right subtree
		p->right=delRecursive(p->right,x);
	else  if(p->left && p->right)
		{
			 bTreenode<T>* temp=MinSuccessor(p->right);
			 p->info=temp->info;
			 p->right=delRecursive(p->right,p->info);

		}
		else
		{
			bTreenode<T>* temp=p;
			if(p->left==NULL)
				 p=p->right;
			else if(p->right==NULL)
				 p=p->left;

		   delete(temp);
		}

	return p;

}

template<typename T>
void btree<T>::delNonRecursive(T a)
{

	bTreenode<T>*n,*p;
			//n=new bTreenode<T>;
			//p=new bTreenode<T>;
			p=root;
			n=root;
			while(n!=NULL)
			{

				if(a<n->info)
				{
					p=n;
					n=n->left;
					}
				else if(a>n->info)
				{
					p=n;
					n=n->right;
					}
				else if(a==n->info){
					//cout<<"Inside else"<<endl;
					if(n->left==NULL && n->right==NULL)
					{
						if(p->right==n)
							p->right=NULL;
						else
							p->left=NULL;
						delete n;
						cout<<"Node deleted"<<endl;
						return;
					}
					else if(n->left==NULL && n->right!=NULL)
					{
						p->right=n->right;
						delete n;
						cout<<"Node deleted"<<endl;
						return;
					}
					else if(n->left!=NULL && n->right==NULL)
					{
						p->left=n->left;
						delete n;
						cout<<"Node deleted"<<endl;
						return;
					}
					else
					{

						bTreenode<T>* temp=n;
						//temp=n;
						p=n;
						temp=temp->right;
						while(temp->left!=NULL)
						{
							p=temp;
							temp=temp->left;
						}

						if(temp->left==NULL && temp->right==NULL)
						{
							n->info=temp->info;
							cout<<n->info<<endl;
							if(p->right==temp)
							p->right=NULL;
						else
							p->left=NULL;
						delete temp;
						cout<<"Node deleted"<<endl;
						return;


						}
						else
						{
							p->right=temp->right;
						delete temp;
						cout<<"Node deleted"<<endl;
						return;
						}

					}

				}
			}
			cout<<"Node not found"<<endl;
}





