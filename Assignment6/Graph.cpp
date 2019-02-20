/*
 * Graph.cpp
 *
 *  Created on: 07-Feb-2019
 *      Author: gaurav
 */

#include "Graph.h"
#include <queue>
#include <stack>
#include <vector>
#include <iomanip>

Graph::Graph()
{
	// TODO Auto-generated constructor stub

}

Graph::~Graph()
{
	// TODO Auto-generated destructor stub
}

Headnode* Graph::makeHeadnode(string name,int ID) //Initialize name and ID
{
	Headnode* temp=new Headnode;
	temp->ID=ID;
	temp->name=name;
	temp->right=NULL;
	temp->down=NULL;
	return temp;

}
Friendnode* Graph::makeFriendnode(Headnode* c) //Initialize contents of friendnode
{
	Friendnode* temp=new Friendnode;
	//temp->name=name;
	temp->user=c;
	temp->next=NULL;
	return temp;
}
void Graph::insert_vertex()
{
	string name;
	static int count=0;

	cout<<"Enter name : ";
	cin>>name;


	Headnode* p=leader;

	if(leader==NULL)
		{
			leader=makeHeadnode(name,count);
			cout<<"Enter DOB in (dd mm yyyy) : ";
			cin>>leader->birthdate.day>> leader->birthdate.month>> leader->birthdate.year;
			count++;
			return;
		}

	while(p->down!=NULL)
	{
		if(p->name==name)
		{
			cout<<"Name already exists ! ";
			return;
		}

	   p=p->down;
	}


	if(p->name==name)
		{
				cout<<"Name already exists ! ";
				return;
		}


	if(p->down==NULL)
	{
		Headnode* temp=makeHeadnode(name,count);
		cout<<"Enter DOB in (dd mm yyyy) : ";
		cin>>temp->birthdate.day>> temp->birthdate.month>> temp->birthdate.year;
		count++;
		p->down=temp;
	}



}

bool Graph::check_user(string name)
{
	Headnode* p=leader;

		while(p!=NULL)
		{
			if(p->name==name)
			{
				return true;
			}

			p=p->down;
		}

		return false;

}

void Graph::insert_edge(string name,string name_f)
{
	Headnode* p=leader;
	int comments;

	while(p!=NULL)
	{
		if(p->name==name)
			break;
		p=p->down;
	}

/*
	 int ch;
	 do
	 {
	 string name_f;
	 cout<<"Enter name of friend to add";
	 cin>>name_f;
*/
	 Headnode* c=leader;

	 while(c!=NULL)
	 	{
	 		if(c->name==name_f)
	 		{
	 			Friendnode* temp=makeFriendnode(c);

	 			if(p->right==NULL)
	 			{
	 				cout<<"Enter no of comments "<<p->name<<" made on "<<c->name<<"'s wall : ";
	 				cin>>comments;
	 				temp->comments=comments;
	 				p->right=temp;
	 				break;
	 			}


	 			Friendnode* q=p->right;

	 			while(q->next!=NULL)
	 				q=q->next;

	 			cout<<"Enter no of comments "<<p->name<<" made on "<<c->name<<"'s wall : ";
	 			cin>>comments;
	 			temp->comments=comments;
	 			q->next=temp;

	 		}

	 		c=c->down;
	 	}


/*	 cout<<"Do you wish to add more friends(1/0) : ";
	 cin>>ch;

	 }while(ch);
*/
}

void Graph::display()
{
	Headnode* temp=leader;

	cout<<"-----------------------------------------------------------\n";
	cout<<"| ID |    Name    |  Birthdate  |    Friends              |\n";
	cout<<"-----------------------------------------------------------\n";

	while(temp!=NULL)
	{

		cout<<"|"<<setw(4)<<temp->ID<<"|";
		cout<<setw(12)<<temp->name<<"|";
		cout<<setw(3)<<temp->birthdate.day<<"/"<<setw(3)<<temp->birthdate.month<<"/"<<setw(5)<<temp->birthdate.year<<"|";
		Friendnode* tempU=temp->right;

		while(tempU!=NULL)
		{
			cout<<"->"<<tempU->user->name<<"("<<tempU->comments<<")";
			tempU=tempU->next;
		}

		cout<<"\n";


		temp=temp->down;
	}


}

void Graph::BFS()
{
	queue<Headnode*>q;
	bool visited[20];

	for(int i=0;i<20;i++)
		visited[i]=false;

	Headnode* p=leader;
	Friendnode* f;

	q.push(p);
	visited[0]=true;

	while(!q.empty())
	{
		p=q.front();
		q.pop();

		cout<<p->name<<" ";
		//visited[p->ID]=true;
		f=p->right;

		while(f!=NULL)
		{
			if(!visited[f->user->ID])
			{
				q.push(f->user);
				visited[f->user->ID]=true;
			}

			f=f->next;
		}

	}

}

void Graph::DFS()
{
		stack<Headnode*>s;
		bool visited[20];

		for(int i=0;i<20;i++)
			visited[i]=false;

		Headnode* p=leader;
		Friendnode* f;

		s.push(p);
		visited[0]=true;

		while(!s.empty())
		{
			p=s.top();
			s.pop();

			cout<<p->name<<" ";
			//visited[p->ID]=true;
			f=p->right;

			while(f!=NULL)
			{
				if(!visited[f->user->ID])
				{
					s.push(f->user);
					visited[f->user->ID]=true;
				}

				f=f->next;
			}

		}


}

int Graph::friend_count(Headnode* u)
{
	int count=0;

	Friendnode* f=u->right;

	while(f!=NULL)
	{
		f=f->next;
		count++;
	}

    return count;
}

void Graph::max_friends()
{
		queue<Headnode*>q;
		bool visited[20];
		int max=0,count;
		Headnode* maxID;

		for(int i=0;i<20;i++)
			visited[i]=false;

		Headnode* p=leader;
		Friendnode* f;

		q.push(p);
		visited[0]=true;

		cout<<"-----------------------------------------------------------\n";

		while(!q.empty())
		{
			count=0;

			p=q.front();
			q.pop();

			count=friend_count(p);
			cout<<p->name<<" has "<<count<<" friends\n";
			if(count>max)
			{
				max=count;
				maxID=p;
			}

			f=p->right;

			while(f!=NULL)
			{
				if(!visited[f->user->ID])
				{
					q.push(f->user);
					visited[f->user->ID]=true;
				}

				f=f->next;
			}

		}

		cout<<"-----------------------------------------------------------\n";
		cout<<maxID->name<<" has maximum no of friends\n";
		cout<<"-----------------------------------------------------------\n";

}


/*void Graph::comment_count(Headnode* u,int* c,Headnode** minptr,Headnode** maxptr)
{
	Friendnode* f=u->right;

	while(f!=NULL)
	{
		c[f->user->ID]+=f->comments;

		if(c[f->user->ID]<c[(*minptr)->ID])
			minptr=&f->user;

		if(c[f->user->ID]>c[(*maxptr)->ID])
			maxptr=&f->user;

		f=f->next;
	}

	//return c;


}*/

void Graph::max_min_comments()
{

			stack<Headnode*>s;
			bool visited[20];


			int comments[20];
			Headnode* minptr;
			Headnode* maxptr;

			for(int i=0;i<20;i++)
			{
				visited[i]=false;
				comments[i]=0;
			}




			Headnode* p=leader;
			Friendnode* f;

			s.push(p);
			minptr=p->right->user;
			maxptr=p->right->user;
			comments[p->right->user->ID]=p->right->comments;
			visited[0]=true;

			while(!s.empty())
			{
				p=s.top();
				s.pop();

				//comment_count(p,comments,&minptr,&maxptr);




				Friendnode* fptr=p->right;

					while(fptr!=NULL)
					{
						if(fptr!=leader->right)
							comments[fptr->user->ID]+=fptr->comments;

						if(comments[fptr->user->ID]<comments[minptr->ID])
							minptr=fptr->user;

						if(comments[fptr->user->ID]>comments[maxptr->ID])
							maxptr=fptr->user;

						fptr=fptr->next;
					}






				//cout<<p->name<<" ";
				f=p->right;

				while(f!=NULL)
				{
					if(!visited[f->user->ID])
					{
						s.push(f->user);
						visited[f->user->ID]=true;
					}

					f=f->next;
				}

			}


    cout<<"-----------------------------------------------------------\n";
	cout<<"Minimum comments are on "<<minptr->name<<"'s wall--> Count="<<comments[minptr->ID]<<endl;
	cout<<"-----------------------------------------------------------\n";
	cout<<"Maximum comments are on "<<maxptr->name<<"'s wall--> Count="<<comments[maxptr->ID]<<endl;
	cout<<"-----------------------------------------------------------\n";


}


void Graph::birthday_check()
{
	int m;
	cout<<"Enter current month(1-12) : ";
	cin>>m;

	queue<Headnode*>q;
		bool visited[20];

		for(int i=0;i<20;i++)
			visited[i]=false;

		Headnode* p=leader;
		Friendnode* f;

		q.push(p);
		visited[0]=true;

		cout<<"\n****************TIME TO CELEBRATE***********************\n";
		cout<<"-----------------------------------------------------------\n";

		while(!q.empty())
		{
			p=q.front();
			q.pop();

			//cout<<p->name<<" ";
			if(p->birthdate.month==m)
			{
				cout<<p->name<<" has birthday on "<<p->birthdate.day<<"/"<<p->birthdate.month<<"\n";
				cout<<"-----------------------------------------------------------\n";
			}
			f=p->right;

			while(f!=NULL)
			{
				if(!visited[f->user->ID])
				{
					q.push(f->user);
					visited[f->user->ID]=true;
				}

				f=f->next;
			}

		}





}
