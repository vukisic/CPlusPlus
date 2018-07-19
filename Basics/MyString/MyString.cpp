#include"MyString.hpp"
using namespace std;

MyString::MyString(const char input[])
{
	length = 0;
	while (input[length] != '\0')
	{
		++length;
	}

	text = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		text[i] = input[i];
	}
	text[length] = '\0';
}

MyString::MyString(const MyString& s)
{
	length = s.length;
	text = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		text[i] = s.text[i];
	}
	text[length] = '\0';
}

MyString& MyString::operator=(const MyString& x)
{
	if (this != &x)
	{
		delete[] text;
		length = x.length;
		text = new char[length + 1];
		for (int i = 0; i < length; ++i)
		{
			text[i] = x.text[i];
		}
		text[length] = '\0';

	}
	return *this;
}

MyString& MyString::operator+=(const MyString& x)
{
	int i;
	char* temp = new char[length + x.length + 1];
	for (i = 0; i < length; ++i)
		temp[i] = text[i];
	for (i = 0; i < x.length; ++i)
		temp[length + i] = x.text[i];
	temp[length + x.length] = '\0';
	length += x.length;
	delete[] text;
	text = temp;
	return *this;
}

bool operator==(const MyString& x, const MyString& y)
{
	if (x.length != y.length)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < x.length; ++i)
		{
			if (x.text[i] != y.text[i])
				return false;
		}
	}
	return true;
}
bool operator!=(const MyString& x, const MyString& y)
{
	return !(x == y);
}

MyString operator+(const MyString& x, const MyString& y)
{
	MyString temp;
	temp += x;
	temp += y;
	return temp;
}

ostream& operator<<(ostream& out, const MyString& x)
{
	if (x.length > 0)
		cout << x.text;
	return out;
}

