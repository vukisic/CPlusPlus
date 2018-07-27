#pragma once
#include "Node.hpp"
#include<list>
using namespace std;

class FamilyTree
{
private:
	Node* root;
public:

	list<Node*> listNode;

	FamilyTree() { root = NULL; }
	~FamilyTree(){ }

	//Get and Set
	Node* GetRoot()const { return root; }
	void SetRoot(Node* r){ root=r; }

	//Others
	Node* Search(string, string);

	void AddSibilig(Node*, Node*);
	void AddChild(Node*, Node*);
	void AddNew();

	void Find();
	void Show(Node*);
	void Display(Node*);
	void Destroy(Node*);
	void Update(Node*, int);
	void Edit(string, string);




};

//Other methods(help)
void Connect(FamilyTree*, FamilyTree*);
void Count(Node*, int&);
bool Valid(Node*, string, string);
bool Look_down(Node*, string, string);
bool Look_right(Node*, string, string);
bool Empty(FamilyTree*);