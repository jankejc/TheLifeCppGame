#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
private:
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	Wilk* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
public:
	Wilk(Organizm*** plansza, Swiat* swiat);
	Wilk(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Wilk();
};

