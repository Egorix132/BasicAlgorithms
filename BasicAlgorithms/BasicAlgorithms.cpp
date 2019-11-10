#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include "LinkedList.cpp"
#include "DynamicArray.cpp"

using namespace std;

int main()
{
	//Стэк
	stack<int> s = *(new stack<int>());
	s.push(8);
	s.push(7);
	cout << "stack pop: "<<s.pop() << endl;

	//Динамический массив
	DynamicArray<int> ar = *(new DynamicArray<int>());
	ar.add(1);
	ar.add(8);
	ar.add(8);
	ar.insert(1, 4);
	cout << "array: ";
	ar.print();

	//Связанный список
	List<int> list = *(new List<int>());
	list.add(4);
	list.add(2);
	cout << "Linked list: ";
	list.print();

	//Очередь
	queue<int> qu = *(new queue<int>());
	qu.push(6);
	qu.push(66);
	cout << "queue pop: " << qu.pop() << endl;


}