#include "Guarana.h"
#include "Zwierze.h"

Guarana::Guarana(Organizm*** plansza, Swiat* swiat)
{
	this->setSymbol('G');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Guarana::Guarana(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setSymbol('G');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Guarana* Guarana::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Guarana(x, y, plansza, swiat);
}

void Guarana::kolizja(Organizm* atakujacy)
{
	if (this->czyOdbilAtak(atakujacy))
	{
		if (dynamic_cast<Roslina*>(atakujacy) != NULL)
		{
			swiat->inkrIlosciZgonowOdRoslin();
			swiat->usunOrganizm(atakujacy);
		}
		else if (dynamic_cast<Zwierze*>(atakujacy) != NULL)
		{
			swiat->inkrIlosciZgonowOdRoslin();
			swiat->usunOrganizm();
		}
	}
	else if (this->czyOdbilAtak(atakujacy) == false)
	{
		if (dynamic_cast<Roslina*>(atakujacy) != NULL)
		{
			swiat->inkrIlosciZgonowOdRoslin();
			swiat->inkrIlosciRozsiewow();
			Organizm* temp_organizm = this;
			plansza_organizmu[x][y] = atakujacy;
			swiat->dodajOrganizmDoListy(atakujacy);
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
			atakujacy->zwiekszSileOTrzy();
		}
	}
}

bool Guarana::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Guarana*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

bool Guarana::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila())
		return true;
	else
		return false;
}

Guarana::~Guarana()
{

}