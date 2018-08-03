// Napisati konkurentni program koji simulira raspore�ivanje diska po SSTF (Shortest Service Time First) principu.
//
// Kod ovog na�ina raspore�ivanja diska, iz skupa UI zahteva prednost ima onaj zahtev koji zahteva najmanje pomeranje ru�ice diska.
//Drugim re�ima, pristupi�e se onoj stazi koja je najbli�a stazi na kojoj je trenutno glava diska.
//
// Klasa OS predstavlja deo operativnog sistema koji je zadu�en za raspore�ivanje zahteva. Metodu uputi_ui_zahtev pozivaju niti koje predstavljaju procese.
//U ovoj metodi postavlja se zahtev raspore�iva�u diska da izvr�i UI operaciju na odre�enoj stazi diska.
//Proces mora da sa�eka da zahtev bude izvr�en, pre nego nastavi dalje izvr�avanje.
//
// Metodu obradi_zahtev poziva nit koja predstavlja raspore�iva� diska. Metoda je zadu�ena da obradi jedan zahtev iz skupa zahteva.
//Zahtev za obradu se iz skupa zahteva bira po SSTF principu. Obrada zahteva traje 300 ms. Rezultat metode je broj staze kojoj je disk pristupio pri obradi zahteva.
//

#include <thread>
#include<cstdlib>
#include "os.hpp"

using namespace std;
using namespace chrono;

void proces(OS& os, int broj_staze, int rbp) {
	os.getDijagnostika().zahtev_prosledjen(rbp, broj_staze);
	os.uputi_UI_zahtev(rbp, broj_staze);
}

void rasporedjivac_diska(OS& os) {
	this_thread::sleep_for(milliseconds(200));
	os.getDijagnostika().uredjaj_aktiviran();
	while (true) {
		int broj_staze = os.obradi_zahtev();
		os.getDijagnostika().zahtev_obradjen(broj_staze);
	}
}

void testirajSve() {
	int brojevi_staza[] = { 55, 58, 39, 18, 90, 160, 150, 38, 184 };

	Dijagnostika d;
	OS os(d, 100);

	thread rasporedjivac_thread(rasporedjivac_diska, ref(os));
	rasporedjivac_thread.detach();

	thread procesi[9];
	for (int i = 0; i < 9; i++)
		procesi[i] = thread(proces, ref(os), brojevi_staza[i], i + 1);

	for (int i = 0; i < 9; i++)
		procesi[i].join();
}

int main() {
	testirajSve();
	system("pause");
	exit(0);
}
