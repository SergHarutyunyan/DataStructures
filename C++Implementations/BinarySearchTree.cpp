struct Node{
	int info_;
	Node* parent_;
	Node* llink_;
	Node* rlink_;

	Node(int info, Node* parent = 0, Node* llink = 0, Node* rlink = 0) :
		parent_(parent), info_(info), llink_(llink), rlink_(rlink)
	{}
};

#include <iostream>
using namespace std;

class BinarySearchTree {
public:
	BinarySearchTree() { tree = 0; };

	void insert(Node*& tree, int elem);
	Node* find(Node* tree, int elem);
	void remove(Node*& tree, int elem);

	void inorder(Node* tree);							// Printing the tree in inorder traversal

	int predecessor(Node* ptr);
	int successor(Node* ptr);

	int min(Node* tree) const {							
		{
			if (tree->llink_ == NULL)
			return tree->info_;
			return min(tree->llink_);

		}
	};

	int max(Node* tree) const  {
		if (tree->rlink_ == NULL)
			return tree->info_;
		return max(tree->rlink_);
	};

	Node *tree;										 

};

void BinarySearchTree::inorder(Node* tree)			// Inorder Traversal for printing the binary three node's values.
{
	if (tree != NULL)
	{
		inorder(tree->llink_);

		cout << tree->info_ << endl;

		inorder(tree->rlink_);
	}
}

Node* BinarySearchTree::find(Node* tree, int elem){
	Node* current = tree;
	while (current){
		if (current->info_ == elem) return current;
		current = (elem<current->info_) ? current->llink_ : current->rlink_;
	}
	return 0;
}


void BinarySearchTree::insert(Node*& tree, int elem){
	Node* current = tree;
	Node* prev = 0;
	while (current){
		prev = current;
		current = (elem<current->info_) ? current->llink_ : current->rlink_;
	}
	current = new Node(elem, prev);
	if (prev == 0)
		tree = current;
	else
		(elem<prev->info_) ? prev->llink_ = current : prev->rlink_ = current;
}

void BinarySearchTree::remove(Node*& tree, int elem){
	Node* current = find(tree, elem);
	if (current == 0)return;

	Node* next;
	if (current->llink_ && current->rlink_){
		for (next = current->rlink_; next->llink_; next = next->llink_)
			;
		current->info_ = next->info_;
		current = next;
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


int BinarySearchTree::successor(Node* ptr) {
	if (ptr->rlink_ != NULL) 
		return min(ptr->rlink_);
	
	Node *p = ptr->parent_;
	while (p != NULL && ptr == p->rlink_)
	{
		ptr = p;
		p = p->parent_;
	}
	return p->info_;

}

int BinarySearchTree::predecessor(Node* ptr) {	
	if (ptr->llink_ != NULL) 
		return max(ptr->llink_);

	Node *p = ptr->parent_;

	while (p != NULL && ptr == p->llink_)
	{
		ptr = p;
		p = p->parent_;
	}
	return p->info_;

}


int main()
{
	BinarySearchTree BST;

	BST.insert(BST.tree, 100);			// inserting nodes
	BST.insert(BST.tree, 50);
	BST.insert(BST.tree, 200);
	
	BST.insert(BST.tree, 70);
	BST.insert(BST.tree, 150);
	BST.insert(BST.tree, 250);
	BST.insert(BST.tree, 225);
	/*
	BST.remove(BST.tree, 100);
	BST.remove(BST.tree, 80);
	BST.remove(BST.tree, 225);
	*/

	BST.inorder(BST.tree);				// Printing tree

	cout << endl;
	cout << "Minimum - " << BST.min(BST.tree) << endl;							//    Testing min()		//
 	cout << "Maximum - " << BST.max(BST.tree) << endl;							//    Testing max()		//

	cout << endl;																	
	Node* temp = BST.tree->rlink_->rlink_->llink_;												   	   
	cout <<"Successor's node value - "<< BST.successor(temp)   << endl;			//  Testing Successor()  //
	cout <<"Predecessor's node value - "<< BST.predecessor(temp) << endl;		// Testing Predecessor() //
	_getchar_nolock();
	return 0;
}
