#pragma once
#include<iostream>
using namespace std;

//custom string class
class String {
private:
	int size_;
	char* chars;
public:
	//default constructor
	String() {
		size_ = 0;
		chars = nullptr;
	}
	// copy constructor
	String(String& data);
	//char arry constructor
	String(const char* data);
	//returning the size of the string
	int getSize() {
		return size_;
	}
	//returning the value of the string
	char* getchar() {
		return chars;
	}
	//destructor
	~String() {
		delete[] chars;
	}
	//checking whether the newchar is present in the set or not
	int compare(String newchar);
};
