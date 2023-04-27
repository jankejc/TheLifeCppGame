#pragma once
#include "Zwierze.h"

class CyberOwca : public Zwierze
{	
public:
	CyberOwca(Organizm*** plansza, Swiat* swiat);
	CyberOwca(int x, int y, Organizm*** plansza, Swiat* swiat);
	CyberOwca* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	~CyberOwca();
};

