#include <iostream>
using namespace std;

struct Node {
	Node* parent_;
	int info_;
	int key_;
	char status_;
	Node(int info, Node* parent = 0, int key = INT_MAX, char status = 'q') :
		info_(info), parent_(parent), key_(key), status_(status) {}
};

const int N = 6;						// Nodes number
const int M = 8;						// Edges number


Node** Prim(Node* arrNode[], int arrEdge[][N]) {

	arrNode[0]->key_ = 0;
	arrNode[0]->status_ = 't';

	Node* current;
	current = arrNode[0];

	int min;

	while (true)
	{
		min = INT_MAX;

		for (int i = 0; i < N; i++) 
		{
			if (arrEdge[current->info_][i] > 0  && arrNode[i]->status_ == 'q')
			{
				if (arrNode[i]->key_ > arrEdge[current->info_][i]) 
				{
					arrNode[i]->key_ = arrEdge[current->info_][i];
					arrNode[i]->parent_ = current;

					if (min > arrEdge[current->info_][i])
						min = arrEdge[current->info_][i];
				}
			}
		}

		if (min == INT_MAX) return arrNode;

		for (int i = 0; i < N; i++) 
		{
			if (arrNode[i]->key_ == min) {
				arrNode[i]->status_ = 't';
				current = arrNode[i];
			}
		}

	}
}

int main() {

	Node* allNodes[N];

	for (int i = 0; i < N; i++) {
		allNodes[i] = new Node(i);
	}

	int Edges[N][N];
	int a, b, c;

	cout << "Please enter the Edges info" << endl;
	cout << "For example - (0 1 9)." << endl;
	cout << "Where <0> and <1> stand for first and second node, <9> for weight." << endl << endl;
	for (int i = 0; i < M; i++) {
		cout << i << " edge info: ";
		cin >> a >> b >> c;
		Edges[a][b] = c;
		Edges[b][a] = c;
		cout << endl << endl;
	}

	/* -----------	PASS THE VALUES GIVEN BELOW FOR OUR EXAMPLE ----------------- */

	/*
	(0, 1, 9);		(0, 4, 1);		(0, 3, 8);
	(1, 5, 3);		(5, 4, 2);		(1, 2, 4);
	(2, 3, 1);		(4, 3, 5);
	*/

	Node** out;

	out = Prim(allNodes, Edges);

	cout << "Node:   ";
	for (int i = 0; i < N; i++) {
		cout << out[i]->info_ << "  ";
	}
	cout << endl;

	cout << "status: ";
	for (int i = 0; i < N; i++) {
		cout << out[i]->status_ << "  ";
	}
	cout << endl;

	cout << "parent: ";
	for (int i = 0; i < N; i++) {
		if (out[i]->parent_)
			cout << out[i]->parent_->info_ << "  ";
		else
			cout << "-  ";
	}
	cout << endl;

	cout << "key:	";
	for (int i = 0; i < N; i++) {
		cout << out[i]->key_ << "  ";
	}
	cout << endl;

	int enterForExit;
	cin >> enterForExit;

	return 0;
}