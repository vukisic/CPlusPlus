#pragma once
#include<iostream>
using namespace std;

class Square
{
private:
	int a;
public:
	Square():a(0){ }
	Square(int aa):a(aa){ }
	Square(const Square& s) :a(s.a) {}
	~Square(){ }

	int GetA()const { return a; }
	void SetA(int aa) { a = aa; }

	int GetP()const { return a * a; }
	int GetO()const { return 4 * a; }

	friend ostream& operator<<(ostream& out, const Square& s);
	friend istream& operator>>(istream& in, Square& s);
	
};

ostream& operator<<(ostream& out, const Square& s)
{
	out << "Square: a=" << s.a << endl;
	return out;
}

istream& operator>>(istream& in, Square& s)
{
	in >> s.a;
	return in;
}
