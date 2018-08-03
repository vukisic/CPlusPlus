// Napisati konkurentni program koji modeluje izvršavanje procesa u multiprogramiranom jednoprocesorskom okruženju.
//
// Procesi su predstavljeni nitima. Svaki proces ima skup instrukcija koje treba da izvrši, pri èemu postoje dva tipa instrukcija:
//STANDARD (instrukcija zahteva odreðeno izraèunavanje od procesora) i UI (zahtev za operacijom ulazno/izlaznog ureðaja).
//U ovom zadatku, smer komunikacije sa UI ureðajem je takav da proces inicira UI operaciju i pritom ostaje blokiran dok se ta operacija ne završi.
//
// Procesor je incijalno slobodan i zauzima ga prvi proces koji do njega doðe i pokuša da izvrši instrukciju.
// Sledi opis obrade STANDARD i UI instrukcija.
//
//-------------------------------------------------------------------------------------------------------------------
// OPIS OBRADE STANDARD INSTRUKCIJE:
//
// U sistemu je definisan maksimalan broj od 3 STANDARD instrukcije koje proces koji je zauzeo procesor može uzastopno da izvrši.
//Nakon što izvrši 3 STANDARD instrukcije, proces prelazi u stanje spreman a drugi proces iz liste spremnih dobija procesor.
//Na ovaj naèin na procesoru se vrši prekljuèivanje izmeðu razlièitih procesa i omoguæava se ravnomerna raspodela procesorskog vremena.
//
// Pri prekljuèivanju nakon 3 STANDARD instrukcije treba voditi raèuna da se obezbedi mehanizam da proces koji oslobaða
//procesor (a koji ima još preostalih instrukcija za izvršavanje) ne pokuša da zauzme procesor ODMAH nakon puštanja.
//Ovo se postiže uvoðenjem cooldown perioda od 100ms.
//
// Iz liste spremnih procesa, naredni proces za izvršavanje se bira bez odreðenog pravila. Bilo koji od spremnih procesa prelazi u izvršavanje.
//
// Ukoliko neki proces nema više instrukcija, on završava svoj rad i prepušta procesor nekom od procesa iz liste spremnih procesa.
//
// Izvršavanje STANDARD instrukcije traje sluèajan vremenski period izmeðu 10 i 50 ms èime se npr. simulira aritmetièko-logièka operacija na procesoru.
//
//--------------------------------------------------------------------------------------------------------------------
//
// OPIS OBRADE UI INSTRUKCIJE:
//
// UI instrukcije predstavljaju zahteve za operacijom ulazno izlaznih ureðaja i njih obraðuje UI podsistem (preko niti ui_podsistem).
//UI podsistem REDOM opslužuje pristigle zahteve ukoliko takvi zahtevi postoje.
//
// Ako proces izvršava UI instrukciju on šalje zahtev UI podsistemu i odlazi u stanje èekanja radi završetka obrade UI zahteva.
//U èekanju proces otpušta procesor (tokom èekanja na UI obradu nema smisla da se drži procesor ako drugi procesi mogu da ga koriste) i tada bilo
//koji drugi proces iz liste spremnih procesa dobija procesor.
//
// UI instrukcija takoðe prekida niz STANDARD instrukcija što znaci da se broj prethodno izvršenih STANDARD instrukcija za dati proces prilikom nailaska na
// UI instrukciju resetuje na 0.
//
// Kada UI podsistem obradi zahtev, proces koji je èekao obradu zahteva može da odmah postane aktivan (ukoliko je procesor slobodan) ili se uvezuje u
// listu spremnih procesa (ukoliko procesor koristi neki drugi proces).
//
// Operacija UI ureðaja traje sluèajan period izmeðu 100 i 300 ms.
//
// Implementirati oznaèene metode, konstruktor i dodati privatne èlanove u klasu OS (fajl os.h).

#include <thread>
#include <vector>

#include "proces.hpp"
#include "dijagnostika.hpp"
#include "os.hpp"

using namespace std;

void p(OS& s, int id) {
	vector<INS_TYPE> instrukcije;
	for (int i = 0; i < 10; i++) {
		instrukcije.push_back((INS_TYPE)(rand() % 10 == 1));
	}
	Proces p(instrukcije, id);
	s.izvrsi_proces(p);
	s.getDijagnostika().proces_zavrsio(id);
}

void ui_podsistem(OS& s) {
	s.obradi_zahteve();
}

void testirajSve() {
	srand(time(NULL));

	Dijagnostika d;
	OS OS(d, 3);
	thread procesi[5];

	thread ui_nit = thread(ui_podsistem, ref(OS));
	ui_nit.detach();

	for (int i = 0; i < 5; i++) {
		procesi[i] = thread(p, ref(OS), i + 1);
	}

	for (int i = 0; i < 5; i++) {
		procesi[i].join();
	}
}

int main() {
	testirajSve();
	system("pause");
	exit(0);
}