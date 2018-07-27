#include"binary_tree.hpp"
#include<fstream>
#include<string>
using namespace std;

int main() {

	binary_tree B;
	int ch,temp;
	char c;
	string st1, st2;

	cout << "Enter infile name:";
	cin >> st1;
	ifstream infile(st1);

	while (1) {
		system("cls");
		cout << "Binary Search Tree Operations" << endl;
		cout << "------------------------------" << endl;
		cout << "1.Create from file" << endl;
		cout << "2.Insert" << endl;
		cout << "3.Inorder Traversal(left,root,right)" << endl;
		cout << "4.Preorder Traversal(root,left,right)" << endl;
		cout << "5.Postorder Traversal(left,right,root)" << endl;
		cout << "6.Remove" << endl;
		cout << "7.Destroy tree" << endl;
		cout << "8.Serach" << endl;
		cout << "0.Exit" << endl;
		cin >> ch;

		switch (ch) {
		default: cout << "Unknow operation" << endl; return 0;
			
		case 1:
			system("cls");
			cout << "Reading from file...";
			if (infile.is_open()) {
				while (infile >> temp)
				{
					B.insert(temp);
				}
			}
			else {
				cout << "File cannot be open!" << endl;
				return 1;
			}
			break;
		case 2:
			system("cls");
			cout << "Enter a number to be inserted:";
			cin >> temp;
			B.insert(temp);
			cout << "Successful added number!";
			break;
		case 3:
			system("cls");
			if (B.isEmpty()) {
				cout << "Tree is empty" << endl;
				break;
			}
			cout << "Inorder Traversal" << endl;
			cout << "-----------------" << endl;
			B.print_inorder();
			break;

		case 4:
			system("cls");
			if (B.isEmpty()) {
				cout << "Tree is empty" << endl;
				break;
			}
			cout << "Preorder Traversal" << endl;
			cout << "-----------------" << endl;
			B.print_preorder();
			break;
		case 5:
			system("cls");
			if (B.isEmpty()) {
				cout << "Tree is empty" << endl;
				break;
			}
			cout << "Postorder Traversal" << endl;
			cout << "-----------------" << endl;
			B.print_postorder();
			break;
		case 6:
			system("cls");
			if (B.isEmpty()) {
				cout << "Tree is empty" << endl;
				break;
			}
			cout << "Enter number to be deleted:";
			cin >> temp;
			B.root=B.remove(B.root,temp);
			break;
		case 7:
			system("cls");
			if (B.isEmpty()) {
				cout << "Tree is empty" << endl;
				break;
			}
			B.destroy_tree();
			cout << "Tree successful destroied!" << endl;
			break;
		case 8:
			system("cls");
			if (B.isEmpty()) {
				cout << "Tree is empty" << endl;
				break;
			}
			cout << "Enter value to search:";
			cin >> temp;
			if (B.search(temp)) {
				cout << "Number exist in tree" << endl;
				break;
			}
			else {
				cout << "Not found!" << endl;
				break;
			}
			break;
		case 0:
			return 0;
		}
		cout << "\n\nPress any key to continue...";
		cin >> c;

	}

	return 0;
}
