#include <iostream>
#pragma once

using namespace std;

template<typename T>
struct Node {
public:
	T value;
	Node<T>* next = nullptr;

	Node<T>(T value) {
		this->value = value;
		this->next = nullptr;
	}
};

template<typename T>
class stack {
	Node<T>* top = nullptr;
public:
	stack<T>(){}

	void push(T value) {
		Node<T>* node = new Node<T>(value);
		node->next = top;
		top = node;
	}

	T pop() {
		if (top != nullptr) {
			Node<T> *r = top;
			T val = r->value;
			top = top->next;
			delete r;
			return val;
		}
		return NULL;
	}

	T peek() {
		if (top != nullptr) {
			return top->value;
		}
		return NULL;
	}

};
