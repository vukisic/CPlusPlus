#pragma once
#include<iostream>
#include<list>
#include"Student.hpp"
using namespace std;

class Table
{
private:
	string date;
	string title;
	list<Student> students;
public:
	Table();
	Table(string da, string ti);
	~Table(){ }

	string GetDate()const { return date; }
	string GetTitle()const { return title; }

	void SetDate(string da) { date = da; }
	void SetTitle(string ti) { title = ti; }

	void SortByIndex(bool val=false);
	void AddStudentToTable(Student s);
	void RemoveStudentFromTable(int ind);

	friend ostream& operator<<(ostream& out, const Table& t);

};
