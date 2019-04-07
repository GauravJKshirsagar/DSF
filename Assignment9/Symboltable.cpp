/*
 * Symboltable.cpp
 *
 *  Created on: 20-Mar-2019
 *      Author: f10
 */

#include "Symboltable.h"
#include<iostream>
#include<iomanip>
using namespace std;

Symboltable::Symboltable() {
	// TODO Auto-generated constructor stub
	for(int i=0;i<10;i++)
	{
		s[i].chain=-1;
		s[i].mobile="$";
	}


}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}

void Symboltable::display_table()
{
	cout<<"----------------------------------------------------\n";
	cout<<"|  Index   |"<<"   Name   |"<<" Mobile Number |"<<" Chain Bit  |\n";
	cout<<"----------------------------------------------------\n";

	for(int i=0;i<10;i++)
	{
		cout<<"|"<<setw(10)<<i<<"|"<<setw(10)<<s[i].name<<"|"<<setw(15)<<s[i].mobile<<"|"<<setw(12)<<s[i].chain<<"|";
		cout<<"\n";
	}

	cout<<"----------------------------------------------------\n";

}

int Symboltable::index_calculation(string x)
{
	int sum=0;

	for(int i=0;x[i]!='\0';i++)
	{
		sum+=x[i];
	}

	cout<<"Sum of ascii values of digits in mobile no is : ";
	cout<<sum<<endl;

	return(sum%10);

}



void Symboltable::create_table_without_replacement()
{
	int index;
	int temp,temp2;
	string name;
	string mob;



	cout<<"Enter name : ";
	cin>>name;

	cout<<"Enter mobile number : ";
	cin>>mob;

	index=index_calculation(mob);

	if(s[index].mobile=="$") //if entry is a new entry for that index then insert directly and return
	{
		s[index].name=name;
		s[index].mobile=mob;
		return;
	}

	temp2=index;

	while(temp2!=index_calculation(s[index].mobile) && s[index].mobile!="$")
		index=(index+1)%10;

	//index=temp2;

	while(s[index].chain!=-1) //Now using chain bits go till end of chain for given index
			index=s[index].chain;


	temp=index;

	while(s[temp].mobile!="$") //Now increment index by one till we get empty place to store new record
		temp=(temp+1)%10;


	//Now use this index of new record and assign it to chain bit of "previous last record"
	if(index!=temp)
		s[index].chain=temp;


	s[temp].name=name;
	s[temp].mobile=mob;

}

int Symboltable::search_table_without_replacement(string x)
{
	int index=index_calculation(x);


	while(1)
	{
		if(s[index].mobile==x)
			{
				cout<<"Record found at index "<<index;
				return index;
			}
		else if(s[index].chain==-1 && index_calculation(s[index].mobile)==index)
			{
				cout<<"Record not found";
				return -1;
			}
		else
		{
			if(index_calculation(s[index].mobile)!=index)
				index=(index+1)%10;
			else
				index=s[index].chain;
		}

	}


}

void Symboltable::create_table_with_replacement()
{
		int index;
		int temp,temp2,chainrem;
		string name;
		string mob;



		cout<<"Enter name : ";
		cin>>name;

		cout<<"Enter mobile number : ";
		cin>>mob;

		index=index_calculation(mob);

		if(s[index].mobile=="$") //if entry is a new entry for that index then insert directly and return
		{
			s[index].name=name;
			s[index].mobile=mob;
			return;
		}

		temp2=index;



		while(temp2!=index_calculation(s[index].mobile) && s[index].mobile!="$")
			index=(index+1)%10;



		//index=temp2;

		while(s[index].chain!=-1) //Now using chain bits go till end of chain for given index
		{
			index=s[index].chain;
		}



		temp=index;

		while(s[temp].mobile!="$") //Now increment index by one till we get empty place to store new record
			temp=(temp+1)%10;


		//Now use this index of new record and assign it to chain bit of "previous last record"
		if(index!=temp)
			s[index].chain=temp;

		if(index_calculation(s[temp2].mobile)!=index_calculation(mob))
		{
			s[temp].name=s[temp2].name;
			s[temp].mobile=s[temp2].mobile;
			s[temp].chain=s[temp2].chain;

			s[temp2].name=name;
			s[temp2].mobile=mob;
			s[temp2].chain=-1;

			for(int i=temp2+1;i!=temp2;i=(i+1)%10)
			{
				if(s[i].chain==temp2)
				{
					s[i].chain=temp;
					break;
				}
			}

		}
		else
		{
			s[temp].name=name;
			s[temp].mobile=mob;
		}


}

void Symboltable::delete_table_without_replacement(string x)
{


	int index=index_calculation(x);

	int pos=search_table_without_replacement(x);

	for(int i=pos+1;i!=pos;i=(i+1)%10)
				{
					if(s[i].chain==pos)
					{
						s[i].chain=s[pos].chain;
						break;
					}
				}

	int temp=pos;
	int temp_next;
	int temp_chain;

	while(s[temp].chain!=-1)
	{
		temp_chain=s[temp].chain;

		s[temp].name=s[s[temp].chain].name;
		s[temp].mobile=s[s[temp].chain].mobile;
		s[temp].chain=s[s[temp].chain].chain;

		temp=temp_chain;


	}

	while(s[temp].mobile!="$")
	{
		temp_next=(temp+1)%10;

		if(index_calculation(s[temp_next].mobile)==temp_next)
		{
			s[temp].name="";
			s[temp].mobile="$";
			s[temp].chain=-1;

			break;

		}


		s[temp].name=s[temp_next].name;
		s[temp].mobile=s[temp_next].mobile;
		s[temp].chain=s[temp_next].chain;

		temp=(temp+1)%10;

	}




}


void Symboltable::delete_table_with_replacement(string x)
{

	int pos=search_table_without_replacement(x);

		for(int i=pos+1;i!=pos;i=(i+1)%10)
					{
						if(s[i].chain==pos)
						{
							s[i].chain=s[pos].chain;
							break;
						}
					}

		int temp=pos;
		int temp_next;
		int temp_chain;

		while(s[temp].chain!=-1)
		{
			temp_chain=s[temp].chain;

			s[temp].name=s[s[temp].chain].name;
			s[temp].mobile=s[s[temp].chain].mobile;
			s[temp].chain=s[s[temp].chain].chain;

			temp=temp_chain;


		}

		while(s[temp].mobile!="$")
		{
			temp_next=(temp+1)%10;

			if(index_calculation(s[temp_next].mobile)==temp_next)
			{
				s[temp].name="";
				s[temp].mobile="$";
				s[temp].chain=-1;

				break;

			}


			s[temp].name=s[temp_next].name;
			s[temp].mobile=s[temp_next].mobile;
			s[temp].chain=s[temp_next].chain;

			temp=(temp+1)%10;

		}



}

