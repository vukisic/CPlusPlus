#pragma once
#include<iostream>
#include<deque>
#include<algorithm>
#include<mutex>
#include "cv_hrono.h"
using namespace std;

class MyQueue
{
private:
	int Priority;
	deque<int> Ready;
	cv_hrono* cv;
public:
	MyQueue(int p) :Priority(p)
	{
		cv = new cv_hrono();
	}

	void Add(int id, unique_lock<mutex>& l)
	{
		auto it = find(Ready.begin(), Ready.end(), id);
		if (it == Ready.end())
		{
			Ready.push_back(id);
		}
		cv->wait(l);
	}

	int Remove()
	{
		cv->notify_one();
		int id = Ready.front();
		Ready.pop_front();
		return id;
	}

	bool IsEmpty()
	{
		return Ready.empty();
	}

	int GetPriority()
	{
		return Priority;
	}
};