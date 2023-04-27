#include "Wilk.h"

Wilk::Wilk(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setInicjatywa(5);
	this->setSila(9);
	this->setSymbol('W');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Wilk::Wilk(Organizm*** plansza, Swiat* swiat)
{
	this->setInicjatywa(5);
	this->setSila(9);
	this->setSymbol('W');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

bool Wilk::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Wilk*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

Wilk* Wilk::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Wilk(x, y, plansza, swiat);
}

Wilk::~Wilk()
{

}