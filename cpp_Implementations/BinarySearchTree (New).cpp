struct Node{
	int info_;
	int size_;
	Node* parent_;
	Node* llink_;
	Node* rlink_;

	Node(int info,int size = 1,Node* parent = 0, Node* llink = 0, Node* rlink = 0) :
		parent_(parent), info_(info), llink_(llink), rlink_(rlink), size_(size)
	{}
};

#include <iostream>
using namespace std;

class BinarySearchTree {
public:
	BinarySearchTree() {
		tree = 0;
	};

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
	cout << tree->info_ <<"(" << tree->size_ << ")" << endl;

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
	current = new Node(elem,1,prev);
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
	Node* temp = tree;
	int k = tree->llink_->size_ + 1;

	if (i <= tree->size_) {										
		while (i != k) 
		{
			if (i < k) {
				temp = temp->llink_;
				if (temp->llink_) { k = temp->llink_->size_ + 1; }
				else k = 1;
			} else if (i > k) {
				i = i - k;
				temp = temp->rlink_;
				if (temp->llink_) { k = temp->llink_->size_ + 1; }
				else k = 1;
			}
		}
		return temp;
	} else {
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

int main()
{
	BinarySearchTree BST;

	BST.insert(100);						// inserting nodes
	BST.insert(120);
	BST.insert(200);
	BST.insert(70);
	BST.insert(150);
	BST.insert(250);
	BST.insert(225);
	BST.insert(235);
	BST.insert(85);
	BST.insert(40);
	BST.insert(30);
	BST.insert(55);
	BST.insert(210);
	BST.insert(205);
	
//	BST.remove(100);
//	BST.remove(225);
	BST.remove(200);
	BST.remove(40);
	BST.remove(30);
	
	BST.print(BST.tree,5);				
	
	cout << endl;
	cout << "Minimum - " << BST.min(BST.tree)->info_ << endl;							
	cout << "Maximum - " << BST.max(BST.tree)->info_ << endl;							


	Node* temp = BST.tree->rlink_;

	cout << temp->info_ <<"'s " <<"Successor's node value - "<< BST.successor(temp)->info_   << endl;			
	cout << temp->info_ << "'s " << "Predecessor's node value - " << BST.predecessor(temp)->info_ << endl;		

	cout << endl;

	int number1 = 3;
	int number2 = 6;

	cout << "Selecting the smallest " << number1 << " value, which was " << BST.select(number1)->info_ << endl;			
	cout << "Selecting the smallest " << number2 << " value, which was " << BST.select(number2)->info_ << endl;

	cout << endl;

	cout << "Rank of the " << BST.select(number1)->info_ << " value was " << BST.Rank(BST.select(number1)) << endl;
	cout << "Rank of the " << BST.select(number2)->info_ << " value was " << BST.Rank(BST.select(number2)) << endl;


	_getchar_nolock();
	return 0;
}
