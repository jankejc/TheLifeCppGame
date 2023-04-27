#pragma once
#include "Roslina.h"

class Trawa : public Roslina
{
private:
	Trawa* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
public:
	Trawa(Organizm*** plansza, Swiat* swiat);
	Trawa(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Trawa();
};

