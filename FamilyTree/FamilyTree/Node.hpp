#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Node
{
private:
	string name;
	string fname;
	int age;
	bool gender;    //true - male, false -female
	int h;			//height in tree!
	Node* fc;		//First_Child
	Node* ns;		//Next_Sibiling
public:
	Node()
	{
		fname = name = "";
		gender = false;
		age = h = 0;
		fc = ns = NULL;
	}

	~Node() { }

	//Get
	string GetName()const { return name; }
	string GetFatherName()const { return fname; }
	int GetAge()const { return age; }
	bool GetGender()const { return gender; }
	int GetHeight()const { return h; }
	Node* GetFirstChild()const { return fc; }
	Node* GetNextSibiling()const { return  ns; }

	//Set
	void SetName(string f) { name = f; }
	void SetFatherName(string l) { fname = l; }
	void SetAge(int a) { age = a; }
	void SetGender(bool g) { gender = g; }
	void SetHeight(int hh) { h = hh; }
	void SetFirstChild(Node* f) { fc = f; }
	void SetNextSibiling(Node* n) { ns = n; }

	//Other
	void GetData()
	{
		char ch;
		cout << "Name: ";
		cin >> name;
		cout << "Father Name: ";
		cin >> fname;
		cout << "Age: ";
		cin >> age;
		cout << "Gender(m/f): ";
		cin >> ch;

		if (ch == 'm' || ch == 'M')
			gender = true;
	}
	void EditData()
	{
		char ch;
		cout << "Name: " << this->name << endl;
		cout << "Father Name: " << this->fname << endl;
		cout << "Age: ";
		cin >> this->age;
		cout << "Gender: ";
		cin >> ch;

		if (ch == 'm' || ch == 'M')
			this->gender = true;
		else
			this->gender = false;
	}

};