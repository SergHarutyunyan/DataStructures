// OA_Hashing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OA_HashTable.h"

#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"OPEN ADDRESS HASHING:"<<endl<<endl;
	
	OA_HashTable table(8);
	//1; 2; 3; 4; 5; 6; 7
	table.insert(1);
	table.insert(2);
	table.insert(3);
	table.insert(4);
	table.insert(5);
	table.insert(6);
	table.insert(7);

//	table.insert(3);
//	table.insert(8);
//	table.insert(9);

//	table.remove(3);
	
	
	table.print();

//	cout << endl;
//	cout << table.search(8);

//	cout << endl;
//	cout << table.search(1);


	_getchar_nolock();
	
	return 0;
}

