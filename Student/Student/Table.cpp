#include "Table.hpp"
using namespace std;

Table::Table()
{
	date = "";
	title = "";
}

Table::Table(string da, string ti)
{
	date = da;
	title = ti;
}

void Table::SortByIndex(bool val)
{
	if (val)
	{
		students.sort([](Student x, Student y) {return x.GetIndex() > y.GetIndex(); });
	}
	else
	{
		students.sort([](Student x, Student y) {return x.GetIndex() < y.GetIndex(); });
	}

}

void Table::AddStudentToTable(Student s)
{
	bool exists = false;
	list<Student>::iterator it;
	for (it = students.begin(); it != students.end(); ++it)
	{
		if (it->GetIndex() == s.GetIndex())
		{
			exists = true;
			break;
		}
	}

	if (!exists)
		students.insert(students.begin(), s);
}

void Table::RemoveStudentFromTable(int ind)
{
	bool exists = false;
	list<Student>::iterator it;
	for (it = students.begin(); it != students.end(); ++it)
	{
		if (it->GetIndex() == ind)
		{
			exists = true;
			students.erase(it);
			break;
		}
	}
}

ostream& operator<<(ostream& out, const Table& t)
{
	out << "----------------------" << t.title<< "----------------------" <<endl;
	cout << "Date: " << t.date << endl;
	for (Student s : t.students)
		cout << "\t" << s << endl;
	out << "----------------------" << t.title << "----------------------" << endl;
	return out;
}