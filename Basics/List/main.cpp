#include"List.hpp"
using namespace std;

typedef List<int> iList;

int main()
{
	iList list;
	list.Add(1, 1);
	list.Add(1, 2);
	list.Add(1, 3);
	list.Add(1, 4);

	cout << list << endl;

	list.Add(2, 12);
	list.Add(3, 13);

	cout << list << endl;

	list.Remove(2);
	list.Remove(4);

	cout << list << endl;

	system("pause");
	return 0;

}