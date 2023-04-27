#include "Swiat.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

Swiat::Swiat(int x, int y)
	:rozmiar_x(x), rozmiar_y(y)
{
	plansza = new Organizm**[rozmiar_x];
	for (int i = 0; i < rozmiar_x; i++)
	{
		plansza[i] = new Organizm * [rozmiar_y] {};
	}
	randTheTime();
	poczatkoweOrganizmy();
}

void Swiat::dodajOrganizmDoListy(Organizm* nowy_organizm)
{
	bool czy_dodany = false;
	if (organizmy.empty())
	{
		organizmy.push_front(nowy_organizm);
	}
	else
	{
		list<Organizm*>::iterator iter = organizmy.end();
		for (iter--; iter != organizmy.begin(); iter--)
		{
			if (czy_dodany == false && (*iter)->getInicjatywa() >= nowy_organizm->getInicjatywa())
			{
				iter++;
				organizmy.insert(iter, nowy_organizm);
				czy_dodany = true;
			}
		}
		if (czy_dodany == false
			&& (*iter)->getInicjatywa() < nowy_organizm->getInicjatywa()
			&& iter == organizmy.begin())
		{
			organizmy.push_front(nowy_organizm);
			czy_dodany = true;
		}
		else if (czy_dodany != true)
		{
			iter++;
			organizmy.insert(iter, nowy_organizm);
			czy_dodany = true;
		}
	}
}

void Swiat::dodajOrganizmDoPlanszy(Organizm* organizm)
{
	if (dynamic_cast<Czlowiek*>(organizm) != NULL)
	{
		//if wykona sie tylko na poczatku gry, bo czlowiek nie rozmnaza sie
		plansza[0][0] = organizm;
		organizm->setX(0);
		organizm->setY(0);
	}
	else
	{
		bool zajety = false;
		bool ustawiony = false;
		do
		{
			losowy_x = rand() % rozmiar_x;
			losowy_y = rand() % rozmiar_y;
			
			if (plansza[losowy_x][losowy_y] != nullptr && (losowy_x == 0 && losowy_y == 0))
				zajety = true;
			
			if(zajety == false)
			{
				//ustawienie organizmu na planszy
				plansza[losowy_x][losowy_y] = organizm;

				//ustawienie polozenia w obiekcie
				organizm->setX(losowy_x);
				organizm->setY(losowy_y);

				ustawiony = true;
			}
		}while (ustawiony == false);
	}
}

int Swiat::getRozmiar_x()
{
	return rozmiar_x;
}

int Swiat::getRozmiar_y()
{
	return rozmiar_y;
}

void Swiat::wizytowka()
{
	cout << "Jan Kornacki 180424" << endl;
}

void Swiat::poczatkoweOrganizmy()
{
	Organizm* nowy_organizm = NULL;

	nowy_organizm = new Czlowiek(plansza, this);
	czlowiek = nowy_organizm;
	dodajOrganizmDoListy(nowy_organizm);
	dodajOrganizmDoPlanszy(nowy_organizm);

	//dodanie organizmow do kolejki w turze
	for (int i = 0; i < POCZATKOWA_ILOSC_ORGANIZMOW; i++)
	{
		nowy_organizm = new Wilk(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);

		
		nowy_organizm = new Owca(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);

		nowy_organizm = new Lis(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);

		nowy_organizm = new Zolw(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);

		nowy_organizm = new Antylopa(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);

		nowy_organizm = new Trawa(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);
		
		nowy_organizm = new Mlecz(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);
		
		nowy_organizm = new Guarana(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);
		
		nowy_organizm = new WilczeJagody(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);
		
		nowy_organizm = new BarszczSosnowskiego(plansza, this);
		dodajOrganizmDoListy(nowy_organizm);
		dodajOrganizmDoPlanszy(nowy_organizm);
	}
}

void Swiat::rysujSwiat()
{
	for (int i = 0; i < rozmiar_x; i++)
	{
		for (int j = 0; j < rozmiar_y; j++)
		{
			if (plansza[i][j] != NULL)
			{
				cout << "|";
				plansza[i][j]->rysowanie();
			}
			else
				cout << "| ";
		}
		std::cout << "|" << std::endl;
	}
}

void Swiat::wykonajTure()
{
	biezacy_organizm_iter = organizmy.begin();
	for (; biezacy_organizm_iter != organizmy.end(); biezacy_organizm_iter++)
	{
		if (czlowiek != NULL && czlowiek->getMoc_aktywna())
			czlowiek->specjalnaMoc();
			
		if ((*biezacy_organizm_iter)->getNoworodek() == false)
			(*biezacy_organizm_iter)->akcja();
		else
			(*biezacy_organizm_iter)->setNoworodek(false);

		if (biezacy_organizm_iter == organizmy.end())
			break;
	}
}

Organizm*** Swiat::getPlansza()
{
	return this->plansza;
}

void Swiat::usunOrganizm(int x, int y)
{
	for (list<Organizm*>::iterator iter = organizmy.begin(); iter != organizmy.end(); iter++)
	{
		if ((*iter) == plansza[x][y])
		{
			iter = organizmy.erase(iter);
			break;
		}	
	}

	if (dynamic_cast<Czlowiek*>(plansza[x][y]) != NULL)
		czlowiek = NULL;
	delete plansza[x][y];
	plansza[x][y] = NULL;
}

void Swiat::usunOrganizm(Organizm* organizm)
{
	for (list<Organizm*>::iterator iter = organizmy.begin(); iter != organizmy.end(); iter++)
	{
		if ((*iter) == organizm)
		{
			iter = organizmy.erase(iter);
			break;
		}
	}

	if (dynamic_cast<Czlowiek*>(organizm) != NULL)
		czlowiek = NULL;
	delete organizm;
}

void Swiat::usunOrganizm()
{
	int temp_x = (*biezacy_organizm_iter)->getX();
	int temp_y = (*biezacy_organizm_iter)->getY();
	for (list<Organizm*>::iterator iter = organizmy.begin(); iter != organizmy.end(); iter++)
	{
		if ((*iter) == (*biezacy_organizm_iter))
		{
			biezacy_organizm_iter = organizmy.erase(biezacy_organizm_iter);
			break;
		}
	}

	if (dynamic_cast<Czlowiek*>(plansza[temp_x][temp_y]) != NULL)
		czlowiek = NULL;
	delete plansza[temp_x][temp_y];
	plansza[temp_x][temp_y] = NULL;
}

void Swiat::randTheTime()
{
	srand(time(NULL));
}

void Swiat::inkrIlosciRozmnozen()
{
	this->ile_rozmnozen++;
}

void Swiat::inkrIlosciKolizji()
{
	this->ile_kolizji++;
}

void Swiat::inkrIlosciZgonowOdRoslin()
{
	this->ile_zgonow_od_roslin++;
}

void Swiat::inkrIlosciZgonowOdZwierzat()
{
	this->ile_zgonow_od_zwierzat++;
}

void Swiat::inkrIlosciRozsiewow()
{
	this->ile_rozsiewow++;
}

void Swiat::inkrIlosciUnikow()
{
	this->ile_unikow++;
}

void Swiat::inkrIlosciChytrychRuchow()
{
	this->ile_chytrych_ruchow++;
}

void Swiat::wypiszStatystyki()
{
	cout << endl <<  "STATYSTYKI TURY: ";
	cout << endl << "Ilosc rozmnozen: " << this->ile_rozmnozen << endl;
	cout << "Ilosc kolizji: " << this->ile_kolizji << endl;
	cout << "Ilosc zgonow od roslin: " << this->ile_zgonow_od_roslin << endl;
	cout << "Ilosc zgonow od zwierzat: " << this->ile_zgonow_od_zwierzat << endl;
	cout << "Ilosc rozsiewow: " << this->ile_rozsiewow << endl;
	cout << "Ilosc unikow antylopy: " << this->ile_unikow << endl;
	cout << "Ilosc chytrych ruchow lisa: " << this->ile_chytrych_ruchow << endl;
	if (this->czlowiek == NULL && czlowiek_nie_zyje == false)
	{
		cout << "CZLOWIEK ZGINAL - O NIE!" << endl;
		czlowiek_nie_zyje = true;
	}
	this->resetStatystyk();
}

void Swiat::resetStatystyk()
{
	this->ile_rozmnozen = 0;
	this->ile_kolizji = 0;
	this->ile_zgonow_od_roslin = 0;
	this->ile_zgonow_od_zwierzat = 0;
	this->ile_rozsiewow = 0;
	this->ile_unikow = 0;
	this->ile_chytrych_ruchow = 0;
}


Swiat::~Swiat()
{
	//dealokacja pamiêci
	for (int i = 0; i < rozmiar_x; i++)
	{
		for (int j = 0; j < rozmiar_y; j++)
		{
			delete[] plansza[i][j];
		}
	}
	delete[] plansza;

	organizmy.clear();
}