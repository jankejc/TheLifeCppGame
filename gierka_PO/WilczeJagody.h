#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina
{
private:
	WilczeJagody* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	void kolizja(Organizm* atakujacy) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
public:
	WilczeJagody(Organizm*** plansza, Swiat* swiat);
	WilczeJagody(int x, int y, Organizm*** plansza, Swiat* swiat);
	~WilczeJagody();
};

