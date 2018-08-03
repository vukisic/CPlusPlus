#pragma once
#include<iostream>
#include<vector>
#include<mutex>
#include<thread>
#include "dijagnostika.hpp"
#include "MyQueue.hpp"

using namespace std;
using namespace chrono;

class Rasporedjivac
{
private:
	Dijagnostika & dijagnostika;
	mutex m;
	int ActiveProcess;
	vector<MyQueue> Queue;
public:
	Rasporedjivac(Dijagnostika& d, int broj_nivoa_prioriteta) :dijagnostika(d)
	{
		for (int i = 0; i < broj_nivoa_prioriteta; ++i)
			Queue.push_back(MyQueue(i));
		ActiveProcess = -1;
	}

	Dijagnostika& getDijagnostika() { return dijagnostika; }

	void izvrsi(int id, int broj_naredbi, int p)
	{
		for (int i = 0; i < broj_naredbi; ++i)
		{
			unique_lock<mutex> l(m);
			if (ActiveProcess == -1)
			{
				ActiveProcess = id;
			}

			while (ActiveProcess != id)
			{
				dijagnostika.proces_ceka(id);
				Queue[p].Add(id, l);
			}

			l.unlock();
			this_thread::sleep_for(milliseconds(300));
			l.lock();

			int notify = -1;
			for (auto it = Queue.begin(); it != Queue.end(); ++it)
			{
				if (!it->IsEmpty())
				{
					notify = it->GetPriority();
					break;
				}
			}

			if (notify != -1)
			{
				int next;
				if (notify > p&& i < broj_naredbi - 1)
				{
					next = id;
				}
				else
				{
					next = Queue[notify].Remove();
				}
				ActiveProcess = next;
			}
			else
			{
				ActiveProcess = -1;
			}
			dijagnostika.izvrsio_naredbu(id, i);
		}
	}

};
