#pragma once
#include "Zwierze.h"
#include "Swiat.h"
#include <conio.h>

class Czlowiek : public Zwierze
{
private:
	char temp_char;
	char kierunek_ruchu;
	int tur_z_moca = 0;
	int tur_bez_mocy = 4;
	bool moc_aktywna = false;
	void specjalnaMoc();
	bool getMoc_aktywna() override;
	bool czyTakiSamTyp(Organizm* atakujacy) override;
	Czlowiek* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) override;
	void obslugaRuchu(char kierunek_ruchu);
	void akcja() override;
public:
	Czlowiek(Organizm*** plansza, Swiat* swiat);
	Czlowiek(int x, int y, Organizm*** plansza, Swiat* swiat);
	~Czlowiek();
};

