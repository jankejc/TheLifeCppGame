#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
private:
	Guarana* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	void kolizja(Organizm* atakujacy) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
public:
	Guarana(Organizm*** plansza, Swiat* swiat);
	Guarana(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Guarana();
};

