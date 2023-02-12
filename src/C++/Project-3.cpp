// Project-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include<iostream>
#include "String.h"
#include "Node.h"
#include "Bst.h"
#include "Set.h"
using namespace std;

// copy constructor
String::String(String& data) {
	size_ = int(strlen(data.chars) + 1);
	chars = new char[size_];
	strcpy_s(chars, size_, data.chars);
}
//char arry constructor
String::String(const char* data) {
	size_ = int(strlen(data) + 1);
	chars = new char[size_];
	strcpy_s(chars, size_, data);
}
int String::compare(String newchar) {

	if (strcmp(this->chars, newchar.getchar()) == 1) {
		return 1;
	}
	else if (strcmp(this->chars, newchar.getchar()) == -1) {
		return -1;
	}
	else
		return 0;
}
//copy constructor
BST::BST(BST& a) {
	root = new Node(*a.root);
	Node* temp = root;
	deepcopy(temp, a.root);
	size = a.size;
}
//copying one object with another object
void BST::copy(BST& a) {
	if (root != nullptr) {
		postorder(root);
	}
	root = new Node(*a.root);
	Node* temp = root;
	deepcopy(temp, a.root);
	size = a.size;

}
// copying one set with another set
void BST::deepcopy(Node* a, Node* b) {
	//checking node is nullptr
	if (b == nullptr) {
		return;
	}
	//checking node.left is nullptr
	if (b->left != nullptr) {
		a->left = new Node(*b->left);

	}
	//checking node.right is nullptr
	if (b->right != nullptr) {
		a->right = new Node(*b->right);
	}
	//recursion of the left and right of the tree
	deepcopy(a->left, b->left);
	deepcopy(a->right, b->right);
}
//post order traversal
void BST::postorder(Node* a) {
	//checking the root is nullptr
	if (a == nullptr) {
		return;
	}
	//recursion of the postorder traversal
	postorder(a->left);
	postorder(a->right);
	//deleting a tree
	delete a;
}
//searching whether the string is present or not 
int BST::search(String value) {
	Node* temp = this->root;
	//checking the root is present or not
	while (temp != nullptr) {
		//when the value is present
		if (temp->getValue().compare(value) == 0) {
			return 1;
		}
		//when the value is less than the current
		else if (temp->getValue().compare(value) == 1) {
			temp = temp->left;
		}
		//when the value is greater than the current
		else
			temp = temp->right;
	}
	return 0;

}
//inserting the value to the tree
void BST::push(String value) {
	//do the process when the value is not present in the tree
	if (search(value) == 0) {
		Node* iter = this->root;
		/*if (iter->getValue().compare(value) == 0) {
			return;
		}*/
		//looping the entire tree
		while (iter != nullptr) {
			//when the value is greater than the root value
			if (iter->getValue().compare(value) == -1) {
				if (iter->right == nullptr) {
					iter->right = new Node(value);
					size += 1;
					iter = nullptr;
				}
				else
					iter = iter->right;
			}
			//when the value is less than the root value
			else if (iter->getValue().compare(value) == 1) {
				if (iter->left == nullptr) {
					iter->left = new Node(value);
					size += 1;
					iter = nullptr;
				}
				else
					iter = iter->left;
			}
		}
	}

}

//print the root values
void BST::print() {
	cout << this->root->getValue().getchar() << endl;
	cout << this->root->right->getValue().getchar() << endl;
	cout << this->root->left->getValue().getchar() << endl;
}
//inorder traversal
void BST::inorder(Node* root) {
	//checking the root is null or not
	if (root == nullptr)
		return;
	//recursion of the inorder traversal
	inorder(root->left);
	cout << root->getValue().getchar() << " ";
	inorder(root->right);
}
//adding elements to the set
void Set::addElement(String value) {
	//condition when the root is null
	if (this->bst == nullptr)
	{
		this->bst = new BST(value);
		totalelements = 1;
	}
	//condition when root is not null
	else
	{
		if (this->bst->search(value) == 0)
		{
			this->bst->push(value);
			totalelements += 1;
		}

	}

}
//helper function for the union set
void Set::unionSet(Set* s2) {
	//code when both sets are null
	if (this->bst == nullptr && s2->bst == nullptr) {
		return;
	}
	//code when the bst is null
	else if (this->bst == nullptr) {
		this->bst = new BST();
		this->bst->copy(*s2->bst);
		totalelements = s2->totalelements;
	}
	//code when set2 is null
	else if (s2->bst != nullptr) {
		unionSetdup(s2->bst->getRoot());
	}
}
//subset function checking whenther s2 is proper subset of s1 or not
int Set::subsetdup(Node* n) {

	//code when the node is not nullptr
	while (n != nullptr)
	{
		if (this->bst->search(n->getValue()) != 1) {
			return 0;
		}
		//recursion of subset
		int left = subsetdup(n->left);
		int right = subsetdup(n->right);
		return (left + right == 1) ? 0 : 1;
	}
	return 1;
}
//helper function for proper subset
int Set::subset(Set& s2) {
	//edge cases
	if (this->bst == nullptr && s2.bst != nullptr)
	{
		return 0;
	}
	else if (this->bst == nullptr)
	{
		return 0;
	}
	else if (s2.bst == nullptr)
	{
		return 1;
	}
	else
	{
		int x = subsetdup(s2.bst->getRoot());
		if (x == 1)
		{
			if (this->bst->size == s2.bst->size)
			{
				return 0;
			}
		}
		return x;
	}

}
//copying set1 contents into s2
void Set::copy(Set& s2)
{
	//when s2 is nullptr
	if (s2.bst == nullptr)
	{
		if (this->bst == nullptr)
		{
			delete this->bst;
		}
		this->bst = nullptr;
	}
	//when s2 is not nullptr
	else
	{
		if (this->bst == nullptr)
		{
			delete this->bst;
		}
		this->bst = new BST(*s2.bst);
		totalelements = s2.totalelements;

	}
}
//intersection of the two sets
void Set::intersectionSetdup(Node* s2) {
	//when s2 is not nullptr
	if (s2 != nullptr) {
		//recursion of the intersection
		intersectionSetdup(s2->left);
		if (this->bst->search(s2->getValue().getchar()) == 1) {
			if (this->bst3 == nullptr) {
				this->bst3 = new BST(s2->getValue());
			}
			else {
				this->bst3->push(s2->getValue());
			}
		}
		intersectionSetdup(s2->right);
	}
}
//helper function for intersection of the sets
void Set::intersectionSet(Set& s2) {
	if (this->bst == nullptr)
	{
		return;
	}
	if (s2.isEmpty()) {
		delete this->bst;
		this->bst = nullptr;
		return;
	}
	if (this->bst != nullptr && s2.bst != nullptr) {
		Node* n = s2.bst->getRoot();
		intersectionSetdup(n);
		if (this->bst != nullptr)
		{
			delete this->bst;
			this->bst = nullptr;
		}
		this->bst = this->bst3;
		this->bst3 = nullptr;
	}

}
//switching one set contents with another set 
void Set::switchSet(Set& s2) {
	//edge cases of the roots
	if (this->bst == nullptr && s2.bst == nullptr)
	{
		return;
	}
	else if (this->bst == nullptr)
	{
		this->bst = new BST(*s2.bst);
		delete s2.bst;
		s2.bst = nullptr;
	}
	else if (s2.bst == nullptr)
	{
		s2.bst = new BST(*this->bst);
		delete this->bst;
		this->bst = nullptr;
	}
	else
	{
		/*cout << (s2.bst == nullptr) << endl;*/
		BST temp = *this->bst;
		/*cout << (s2.bst == nullptr) << endl;*/
		delete this->bst;
		/*cout << (s2.bst == nullptr) << endl;*/
		this->bst = new BST(*s2.bst);
		delete s2.bst;
		s2.bst = nullptr;
		s2.bst = new BST(temp);
	}

}
//printing the contents of s1
void Set::print() {
	if (this->isEmpty()) {
		cout << "set is empty" << endl;
	}
	else {
		this->bst->inorderdup();
	}
}


int main()
{
	{

		Set* S1 = new Set();
		Set* S2 = new Set();
		bool flag = true;
		while (flag) {
			char cmd;
			cout << endl;
			cout << "Enter Command" << endl;
			cin >> cmd;

			switch (cmd) {
			case 'e':
			{
				S1->clear();
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 's':
			{
				S1->switchSet(*S2);
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 'b':
			{
				int output = S1->subset(*S2);
				if (output == 0)
					cout << "not proper subset" << endl;
				else
					cout << "proper subset" << endl;
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 'c':
			{
				S2->copy(*S1);
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 'l':
			{
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 'a':
			{
				char value[100];
				cin >> value;
				String* s1 = new String(value);
				S1->addElement(*s1);
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 'u':
			{
				S1->unionSet(S2);
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 'i':
			{
				S1->intersectionSet(*S2);
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			case 'q':
			{
				flag = false;
				cout << "S1 set is :" << endl;
				S1->print();
				cout << endl;
				cout << "S2 set is :" << endl;
				S2->print();
				break;
			}
			}
		}
	}
}