#include "Owca.h"

Owca::Owca(Organizm*** plansza, Swiat* swiat)
{
	this->setInicjatywa(4);
	this->setSila(4);
	this->setSymbol('O');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Owca::Owca(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setInicjatywa(4);
	this->setSila(4);
	this->setSymbol('O');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Owca* Owca::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Owca(x, y, plansza, swiat);
}

bool Owca::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Owca*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

Owca::~Owca()
{

}