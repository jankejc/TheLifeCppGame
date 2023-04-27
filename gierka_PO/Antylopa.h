#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
private:
	Antylopa* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	bool czyUnik();
	bool czyUnikPoSkokuNaZajetePole(Organizm* domownik_pola);
	void kolizja(Organizm* atakujacy) override;
	void akcja() override;
public:
	Antylopa(Organizm*** plansza, Swiat* swiat);
	Antylopa(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Antylopa();
};

