#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze
{
private:
	Zolw* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	void kolizja(Organizm* atakujacy) override;
public:
	Zolw(Organizm*** plansza, Swiat* swiat);
	Zolw(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Zolw();
};

