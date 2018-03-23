#include "StdAfx.h"
#include "OA_HashTable.h"
#include <iostream>
using namespace std;

OA_HashTable::OA_HashTable(int size):
size_(size), table_(new Node[size]), hFunction_(new HashFunction())
{
	
}

OA_HashTable::~OA_HashTable(void)
{
	delete []table_; delete hFunction_;
}

bool  
OA_HashTable::search(int key)const
{
	int a = hFunction_->firstFunction(key) % size_;
	int b = hFunction_->secondFunction(key) % size_;
	int count = 0;
	
	while (table_[a].status_ != FREE) {
		if (table_[a].status_ == OCCUPIED && table_[a].key_ == key) {
				return true;
		}
		else {	
			count++;
			if (count == size_) return false;
			a = a + b;
			if (a >= size_) {
				a = a - size_;
			}
		}
	}
	return false;
}

void  
OA_HashTable::insert(int key)
{
	if (search(key) == false) 
	{
		int a = hFunction_->firstFunction(key) % size_;
		int b = hFunction_->secondFunction(key) % size_;
		int count = 0;

		while (table_[a].status_ == OCCUPIED) 
		{
			count++;
			if (count == size_) return;

			a = a + b;
			if (a >= size_) {
				a = a - size_;
			}
		}
		table_[a].key_ = key;
		table_[a].status_ = OCCUPIED;
		return;
	} 
	return;
}

void  
OA_HashTable::remove(int key)
{
	if (search(key) == true) {
		int a = hFunction_->firstFunction(key) % size_;
		int b = hFunction_->secondFunction(key) % size_;

		while (true) {
			if (table_[a].status_ == OCCUPIED && table_[a].key_ == key) {
				table_[a].key_ = 0;
				table_[a].status_ = DELETED;
				return;
			}
			else {
				a = a + b;
				if (a >= size_) {
					a = a - size_;
				}
			}
		}
	}	
	return;
}

void  
OA_HashTable::print()const
{
	for(int i=0; i<size_; i++){
		cout<<"pos="<<i<<": ";
		if(table_[i].status_==OCCUPIED)
			cout<<table_[i].key_<<endl;
		else
			if(table_[i].status_==FREE)
				cout<<"FREE"<<endl;
			else
				cout<<"DELETED"<<endl;
	}
	cout<<endl;
}
