#include "FamilyTree.hpp"
#define MAX_TREE 100
#include<iostream>
using namespace std;

int main() {

	FamilyTree T[MAX_TREE];
	int op, n, n1, n2, counter = 0;
	char c, c1=' ';
	string name, fname;
	cout << "\nEnter the family tree number = ";
	cin >> n;

	while (1) {
		system("cls");
		cout << "\n\n\n\tFamily tree No. : "
			<< n << "\n\n\t1.Add new person\n\t"
			<< "2.Find relationship b/w two person\n\t"
			<< "3.Search\n\t"
			<< "4.Destroy whole tree\n\t"
			<< "5.Display\n\t"
			<< "6.Change family tree\n\t"
			<< "7.Connect two trees\n\t"
			<< "8.Count people in a tree\n\t"
			<< "9.Change data(age and gender)\n\t"
			<< "0.Exit\n\n\t" << "Enter your choice >> ";

		cin >> op;
		cout << endl;
		switch (op) {
		default:
			cout << "Invalid input" << endl;
			return 0;
		case 1:
			system("cls");
			T[n].AddNew();
			break;
		case 2:
			system("cls");
			if (Empty(&T[n])) {
				cout << "Tree is empty!" << endl;
				break;
			}
			T[n].Find();
			break;
		case 3:
			system("cls");
			if (Empty(&T[n])) {
				cout << "Tree is empty!" << endl;
				break;
			}
			system("cls");
			cout << "Enter name of a person to search: ";
			cin >> name;
			cout << "Father name: ";
			cin >> fname;
			if (!Valid(T[n].GetRoot(), name, fname)) {
				cout << "Invalid name!";
				break;
			}
			T[n].Show(T[n].Search(name, fname));
			break;
		case 4:
			system("cls");
			T[n].Destroy(T[n].GetRoot());
			counter = 0;
			cout << "Tree " << n << " has beed destroyed successfully!";
			break;
		case 5:
			system("cls");
			if (Empty(&T[n])) {
				cout << "Tree is empty!" << endl;
			}
			T[n].Display(T[n].GetRoot());
			break;
		case 6:
			system("cls");
			cout << "Enter family tree number: ";
			cin >> n;
			break;
		case 7:
			system("cls");
			cout << "e.g. If you put 'Merge 1 to 2' "
				<< "It will put tree 1 above tree 2." << endl;
			cout << "Merge__to__:" << endl;
			cin >> n1 >> n2;
			Connect(&T[n1], &T[n2]);
			break;
		case 8:
			Count(T[n].GetRoot(), counter);
			cout << endl << "Number of people in tree: " << counter << endl;
			break;
		case 9:
			system("cls");
			if (Empty(&T[n])) {
				cout << "Tree is empty!" << endl;
				break;
			}
			system("cls");
			cout << "Enter name of a person: ";
			cin >> name;
			cout << "Father name: ";
			cin >> fname;
			if (!Valid(T[n].GetRoot(), name, fname)) {
				cout << "Invalid name!";
				break;
			}
			system("cls");
			T[n].Edit(name, fname);
			break;
		case 0:
			return 0;

		}
		system("pause");
	}
}
