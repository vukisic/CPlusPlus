#pragma once
#include"Person.hpp"
using namespace std;

class Worker : public Person
{
private:
	int hours;
	double pricebyhour;
public:
	Worker(string fn, string ln, int h, double ph) :Person(fn, ln), hours(h), pricebyhour(ph){}
	~Worker(){}

	void SetHours(int h) { hours = h; }
	void SetPrice(double p) { pricebyhour = p; }

	double Salary()
	{
		return hours * pricebyhour;
	}

	void Info()
	{
		Person::Info();
		cout << " I'm Worker!" << endl;
	}


};
