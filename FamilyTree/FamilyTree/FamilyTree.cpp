#include "FamilyTree.hpp"
using namespace std;

Node* FamilyTree::Search(string n, string f)
{
	Node* p = root;
	if (!Valid(p, n, f))
	{
		cout << "*** Invalid Data! ***" << endl;
		return NULL;
	}
	list<Node*>::iterator it;
	for (it = listNode.begin(); it != listNode.end(); ++it)
	{
		if ((*it)->GetName() == n && (*it)->GetFatherName() == f)
			return (*it);
	}
	cout << "*** Not Found! ***" << endl;
	return NULL;
}

void FamilyTree::AddSibilig(Node* a, Node* b)
{
	//b will be added as sibiling of a
	Node* temp = a;
	while (temp->GetNextSibiling() != NULL)
		temp = temp->GetNextSibiling();

	b->SetHeight(a->GetHeight());
	temp->SetNextSibiling(b);
	listNode.push_back(b);
}

void FamilyTree::AddChild(Node* a, Node* b)
{
	//b will be added as first child or next sibiling of last child
	if (a->GetFirstChild() == NULL)
	{
		b->SetHeight(a->GetHeight() + 1);
		a->SetFirstChild(b);
		listNode.push_back(b);
	}
	else
		AddSibilig(a->GetFirstChild(), b);
}

void FamilyTree::AddNew()
{
	Node* temp = new Node;
	temp->GetData();

	if (root == NULL)
	{
		temp->SetHeight(0);
		root = temp;
		listNode.push_back(temp);
	}
	else
	{
		string name, fname;
		cout << "\nRelation's Name: ";
		cin >> name;
		cout << "\nRelation's Father Name: ";
		cin >> fname;
		cout << temp->GetName() << " is ____ to " << name << " :" << endl;
		int op;
		cout << "1.Child\n2.Sibiling\nAnswer:";
		cin >> op;
		switch (op)
		{
		case 1:AddChild(Search(name, fname), temp); break;
		case 2:AddSibilig(Search(name, fname), temp); break;
		}

		cout << "Person successfully added!!!" << endl;
	}
}

void FamilyTree::Find()
{
	/*
		Difference in height:
			-0 ->sibiling if same parent else cousins
			-1 ->parent if immediate else uncle/aunt
			-2 -> grandfather/granmother;
			-3 -> great-grandfather/great-grandmother
	*/

	string name1, name2, fname1, fname2;
	cout << "Perosn1 Name: ";
	cin >> name1;
	cout << "Person1 Father Name: ";
	cin >> fname1;
	if (!Valid(this->root, name1, fname1))
	{
		cout << "Invalid Person!!!";
		return;
	}

	cout << "Perosn2 Name: ";
	cin >> name2;
	cout << "Person2 Father Name: ";
	cin >> fname2;
	if (!Valid(this->root, name2, fname2))
	{
		cout << "Invalid Person!!!";
		return;
	}

	Node* p1 = Search(name1, fname1);
	Node* p2 = Search(name2, fname2);
	Node* temp;
	int h = p1->GetHeight() - p2->GetHeight();

	if (h == 0)
	{
		string s = p1->GetGender() ? "Brother" : "Sister";
		if (p1->GetFatherName() == p2->GetFatherName())
		{
			cout << endl << name1 << " (" << fname1 << ")" << " is " << name2 << " (" << fname2 << ") 's " << s << endl;
		}
		else
		{
			cout << endl << name1 << " (" << fname1 << ") and " << name2 << " (" << fname2 << ") are cousins" << endl;
		}
	}
	else if (h == 1)
	{
		string s = p1->GetGender() ? "Son" : "Daughter";
		if (p1->GetFatherName() == p2->GetName())
		{
			cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
		}
		else
		{
			s = p1->GetGender() ? "Nephew" : "Niece";
			cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
		}
	}
	else if (h == -1)
	{
		string s = p1->GetGender() ? "Father" : "Mother";
		if (p1->GetName() == p2->GetFatherName())
		{
			cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
		}
		else
		{
			s = p1->GetGender() ? "Uncle" : "Aunt";
			cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
		}
	}
	else if (h == 2)
	{
		string s = p1->GetGender() ? "GrandSon" : "GrandDaughter";
		cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
	}
	else if (h == -2)
	{
		string s = p1->GetGender() ? "GrandFather" : "GrandMother";
		cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
	}
	else if (h == 3)
	{
		string s = p1->GetGender() ? "Great-GrandSon" : "Great-GrandDaughter";
		cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
	}
	else if (h == -3)
	{
		string s = p1->GetGender() ? "Great-GrandFather" : "Great-GrandMother";
		cout << endl << name1 << "(" << fname1 << ")" << " is " << name2 << "(" << fname2 << ") " << " 's " << s << endl;
	}
	else
	{
		cout << "Too Far Relationship!!!" << endl;
		return;
	}
}

void FamilyTree::Show(Node* p)
{
	string g = p->GetGender() == true ? "Male" : "Female";
	cout << endl << endl << "Name: " << p->GetName() << endl;
	cout << "Father: " << p->GetFatherName() << endl;
	cout << "Age: " << p->GetAge() << endl;
	cout << "Gender: " << g << endl;
}

void FamilyTree::Display(Node* p)
{
	if (p == NULL)
		return;
	while (p != NULL)
	{
		cout << p->GetName() << "  " << p->GetHeight() << endl;
		Display(p->GetFirstChild());
		p = p->GetNextSibiling();
	}
}

void FamilyTree::Destroy(Node* p)
{
	Node* temp = p;
	if (p == NULL)
		return;
	while (p != NULL)
	{
		Destroy(p->GetFirstChild());
			temp = p;
			p = p->GetNextSibiling();
			delete temp;
	}
	root = NULL;
	listNode.clear();
}

void FamilyTree::Update(Node* p, int x)
{
	if (p == NULL)
		return;
	p->SetHeight(x);
	int h = x;
	++h;
	while (p != NULL)
	{
		if (p->GetFirstChild() != NULL)
			Update(p->GetFirstChild(), h);
		while (p->GetNextSibiling() != NULL)
		{
			p->GetNextSibiling()->SetHeight(x);
			p = p->GetNextSibiling();
		}
		p = p->GetNextSibiling();
		++x;
	}
}

void FamilyTree::Edit(string n, string f)
{
	Node *p = Search(n, f);
	if (p == NULL)
	{
		return;
	}
	p->EditData();
	return;
}

void Connect(FamilyTree *T1, FamilyTree *T2) {
	string name, fname;
	int op, x;
	cout << "Name of person in 1st tree to merge: ";
	cin >> name;
	cout << "Father name: ";
	cin >> fname;
	cout << T2->GetRoot()->GetName() << " is__to " << name << "\n1.Child \n2.Sibiling" << endl;
	cin >> op;
	Node *p = T1->Search(name, fname);
	switch (op) {
	case 1:
		T1->AddChild(p, T2->GetRoot());
		x = p->GetHeight() + 1;
		break;
	case 2:
		T1->AddSibilig(p, T2->GetRoot());
		x = p->GetHeight();
		break;
	}
	T2->Update(T2->GetRoot(), x);
	cout << "\nMerged!\n";
}

void Count(Node *p, int& c) {
	Node *temp = p;
	if (temp == NULL)
		return;
	while (temp != NULL) {
		c++;
		Count(temp->GetFirstChild(), c);
		temp = temp->GetNextSibiling();
	}
	return;
}

bool Valid(Node *p, string s, string f) {

	Node *temp = p;
	if (temp->GetName() == s && temp->GetFatherName() == f)
		return true;
	else if (Look_right(temp, s, f) == true)
		return Look_right(temp, s, f);
	else if (Look_down(temp, s, f) == true)
		return Look_down(temp, s, f);
	else {
		return false;
		cout << "***Not found***";
	}
}

bool Look_down(Node *p, string s, string f) {

	p = p->GetFirstChild();

	while (p != NULL) {
		if (p->GetName() == s && p->GetFatherName() == f)
			return true;
		else if (Look_right(p, s, f) == true)
			return Look_right(p, s, f);
		else
			p = p->GetFirstChild();
	}
	return false;
}

bool Look_right(Node *p, string s, string f) {

	p = p->GetNextSibiling();

	while (p != NULL) {
		if (p->GetName() == s && p->GetFatherName() == f)
			return true;
		else if (Look_down(p, s, f) == true)
			return Look_down(p, s, f);
		else
			p = p->GetNextSibiling();
	}
	return false;
}

bool Empty(FamilyTree *T) {
	if (T->GetRoot() == NULL)
		return true;
	return false;
}

