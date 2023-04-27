#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina
{
private:
	BarszczSosnowskiego* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	void akcja() override;
	void specjalnaMoc() override;
	void kolizja(Organizm* atakujacy) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
public:
	BarszczSosnowskiego(Organizm*** plansza, Swiat* swiat);
	BarszczSosnowskiego(int x, int y, Organizm*** plansza, Swiat* swiat);
	~BarszczSosnowskiego();
};

