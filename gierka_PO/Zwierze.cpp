#include "Zwierze.h"
#include "Roslina.h"

bool Zwierze::getRozsiany()
{
	return false;
}

void Zwierze::setRozsiany(bool option){}

bool Zwierze::getMoc_aktywna()
{
	return false;
}

void Zwierze::specjalnaMoc(){}

void Zwierze::rozmnazanie(Organizm* atakujacy)
{
	czy_ustawiony = false;
	bool pole_zajete[8] = {false, false, false, false, false, false, false, false};
	int atak_x = atakujacy->getX();
	int atak_y = atakujacy->getY();
	while (czy_ustawiony == false)
	{
		if (pole_zajete[0] && pole_zajete[1] && pole_zajete[2] && pole_zajete[3]
			&& pole_zajete[4] && pole_zajete[5] && pole_zajete[6] && pole_zajete[7])
			break;
			
		losowa_pozycja = rand() % 8 + 1;
		switch (losowa_pozycja)
		{
		case 1:
		{
			if (y != 0 && plansza_organizmu[x][y - 1] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[x][y - 1] = this->kopiujObiekt(x, y - 1, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[x][y - 1]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);

			}
			else
				pole_zajete[0] = true;
		}
		break;
		case 2:
		{
			if (x < swiat->getRozmiar_x() - 1 && plansza_organizmu[x + 1][y] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[x + 1][y] = this->kopiujObiekt(x + 1, y, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[x + 1][y]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);

			}
			else
				pole_zajete[1] = true;
		}
		break;
		case 3:
		{
			if (y < swiat->getRozmiar_y() - 1 && plansza_organizmu[x][y + 1] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[x][y + 1] = this->kopiujObiekt(x, y + 1, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[x][y + 1]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);

			}
			else
				pole_zajete[2] = true;
		}
		break;
		case 4:
		{
			if (x != 0 && plansza_organizmu[x - 1][y] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[x - 1][y] = this->kopiujObiekt(x - 1, y, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[x - 1][y]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);

			}
			else
				pole_zajete[3] = true;
		}
		break;
		
		case 5:
		{
			if (atak_x != 0 && plansza_organizmu[atak_x - 1][atak_y] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[atak_x - 1][atak_y] = atakujacy->kopiujObiekt(atak_x - 1, atak_y, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[atak_x - 1][atak_y]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);
				
			}
			else
				pole_zajete[4] = true;
		}
		break;
		
		case 6:
		{
			if (atak_y != 0 && plansza_organizmu[atak_x][atak_y - 1] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[atak_x][atak_y - 1] = atakujacy->kopiujObiekt(atak_x, atak_y - 1, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[atak_x][atak_y - 1]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);
				
			}
			else
				pole_zajete[5] = true;
		}
		break;
		
		case 7:
		{
			if (atak_x < swiat->getRozmiar_x() - 1 && plansza_organizmu[atak_x + 1][atak_y] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[atak_x + 1][atak_y] = atakujacy->kopiujObiekt(atak_x + 1, atak_y, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[atak_x + 1][atak_y]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);
				
			}
			else
				pole_zajete[6] = true;
		}
		break;
		
		case 8:
		{
			if (atak_y < swiat->getRozmiar_y() - 1 && plansza_organizmu[atak_x][atak_y + 1] == NULL)
			{
				swiat->inkrIlosciRozmnozen();
				plansza_organizmu[atak_x][atak_y + 1] = atakujacy->kopiujObiekt(atak_x, atak_y + 1, plansza_organizmu, swiat);
				swiat->dodajOrganizmDoListy(plansza_organizmu[atak_x][atak_y + 1]);
				this->czy_ustawiony = true;
				atakujacy->setCzy_ustawiony(true);
				
			}
			else
				pole_zajete[7] = true;
		}
		break;
		default:
			break;
		}
	}
}

void Zwierze::setCzy_ustawiony(bool option)
{
	this->czy_ustawiony = option;
}

void Zwierze::akcja()
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
				plansza_organizmu[x][y - 1] = this;
				plansza_organizmu[x][y] = NULL;
				this->setY(y - 1);
			}
			else if(plansza_organizmu[x][y - 1] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x][y - 1]->kolizja(this);
				
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
				plansza_organizmu[x + 1][y] = this;
				plansza_organizmu[x][y] = NULL;
				this->setX(x + 1);
			}
			else if (plansza_organizmu[x + 1][y] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x + 1][y]->kolizja(this);
				
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
				plansza_organizmu[x][y + 1] = this;
				plansza_organizmu[x][y] = NULL;
				this->setY(y + 1);
			}
			else if (plansza_organizmu[x][y + 1] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x][y + 1]->kolizja(this);
				
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
				plansza_organizmu[x - 1][y] = this;
				plansza_organizmu[x][y] = NULL;
				this->setX(x - 1);
			}
			else if (plansza_organizmu[x - 1][y] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x - 1][y]->kolizja(this);
				
			}		
		}
	}
	break;
	default:
		break;
	}
}

void Zwierze::kolizja(Organizm* atakujacy)
{
	if (this->czyTakiSamTyp(atakujacy))
	{
		this->rozmnazanie(atakujacy);
	}
	else if(this->czyOdbilAtak(atakujacy))
	{
		swiat->inkrIlosciZgonowOdZwierzat();
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
			swiat->inkrIlosciRozsiewow();
			Organizm* temp_organizm = this;
			plansza_organizmu[x][y] = atakujacy;
			swiat->dodajOrganizmDoListy(atakujacy);
			atakujacy->setRozsiany(true);
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

bool Zwierze::czyOdbilAtak(Organizm* atakujacy)
{
	if (this->sila > atakujacy->getSila())
		return true;
	else
		return false;
}

int Zwierze::getNoworodek()
{
	return this->noworodek;
}

void Zwierze::zwiekszSileOTrzy()
{
	this->sila += 3;
}

void Zwierze::setNoworodek(bool option)
{
	this->noworodek = option;
}

void Zwierze::rysowanie()
{
	std::cout << this->symbol;
}

void Zwierze::setX(int x)
{
	this->x = x;
}

void Zwierze::setY(int y)
{
	this->y = y;
}

void Zwierze::setInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}

void Zwierze::setSila(int sila)
{
	this->sila = sila;
}

int Zwierze::getSila()
{
	return this->sila;
}

int Zwierze::getX()
{
	return this->x;
}

int Zwierze::getY()
{
	return this->y;
}

int Zwierze::getInicjatywa()
{
	return this->inicjatywa;
}

void Zwierze::setSymbol(char symbol)
{
	this->symbol = symbol;
}

Zwierze::~Zwierze()
{

}


