#pragma once
#include<iostream>
using namespace std;

class Figure
{
public:
	virtual double GetP()const = 0;
	virtual double GetO()const = 0;
	virtual void Info() = 0;
};
