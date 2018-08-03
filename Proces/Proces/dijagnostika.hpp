#pragma once
#include <iostream>
#include <mutex>

using namespace std;

class Dijagnostika {
private:
	mutex mx;
public:
	void proces_ceka(int id) 
	{
		unique_lock<mutex>l(mx);
		cout << "[PROCES] " << id << " se uvezuje u red spremnih procesa." << endl;
	}

	void proces_izvrsio_standardnu(int id) 
	{
		unique_lock<mutex>l(mx);
		cout << "[PROCES] " << id << " izvrsio standardnu instrukciju." << endl;
	}

	
	void proces_ceka_na_UI(int id) 
	{
		unique_lock<mutex>l(mx);
		cout << "[PROCES] " << id << " odlazi u cekanje zbog U/I operacije." << endl;
	}

	void proces_zavrsio_UI(int id) 
	{
		unique_lock<mutex>l(mx);
		cout << "[PROCES] " << id << " probudjen iz cekanja od strane U/I uredjaja " << endl;
	}

	void proces_oslobadja_procesor(int id)
	{
		unique_lock<mutex>l(mx);
		cout << "[PROCES] " << id << " oslobadja procesor." << endl;
	}

	void proces_zavrsio(int id) 
	{
		unique_lock<mutex>l(mx);
		cout << "[PROCES] " << id << " se zavrsio." << endl;
	}

	void ui_ceka() 
	{
		unique_lock<mutex>l(mx);
		cout << "[U/I] podsistem ceka na zahtev." << endl;
	}

	void ui_zapocinje(int id_procesa)
	{
		unique_lock<mutex>l(mx);
		cout << "[U/I] podsistem obradjuje zahtev procesa " << id_procesa << endl;
	}

	void ui_zavrsio(int id_procesa) 
	{
		unique_lock<mutex>l(mx);
		cout << "[U/I] podsistem je obradio zahtev procesa " << id_procesa << endl;
	}
};
