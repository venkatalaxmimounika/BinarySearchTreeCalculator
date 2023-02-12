#pragma once
#include<iostream>
using namespace std;
#include "String.h"
#include "Node.h"

//bst class
class BST {
	//root in bst
private:
	Node* root;
public:
	int size;
	//default constructor
	BST() {
		root = nullptr;
		size = 0;
	}
	//copy constructor
	BST(BST& a);
	//copying one object with another object
	void copy(BST& a);
	// copying one set with another set
	void deepcopy(Node* a, Node* b);
	//bst destructor
	~BST() {
		Node* temp = root;
		postorder(temp);
	}
	//post order traversal
	void postorder(Node* a);
	//constructor with string object
	BST(String value) {
		root = new Node(value);
		size = 1;
	}
	//retruning the root
	Node* getRoot() {
		return root;
	}
	//searching whether the string is present or not 
	int search(String value);
	//inserting the value to the tree
	void push(String value);

	//print the root values
	void print();
	//inorder traversal
	void inorder(Node* root);
	//supporting function for inorder
	void inorderdup() {
		inorder(this->root);
	}
};
