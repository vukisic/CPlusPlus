// Napisati konkurentni program koji simulira prioritetni rasporeðivaè u jednoprocesorskom sistemu.
//
// Procesi su predstavljeni nitima. Da bi se izvršili pozivaju metodu "izvrsi" deljene promenljive tipa Rasporedjivac.
//Svaki proces sadrži odreðeni broj naredbi. Naredbe se izvršavaju jedna po jedna. Za svaku naredbu, proces mora da saèeka da procesor
//bude slobodan. Izvršavanje jedne naredbe traje 300 ms. Nakon izvršavanja naredbe, proces odlazi u stanje spreman, a drugi spreman proces dobija procesor.
//
// Procesi su klasifikovani prema prioritetu. 0 je najviši prioritet dok je N najmanji!
//
// Za svaki prioritet, postoji odvojen red èekanja na procesor. Prednost u korišæenju procesora imaju procesi sa višim prioritetom.
//Meðu procesima istog prioriteta, rasporeðivanje se obavlja po FIFO principu (tj. ciklièno æe se smenjivati razlièite naredbe procesa istih
//prioriteta na procesoru).
//
// Prioritet procesa je odreðen statièki u trenutku kreiranja procesa.
//
// Za uspostavljanje reda èekanja po FIFO principu koristiti datu klasu "cv_hrono".
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
