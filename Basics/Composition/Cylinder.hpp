#pragma once
#include "Circle.hpp"
#include "Rectangle.hpp"
using namespace std;

class Cylinder
{
private:
	Circle b;
	Rectangle m;
public:
	Cylinder() :b(0), m(b.GetO(), 0){}
	Cylinder(double rr, double hh) :b(rr), m(b.GetO(), hh){}
	Cylinder(const Cylinder& c):b(c.b),m(c.m){}
	~Cylinder(){ }

	double GetR()const { return b.GetR(); }
	double GetH()const { return m.GetB(); }
	double GetP()const { return 2 * b.GetP() + m.GetP(); }
	double GetV()const { return b.GetP()*m.GetB(); }
};
