#include "Lis.h"

Lis::Lis(Organizm*** plansza, Swiat* swiat)
{
	this->setInicjatywa(7);
	this->setSila(3);
	this->setSymbol('L');
	this->swiat = swiat;
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
}

Lis::Lis(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setInicjatywa(7);
	this->setSila(3);
	this->setSymbol('L');
	this->noworodek = true;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Lis* Lis::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Lis(x, y, plansza, swiat);
}

void Lis::akcja()
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
			else if (plansza_organizmu[x][y - 1]->getSila() > this->sila)
				swiat->inkrIlosciChytrychRuchow();
			else if (plansza_organizmu[x][y - 1]->getSila() <= this->sila)
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
			else if (plansza_organizmu[x + 1][y]->getSila() > this->sila)
				swiat->inkrIlosciChytrychRuchow();
			else if (plansza_organizmu[x + 1][y]->getSila() <= this->sila)
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
			else if (plansza_organizmu[x][y + 1]->getSila() > this->sila)
				swiat->inkrIlosciChytrychRuchow();
			else if (plansza_organizmu[x][y + 1]->getSila() <= this->sila)
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
			else if (plansza_organizmu[x - 1][y]->getSila() > this->sila)
				swiat->inkrIlosciChytrychRuchow();
			else if (plansza_organizmu[x - 1][y]->getSila() <= this->sila)
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

bool Lis::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Lis*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

Lis::~Lis()
{

}