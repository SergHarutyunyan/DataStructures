#include "StdAfx.h"
#include "HashFunction.h"


HashFunction::HashFunction()
{
}


HashFunction::~HashFunction()
{
}

int 
HashFunction::firstFunction(int key)const
{
	return key*key+1;
}


int 
HashFunction::secondFunction(int key)const
{
	return (key<<1)+1;
}


