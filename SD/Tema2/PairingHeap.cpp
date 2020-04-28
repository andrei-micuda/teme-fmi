#include "PairingHeap.h"

/*// NODE IMPLEMENTATION //*/
// STATIC VARIABLES
int Node::nrOfNodes = 0;

// CONSTRUCTORS
Node::Node(int val):val(val), nextSibling(nullptr), firstChild(nullptr){
	nrOfNodes++;
}

// METHODS
void Node::addChild(Node* node) {
	if (this->firstChild == nullptr)
		this->firstChild = node;
	else {
		node->nextSibling = this->firstChild;
		this->firstChild = node;
	}
}

// FRIENDS
void freeMemory(Node* root) {
	if (root == nullptr)
		return;
	freeMemory(root->nextSibling);
	freeMemory(root->firstChild);
	delete root;
}

/*// PAIRING HEAP IMPLEMENTATION //*/
// STATIC VARIABLES
std::map<int, bool> PairingHeap::deleted;

// CONSTRUCTORS
PairingHeap::PairingHeap():root(nullptr){}

PairingHeap::PairingHeap(int val) {
	this->root = new Node(val);
}

PairingHeap::PairingHeap(Node* root):root(root){}

// METHODS
void PairingHeap::build(const std::vector<int>& v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		this->insert(v[i]);
	}
}

int PairingHeap::getMin() {
	return root->val;
}

int PairingHeap::size() {
	return Node::nrOfNodes;
}

void PairingHeap::insert(int val) {
	PairingHeap* tmp = new PairingHeap(val);
	(*this) = merge((*this), (*tmp));
}

void PairingHeap::deleteMin() {
	Node* childOfRoot = this->root->firstChild;
	delete this->root;
	std::queue<Node*> subHeaps;

	// we get pointers to all children of the previous root
	while (childOfRoot != nullptr) {
		subHeaps.push(childOfRoot);
		Node* tmp = childOfRoot->nextSibling;
		// we don't want the children to be connected anymore
		childOfRoot->nextSibling = nullptr;
		childOfRoot = tmp;
	}

	// merge heaps using the two pass method

	// first traversal - we "pair" the heaps left to right and merge them
	std::stack<Node*> firstTraversal;
	// while we have enough heaps to "pair"
	while (subHeaps.size() > 1) {
		PairingHeap heap1(subHeaps.front());
		subHeaps.pop();
		PairingHeap heap2(subHeaps.front());
		subHeaps.pop();
		firstTraversal.push(merge(heap1, heap2).root);
	}
	if (subHeaps.size() == 1) {
		firstTraversal.push(subHeaps.front());
		subHeaps.pop();
	}

	// second traversal - start from rightmost heap and merge each other heap with this one
	this->root = nullptr;
	while (!firstTraversal.empty()) {
		PairingHeap tmpHeap(firstTraversal.top());
		(*this) = merge((*this), tmpHeap);
		firstTraversal.pop();
	}
	// if the new minimum has been marked for deletion by lazy deletion, we delete the minimum again
	if (this->root != nullptr && deleted[this->root->val])
		this->deleteMin();
}

void PairingHeap::deleteVal(int val) {
	// if the value we want to delete is the minumum we delete it, else we just mark it for deletion
	if (this->root->val == val) {
		this->deleteMin();
	}
	else {
		deleted[val] = 1;
	}
}

void PairingHeap::freeMemory() {
	::freeMemory(this->root);
	this->root = nullptr;
}

// FRIENDS
PairingHeap& merge(PairingHeap& heap1, PairingHeap& heap2) {
	if (heap1.root == nullptr) return heap2;
	if (heap2.root == nullptr) return heap1;

	// we make the minumum of the two roots the root of the new heap and add the other as its leftmost child
	if (heap1.getMin() < heap2.getMin()) {
		heap1.root->addChild(heap2.root);
		return heap1;
	}
	else {
		heap2.root->addChild(heap1.root);
		return heap2;
	}
}
