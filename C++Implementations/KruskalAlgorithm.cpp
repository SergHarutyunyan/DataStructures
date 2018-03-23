#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
	int first_;
	int second_;
	float weight_;
	Edge(int first, int second, float weight) :
		first_(first), second_(second), weight_(weight){}
};

struct Node {
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

bool compare(Edge* i, Edge* j) 
{ 
	return i->weight_ < j->weight_;
}

const int N = 6;										// For our example problem we have N = 6 Nodes and M = 9 Edges.
const int M = 9;
int numb;



void Kruskal(Edge* arrEdge[], Node* arrNode[], Edge* output[]) {

	sort(&arrEdge[0], &arrEdge[M], compare);

	int iter = 0;
	for (int j = 0; j < M - 1; j++) {

		if (find_set(arrNode[arrEdge[j]->first_]) != find_set(arrNode[arrEdge[j]->second_])) {

			output[iter] = arrEdge[j];
			iter++;
			unionTrees(arrNode[arrEdge[j]->first_], arrNode[arrEdge[j]->second_]);
		}
	}
	numb = iter;
}

int main() {

	/*
		Here I am testing the Kruskal's algorithm for the example given in our problems document 1-st problem. 
	*/

	Node* AllNodes[N];
	for (int i = 0; i < N; i++) {
		Node* tmp = new Node(i);
		make_set(tmp);
		AllNodes[i] = tmp;
	}

	Edge* AllEdges[M];

	AllEdges[0] = new Edge(0, 1, 5);
	AllEdges[1] = new Edge(1, 3, 3);
	AllEdges[2] = new Edge(0, 2, 20);
	AllEdges[3] = new Edge(2, 3, 4);
	AllEdges[4] = new Edge(0, 4, 25);
	AllEdges[5] = new Edge(1, 5, 20);
	AllEdges[6] = new Edge(2, 4, 5);
	AllEdges[7] = new Edge(3, 5, 10);
	AllEdges[8] = new Edge(4, 5, 4);

	Edge* Output[M - 1];

	Kruskal(AllEdges, AllNodes, Output);
	
	for (int i = 0; i < numb; i++) {
		cout << "First-second: " << Output[i]->first_ << " - " << Output[i]->second_ << "	Weight: " << Output[i]->weight_ << endl << endl;
	}
	

	_getchar_nolock();
	
	return 0;
}