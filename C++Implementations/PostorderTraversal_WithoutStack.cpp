#include <iostream>
using namespace std;

struct Node{
	char info_;
	Node* llink_;
	Node* rlink_;
	Node* parent_;
	Node(){}
	Node(char info,
		Node* llink = 0,
		Node* rlink = 0,
		Node* parent = 0
		) :
		info_(info),
		llink_(llink),
		rlink_(rlink),
		parent_(parent)
	{}
};

void Postorder(Node* tree)	{								/////   Postorder traversal without stack   /////
	Node* vertex = tree;
	Node* parent;

	if (vertex == NULL) { return; }

	while (true)
	{
		if (vertex->llink_){ vertex = vertex->llink_; continue; }
		if (vertex->rlink_){ vertex = vertex->rlink_; continue; }

		cout << vertex->info_;
		if (vertex == tree) { return; }
		parent = vertex->parent_;

		while (true) {
			if (vertex == parent->llink_)
			{
				if (parent->rlink_) {
					vertex = parent->rlink_;
					break;
				}
				else {
					vertex = parent;
					cout << vertex;
					if (vertex == tree) { return; }
					parent = vertex->parent_;

				}
			}
			else {
				while (vertex == parent->rlink_) {
					vertex = parent;
					cout << vertex;
					if (vertex == tree) { return; }
					parent = vertex->parent_;
				}
			}
		}


	}
}