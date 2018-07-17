#include<iostream>
#include<string>
#include"Table.hpp"
#include"Student.hpp"
using namespace std;

int main()
{
	Student s1("Vuk","Isic" ,"PR", 39);
	s1.AddMarkFromSubject("OOP", 10);
	Student s2("Marko", "Jankovic", "PR", 148);
	s2.AddMarkFromSubject("NRS", 10);

	Table t("26.10.2019", "Spisak");
	t.AddStudentToTable(s1);
	t.AddStudentToTable(s1);
	t.AddStudentToTable(s2);
	cout << t << endl<<endl<<endl;

	t.SortByIndex();
	cout << t << endl << endl << endl;

	t.RemoveStudentFromTable(39);

	cout << t << endl << endl << endl;

	system("pause");
	return 0;
}