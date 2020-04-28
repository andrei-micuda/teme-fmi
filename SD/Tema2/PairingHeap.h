#pragma once
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

class Node {
	int val;
	Node* nextSibling;
	Node* firstChild;
	static int nrOfNodes; //to easily get the size of the heap
public:
	// CONSTRUCTORS
	Node(int val);

	// METHODS
	void addChild(Node* node);

	// FRIENDS
	friend class PairingHeap;
	friend void freeMemory(Node* root); //deletes the root node and all its descendants
};

class PairingHeap {
	Node* root;
	static std::map<int, bool> deleted;
public:
	// CONSTRUCTORS
	PairingHeap();
	PairingHeap(int val); //creates a heap with one element (used for insertion)
	PairingHeap(Node* root); //initializes a heap with another node (used for deletion)

	// METHODS
	int getMin();
	void show();
	int size();
	void build(const std::vector<int>& v);
	void insert(int val);
	void deleteMin();
	void deleteVal(int val);
	void freeMemory();

	// FRIENDS
	friend PairingHeap& merge(PairingHeap& heap1, PairingHeap& heap2);
};
