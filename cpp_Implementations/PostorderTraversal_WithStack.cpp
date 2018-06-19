#include <iostream>
using namespace std;

struct Node{
	int info_;
	Node* llink_;
	Node* rlink_;
	Node(){}
	Node(int info, Node* llink = 0, Node* rlink = 0) : info_(info), llink_(llink), rlink_(rlink) {}
};


void Postorder(Node* tree)	{								/////   Postorder traversal with stack   /////
	Node* vertex = tree;
	Node* temp;
	Stack s;

	while (vertex != NULL || !s.isEmpty()) {
		if (vertex) {
			s.push(vertex);
			vertex = vertex->llink_;
		}
		else {
			temp = s.top()->rlink_;
			if (temp == NULL)
			{
				temp = s.pop();
				cout << temp->info_;
				while (!s.isEmpty() && temp == s.top()->rlink_) {
					temp = s.pop();
					cout << temp->info_;
				}
			}
			else {
				vertex = temp;
			}
		}
	}
}
