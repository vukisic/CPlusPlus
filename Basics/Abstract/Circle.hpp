#pragma once
#include "Figure.hpp"
#define PI 3.14159
using namespace std;

class Circle :public Figure
{
private:
	double r;
public:
	Circle(double rr = 1):r(rr){}
	~Circle(){}

	double GetP() const
	{
		return r * r*PI;
	}

	double GetO() const
	{
		return 2 * r*PI;
	}

	void Info()
	{
		cout << "Circle: r=" << r << endl;
	}
};