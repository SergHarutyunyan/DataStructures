#pragma once
class HashFunction
{
public:
	HashFunction();	
	~HashFunction(void);
	int firstFunction(int key)const;
	int secondFunction(int key)const; //should return odd numbers
};

