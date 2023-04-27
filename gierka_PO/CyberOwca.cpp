#include "CyberOwca.h"

CyberOwca::CyberOwca(Organizm*** plansza, Swiat* swiat)
{
	this->setInicjatywa(4);
	this->setSila(11);
	this->setSymbol('S');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

CyberOwca::CyberOwca(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setInicjatywa(4);
	this->setSila(11);
	this->setSymbol('S');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

CyberOwca* CyberOwca::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new CyberOwca(x, y, plansza, swiat);
}

void CyberOwca::akcja()
{

}

void CyberOwca::kolizja(Organizm* atakujacy)
{

}

bool CyberOwca::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<CyberOwca*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

CyberOwca::~CyberOwca()
{

}
