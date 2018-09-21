/*

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both, 
which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the element to the end,
and a get(index) which returns the node at index.

*/

#include<iostream>
#include<string>
#include"LinkedList.hpp"
using namespace std;

int main()
{
	LinkedList list;

	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.PrintList();

	cout << list.GetData(0) << endl << list.GetData(3) << endl;

	int *pa = new int();
	*pa = 5;
	cout << *pa << endl;
	delete(pa);


	system("pause");
	return 0;
}
