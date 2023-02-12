#pragma once
#include<iostream>
using namespace std;
#include "String.h"

//node class
class Node {

	//value in the node
private:
	String val;
	// left and right pointers in the node
public:
	Node* left;
	Node* right;

	//default constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}
	//copy constructor
	Node(Node& a) :val(a.val) {
		left = nullptr;
		right = nullptr;
	}
	//constructor by string object
	Node(String data) : val(data) {
		left = nullptr;
		right = nullptr;
	}
	//returning the value of the string
	String& getValue() {
		return val;
	}
};
