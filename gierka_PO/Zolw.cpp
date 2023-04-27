#include "Zolw.h"
#include "Roslina.h"

Zolw::Zolw(Organizm*** plansza, Swiat* swiat)
{
	this->setInicjatywa(1);
	this->setSila(2);
	this->setSymbol('Z');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Zolw::Zolw(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setInicjatywa(1);
	this->setSila(2);
	this->setSymbol('Z');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Zolw* Zolw::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Zolw(x, y, plansza, swiat);
}

void Zolw::akcja()
{
	int czy_ruch = rand() % 100 + 1;
	if (czy_ruch >= 75 && czy_ruch <= 100)
		Zwierze::akcja();
}

bool Zolw::czyOdbilAtak(Organizm* atakujacy)
{
	if (atakujacy->getSila() < 5)
		return true;
	else
		return false;
}

void Zolw::kolizja(Organizm* atakujacy)
{
	if (this->czyTakiSamTyp(atakujacy))
	{
		swiat->inkrIlosciRozmnozen();
		this->rozmnazanie(atakujacy);
		
	}
	else if (this->czyOdbilAtak(atakujacy) == false)
	{
		if (dynamic_cast<Roslina*>(atakujacy) != NULL)
		{
			swiat->inkrIlosciZgonowOdRoslin();
			Organizm* temp_organizm = this;
			plansza_organizmu[atakujacy->getX()][atakujacy->getY()] = atakujacy;
			plansza_organizmu[x][y] = NULL;
			swiat->usunOrganizm(temp_organizm);
			
		}
		else if (dynamic_cast<Zwierze*>(atakujacy) != NULL)
		{
			swiat->inkrIlosciZgonowOdZwierzat();
			Organizm* temp_organizm = this;
			plansza_organizmu[atakujacy->getX()][atakujacy->getY()] = NULL;
			atakujacy->setX(this->x);
			atakujacy->setY(this->y);
			plansza_organizmu[x][y] = atakujacy;
			swiat->usunOrganizm(temp_organizm);
		}
	}
}

bool Zolw::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Zolw*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

Zolw::~Zolw()
{

}