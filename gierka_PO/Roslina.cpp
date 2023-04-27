#include "Roslina.h"
#include "Zwierze.h"

Roslina::Roslina()
{
	this->setInicjatywa(0);
	this->setSila(0);
}

bool Roslina::getRozsiany()
{
	return this->rozsiany;
}

void Roslina::setRozsiany(bool option)
{
	this->rozsiany = option;
}

void Roslina::specjalnaMoc(){}

bool Roslina::getMoc_aktywna()
{
	return false;
}

void Roslina::setCzy_ustawiony(bool option)
{
	this->czy_ustawiony = option;
}

void Roslina::setNoworodek(bool option)
{
	this->noworodek = option;
}

int Roslina::getNoworodek()
{
	return this->noworodek;
}

void Roslina::zwiekszSileOTrzy(){}

void Roslina::akcja()
{
	Organizm* kopia_do_rozsiania = NULL;
	int liczba_losowa = rand() % 100 + 1;
	if (liczba_losowa >= 0 && liczba_losowa <= 20)
	{
		czy_ustawiony = false;
		losowa_pozycja = rand() % 4 + 1;
		switch (losowa_pozycja)
		{
		case 1:
		{
			if (y != 0)
			{
				if (plansza_organizmu[x][y - 1] == NULL)
				{
					swiat->inkrIlosciRozsiewow();
					plansza_organizmu[x][y - 1] = this->kopiujObiekt(x, y - 1, plansza_organizmu, swiat);
					swiat->dodajOrganizmDoListy(plansza_organizmu[x][y - 1]);
					this->setRozsiany(true);
					
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
					this->setRozsiany(true);
					
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
					this->setRozsiany(true);
					
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
					this->setRozsiany(true);
					
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

void Roslina::kolizja(Organizm* atakujacy)
{
	if (this->czyOdbilAtak(atakujacy))
	{
		swiat->inkrIlosciZgonowOdRoslin();
		if (dynamic_cast<Roslina*>(atakujacy) != NULL)
		{
			swiat->usunOrganizm(atakujacy);
		}
		else if (dynamic_cast<Zwierze*>(atakujacy) != NULL)
		{
			swiat->usunOrganizm();
		}
			
	}
	else if (this->czyOdbilAtak(atakujacy) == false)
	{
		if (dynamic_cast<Roslina*>(atakujacy) != NULL)
		{
			swiat->inkrIlosciZgonowOdRoslin();
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
		}
	}
}

void Roslina::rysowanie()
{
	std::cout << this->symbol;
}

void Roslina::setSymbol(char symbol)
{
	this->symbol = symbol;
}

void Roslina::setX(int x)
{
	this->x = x;
}

void Roslina::setY(int y)
{
	this->y = y;
}

int Roslina::getSila()
{
	return this->sila;
}

int Roslina::getInicjatywa()
{
	return this->inicjatywa;
}

void Roslina::setInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}

void Roslina::setSila(int sila)
{
	this->sila = sila;
}

int Roslina::getX()
{
	return this->x;
}

int Roslina::getY()
{
	return this->y;
}


Roslina::~Roslina()
{

}


