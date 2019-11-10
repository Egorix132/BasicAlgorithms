#include <iostream>

using namespace std;

template<typename T>
struct LNode {
	LNode() {
		this->next = nullptr;
		this->prev = nullptr;
	}
	LNode(T newValue) {
		this->value = newValue;
		this->next = nullptr;
		this->prev = nullptr;
	}
	T value;
	LNode* next;
	LNode* prev;
};

template<typename T>
class List {
public:
	List<T>() {
		head = nullptr;
		tail = nullptr;
	}

	void add(T value) {
		LNode<T> *node = new LNode<T>(value);

		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}

	bool remove(T value) {
		LNode<T> *current = head;
		while (current != nullptr) {
			if (current->value == value) {
				current->prev->next = current->next;
				if(current->next != nullptr) current->next->prev = current->prev;
				delete current;
				return true;
			}
			current = current->next;
		}
		return false;
	}
	void print() {
		LNode<T>* current = head;
		while (current != nullptr) {
			std::cout << current->value<<' ';
			current = current->next;
		}
		cout << endl;
	}
private:
	LNode<T> * head;
	LNode<T> * tail;
};