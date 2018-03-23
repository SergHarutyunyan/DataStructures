#include <iostream>
using namespace std;

class Node{
public:
	int  	info_;
	int   	rank_;
	Node*	parent_;
	Node(int info, int rank = 0, Node* parent = 0) :
		info_(info), rank_(rank), parent_(parent){}
};


void make_set(Node* elem) {
	elem->parent_ = elem;
	elem->rank_ = 0;
}

void link(Node* elem1, Node* elem2) {
	if (elem1->rank_ > elem2->rank_)
		elem2->parent_ = elem1;
	else {
		elem1->parent_ = elem2;
		if (elem1->rank_ == elem2->rank_)
			elem2->rank_ = elem2->rank_ + 1;
	}
}

Node* find_set(Node* elem) {
	if (elem != elem->parent_) {
		elem->parent_ = find_set(elem->parent_);
	}
	return elem->parent_;
}

void unionTrees(Node* elem1, Node* elem2) {
	link(find_set(elem1), find_set(elem2));
}


