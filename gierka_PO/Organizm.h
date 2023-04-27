#pragma once
#include "Swiat.h"

class Swiat;

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	char symbol;
	int x;
	int y;
	int losowa_pozycja;
	bool czy_ustawiony;
	bool noworodek;
	bool rozsiany;

	Organizm*** plansza_organizmu;
	Swiat* swiat;

	virtual bool czyTakiSamTyp(Organizm* atakujacy) = 0;
	virtual bool czyOdbilAtak(Organizm* atakujacy) = 0;
	virtual bool getRozsiany() = 0;
	virtual void setSymbol(char symbol) = 0;
	virtual void setInicjatywa(int inicjatywa) = 0;
	virtual void setSila(int sila) = 0;
	
public:
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getSila() = 0;
	virtual int getInicjatywa() = 0;
	virtual bool getMoc_aktywna() = 0;
	virtual int getNoworodek() = 0;
	virtual void setY(int y) = 0;
	virtual void setX(int x) = 0;
	virtual void setNoworodek(bool option) = 0;
	virtual void setRozsiany(bool option) = 0;
	virtual void setCzy_ustawiony(bool option) = 0;
	virtual Organizm* kopiujObiekt(int x, int y, Organizm*** plansza, Swiat* swiat) = 0;
	virtual void kolizja(Organizm* atakujacy) = 0;
	virtual void rysowanie() = 0;
	virtual void akcja() = 0;
	virtual void specjalnaMoc() = 0;
	virtual void zwiekszSileOTrzy() = 0;
	virtual ~Organizm();
};

