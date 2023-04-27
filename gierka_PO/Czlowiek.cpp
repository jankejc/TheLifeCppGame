#define W_GORE 72
#define W_DOL 80
#define W_PRAWO 77
#define W_LEWO 75
#include "Czlowiek.h"

Czlowiek::Czlowiek(Organizm*** plansza, Swiat* swiat)
{
	this->setInicjatywa(4);
	this->setSila(5);
	this->setSymbol('C');
	this->noworodek = false;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Czlowiek::Czlowiek(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	this->x = x;
	this->y = y;
	this->setInicjatywa(4);
	this->setSila(5);
	this->setSymbol('C');
	this->noworodek = false;
	this->czy_ustawiony = false;
	this->plansza_organizmu = plansza;
	this->swiat = swiat;
}

Czlowiek* Czlowiek::kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat)
{
	return new Czlowiek(x, y, plansza, swiat);
}

void Czlowiek::specjalnaMoc()
{
	if (x != 0 && plansza_organizmu[x - 1][y] != NULL)
	{
		swiat->usunOrganizm(x - 1, y);
	}
		
	if (x < swiat->getRozmiar_x() - 1 && plansza_organizmu[x + 1][y] != NULL)
	{
		swiat->usunOrganizm(x + 1, y);
		
	}
		
	if (y != 0 && plansza_organizmu[x][y - 1] != NULL)
	{
		swiat->usunOrganizm(x, y - 1);
	}
		
	if (y < swiat->getRozmiar_y() - 1 && plansza_organizmu[x][y + 1] != NULL)
	{
		swiat->usunOrganizm(x, y + 1);
	}	
	swiat->inkrIlosciZgonowOdZwierzat();
}

void Czlowiek::obslugaRuchu(char kierunek_ruchu)
{
	switch (kierunek_ruchu)
	{
	case W_GORE:
	{
		if (x - 1 == -1)
			;
		else
		{
			if (plansza_organizmu[x - 1][y] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				x -= 1;
				plansza_organizmu[x][y] = this;
			}
			else if (plansza_organizmu[x - 1][y] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x - 1][y]->kolizja(this);
				
			}
		}
	}
	break;

	case W_DOL:
	{
		if (x + 1 == swiat->getRozmiar_x())
			;
		else
		{
			if (plansza_organizmu[x + 1][y] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				x += 1;
				plansza_organizmu[x][y] = this;
			}
			else if (plansza_organizmu[x + 1][y] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x + 1][y]->kolizja(this);
				
			}
		}
	}
	break;

	case W_PRAWO:
	{
		if (y + 1 == swiat->getRozmiar_y())
			;
		else
		{
			if (plansza_organizmu[x][y + 1] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				y += 1;
				plansza_organizmu[x][y] = this;
			}
			else if (plansza_organizmu[x][y + 1] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x][y + 1]->kolizja(this);
				
			}
		}
	}
	break;

	case W_LEWO:
	{
		if (y - 1 == -1)
			;
		else
		{
			if (plansza_organizmu[x][y - 1] == NULL)
			{
				plansza_organizmu[x][y] = NULL;
				y -= 1;
				plansza_organizmu[x][y] = this;
			}
			else if (plansza_organizmu[x][y - 1] != NULL)
			{
				swiat->inkrIlosciKolizji();
				plansza_organizmu[x][y - 1]->kolizja(this);
				
			}
		}

	}
	break;

	default:
		break;
	}
}

void Czlowiek::akcja()
{
	system("cls");
	if (tur_bez_mocy == 4)
	{
		cout << "Zdolnosc gotowa do uzycia! (nacisnij x)." << endl;
		cout << "Jesli nie chcesz teraz wykorzystywac mocy nacisnij strzalke." << endl << endl;
		swiat->rysujSwiat();
		temp_char = _getch();
		if (temp_char == 'x')
		{
			this->specjalnaMoc();
			system("cls");
			cout << endl << "Moc dziala. Mozesz sie jeszcze ruszyc." << endl << endl;
			swiat->rysujSwiat();
			tur_bez_mocy = 0;
			tur_z_moca = 1;
			moc_aktywna = true;
			temp_char = _getch();
			kierunek_ruchu = _getch();
		}
		else
			kierunek_ruchu = _getch();
	}
	else if (tur_z_moca > 0 && tur_z_moca < 5)
	{
		system("cls");
		cout << endl << "Moc dziala. Mozesz sie jeszcze ruszyc." << endl << endl;
		swiat->rysujSwiat();
		temp_char = _getch();
		kierunek_ruchu = _getch();
		tur_z_moca++;
	}
	else if (tur_z_moca == 5)
	{
		system("cls");
		cout << endl << "Deaktywacja mocy. Mozesz sie jeszcze ruszyc." << endl << endl;
		swiat->rysujSwiat();
		moc_aktywna = false;
		temp_char = _getch();
		kierunek_ruchu = _getch();
		tur_z_moca = 0;
	}
	else if (tur_bez_mocy < 4)
	{
		system("cls");
		cout << endl << "Moc jest nieaktywna jeszcze przez " << 4 - tur_bez_mocy << " tur. Mozesz sie jeszcze ruszyc." << endl << endl;
		swiat->rysujSwiat();
		temp_char = _getch();
		kierunek_ruchu = _getch();

		tur_bez_mocy++;
	}

	this->obslugaRuchu(kierunek_ruchu);

}

bool Czlowiek::getMoc_aktywna()
{
	return this->moc_aktywna;
}

bool Czlowiek::czyTakiSamTyp(Organizm* atakujacy)
{
	if (dynamic_cast<Czlowiek*>(atakujacy) != NULL)
		return true;
	else
		return false;
}

Czlowiek::~Czlowiek()
{

}