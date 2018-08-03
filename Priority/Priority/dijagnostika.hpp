#pragma once
#include <iostream>
#include <mutex>

using namespace std;

class Dijagnostika {
private:
	mutex mx;
public:
	void proces_kreiran(int id_procesa, int prioritet, int broj_naredbi) 
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] Kreira se proces " << id_procesa << " prioriteta " << prioritet << " sa brojem naredbi " << broj_naredbi << endl;
	}

	void proces_ceka(int id_procesa) 
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] Proces " << id_procesa << " ceka da se oslobodi procesor." << endl;
	}

	void proces_zavrsio(int id_procesa, int prioritet)
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] Proces " << id_procesa << " sa prioritetom " << prioritet << " se zavrsio." << endl;
	}

	void izvrsio_naredbu(int id_procesa, int naredba)
	{
		unique_lock<mutex> l(mx);
		cout << "[PROCES] " << id_procesa << " je izvrsio naredbu " << naredba << endl;
	}
};