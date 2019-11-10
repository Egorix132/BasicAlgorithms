#include <iostream>

using namespace std;

template<typename T>
class DynamicArray {
public:
	int size = 0;
	T *p = new T[size];

	DynamicArray<T>() {}

	void add(T value) {
		size++;
		updateSize();

		*(p + size-1) = value;
	}

	T get(int index) {
		return *(p + index);
	}

	void insert(int index, T value) {
		size++;
		updateSize();
		for (int i = size-1; i > index; i--) {
			*(p + i) = *(p + i - 1);
		}
		*(p + index) = value;
	}

	void removeAt(int index) {
		for (int i = index; i < size - 2; i++) {
			*(p + i) = *(p + i + 1);
		}
		size--;
		updateSize();
	}

	void remove() {
		size--;
		updateSize();
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << *(p+i) << ' ';
		}
		cout << endl;
	}
private:
	void updateSize() {
		T *newP = new T[size];
		for (int i = 0; i != size; i++)
		{
			*(newP + i) = *(p + i);
		}
		delete[] p;
		p = newP;
	}
};