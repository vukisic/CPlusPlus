#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
	string first_name;
	string last_name;
public:
	Person(string firstn="",string lastn=""):first_name(firstn),last_name(lastn){}
	~Person(){ }

	string GetFirstName()const { return first_name; }
	string GetLastName()const { return last_name; }

	void SetFirstName(string fn) { first_name = fn; }
	void SetLastName(string ln) { last_name = ln; }

	virtual void Info()
	{
		cout << "I'm " << first_name << " " << last_name << " !" << endl;
	}

};