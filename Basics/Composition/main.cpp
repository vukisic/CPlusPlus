#include<iostream>
#include"Cylinder.hpp"
using namespace std;

int main()
{
	Cylinder c1(2, 5);
	cout << "R: " << c1.GetR() << endl;
	cout << "H: " << c1.GetH() << endl;
	cout << "P: " << c1.GetP() << endl;
	cout << "V: " << c1.GetV() << endl;




	system("pause");
	return 0;
}