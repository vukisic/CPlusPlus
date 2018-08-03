// Napisati konkurentni program koji modeluje izvr�avanje procesa u multiprogramiranom jednoprocesorskom okru�enju.
//
// Procesi su predstavljeni nitima. Svaki proces ima skup instrukcija koje treba da izvr�i, pri �emu postoje dva tipa instrukcija:
//STANDARD (instrukcija zahteva odre�eno izra�unavanje od procesora) i UI (zahtev za operacijom ulazno/izlaznog ure�aja).
//U ovom zadatku, smer komunikacije sa UI ure�ajem je takav da proces inicira UI operaciju i pritom ostaje blokiran dok se ta operacija ne zavr�i.
//
// Procesor je incijalno slobodan i zauzima ga prvi proces koji do njega do�e i poku�a da izvr�i instrukciju.
// Sledi opis obrade STANDARD i UI instrukcija.
//
//-------------------------------------------------------------------------------------------------------------------
// OPIS OBRADE STANDARD INSTRUKCIJE:
//
// U sistemu je definisan maksimalan broj od 3 STANDARD instrukcije koje proces koji je zauzeo procesor mo�e uzastopno da izvr�i.
//Nakon �to izvr�i 3 STANDARD instrukcije, proces prelazi u stanje spreman a drugi proces iz liste spremnih dobija procesor.
//Na ovaj na�in na procesoru se vr�i preklju�ivanje izme�u razli�itih procesa i omogu�ava se ravnomerna raspodela procesorskog vremena.
//
// Pri preklju�ivanju nakon 3 STANDARD instrukcije treba voditi ra�una da se obezbedi mehanizam da proces koji osloba�a
//procesor (a koji ima jo� preostalih instrukcija za izvr�avanje) ne poku�a da zauzme procesor ODMAH nakon pu�tanja.
//Ovo se posti�e uvo�enjem cooldown perioda od 100ms.
//
// Iz liste spremnih procesa, naredni proces za izvr�avanje se bira bez odre�enog pravila. Bilo koji od spremnih procesa prelazi u izvr�avanje.
//
// Ukoliko neki proces nema vi�e instrukcija, on zavr�ava svoj rad i prepu�ta procesor nekom od procesa iz liste spremnih procesa.
//
// Izvr�avanje STANDARD instrukcije traje slu�ajan vremenski period izme�u 10 i 50 ms �ime se npr. simulira aritmeti�ko-logi�ka operacija na procesoru.
//
//--------------------------------------------------------------------------------------------------------------------
//
// OPIS OBRADE UI INSTRUKCIJE:
//
// UI instrukcije predstavljaju zahteve za operacijom ulazno izlaznih ure�aja i njih obra�uje UI podsistem (preko niti ui_podsistem).
//UI podsistem REDOM opslu�uje pristigle zahteve ukoliko takvi zahtevi postoje.
//
// Ako proces izvr�ava UI instrukciju on �alje zahtev UI podsistemu i odlazi u stanje �ekanja radi zavr�etka obrade UI zahteva.
//U �ekanju proces otpu�ta procesor (tokom �ekanja na UI obradu nema smisla da se dr�i procesor ako drugi procesi mogu da ga koriste) i tada bilo
//koji drugi proces iz liste spremnih procesa dobija procesor.
//
// UI instrukcija tako�e prekida niz STANDARD instrukcija �to znaci da se broj prethodno izvr�enih STANDARD instrukcija za dati proces prilikom nailaska na
// UI instrukciju resetuje na 0.
//
// Kada UI podsistem obradi zahtev, proces koji je �ekao obradu zahteva mo�e da odmah postane aktivan (ukoliko je procesor slobodan) ili se uvezuje u
// listu spremnih procesa (ukoliko procesor koristi neki drugi proces).
//
// Operacija UI ure�aja traje slu�ajan period izme�u 100 i 300 ms.
//
// Implementirati ozna�ene metode, konstruktor i dodati privatne �lanove u klasu OS (fajl os.h).

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