#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class List
{
private:
	struct ListEl
	{
		T content;
		ListEl* next;
	};
	ListEl* head;
	ListEl* tail; //not necessary
	int count;
public:
	List()
	{
		head = tail = NULL;
		count = 0;
	}

	List(const List<T>& li);
	virtual ~List();

	int Count()const { return count; }
	bool IsEmpty()const { return head == NULL ? true : false; }

	List<T>& operator=(const List<T>& li);
	bool Add(int n, const T& el);
	bool Remove(int n);
	bool Read(int n,T& el);
	void Clear();
};

template<class T>
List<T>::List(const List<T>& li)
{
	head = tail = NULL;
	count = 0;
	for (int i = 0; i < li.Count; ++i)
	{
		T temp;
		if (li.Read(i, temp))
			Add(i, temp);
	}
}

template<class T>
List<T>::~List()
{
	while (!IsEmpty())
		Remove(1);
}

template<class T>
List<T>& List<T>::operator=(const List<T>& li)
{
	if (this != &li)
	{
		Clear();
		heade = tail = NULL;
		count = 0;
		for (int i = 0; i < li.Count; ++i)
		{
			T temp;
			if (li.Read(i, temp))
				Add(i, temp);
		}
	}
	return *this;
}

template<class T>
bool List<T>::Add(int n, const T& el)
{
	if (n < 1 || (!IsEmpty() && n > count + 1))
	{
		return false;
	}
	else
	{
		ListEl *newEl = new ListEl();
		if (newEl == NULL)
		{
			//Not Enough Memory!
			return false;
		}
		else
		{
			newEl->content = el;
			if (n == 1)
			{
				newEl->next = head;
				head = newEl;
			}
			else if (n == count + 1)
			{
				newEl->next = NULL;
				tail->next = newEl;
			}
			else
			{
				ListEl*temp = head;
				for (int i = 2; i < n; ++i)
					temp = temp->next;
				newEl->next = temp->next;
				temp->next = newEl;

			}
			++count;
			if (newEl->next == NULL)
			{
				tail = newEl;
			}
			return true;
		}
	}
}

template<class T>
bool List<T>::Remove(int n)
{
	if (IsEmpty() || n<1 || n>count)
	{
		return false;
	}
	else
	{
		if (n == 1)
		{
			ListEl *temp = head;
			head = head->next;
			delete temp;
			--count;
		}
		else
		{
			ListEl *temp = head;
			for (int i = 2; i < n; ++i)
				temp = temp->next;
			ListEl *del = temp->next;
			temp->next = del->next;
			if (tail == del)
				tail = temp;
			delete del;
			--count;
		}
		return true;
	}
}

template<class T>
bool List<T>::Read(int n, T& el)
{
	if (IsEmpty() || n<1 || n>count)
	{
		return false;
	}
	else
	{
		if (n == 1)
		{
			el = head->content;
		}
		else if (n == count)
		{
			el = tail->content;
		}
		else
		{
			ListEl *temp = head;
			for (int i = 1; i < n; ++i)
				temp = temp->next;
			el = temp->content;
		}
		return true;
	}
}

template<class T>
void List<T>::Clear()
{
	while (!IsEmpty())
		Remove(1);
}

template<class T>
ostream& operator<<(ostream& out,List<T>& li)
{
	out << "--------------------------------------------------------------" << endl;

	for (int i = 1; i <= li.Count(); ++i)
	{
		if (i != 1)
			cout << ", ";
		T temp;
		li.Read(i, temp);
		cout << temp;
	}
	cout << endl;

	out << "--------------------------------------------------------------" << endl;

	return out;
}



