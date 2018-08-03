// Napisati konkurentni program koji simulira prioritetni raspore�iva� u jednoprocesorskom sistemu.
//
// Procesi su predstavljeni nitima. Da bi se izvr�ili pozivaju metodu "izvrsi" deljene promenljive tipa Rasporedjivac.
//Svaki proces sadr�i odre�eni broj naredbi. Naredbe se izvr�avaju jedna po jedna. Za svaku naredbu, proces mora da sa�eka da procesor
//bude slobodan. Izvr�avanje jedne naredbe traje 300 ms. Nakon izvr�avanja naredbe, proces odlazi u stanje spreman, a drugi spreman proces dobija procesor.
//
// Procesi su klasifikovani prema prioritetu. 0 je najvi�i prioritet dok je N najmanji!
//
// Za svaki prioritet, postoji odvojen red �ekanja na procesor. Prednost u kori��enju procesora imaju procesi sa vi�im prioritetom.
//Me�u procesima istog prioriteta, raspore�ivanje se obavlja po FIFO principu (tj. cikli�no �e se smenjivati razli�ite naredbe procesa istih
//prioriteta na procesoru).
//
// Prioritet procesa je odre�en stati�ki u trenutku kreiranja procesa.
//
// Za uspostavljanje reda �ekanja po FIFO principu koristiti datu klasu "cv_hrono".
//

#include <thread>
#include <cstdlib>
#include "rasporedjivac.hpp"
#include"MyQueue.hpp"

using namespace std;

const int BROJ_PRIORITETA = 5;

void proces(Rasporedjivac& r, int id_procesa, int broj_naredbi) {
	int prioritet = rand() % BROJ_PRIORITETA;
	r.getDijagnostika().proces_kreiran(id_procesa, prioritet, broj_naredbi);

	r.izvrsi(id_procesa, broj_naredbi, prioritet);

	r.getDijagnostika().proces_zavrsio(id_procesa, prioritet);
}

const int BROJ_PROCESA = 10;

void testirajSve() {
	//srand(time(NULL));

	Dijagnostika d;
	Rasporedjivac r(d, BROJ_PRIORITETA);
	thread procesi[BROJ_PROCESA];

	for (int i = 0; i < BROJ_PROCESA; i++)
		procesi[i] = thread(proces, ref(r), i + 1, rand() % 10 + 1);

	for (int i = 0; i < BROJ_PROCESA; i++)
		procesi[i].join();
}

int main() {
	srand(time(NULL));
	testirajSve();
	system("pause");
	return 0;
}
