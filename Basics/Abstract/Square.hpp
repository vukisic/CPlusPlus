#pragma once
#include "Figure.hpp"
using namespace std;

class Square :public Figure
{
private:
	double a;
public:
	Square(double aa = 1) :a(aa){}
	~Square(){}

	double GetP()const
	{
		return a * a;
	}

	double GetO()const
	{
		return 4 * a;
	}

	void Info()
	{
		cout << "Square: a=" << a << endl;
	}
};
