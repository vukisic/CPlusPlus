#pragma once
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Student
{
private:
	string first_name;
	string last_name;
	map<string,int> marks;
	string id;
	int index;
public:
	Student();
	Student(string fn, string ln, string i , int in);
	Student(const Student& s);
	~Student();
	
	string GetFirstName()const { return first_name; }
	string GetLastName()const { return last_name; }
	string GetId()const { return id; }
	int GetIndex()const { return index; }
	map<string, int> GetMarks()const { return marks; }
	int GetMarkFromSubject(string subject);

	void SetFirstName(string fn) { first_name = fn; }
	void SetLastName(string ln) { last_name = ln; }
	void SetId(string i) { id = id; }
	void SetIndex(int in) { index = in; }
	void AddMarkFromSubject(string sub, int mark);

	friend ostream& operator<<(ostream& out,const Student& s);
};
