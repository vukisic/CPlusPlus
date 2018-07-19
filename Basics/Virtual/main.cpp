#include<iostream>
#include "Director.hpp"
using namespace std;

int main()
{
	Person p("Bill", "Gates");
	p.Info();

	Worker w("Bill", "Gates", 100, 15);
	w.Info();
	cout << "Salary: " << w.Salary() << endl;

	Director d("Bill", "Gates", 100, 15, 5);
	d.Info();
	cout << "Salary: " << d.Salary() << endl;

	cout << "****************************************************" << endl;
	//****************************
	//Power of virtual methods!!!
	Person *pa = &d;
	pa->Info();

	//****************************

	system("pause");
	return 0;
}