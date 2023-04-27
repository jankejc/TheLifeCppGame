#include "WilczeJagody.h"
#include "Zwierze.h"

WilczeJagody::WilczeJagody(Organizm*** plansza, Swiat* swiat)
{
	this->setSila(99);
	this->setSymbol('J');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

WilczeJagody::WilczeJagody(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setSila(99);
	this->setSymbol('J');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

WilczeJagody* WilczeJagody::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new WilczeJagody(x, y, plansza, swiat);
}

void WilczeJagody::kolizja(Organizm* atakujacy)
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
			swiat->usunOrganizm(this);
			swiat->usunOrganizm(atakujacy);
			
		}
	}
}

bool WilczeJagody::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<WilczeJagody*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

bool WilczeJagody::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila())
		return true;
	else
		return false;
}

WilczeJagody::~WilczeJagody()
{

}