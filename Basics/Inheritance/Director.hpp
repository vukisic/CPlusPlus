#pragma once
#include "Worker.hpp"
using namespace std;

class Director : public Worker
{
private:
	double coef;
public:
	Director(string fn, string ln, int h, double ph, double c) :Worker(fn, ln, h, ph), coef(c){}
	~Director(){}

	void SetCoef(double c) { coef = c; }

	double Salary()
	{
		return (1 + coef / 100)*Worker::Salary();
	}

	void Info()
	{
		Person::Info();
		cout << " I'm Director!" << endl;
	}
};