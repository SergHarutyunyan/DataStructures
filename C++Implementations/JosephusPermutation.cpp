struct Node{
	int info_;
	int size_;
	Node* parent_;
	Node* llink_;
	Node* rlink_;

	Node(int info, int size = 1, Node* parent = 0, Node* llink = 0, Node* rlink = 0) :
		parent_(parent), info_(info), llink_(llink), rlink_(rlink), size_(size)
	{}
};

#include <iostream>
#include <algorithm>
using namespace std;

class BinarySearchTree {
public:
	BinarySearchTree() {
		tree = 0;
	};

	void PrintJosephusPermutation(int n, int m);


	void insert(int elem);
	void remove(int elem);

	Node* select(int i);				// returns the <i>-th smallest element from tree.
	int Rank(Node* node);				// returns the rank of the given <Node> from tree.

	void print(Node* tree, int ind);

	Node* find(int elem);
	Node* predecessor(Node* ptr);
	Node* successor(Node* ptr);

	Node* min(Node*& tree) const {
		if (tree->llink_ == NULL)
			return tree;
		return min(tree->llink_);
	};

	Node* max(Node*& tree) const  {
		if (tree->rlink_ == NULL)
			return tree;
		return max(tree->rlink_);
	};

	Node* tree;
};

void  BinarySearchTree::print(Node* tree, int indent)
{
	if (tree == 0) return;

	print(tree->rlink_, indent + 5);

	for (int i = 0; i<indent; i++) cout << ' ';
	cout << tree->info_ << "(" << tree->size_ << ")" << endl;

	print(tree->llink_, indent + 5);

}

Node* BinarySearchTree::find(int elem){
	Node* current = tree;
	while (current){
		if (current->info_ == elem) return current;
		current = (elem<current->info_) ? current->llink_ : current->rlink_;
	}
	return 0;
}


void BinarySearchTree::insert(int elem){
	Node* current = tree;
	Node* prev = 0;
	while (current){
		prev = current;
		current->size_++;
		current = (elem<current->info_) ? current->llink_ : current->rlink_;
	}
	current = new Node(elem, 1, prev);
	if (prev == 0)
		tree = current;
	else
		(elem<prev->info_) ? prev->llink_ = current : prev->rlink_ = current;
}

void BinarySearchTree::remove(int elem){
	bool a = false;
	Node* current = find(elem);
	if (current == 0)return;


	Node* next;
	if (current->llink_ && current->rlink_){
		for (next = current->rlink_; next->llink_; next = next->llink_);
		current->info_ = next->info_;
		current = next;

		Node* temp = next->parent_;
		while (temp) {
			temp->size_--;
			temp = temp->parent_;
		}
		a = true;

	}

	if (current->llink_ == 0){
		if (current->parent_)
		if (current == current->parent_->llink_)
			current->parent_->llink_ = current->rlink_;
		else
			current->parent_->rlink_ = current->rlink_;
		else
			tree = current->rlink_;

		if (current->rlink_)
			current->rlink_->parent_ = current->parent_;


		if (!a) {
			Node* temp = current->parent_;
			while (temp) {
				temp->size_--;
				temp = temp->parent_;
			}
		}
		delete current;
		return;
	}

	if (current->parent_)
	if (current == current->parent_->llink_)
		current->parent_->llink_ = current->llink_;
	else
		current->parent_->rlink_ = current->llink_;
	else
		tree = current->llink_;

	current->llink_->parent_ = current->parent_;


	delete current;
}

Node* BinarySearchTree::successor(Node* ptr) {
	if (ptr->rlink_ != NULL)
		return min(ptr->rlink_);

	Node *p = ptr->parent_;
	while (p != NULL && ptr == p->rlink_)
	{
		ptr = p;
		p = p->parent_;
	}
	return p;

}

Node* BinarySearchTree::predecessor(Node* ptr) {
	if (ptr->llink_ != NULL)
		return max(ptr->llink_);

	Node *p = ptr->parent_;

	while (p != NULL && ptr == p->llink_)
	{
		ptr = p;
		p = p->parent_;
	}
	return p;
}

Node* BinarySearchTree::select(int i) {
	int k;
	Node* temp = tree;

	if (tree->llink_) {
		k = tree->llink_->size_ + 1;
	}
	else {
		k = 1;
	}

	if (i <= tree->size_) {
		while (i != k)
		{
			if (i < k) {
				temp = temp->llink_;
				if (temp->llink_) { k = temp->llink_->size_ + 1; }
				else k = 1;
			}
			else if (i > k) {
				i = i - k;
				temp = temp->rlink_;
				if (temp->llink_) { k = temp->llink_->size_ + 1; }
				else k = 1;
			}
		}
		return temp;
	}
	else {
		return 0;
	}

}

int BinarySearchTree::Rank(Node* node) {
	int k;
	if (node->llink_) { k = node->llink_->size_ + 1; }
	else k = 1;

	while (node != tree) {
		if (node == node->parent_->rlink_) {

			if (node->parent_->llink_) { k += node->parent_->llink_->size_ + 1; }
			else k++;
		}
		node = node->parent_;
	}

	return k;
}


void BinarySearchTree::PrintJosephusPermutation(int n, int m) {

	cout << "Passed parameters: " << "n = " << n << " m = " << m << endl <<endl;


	BinarySearchTree obj1;							

	int * arr = new int[n];
	for (int i = 0; i < n; i++) {					
		arr[i] = i + 1;
	}

	random_shuffle(arr, arr + n);					

	for (int i = 0; i < n; i++) {					
		obj1.insert(arr[i]);
	}
		
	int step = m;									
	int iter;
	
	while (obj1.tree) {								
		while (step > n) {
			step = step - n;
		}

		iter = obj1.select(step)->info_;
		cout << iter << " ";
		obj1.remove(iter);
		
		n--;

		if (n == 1) {
			iter = obj1.select(1)->info_;
			cout << iter << " ";
			obj1.remove(iter);
			return;
		}

		step = step + m - 1;
	}

}

int main()
{
	BinarySearchTree BST;

	BST.PrintJosephusPermutation(7, 3);

	_getchar_nolock();

	return 0;
}
