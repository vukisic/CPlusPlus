#pragma once
#include <iostream>
#include <mutex>

using namespace std;

class Dijagnostika {
private:
	mutex mx;

public:
	
	void zahtev_prosledjen(int id_procesa, int broj_staze) 
	{
		unique_lock<mutex> l(mx);
		cout << "[Proces] Proces " << id_procesa << " formirao je novi zahtev za pristup stazi: " << broj_staze << endl;
	}

	void proces_ceka(int id_procesa, int broj_staze) 
	{
		unique_lock<mutex> l(mx);
		cout << "[Proces] Proces " << id_procesa << " ceka kako bi pristupio stazi: " << broj_staze << endl;
	}

	void zahtev_obradjen(int broj_staze)
	{
		unique_lock<mutex> l(mx);
		cout << "[U/I] obradjena je staza broj:  " << broj_staze << endl;
	}

	void uredjaj_aktiviran() 
	{
		unique_lock<mutex> l(mx);
		cout << "[U/I] uredjaj je aktiviran i pocinje sa obradom zahteva" << endl;
	}
};
