#pragma once
#define POCZATKOWA_ILOSC_ORGANIZMOW (rozmiar_x * rozmiar_y)/80 + 1

#include <iostream>
#include <conio.h>
#include <time.h>
#include <list>
#include <windows.h>
#include <stdlib.h>
#include "Organizm.h"
using namespace std;

class Organizm;

class Swiat
{
private:
	int rozmiar_x;
	int rozmiar_y;
	char kierunek;
	char temp_char;
	int losowy_x;
	int losowy_y;
	int ile_rozmnozen = 0;
	int ile_kolizji = 0;
	int ile_zgonow_od_roslin = 0;
	int ile_zgonow_od_zwierzat = 0;
	int ile_rozsiewow = 0;
	int ile_unikow = 0;
	int ile_chytrych_ruchow = 0;
	bool czlowiek_nie_zyje = false;

	list<Organizm*>::iterator biezacy_organizm_iter;
	Organizm* czlowiek;

	Organizm*** plansza;
	list<Organizm*> organizmy;

	void poczatkoweOrganizmy();
	void randTheTime();
	void resetStatystyk();
	void dodajOrganizmDoPlanszy(Organizm* organizm);
	Organizm*** getPlansza();
public:
	Swiat(int x, int y);
	int getRozmiar_x();
	int getRozmiar_y();
	void usunOrganizm(int x, int y);
	void usunOrganizm(Organizm* organizm);
	void usunOrganizm();
	void dodajOrganizmDoListy(Organizm* organizm);

	void inkrIlosciRozmnozen();
	void inkrIlosciKolizji();
	void inkrIlosciZgonowOdRoslin();
	void inkrIlosciZgonowOdZwierzat();
	void inkrIlosciRozsiewow();
	void inkrIlosciUnikow();
	void inkrIlosciChytrychRuchow();

	void wypiszStatystyki();
	void rysujSwiat();
	void wykonajTure();
	void wizytowka();
	~Swiat();
};

