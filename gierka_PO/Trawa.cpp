#include "Trawa.h"

Trawa::Trawa(Organizm*** plansza, Swiat* swiat)
{
	this->setSymbol('T');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Trawa::Trawa(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setSymbol('T');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Trawa* Trawa::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Trawa(x, y, plansza, swiat);
}

bool Trawa::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Trawa*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

bool Trawa::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila())
		return true;
	else
		return false;
}

Trawa::~Trawa()
{

}