#include "BarszczSosnowskiego.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(Organizm*** plansza, Swiat* swiat)
{
	this->setSila(10);
	this->setSymbol('B');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setSila(10);
	this->setSymbol('B');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

BarszczSosnowskiego* BarszczSosnowskiego::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new BarszczSosnowskiego(x, y, plansza, swiat);
}

bool BarszczSosnowskiego::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila())
		return true;
	else
		return false;
}

void BarszczSosnowskiego::specjalnaMoc()
{
	if (x != 0 && plansza_organizmu[x - 1][y] != NULL
		&& dynamic_cast<BarszczSosnowskiego*>(plansza_organizmu[x - 1][y]) == NULL)
	{
		swiat->usunOrganizm(x - 1, y);
		swiat->inkrIlosciZgonowOdRoslin();
	}
		

	if (x < swiat->getRozmiar_x() - 1 && plansza_organizmu[x + 1][y] != NULL
		&& dynamic_cast<BarszczSosnowskiego*>(plansza_organizmu[x + 1][y]) == NULL)
	{
		swiat->usunOrganizm(x + 1, y);
		swiat->inkrIlosciZgonowOdRoslin();
	}
		

	if (y != 0 && plansza_organizmu[x][y - 1] != NULL
		&& dynamic_cast<BarszczSosnowskiego*>(plansza_organizmu[x][y - 1]) == NULL)
	{
		swiat->usunOrganizm(x, y - 1);
		swiat->inkrIlosciZgonowOdRoslin();
	}
		

	if (y < swiat->getRozmiar_y() - 1 && plansza_organizmu[x][y + 1] != NULL
		&& dynamic_cast<BarszczSosnowskiego*>(plansza_organizmu[x][y + 1]) == NULL)
	{
		swiat->usunOrganizm(x, y + 1);
		swiat->inkrIlosciZgonowOdRoslin();
	}
}

void BarszczSosnowskiego::akcja()
{
	Organizm* kopia_do_rozsiania = NULL;
	int liczba_losowa = rand() % 100 + 1;
	this->specjalnaMoc();
	if (liczba_losowa >= 0 && liczba_losowa <= 20)
	{
		losowa_pozycja = rand() % 4 + 1;
		switch (losowa_pozycja)
		{
		case 1:
		{
			if (y != 0)
			{
				if (plansza_organizmu[x][y - 1] == NULL)
				{
					plansza_organizmu[x][y - 1] = this->kopiujObiekt(x, y - 1, plansza_organizmu, swiat);
					swiat->dodajOrganizmDoListy(plansza_organizmu[x][y - 1]);
					swiat->inkrIlosciRozsiewow();
				}
				else if (plansza_organizmu[x][y - 1] != NULL)
				{
					swiat->inkrIlosciKolizji();
					kopia_do_rozsiania = this->kopiujObiekt(x, y - 1, plansza_organizmu, swiat);
					plansza_organizmu[x][y - 1]->kolizja(kopia_do_rozsiania);
				}
			}
		}
		break;
		case 2:
		{
			if (x < swiat->getRozmiar_x() - 1)
			{
				if (plansza_organizmu[x + 1][y] == NULL)
				{
					swiat->inkrIlosciRozsiewow();
					plansza_organizmu[x + 1][y] = this->kopiujObiekt(x + 1, y, plansza_organizmu, swiat);
					swiat->dodajOrganizmDoListy(plansza_organizmu[x + 1][y]);

				}
				else if (plansza_organizmu[x + 1][y] != NULL)
				{
					swiat->inkrIlosciKolizji();
					kopia_do_rozsiania = this->kopiujObiekt(x + 1, y, plansza_organizmu, swiat);
					plansza_organizmu[x + 1][y]->kolizja(kopia_do_rozsiania);

				}
			}
		}
		break;
		case 3:
		{
			if (y < swiat->getRozmiar_y() - 1)
			{
				if (plansza_organizmu[x][y + 1] == NULL)
				{
					swiat->inkrIlosciRozsiewow();
					plansza_organizmu[x][y + 1] = this->kopiujObiekt(x, y + 1, plansza_organizmu, swiat);
					swiat->dodajOrganizmDoListy(plansza_organizmu[x][y + 1]);

				}
				else if (plansza_organizmu[x][y + 1] != NULL)
				{
					swiat->inkrIlosciKolizji();
					kopia_do_rozsiania = this->kopiujObiekt(x, y + 1, plansza_organizmu, swiat);
					plansza_organizmu[x][y + 1]->kolizja(kopia_do_rozsiania);

				}
			}
		}
		break;
		case 4:
		{
			if (x != 0)
			{
				if (plansza_organizmu[x - 1][y] == NULL)
				{
					swiat->inkrIlosciRozsiewow();
					plansza_organizmu[x - 1][y] = this->kopiujObiekt(x - 1, y, plansza_organizmu, swiat);
					swiat->dodajOrganizmDoListy(plansza_organizmu[x - 1][y]);

				}
				else if (plansza_organizmu[x - 1][y] != NULL)
				{
					swiat->inkrIlosciKolizji();
					kopia_do_rozsiania = this->kopiujObiekt(x - 1, y, plansza_organizmu, swiat);
					plansza_organizmu[x - 1][y]->kolizja(kopia_do_rozsiania);

				}
			}
		}
		break;
		default:
			break;
		}
	}
}

void BarszczSosnowskiego::kolizja(Organizm* atakujacy)
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
			swiat->inkrIlosciZgonowOdRoslin();
			swiat->inkrIlosciZgonowOdZwierzat();
			swiat->usunOrganizm(this);
			swiat->usunOrganizm(atakujacy);
		}
	}
}

bool BarszczSosnowskiego::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<BarszczSosnowskiego*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{

}