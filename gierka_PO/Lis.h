#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
private:
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	Lis* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	void akcja() override;
public:
	Lis(Organizm*** plansza, Swiat* swiat);
	Lis(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Lis();
};

