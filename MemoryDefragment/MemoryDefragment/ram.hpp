#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>
#include"dijagnostika.hpp"
using namespace std;
using namespace chrono;

class Ram
{
private:
	Dijagnostika & dijagnostika;
	mutex m;
	condition_variable Defragmentation;
	condition_variable Process;
	bool StartDefragmentation;
	vector<int> Memory;
public:
	Ram(Dijagnostika& d, int ukupno_loc) :dijagnostika(d)
	{
		Memory.resize(ukupno_loc, -1);
		StartDefragmentation = false;
	}

	Dijagnostika& getDijagnostika()
	{
		return dijagnostika;
	}

	int CheckMemory(int locations)
	{
		int counter = 0;
		for (size_t i = 0; i < Memory.size(); ++i)
		{
			if (Memory[i] == -1)
				++counter;
			else
				counter = 0;

			if (counter == locations)
				return i - counter + 1;
		}
		return -1;
	}

	void koristi_memoriju(int id, int br_loc, int trajanje)
	{
		int start = 0;
		unique_lock<mutex> l(m);
		while ((start = CheckMemory(br_loc)) == -1)
		{
			dijagnostika.proces_ceka(id);
			Process.wait(l);
		}

		for (int i = 0; i < br_loc; ++i)
			Memory[start + i] = id;
		dijagnostika.proces_zauzeo_okvire(id, start, start + br_loc);
		dijagnostika.ispisi_memoriju(Memory.begin(), Memory.end());

		l.unlock();
		this_thread::sleep_for(seconds(trajanje));
		l.lock();

		int new_p = 0;
		for (size_t i = 0; i < Memory.size(); ++i)
		{
			if (Memory[i] == id)
			{
				new_p = i;
				break;
			}
		}

		for (int i = 0; i < br_loc; ++i)
			Memory[new_p + i] = -1;
		dijagnostika.proces_zavrsio(id);
		dijagnostika.ispisi_memoriju(Memory.begin(), Memory.end());

		StartDefragmentation = true;
		Defragmentation.notify_one();
	}

	void Sazimanje()
	{
		unique_lock<mutex> l(m);
		while (!StartDefragmentation)
			Defragmentation.wait(l);

		StartDefragmentation = false;
		vector<int> temp;
		temp.resize(Memory.size(), -1);
		int index = 0;
		for (size_t i = 0; i < Memory.size(); ++i)
		{
			if (Memory[i] != -1)
				temp[index++] = Memory[i];
		}
		Memory = temp;
		dijagnostika.sazimanje_obavljeno();
		dijagnostika.ispisi_memoriju(Memory.begin(), Memory.end());
		Process.notify_all();
	}

};