#pragma once
#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<vector>
#include "dijagnostika.hpp"
using namespace std;
using namespace chrono;

struct Request
{
	int id;
	int sector;
	bool finished;
	condition_variable cv;
	Request(int i,int s):id(i),sector(s),finished(false){}
};

class OS
{
private:
	Dijagnostika & dijagnostika;
	mutex m;
	int CurrentSector;
	condition_variable cv_daemon;
	vector<Request*> Requests;
public:
	OS(Dijagnostika& d, int t) :dijagnostika(d)
	{
		CurrentSector = t;
	}

	Dijagnostika& getDijagnostika() { return dijagnostika; }

	void uputi_UI_zahtev(int id, int sector)
	{
		unique_lock<mutex> l(m);

		Request* temp = new Request(id, sector);
		Requests.push_back(temp);

		cv_daemon.notify_one();
		while (!(temp->finished))
		{
			dijagnostika.proces_ceka(id, sector);
			temp->cv.wait(l);
		}
		delete temp;
	}

	int obradi_zahtev()
	{
		unique_lock<mutex> l(m);
		while (Requests.empty())
			cv_daemon.wait(l);

		auto temp = Requests.begin();
		int min_distance = abs((*temp)->sector - CurrentSector);
		for (auto it = Requests.begin(); it != Requests.end(); ++it)
		{
			if (abs((*it)->sector - CurrentSector) < min_distance)
			{
				min_distance = abs((*it)->sector - CurrentSector);
				temp = it;
			}
		}

		l.unlock();
		this_thread::sleep_for(milliseconds(300));
		l.lock();

		(*temp)->finished = true;
		int ret = (*temp)->sector;
		CurrentSector = ret;
		(*temp)->cv.notify_one();
		Requests.erase(temp);
		return ret;
	}
};