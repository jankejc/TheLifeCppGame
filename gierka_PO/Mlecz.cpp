#include "Mlecz.h"

Mlecz::Mlecz(Organizm*** plansza, Swiat* swiat)
{
	this->setSymbol('M');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
	this->rozsiany = false;
}

Mlecz::Mlecz(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setSymbol('M');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Mlecz* Mlecz::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Mlecz(x, y, plansza, swiat);
}

void Mlecz::akcja()
{
	for (int i = 0; i < 3; i++)
	{
		this->Roslina::akcja();

		if (rozsiany == true)
		{
			//cout << endl << "MLECZ SIE ZROBIL" << endl;
			break;
		}
			
	}
}

bool Mlecz::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Mlecz*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

bool Mlecz::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila())
		return true;
	else
		return false;
}

Mlecz::~Mlecz()
{

}
