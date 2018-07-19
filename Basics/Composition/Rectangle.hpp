#pragma once
#include<iostream>
using namespace std;

class Rectangle
{
private:
	double a;
	double b;
public:
	Rectangle():a(0),b(0){}
	Rectangle(double aa,double bb):a(aa),b(bb){}
	Rectangle(const Rectangle& r):a(r.a),b(r.b){}
	~Rectangle(){ }

	double GetA()const { return a; }
	double GetB()const { return b; }
	void SetA(double aa) { a = aa; }
	void SetB(double bb) { b = bb; }

	double GetP() const{ return a * b; }
	double GetO() const { return 2 * a + 2 * b; }
};