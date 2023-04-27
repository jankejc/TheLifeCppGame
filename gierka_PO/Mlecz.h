#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
private:
	Mlecz* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
public:
	Mlecz(Organizm*** plansza, Swiat* swiat);
	Mlecz(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Mlecz();
};

