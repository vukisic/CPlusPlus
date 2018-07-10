#include<iostream>
#include<string>
#include<mutex>
#include<thread>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

void PrintValue(int val)
{
	cout << val << endl;
}

void ForEach(const vector<int>& vec,const function<void (int)>& func)
{
	for (int value : vec)
		func(value);

}


int main()
{
	vector<int> vect = { 1,2,3,4,5 };

	int a = 10;

	auto lambda = [](int val) {cout << val << endl; };
	
	auto lambda1 = [=](int val) mutable {a = 7; cout << a << endl; };
	/*
	Passing extern params in lambda
	[=] - pass all by value
	[&] - pass all by ref
	[a] - pass only a by value
	[&a] - pass only a by ref
	mutable - specifier ,allow assigning value for captured var
	*/

	lambda1(5);

	cout << endl << endl;

	ForEach(vect, lambda1); //Lambda
	
	cout << endl << endl;

	ForEach(vect, PrintValue); //Function Pointer

	cout << endl << endl;

	sort(vect.begin(), vect.end(), [](int x, int y) {return x > y; });
	ForEach(vect, PrintValue);

	system("pause");
	return 0;
}