#include"Square.hpp"
#include"Circle.hpp"
using namespace std;

int main()
{
	/*
		Not allowed to instance abstract class!!!
		Figure f;
	*/

	Square s(5);
	s.Info();
	cout << "P: " << s.GetP() << " O:" << s.GetO() << endl << endl;

	Circle c(5);
	c.Info();
	cout << "P: " << c.GetP() << " O:" << c.GetO() << endl << endl;



	system("pause");
	return 0;
}