#include<iostream>
#include<string>
#include<memory>
using namespace std;

/*
Smart pointers - way to automate allocating
and freeing memory(e.g. only call new instead of new and delete...)

unique pointer: scope pointer(when is something out of scope it will free the allocated memory) - CANNOT copy these pointers!
shared pointer: use reference counting , CAN copy
weak pointer: works with shared pointers,it doesn't incarase ref counter!

*/

class Entity
{
public:
	Entity()
	{
		cout << "Created Entity!" << endl;
	}

	~Entity()
	{
		cout << "Destroyed Entity!" << endl;
	}

	void Print(){}
};




int main()
{
	//Scope
	{
		weak_ptr<Entity> e0;
		{
			//unique_ptr<Entity> en(new Entity); //Explicite constructor
			unique_ptr<Entity> en = make_unique<Entity>(); //Better way(Exception safe)
			en->Print();

			//Allocates one more block of memory for control (referece counter)
			shared_ptr<Entity> shared_en = make_shared<Entity>(); //This way we allocate both memory TOGETHER!
			e0 = shared_en;
		}
	}
	

	cout << "Test" << endl;

	system("pause");
	return 0;
}