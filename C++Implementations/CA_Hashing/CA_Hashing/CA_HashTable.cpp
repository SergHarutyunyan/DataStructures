#include "StdAfx.h"
#include "CA_HashTable.h"
#include <iostream>
using namespace std;

CA_HashTable::CA_HashTable(int size):
size_(size), table_(new Node*[size])
{
	for(int i=0; i<size; i++)
		table_[i]=0;
}

CA_HashTable::~CA_HashTable(void)
{
	Node* temp;
	for(int i=0; i<size_; i++)
		while(table_[i]!=0)
		{
			temp=table_[i]; 
			table_[i]=temp->next_;
			delete temp;
		}
	delete []table_;
}

int 
CA_HashTable::hashCode(int key)const
{
	return (10*key) % size_;
}

bool  
CA_HashTable::search(int key)const
{
	int i = hashCode(key);

	Node *current = table_[i];

	while (current) {	
		if (current->key_ == key) return true;
		current = current->next_;
	}
	return false; 
}

void
CA_HashTable::insert(int key)
{
	if (search(key) == false) 
	{
		int i = hashCode(key);

		Node *iter = new Node();
		iter->key_ = key;
		iter->next_ = table_[i];
		table_[i] = iter;
	}
	else {
		return;
	}
}

void  
CA_HashTable::remove(int key)
{
	if (search(key) == true) 
	{
		int i = hashCode(key);

		if (table_[i]->key_ == key) 
		{

			if (table_[i]->next_)
			{
				Node *temp = new Node();
				temp = table_[i]->next_;
				table_[i] = temp;
				temp = 0;
			}
			else table_[i] = 0;

			return;
		}
		else
		{
			Node *current = table_[i]->next_;
			Node *prev = table_[i];
			while (current)
			{
				if (current->key_ != key) {
					prev = current;
					current = current->next_;
				}
				else {
					prev->next_ = current->next_;
					delete current;
					return;
				}
			}
		}		
	}
	else {
		return;
	}
}
	
void  
CA_HashTable::print()const
{
	Node* current;
	for(int i=0; i<size_; i++)
	{
		cout<<i<<": ";
		for(current=table_[i]; current!=0; current=current->next_)
			cout<<current->key_<<" ";
		cout<<endl;
	}
	cout<<endl;
}


