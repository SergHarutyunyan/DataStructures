#include <iostream>
using namespace std;

struct Node{
	int		key_;
	int		degree_;
	Node*	parent_;
	Node*	child_;
	Node*	sibling_;
	Node(int key = 0, int degree = 0,
		Node* parent = 0, Node* child = 0, Node* sibling = 0) :
		key_(key), degree_(degree),
		parent_(parent), child_(child), sibling_(sibling){}
};

Node* minimum(Node* head) {

	Node* temp = head;
	temp = temp->sibling_;
	Node* min = new Node();
	min->key_ = INT_MAX;

	while (temp) {
		if (temp->key_ < min->key_) {
			min = temp;
		}
		temp = temp->sibling_;
	}

	return min;
}

void binomialLink(Node* x, Node* y) {
	x->parent_ = y;
	x->sibling_ = y->child_;
	y->child_ = x;
	y->degree_ = y->degree_ + 1;
}


Node* binomialHeapMerge(Node* H1, Node* H2) {

	Node* head = new Node();
	Node* current = new Node();
	head->sibling_ = current;
	
	H1 = H1->sibling_;
	H2 = H2->sibling_;

	bool both = false;
	bool exH1 = false;
	bool exH2 = false;

	if (H1 || H2) 
	{
		while (true)
		{
			if (H1 && H2) both = true;
			else if (H1) exH1 = true;
			else if (H2) exH2 = true;

			if (both) {
				if (H1->degree_ <= H2->degree_) {
					current->sibling_ = H1;
					H1 = H1->sibling_;
				}
				else {
					current->sibling_ = H2;
					H2 = H2->sibling_;
				}
				both = false;
			}
			else if (exH1) {
				current->sibling_ = H1;
				H1 = H1->sibling_;
				exH1 = false;
			}
			else {
				current->sibling_ = H2;
				H2 = H2->sibling_;
				exH2 = false;
			}

			if (H1 || H2) {
				current = current->sibling_;
				current->sibling_ = new Node();
			}
			else {
				return head->sibling_;
			}
		}	
	}
}

Node* binomialHeapUnion(Node* heap1, Node* heap2) {

	Node* head = binomialHeapMerge(heap1, heap2); 
	
	if (head->sibling_) {
		Node* x = new Node();
		Node* prev_x = new Node();
		Node* next_x = new Node();

		x = head;
		next_x = x->sibling_;

		while (next_x) {
			if (next_x->sibling_ && next_x->sibling_->degree_ == x->degree_) {
				prev_x = x;
				x = next_x;
			}
			else if (x->key_ < next_x->key_) {
				x->sibling_ = next_x->sibling_;
				binomialLink(next_x, x);
			}
			else if (prev_x) {
				prev_x->sibling_ = next_x;
				binomialLink(x, next_x);
				x = next_x;
			}
			else  head = next_x;

			next_x = x->sibling_;
		}
		return head;
	}
	else {
		return head;
	}

}

void insert(Node* head, Node* x) {
	Node* temp = new Node();
	temp->sibling_ = x;
	binomialHeapUnion(head, temp);
};

void decreaseKey(Node* head, Node* x, int k) {

	Node* tmp1 = new Node();
	Node* tmp2 = new Node();
	int temp = 0;

	if (k > x->key_) {
		return;
	}
	else {
		x->key_ = k;
		tmp1 = x;
		tmp2 = tmp1->parent_;

		while (tmp2 && tmp1->key_ < tmp2->key_) {
			tmp1->key_ = temp;
			tmp1->key_ = tmp2->key_;
			tmp2->key_ = temp;

			tmp1 = tmp2;
			tmp2 = tmp1->parent_;
		}
	}

}
