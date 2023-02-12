#pragma once
#include<iostream>
using namespace std;
#include "String.h"
#include "Node.h"
#include "Bst.h"


//set classs
class Set {
public:
	BST* bst;
	BST* bst3;
public:
	int totalelements;
	//default constructor
	Set() {
		bst = nullptr;
		bst3 = nullptr;
		totalelements = 0;
	}
	//constructor with string object
	Set(String s1) {
		bst = new BST(s1);
		totalelements = 1;
	}
	//destructor
	~Set() {
		delete bst;
	}
	//adding elements to the set
	void addElement(String value);

	//union of the two sets
	void unionSetdup(Node* s2) {
		//condition when s2 is null
		if (s2 != nullptr) {
			//recursion for the union 
			unionSetdup(s2->left);
			if (this->bst->search(s2->getValue().getchar()) == 0) {
				this->addElement(s2->getValue().getchar());
			}
			unionSetdup(s2->right);

		}
	}
	//helper function for the union set
	void unionSet(Set* s2);
	/*bool match(Node* s1, Node* s2) {
		if (s1 != nullptr && s2 != nullptr)
			return (strcmp(s1->getValue().getchar(), s2->getValue().getchar()) == 0)
			&& match(s1->left, s2->left) and match(s1->right, s2->right);
			return s1 == s2;
	}

	int subset(Set* s2) {

		Node* temp = this->bst->getRoot();
		while (temp != nullptr) {
			if (temp->getValue().compare(s2->bst->getRoot()->getValue()) == 0) {
-				return match(temp, s2->bst->getRoot());
			}
			else if (temp->getValue().compare(s2->bst->getRoot()->getValue()) == 1) {
				temp = temp->left;
			}
			else
				temp = temp->right;
		}
		return 0;

	}*/

	//subset function checking whenther s2 is proper subset of s1 or not
	int subsetdup(Node* n);


	//helper function for proper subset
	int subset(Set& s2);
	//copying set1 contents into s2
	void copy(Set& s2);

	//intersection of the two sets
	void intersectionSetdup(Node* s2);

	//helper function for intersection of the sets
	void intersectionSet(Set& s2);

	//switching one set contents with another set 
	void switchSet(Set& s2);


	//erasing the contents of the set s1
	void clear()
	{
		delete this->bst;
		this->bst = nullptr;
	}
	bool isEmpty()
	{
		return (this->bst == nullptr);
	}
	//printing the contents of s1
	void print();

};
