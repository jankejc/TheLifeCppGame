#include "Antylopa.h"

Antylopa::Antylopa(Organizm*** plansza, Swiat* swiat)
{
	this->setInicjatywa(4);
	this->setSila(4);
	this->setSymbol('A');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Antylopa::Antylopa(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setInicjatywa(4);
	this->setSila(4);
	this->setSymbol('A');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Antylopa* Antylopa::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Antylopa(x, y, plansza, swiat);
}

void Antylopa::akcja()
{
	int czy_walczy = rand() % 100 + 1;
	losowa_pozycja = rand() % 4 + 1;
	switch (losowa_pozycja)
	{
	case 1:
	{
		if (y > 1)
		{
			if (plansza_organizmu[x][y - 2] == NULL)
			{
				plansza_organizmu[x][y - 2] = this;
				plansza_organizmu[x][y] = NULL;
				this->setY(y - 2);
			}
			else if (plansza_organizmu[x][y - 2] != NULL && czy_walczy >= 50 && czy_walczy <= 100)
			{
				if (this->czyUnikPoSkokuNaZajetePole(plansza_organizmu[x][y - 2]))
					swiat->inkrIlosciUnikow();
				else
				{
					swiat->inkrIlosciKolizji();
					plansza_organizmu[x][y - 2]->kolizja(this);
					
				}
					
			}
			else if (plansza_organizmu[x][y - 2] != NULL && czy_walczy >= 0 && czy_walczy <= 50)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x][y - 2]->kolizja(this);
				
			}
		}
	}
	break;
	case 2:
	{
		if (x < swiat->getRozmiar_x() - 2)
		{
			if (plansza_organizmu[x + 2][y] == NULL)
			{
				plansza_organizmu[x + 2][y] = this;
				plansza_organizmu[x][y] = NULL;
				this->setX(x + 2);
			}
			else if (plansza_organizmu[x + 2][y] != NULL && czy_walczy >= 50 && czy_walczy <= 100)
			{
				if (this->czyUnikPoSkokuNaZajetePole(plansza_organizmu[x + 2][y]))
					swiat->inkrIlosciUnikow();
				else
				{
					swiat->inkrIlosciKolizji();
					plansza_organizmu[x + 2][y]->kolizja(this);
				}
					
			}
			else if (plansza_organizmu[x + 2][y] != NULL && czy_walczy >= 0 && czy_walczy <= 50)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x + 2][y]->kolizja(this);
				
			}
		}
	}
	break;
	case 3:
	{
		if (y < swiat->getRozmiar_y() - 2)
		{
			if (plansza_organizmu[x][y + 2] == NULL)
			{
				plansza_organizmu[x][y + 2] = this;
				plansza_organizmu[x][y] = NULL;
				this->setY(y + 2);
			}
			else if (plansza_organizmu[x][y + 2] != NULL && czy_walczy >= 50 && czy_walczy <= 100)
			{
				if (this->czyUnikPoSkokuNaZajetePole(plansza_organizmu[x][y + 2]))
					swiat->inkrIlosciUnikow();
				else
				{
					swiat->inkrIlosciKolizji();
					plansza_organizmu[x][y + 2]->kolizja(this);
					
				}		
			}
			else if (plansza_organizmu[x][y + 2] != NULL && czy_walczy >= 0 && czy_walczy <= 50)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x][y + 2]->kolizja(this);
				
			}
		}
	}
	break;
	case 4:
	{
		if (x > 1)
		{
			if (plansza_organizmu[x - 2][y] == NULL)
			{
				plansza_organizmu[x - 2][y] = this;
				plansza_organizmu[x][y] = NULL;
				this->setX(x - 2);
			}
			else if (plansza_organizmu[x - 2][y] != NULL && czy_walczy >= 50 && czy_walczy <= 100)
			{
				if (this->czyUnikPoSkokuNaZajetePole(plansza_organizmu[x - 2][y]))
					swiat->inkrIlosciUnikow();
				else
				{
					swiat->inkrIlosciKolizji();
					plansza_organizmu[x - 2][y]->kolizja(this);
					
				}	
			}
			else if (plansza_organizmu[x - 2][y] != NULL && czy_walczy >= 0 && czy_walczy <= 50)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x - 2][y]->kolizja(this);
			
			}
				
		}
	}
	break;
	default:
		break;
	}
}

void Antylopa::kolizja(Organizm* atakujacy)
{
	int czy_walczy = rand() % 100 + 1;
	if (czy_walczy >= 50 && czy_walczy <= 100)
	{
		if (this->czyUnik())
			swiat->inkrIlosciUnikow();
		else
		{
			swiat->inkrIlosciKolizji();
			this->Zwierze::kolizja(atakujacy);
			
		}	
	}
	else if (czy_walczy >= 0 && czy_walczy <= 50)
	{
		swiat->inkrIlosciKolizji();
		this->Zwierze::kolizja(atakujacy);
	
	}	
}

bool Antylopa::czyUnikPoSkokuNaZajetePole(Organizm* domownik_pola)
{
	int domownik_x = domownik_pola->getX();
	int domownik_y = domownik_pola->getY();
	bool pole_zajete[4] = { false, false, false, false };
	while (true)
	{
		if (pole_zajete[0] && pole_zajete[1] && pole_zajete[2] && pole_zajete[3])
			return false;

		losowa_pozycja = rand() % 4 + 1;
		switch (losowa_pozycja)
		{
		case 1:
		{
			if (domownik_y != 0 && plansza_organizmu[domownik_x][domownik_y - 1] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				y = domownik_y - 1;
				x = domownik_x;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[0] = true;
		}
		break;
		case 2:
		{
			if (domownik_x < swiat->getRozmiar_x() - 1 && plansza_organizmu[domownik_x + 1][domownik_y] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				x = domownik_x + 1;
				y = domownik_y;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[1] = true;
		}
		break;
		case 3:
		{
			if (domownik_y < swiat->getRozmiar_y() - 1 && plansza_organizmu[domownik_x][domownik_y + 1] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				y = domownik_y + 1;
				x = domownik_x;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[2] = true;
		}
		break;
		case 4:
		{
			if (domownik_x != 0 && plansza_organizmu[domownik_x - 1][domownik_y] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				x = domownik_x - 1;
				y = domownik_y;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[3] = true;
		}
		break;

		default:
			break;
		}
	}
}

bool Antylopa::czyUnik()
{
	bool pole_zajete[4] = { false, false, false, false };
	while (true)
	{
		if (pole_zajete[0] && pole_zajete[1] && pole_zajete[2] && pole_zajete[3])
			return false;

		losowa_pozycja = rand() % 4 + 1;
		switch (losowa_pozycja)
		{
		case 1:
		{
			if (y != 0 && plansza_organizmu[x][y - 1] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				y -= 1;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[0] = true;
		}
		break;
		case 2:
		{
			if (x < swiat->getRozmiar_x() - 1 && plansza_organizmu[x + 1][y] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				x += 1;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[1] = true;
		}
		break;
		case 3:
		{
			if (y < swiat->getRozmiar_y() - 1 && plansza_organizmu[x][y + 1] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				y += 1;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[2] = true;
		}
		break;
		case 4:
		{
			if (x != 0 && plansza_organizmu[x - 1][y] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				x -= 1;
				plansza_organizmu[x][y] = this;
				return true;
			}
			else
				pole_zajete[3] = true;
		}
		break;

		default:
			break;
		}
	}
}

bool Antylopa::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Antylopa*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

Antylopa::~Antylopa()
{

}