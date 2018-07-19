#pragma once
#include<iostream>
#include<cmath>
#define PI 3.14159
using namespace std;


class Circle
{
private:
	double r;
public:
	Circle() :r(0) {}
	Circle(double rr):r(rr){}
	Circle(const Circle& c):r(c.r){}
	~Circle(){}

	double GetR()const { return r; }
	void SetR(double rr){ r = rr; }
	double GetP()const { return  pow(r,2)*PI; }
	double GetO()const { return 2*r*PI; }
};
