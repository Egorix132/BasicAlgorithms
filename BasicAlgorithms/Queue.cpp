#include <iostream>

using namespace std;

template<typename T>
struct QNode {
public:
	T value;
	QNode<T>* prev = nullptr;

	QNode<T>(T value) {
		this->value = value;
		this->prev = nullptr;
	}
};

template<typename T>
class queue {
	QNode<T>* first = nullptr;
	QNode<T>* last = nullptr;
	int size = 0;
public:
	queue<T>() {}

	void push(T value) {
		QNode<T>* node = new QNode<T>(value);
		if (size < 1) {
			first = node;
			last = node;
		}
		else {
			last->prev = node;
			last = node;
		}
		size++;
	}

	T pop() {
		if (first != nullptr) {
			size--;
			QNode<T>* r = first;
			first = first->prev;
			return r->value;
		}
		return NULL;
	}
};