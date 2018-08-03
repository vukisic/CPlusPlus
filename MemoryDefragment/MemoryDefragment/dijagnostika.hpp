#pragma once
#include<iostream>
#include<mutex>
#include<vector>
using namespace std;

class Dijagnostika
{
private:
	mutex mx;
public:
	void proces_ceka(int id)
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] " << id << ", ceka da se oslobodi dovoljno radne memorije!" << endl;
	}

	void proces_krenuo(int id, int br_loc)
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] " << id << " sa " << br_loc << " stranica je krenuo sa radom!" << endl;
	}

	void proces_zauzeo_okvire(int id, int poc, int kr)
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] " << id << " zauzeo okvire od " << poc << " do " << kr << endl;
	}

	void proces_zavrsio(int id)
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] " << id << " se zavrsio!" << endl;
	}

	void sazimanje_obavljeno()
	{
		unique_lock<mutex> l(mx);
		cout << "[SAZIMANJE] zavrseno!" << endl;
	}

	void ispisi_memoriju(vector<int>::iterator poc, vector<int>::iterator kra)
	{
		unique_lock<mutex> l(mx);
		cout << "[MEMORIJA] okviri: {";
		int c = 0;
		for (auto it = poc; it != kra; it++)
		{
			if (c++ > 0)
				cout << " ";
			cout << *it;
			if (c % 20 == 0)
				cout << endl;
		}
		cout << " }" << endl;
	}
};