#pragma once
#include "Zwierze.h"

class Owca : public Zwierze
{
private:
	Owca* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
public:
	Owca(Organizm*** plansza, Swiat* swiat);
	Owca(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Owca();
};

