#include<iostream>
#include "Square.hpp"
using namespace std;

int main()
{
	Square s;
	cout << "Square: a=";
	cin >> s;
	cout << s << endl;
	cout << "P:" << s.GetP() << endl;
	cout << "O:" << s.GetO() << endl;


	system("pause");
	return 0;
}