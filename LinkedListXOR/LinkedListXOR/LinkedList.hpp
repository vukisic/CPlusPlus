#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<inttypes.h>
using namespace std;

struct Node {
	int data;
	Node* npx;
};

class LinkedList {
private:
	
	Node *head;
	int size;
	Node* XOR(Node *a, Node *b)
	{
		return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
	}

public:

	LinkedList()
	{
		head = NULL;
		size = 0;
	}

	void Insert(int newData)
	{
		struct Node* newNode = new Node();
		newNode->data = newData;
		newNode->npx = XOR(head, NULL);

		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			Node* curr = head;
			Node* prev = NULL;
			Node*next=NULL;

			while (curr != NULL)
			{
				next = XOR(prev, curr->npx);
				if (next == NULL)
					break;
				prev = curr;
				curr = next;
			}

			curr->npx = XOR(prev,newNode);
			newNode->npx = XOR(curr, NULL);
		}
		++size;

	}

	void PrintList()
	{
		Node* curr = head;
		Node* prev = NULL;
		Node*next = NULL;

		cout << endl << "Items:";
		while (curr != NULL)
		{
			cout << curr->data << " ";
			next = XOR(prev, curr->npx);
			prev = curr;
			curr = next;
		}
		cout << endl;
	}

	int GetData(int index)
	{
		if (index < 0 || index > size-1)
			return 0;

		Node* curr = head;
		Node* prev = NULL;
		Node*next = NULL;
		for (int i = 0; i < index; i++)
		{
			next = XOR(prev, curr->npx);
			prev = curr;
			curr = next;
		}

		return curr->data;
	}

	~LinkedList()
	{
		Node* curr = head;
		Node* prev = NULL;
		Node*next = NULL;

		while (curr != NULL)
		{
			next = XOR(prev, curr->npx);
			prev = curr;
			delete(curr);
			curr = next;
		}
		head = NULL;
		size = 0;
	}

};

