#include <iostream>
using namespace std;


struct HeadNode{
	int	  length_;										// Using length_ for Linked-list Heuristic mode..
														// To avoid joining long list to short.
	struct Node* head_;									
	struct Node* tail_;
	HeadNode(int length = 1, Node* head = 0, Node* tail = 0) :
		length_(length), head_(head), tail_(tail){}
};
													
struct Node{
	char 	info_;
	Node*	sibling_;
	struct HeadNode *toHead_;
	Node(char info, Node* sibling = 0, HeadNode* toHead = 0) :
		info_(info), sibling_(sibling), toHead_(toHead){}
};

		
void make_set(Node* elem) {
	HeadNode* H = new HeadNode();
	Node* N = elem;

	H->head_ = elem;
	H->tail_ = elem;
	elem->toHead_ = H;
}

Node* find_set(Node* elem) {
	return elem->toHead_->head_;
}

void joinPreparation(Node * elem1, Node * elem2) {
	if (elem1->toHead_ != elem2->toHead_) {
		if (elem1->toHead_->length_ > elem2->toHead_->length_) {

			elem1->toHead_->tail_->sibling_ = elem2->toHead_->head_;
			elem1->toHead_->tail_ = elem2->toHead_->tail_;
			elem1->toHead_->length_ += elem2->toHead_->length_;

			Node* temp = elem2->toHead_->head_;
			while (temp) {
				temp->toHead_ = elem1->toHead_;
				temp = temp->sibling_;
			}	
		}
		else {
			elem2->toHead_->tail_->sibling_ = elem1->toHead_->head_;
			elem2->toHead_->tail_ = elem1->toHead_->tail_;
			elem2->toHead_->length_ += elem1->toHead_->length_;

			Node* temp = elem1->toHead_->head_;
			while (temp) {
				temp->toHead_ = elem2->toHead_;
				temp = temp->sibling_;
			}	
		}
	} else  return;
}

void unionLists(Node* elem1, Node* elem2) {
	joinPreparation(elem1, elem2);
}

void print(Node* elem) {
	Node* current = elem->toHead_->head_;
	cout << "HEAD:";
	while (current) {
		cout << " -> " << current->info_;
		current = current->sibling_;
	}
}


int main() {

	Node* a = new Node('a');	make_set(a);		
	Node* b = new Node('b');	make_set(b);
	Node* c = new Node('c');	make_set(c);
	Node* d = new Node('d');	make_set(d);
	Node* e = new Node('e');	make_set(e);
	Node* f = new Node('f');	make_set(f);
	Node* g = new Node('g');	make_set(g);
	Node* h = new Node('h');	make_set(h);
	Node* i = new Node('i');	make_set(i);
	Node* j = new Node('j');	make_set(j);
	Node* k = new Node('k');	make_set(k);

	/*
		We have these unions...

		(d,i)	(f,k) 	(g,i)	(b,g)		
		(a,h)   (i,j)	(d,k)   (b,j)
		(d,f)	(g,j)	(a,e) 

	*/

	cout << "(d,i):	" ;	unionLists(d, i);	print(d);
	cout << endl << "(f,k):	";	unionLists(f, k);	print(f);
	cout << endl << "(g,i):	";	unionLists(g, i);	print(g);
	cout << endl << "(b,g):	";	unionLists(b, g);	print(b);
	cout << endl << "(a,h):	";	unionLists(a, h);	print(a);
	cout << endl << "(i,j):	";	unionLists(i, j);	print(i);
	cout << endl << "(d,k):	";	unionLists(d, k);	print(d);
	cout << endl << "(b,j):	";	unionLists(b, j);	print(b);
	cout << endl << "(d,f):	";	unionLists(d, f);	print(d);
	cout << endl << "(g,j):	";	unionLists(g, j);	print(g);
	cout << endl << "(a,e):	";	unionLists(a, e);	print(a);

	
	cout << endl << "-------------DONE-----------" << endl;

	_getchar_nolock();
	return 0;
}