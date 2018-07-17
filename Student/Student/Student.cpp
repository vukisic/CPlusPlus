#include"Student.hpp"
#include<string>
using namespace std;

Student::Student()
{
	first_name = "NoName";
	last_name = "NoName";
	id = "";
	index = 0;
}

Student::Student(string fn, string ln, string i, int in):first_name(fn),last_name(ln),id(i),index(in)
{

}

Student::Student(const Student& s)
{
	first_name = s.first_name;
	last_name = s.last_name;
	id = s.id;
	index = s.index;
	marks = s.marks;
}

Student::~Student()
{

}

int Student::GetMarkFromSubject(string subject)
{
	map<string, int>::iterator it;
	bool exists = false;
	for (it = marks.begin(); it != marks.end(); ++it)
	{
		if (it->first == subject)
		{
			exists = true;
			break;
		}
	}

	if (exists)
	{
		return marks[subject];
	}
	else
	{
		return 0;
	}
}

void Student::AddMarkFromSubject(string sub, int mark)
{
	marks[sub] = mark;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << s.id << s.index<<"  ";
	out << s.first_name << " " << s.last_name << endl;
	map<string, int> temp = s.GetMarks();
	map<string, int>::iterator it = temp.begin();
	for (; it != temp.end(); ++it)
	{
		cout <<"\t\t"<< it->first << " " << it->second << endl;
	}
	return out;
}