// Napraviti konkurentni program koji simulira dinami�ku dodelu memorijskog prostora procesima.
// Memorija je podeljena na memorijske lokacije. Procesu je potreban odre�eni broj slobodnih UZASTOPNIH memorijskih lokacija da bi se smestio u memoriju.
// Proces zauzima prvi slobodan blok memorije koji prona�e. Kada proces zavr�i sa radom, osloba�aju se lokacije koje je koristio.
//
// U opisanom scenariju, kako procesi zavr�avaju sa radom, dolazi do pojave "rupa" u memoriji (slobodni blokovi memorije). Mo�e se desiti da ukupan broj slobodnih
// memorijskih lokacija bude dovoljan da se novi proces smesti, ali da se te slobodne lokacije ne nalaze u sukcesivnim lokacijama memorije. Zato je potrebno izvr�iti
//SA�IMANJE memorije. Pri sa�imanju memorije, trenutni procesi u memoriji se pomeraju tako da zauzimaju uzastopne lokacije pocev�i od prve.
//Na taj na�in, na kraju memorije ostaju sve slobodne lokacije kao jedan blok uzastopnih lokacija.
//
// Memorija je predstavljena datom klasom Radna_memorija. Pri instanciranju se prosle�uje broj lokacija u memoriji. Procesi su predstavljeni nitima.
//Telo niti je funkcija proces. Svaki proces dobija kao parametar broj lokacija koje su mu potrebne da se smesti u memoriju.
// Procesi zauzimaju memoriju pozivom operacije "koristi" klase Radna_memorija. Ukoliko ne postoji dovoljno uzastopnih slobodnih memorijskih lokacija koliko
// procesu treba, proces mora da �eka. Kada ima dovoljno lokacija, proces zauzima lokacije. Nakon toga se izvr�ava. Izvr�avanje simulirati uspavljivanjem niti na
// broj sekundi definisan parametrom "trajanje". Nakon toga, proces osloba�a lokacije koje je koristio i tra�i sa�imanje memorije.
//
// Sa�imanje memorije vr�i posebna nit predstavljena funkcijom os. Samo sa�imanje vr�i se u metodi "sazimanje" klase radna memorija.
//U ovoj metodi, mehanizam zadu�en za sa�imanje �eka dok neki proces ne zatra�i sa�imanje. Kada se sa�imanje zatra�i, vr�i se sa�imanje memorije na ranije opisani na�in.
// Nakon sa�imanja, mogu�e je da u memoriji postoji ve�i slobodan blok nego ranije, pa se neki od procesa koji su �ekali na memoriju sada mo�e smestiti.
//
// U okviru sa�imanja NIJE dozvoljeno vr�iti sortiranje memorijskih lokacija kao skra�eni postupak za izbacivanje slobodnih lokacija na kraj. Razlog je u tome �to
// �e sortiranje potencijalno ispreme�tati mnogo vi�e lokacija nego �to bi to uradio postupak sa�imanja koji je prethodno opisan (a u realnom scenariju, svako pomeranje
//lokacija je operacija sa zna�ajnim trajanjem).
//
// Npr. ukoliko je izgled memorije pre sa�imanja:
//
//	-1 -1 3 3 3 1 1 -1 -1 2 2
//
//	Nakon sa�imanja izgled memorije treba da bude:
//
//	3 3 3 1 1 2 2 -1 -1 -1 -1
//
//	a NE:
//
//	1 1 2 2 3 3 3 -1 -1 -1 -1 ili 3 3 3 2 2 1 1 -1 -1 -1
//
#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdlib>
#include<thread>
#include<mutex>
#include<iostream>
#include<condition_variable>
#include"ram.hpp"
using namespace std;
using namespace chrono;

const int BROJ_PROCESA = 5;
const int UKUPNO_OKVIRA = 50;

void Proces(Ram& rm, int id, int br_loc, int trajanje, int kasnjenje)
{
	this_thread::sleep_for(seconds(kasnjenje));
	rm.getDijagnostika().proces_krenuo(id, br_loc);
	rm.koristi_memoriju(id, br_loc, trajanje);
}

void os(Ram& rm)
{
	while (true)
	{
		rm.Sazimanje();
	}
}
thread os_thread;
void testirajSve()
{
	Dijagnostika d;
	Ram rm(d, UKUPNO_OKVIRA);

	int velicine[] = { 20,14,18,8,16 };
	int trajanje[] = { 5,2,5,4,4 };
	int kasnjenje[] = { 0,1,2,4,5 };

	os_thread=thread(os, ref(rm));
	os_thread.detach();
	thread procesi[BROJ_PROCESA];
	for (int i = 0; i < BROJ_PROCESA; ++i)
		procesi[i] = thread(Proces, ref(rm), i + 1, velicine[i], trajanje[i], kasnjenje[i]);
	for (int i = 0; i < BROJ_PROCESA; ++i)
		procesi[i].join();
}

int main()
{
	testirajSve();
	exit(0);
}