// CA_Hashing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CA_HashTable.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"CLOSED ADDRESS HASHING:"<<endl<<endl;
	
	CA_HashTable table(7); //size of table is 7 
	
	//1; 2; 3; 4; 5; 6; 7; 8; 9; 10
	table.insert(1);
	table.insert(2);
	table.insert(3);
	table.insert(4);
	table.insert(5);
	table.insert(6);
	table.insert(7);
	table.insert(8);
	table.insert(9);
	table.insert(10);
//	table.insert(8);
//	table.insert(17);


	
//	table.remove(7);
//	table.remove(10);
//	table.insert(10);

//	table.remove(17);

//	table.remove(8);
//	table.remove(82);

	table.print();

	cout << "In the task 1 in our problem's file, we must count the average number of comparisons successful search - for inserted (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) numbers" << endl <<endl;
	cout << "That will be" << " (7 * 1 + 3 * 2)/10  =  1.3" << endl;														

	_getchar_nolock();
	
	return 0;
}
