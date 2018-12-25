//============================================================================
// Name        : Assignment1.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "stack.cpp"
#include "stack.h"
using namespace std;


class expression
{

	char postfix[50],prefix[50],input[100];


	public:

			void intake();
			void infixToPost();
			int precedence(char);
			void infixToPre();
			int associativity(char);
			float evaluationOfPostfix();
			int evaluationOfPrefix();
			int isOperator(char);
			bool isAlphabet(char);
			bool isDigit(char);


};

void expression::intake()
{
	cout<<"Enter expression : ";
	cin>>input;
	int i;
	for( i=0;input[i]!='\0';i++)
	{
		if(!(isOperator(input[i])||isAlphabet(input[i])||isDigit(input[i])))
			break;
	}
	if(input[i]!='\0')
		cout<<"string not valid";
	cout<<input;
}

void expression::infixToPost()
{
	stack<char>s;
	int i=0,k=0;
	char x,m;

	while(input[i]!='\0')
	{
		x=input[i];

		if(isAlphabet(x) || isDigit(x))
		{
			postfix[k++]=x;

		}


		else if(x=='(')
			s.push(x);

		else if(x==')')
		{
			while(s.peep()!='(')
			{
				postfix[k++]=s.pop();
			}
			m=s.pop();
		}

		else if((s.isEmpty()) || (s.peep()=='('))
		{
			s.push(x);
		}

		else if(precedence(s.peep())<precedence(x))
			s.push(x);
		else if(precedence(s.peep())>precedence(x))
		{
			while(precedence(s.peep())>=precedence(x))
			{

				postfix[k++]=s.pop();
				if(s.isEmpty())
					break;

			}
			s.push(x);
		}

		else if((precedence(s.peep()))== (precedence(x)))
		{
			if((associativity(x))==1)
			{
				m=s.pop();
				postfix[k++]=m;
				s.push(x);

			}
			else if((associativity(x))==2)
				s.push(x);
		}

		i++;
	}

	while(!s.isEmpty())
		postfix[k++]=s.pop();

	cout<<"Postfix expression Of Given Input : ";
	postfix[k]='\0';
	cout<<postfix;

	cout<<"\n";



}

int expression::precedence(char x)
{

	if(x=='^')
		return 3;
	else if(x=='*' || x=='/' || x=='%')
		return 2;
	else if(x=='+' || x=='-')
		return 1;

	return 0;
}

void expression::infixToPre()
{
	stack<char>s;
	int i=0,l,count=0;
	char x,m;


	for(l=0;input[l]!='\0';l++) //calculating length of input string
	{
		if(input[l]=='(' || input[l]==')')
			count++;
	}

	i=l-1;					//starting travesing from oppsite direction
	prefix[l-count]='\0';  //Setting final character of prefix string to NULL

	l=l-count-1;

		while(i>=0)
		{
			x=input[i];

			if(isAlphabet(x) || isDigit(x))
			{
				prefix[l--]=x;

			}


			else if(x==')')
				s.push(x);

			else if(x=='(')
			{
				while(s.peep()!=')')
				{
					prefix[l--]=s.pop();
				}
				m=s.pop();
			}

			else if((s.isEmpty()) || (s.peep()==')'))
			{
				s.push(x);
			}

			else if(precedence(s.peep())<precedence(x))
				s.push(x);
			else if(precedence(s.peep())>precedence(x))
			{
				while(precedence(s.peep())>precedence(x))
				{

					prefix[l--]=s.pop();
					if(s.isEmpty())
						break;

				}
				s.push(x);
			}

			else if((precedence(s.peep()))== (precedence(x)))
			{
				if((associativity(x))==2)
				{
					m=s.pop();
					prefix[l--]=m;
					s.push(x);


				}
				else if((associativity(x))==1)
					s.push(x);
			}

			i--;
		}

		while(!s.isEmpty())
			prefix[l--]=s.pop();

		cout<<"Prefix expression Of Given Input : ";
		for(i=0;prefix[i]!='\0';i++)
			cout<<prefix[i];

		cout<<"\n";


}

int expression::associativity(char x)
{
	if(x=='*' || x=='/' || x=='+' || x=='-' || x=='%')
		return 1;
	else if(x=='^')
		return 2;
	return 0;
}

float expression::evaluationOfPostfix()
{
	stack<float>s;
	int i=0,j=0,m,n,value[10],count=0;
	char x,key[10];

	while(postfix[i]!='\0')
	{
		x=postfix[i];
		if(isAlphabet(x))
			{
				for(j=0;j<count;j++)
					{
						if(key[j]==x)
						{
							s.push(value[j]);
							break;
						}

					}
				if(j==count)
				{
					key[count]=x;
					cout<<"Enter value of "<<x<<" : ";
					cin>>value[count];
					s.push(value[count]);
					count++;
				}

			}
		else if(isDigit(x))
		{
			s.push(x-'0');
		}
		else if(isOperator(x))
			{
				n=s.pop();
				m=s.pop();

				if(x=='+')
					s.push(m+n);

				else if(x=='-')
					s.push(m-n);

				else if(x=='/')
					s.push(m/n);

				else if(x=='*')
					s.push(m*n);

				else if(x=='%')
					s.push(m%n);

				else if(x=='^')
					s.push(pow(m,n));

				}

		i++;

	}




return s.pop();

}

int expression::evaluationOfPrefix()
{
	stack<float>s;
		int i=0,j=0,m,n,value[10],count=0;
		char x,key[10];

		for(i=0;prefix[i]!='\0';i++);
		i=i-1;

		while(i>=0)
		{
			x=prefix[i];
			if(isAlphabet(x))
				{
					for(j=0;j<count;j++)
						{
							if(key[j]==x)
							{
								s.push(value[j]);
								break;
							}

						}
					if(j==count)
					{
						key[count]=x;
						cout<<"Enter value of "<<x<<" : ";
						cin>>value[count];
						s.push(value[count]);
						count++;
					}

				}
			else if(isDigit(x))
			{
				s.push(x-'0');
			}
			else if(isOperator(x))
				{
					m=s.pop();
					n=s.pop();

					if(x=='+')
						s.push(m+n);

					else if(x=='-')
						s.push(m-n);

					else if(x=='/')
						s.push(m/n);

					else if(x=='*')
						s.push(m*n);

					else if(x=='%')
						s.push(m%n);

					else if(x=='^')
						s.push(pow(m,n));

					}

			i--;

		}




	return s.pop();
}


int expression::isOperator(char x)
{
	if(x=='^' || x=='*' || x=='/' || x=='+' || x=='-' || x=='%' || x=='(' || x== ')')
		return 1;
	return 0;
}

bool expression::isDigit(char x)
{
	if((x>='0' && x<='9'))
		return true;
	return false;
}

bool expression::isAlphabet(char x)
{
	if((x>='a' && x<='z')||(x>='A' && x<='Z'))
		return true;
	return false;
}

int main() {


	int ch;

	expression e;

	do
	{
		cout<<"\nMenu\n1.Input\n2.infix to postfix\n3.Infix to prefix\n"
				"4.Evaluation of Postfix\n5.Evaluation of Prefix\n6.Exit\n";
		cout<<"Enter your Choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1: e.intake();
				break;

		case 2: e.infixToPost();
				break;

		case 3: e.infixToPre();
				break;

		case 4:	e.infixToPost();
				cout<<"Answer is "<<e.evaluationOfPostfix();
				break;

		case 5: e.infixToPre();
				cout<<"Answer is "<<e.evaluationOfPrefix();
				break;

		case 6: break;

		}

	}while(ch!=6);


}
