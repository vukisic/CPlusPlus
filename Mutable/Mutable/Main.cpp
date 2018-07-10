#include<iostream>
#include<string>

using namespace std;

class Entity
{
private:
	string name;
	mutable int counter=0; //Allow const methods to change value
public:
	const string& GetName()const { ++counter; return name; }
	void SetName(string n) { name = n; }
};

int main()
{
	Entity e;
	e.SetName("Vuk");
	cout<<e.GetName()<<endl;

	//Lambda
	int x = 8;
	auto f = [=]()mutable 
	{
		//mutable-Allow to change value of obj passed by value
		++x;
		cout << x << endl;
	};

	f();



	system("pause");
	return 0;
}