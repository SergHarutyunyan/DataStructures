#include <iostream>
using namespace std;

class Young_Table {

private:
	int max_size;						///////  Number of rows/columns.				
	const int infinity = 99;			///////  I have put 99 value instead of INT_MAX, to make it easy to test(When printing the table). 
	int temp;							

	void Push_Ordering(int a, int b);						
	void Pop_Ordering();											
	int CompareMax(int a, int b);							
	int CompareMin(int a, int b);							

public:
	int** table;												// this two parameters I wrote in public, just to test then easy. (printing the table in the main() ).
	int Current_Size;

	Young_Table(int a) :Current_Size(0) 
	{
		if (a <= 0) {
			cout << "Can't create table.";
			return;
		}
		else{
			table = new int*[a];
			for (int i = 0; i < a; i++)
				table[i] = new int[a];

			max_size = a;

			for (int i = 0; i < max_size; i++) {
				for (int j = 0; j < max_size; j++){
					table[i][j] = infinity;
				}
			}
		}
	};
	void Push(int a);
	int Pop();
	bool isEmpty()						{ return table[0][0] == infinity;							};
	bool isFull()						{ return table[max_size - 1][max_size - 1] != infinity;		};

};


void Young_Table::Push(int a) {
	if (isEmpty()) { table[0][0] = a; return; }
	
	 if (!isFull()) {
		 if (table[Current_Size][Current_Size] != infinity)    { Current_Size++; }

		table[Current_Size][Current_Size] = a;
		Push_Ordering(Current_Size, Current_Size);
	} else {
		return;
	}
}

void Young_Table::Push_Ordering(int a, int b) {
	int tmp1;
	int tmp2;
	bool do_ = true;										/////// This variables just helping us to order ///////
	bool t1;
	bool t2;
	temp = 0;

	while (do_) {
		t1 = false;
		t2 = false;
		tmp1 = 0;
		tmp2 = 0;

		if (a != 0) { tmp1 = table[a - 1][b]; }			///////																				///////
									 					///////   We must stay in array. P.S. Can't pass negative numbers in table[?][?])	///////
		if (b != 0) { tmp2 = table[a][b - 1]; }			///////																				///////	
																
		if (a == 0 && b == 0) { return; }

		if (table[a][b] < CompareMax(tmp1, tmp2)) {			
			temp = CompareMax(tmp1, tmp2);				
			if (tmp1 == CompareMax(tmp1, tmp2)) {		 ///////  Cheking which one was the maximum.We need coordinates,becaue CompareMax() method does not gives us coordinates.      
				table[a - 1][b] = table[a][b];
				table[a][b] = temp;
				t1 = true;
			}
			else {
				table[a][b - 1] = table[a][b];
				table[a][b] = temp;
				t2 = true;
			}
		}
		else { do_ = false; }
			
		if (t1) { a--; }								
		if (t2) { b--; }
	}
}

int Young_Table::Pop() {                   /////// Here we find the maximum number from last row and column to replace with	
	int popped;							   /////// table[0][0] ,but before that, we saved it in popped variable
	int tmp1;							   /////// and then starting ordering the table with Pop_ordering() method
	int tmp2;
	int iter;

	if (isEmpty()) {
		return 0;
	}
	else { 
		popped = table[0][0];

		iter = Current_Size + 1;
		while (table[Current_Size][iter-1] == infinity) {
			iter--;
			if (iter == 0) { break; }
		}
		tmp1 = table[Current_Size][iter - 1];
	
		iter = Current_Size + 1;
		while (table[iter-1][Current_Size] == infinity) {
			iter--;
			if (iter == 0) { break; }
		}
		tmp2 = table[iter - 1][Current_Size];

			if (tmp1 > tmp2) {
				table[0][0] = table[Current_Size][iter - 1];
				table[Current_Size][iter - 1] = infinity;
				Pop_Ordering();
				if (table[0][Current_Size] == infinity && table[Current_Size][0] == infinity) { Current_Size--; }
				return popped;
			}
			else {
			
				table[0][0] = table[iter - 1][Current_Size];
				table[iter - 1][Current_Size] = infinity;
				Pop_Ordering();
				if (table[0][Current_Size] == infinity && table[Current_Size][0] == infinity) { Current_Size--; }
				return popped;
			}
	
		}
	
}

void Young_Table::Pop_Ordering() {						// Here we doing the same thing like in Push_Ordering(), but backwards.
	int i = 0;										
	int j = 0;
	int tmp1;
	int tmp2;
	bool do_ = true;									
	bool t1;
	bool t2;
	temp = 0;

	while (do_) {
		t1 = false;
		t2 = false;
		tmp1 = infinity;
		tmp2 = infinity;

		if (i != Current_Size) { tmp1 = table[i + 1][j]; }																						
	
		if (j != Current_Size) { tmp2 = table[i][j + 1]; }																				

		if (table[i][j] > CompareMin(tmp1, tmp2)) {
			temp = CompareMin(tmp1, tmp2);
			if (tmp1 == CompareMin(tmp1, tmp2)) {		 
				table[i + 1][j] = table[i][j];
				table[i][j] = temp;
				t1 = true;
			}
			else {
				table[i][j + 1] = table[i][j];
				table[i][j] = temp;
				t2 = true;
			}
		}
		else { do_ = false; }

		if (t1) { i++; }								
		if (t2) { j++; }
	}
}

int Young_Table::CompareMax(int a, int b) {
	if (a > b) { return a; };
	return b;
}

int Young_Table::CompareMin(int a, int b) {
	if (a < b) { return a; }
	return b;
}

int main() {													
	Young_Table y_table(10);	


	y_table.Push(20);							
	y_table.Push(15);
	int a1 = y_table.Pop();										// popped the 15 value
	y_table.Push(35);
	y_table.Push(10);
	y_table.Push(25);
	int a2 = y_table.Pop();										// popped the 10 value
	y_table.Push(5);
	y_table.Push(40);
	y_table.Push(35);
	y_table.Push(20);

	for (int i = 0; i <= y_table.Current_Size; i++) {							
		for (int j = 0; j <= y_table.Current_Size; j++) {
			cout << y_table.table[i][j] << " ";
			if (j == y_table.Current_Size) {
				cout << endl;
			}
		}
	}

	cout << endl;
	cout << "Popped numbers are: " << a1 << "," << a2 << endl;



	_getchar_nolock();
	return 0;
}