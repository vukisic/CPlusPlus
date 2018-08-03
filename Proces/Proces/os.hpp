#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<cstdlib>
#include "dijagnostika.hpp"
#include "proces.hpp"
using namespace std;
using namespace chrono;

class OS
{
private:
	Dijagnostika& dijagnostika;
	mutex m;
	int ActiveProcess;
	int MaxInst;
	condition_variable Ready;
	condition_variable UI;
	queue<UI_Request*> UI_Requests;
public:
	OS(Dijagnostika& d, int maks) :dijagnostika(d)
	{
		MaxInst = maks;
		ActiveProcess = -1;
	}

	Dijagnostika& getDijagnostika() { return dijagnostika; }

	void izvrsi_proces(Proces& p)
	{
		int InstCounter = 0;
		for (auto it = p.inst.begin(); it != p.inst.end(); ++it)
		{
			unique_lock<mutex> l(m);
			while (ActiveProcess != p.id && ActiveProcess != -1)
			{
				dijagnostika.proces_ceka(p.id);
				Ready.wait(l);
			}

			ActiveProcess = p.id;

			if (*it == STANDARD)
			{
				l.unlock();
				this_thread::sleep_for(milliseconds(rand() % 40 + 10));
				l.lock();

				dijagnostika.proces_izvrsio_standardnu(p.id);
				if (++InstCounter == MaxInst || it == (p.inst.end() - 1))
				{
					dijagnostika.proces_oslobadja_procesor(p.id);
					ActiveProcess = -1;
					InstCounter = 0;
					Ready.notify_one();
					l.unlock();
					this_thread::sleep_for(milliseconds(100));
				}
			}
			else
			{
				UI_Request* z = new UI_Request(p.id);
				UI_Requests.push(z);
				UI.notify_one();
				dijagnostika.proces_ceka_na_UI(p.id);
				while (!z->finished)
				{
					ActiveProcess = -1;
					InstCounter = 0;
					Ready.notify_one();
					z->cv.wait(l);
					dijagnostika.proces_zavrsio_UI(p.id);
				}
				delete z;
			}
		}
	}

	void obradi_zahteve()
	{
		while (true)
		{
			unique_lock<mutex> l(m);
			while (UI_Requests.empty())
			{
				dijagnostika.ui_ceka();
				UI.wait(l);
			}

			UI_Request* z = UI_Requests.front();
			UI_Requests.pop();
			dijagnostika.ui_zapocinje(z->id);
			l.unlock();
			this_thread::sleep_for(milliseconds(rand() % 200 + 100));
			l.lock();
			z->finished = true;
			z->cv.notify_one();
			dijagnostika.ui_zavrsio(z->id);
		}
	}
};
