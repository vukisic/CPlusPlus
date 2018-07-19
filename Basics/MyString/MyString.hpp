#pragma once
#include<iostream>
using namespace std;

class MyString
{
private:
	int length;
	char* text;
public:
	MyString() { length = 0; text = NULL; }
	MyString(const char[]);
	MyString(const MyString& s);
	~MyString() { delete[] text; }

	char& operator[](int i) { return text[i]; }
	char operator[](int i)const { return text[i]; }

	MyString& operator=(const MyString& x);
	MyString& operator+=(const MyString& x);

	friend bool operator==(const MyString& x, const MyString& y);
	friend bool operator!=(const MyString& x, const MyString& y);
	friend MyString operator+(const MyString& x, const MyString& y);
	friend ostream& operator<<(ostream& out, const MyString& x);

	int GetLength()const { return length; }
};