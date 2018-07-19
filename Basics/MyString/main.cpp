#include "MyString.hpp"
using namespace std;

int main()
{
	MyString s1("Vuk ");
	MyString s2("Isic");

	cout << "S1: " << s1 << endl;
	cout << "S2: " << s2 << endl;

	if (s1 == s2)
	{
		cout << "Equal!" << endl;
	}
	else
	{
		cout << "Not Equal!" << endl;
	}

	MyString s3 = s1 + s2;
	cout << "S3: " << s3 << endl;

	system("pause");
	return 0;
}