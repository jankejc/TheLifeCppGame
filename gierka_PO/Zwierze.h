#pragma once
#include "Organizm.h"
#include <iostream>

class Zwierze : public Organizm
{
private:
	int getX() override;
	int getY() override;
	int getSila() override;
	int getNoworodek() override;
	virtual bool getMoc_aktywna() override;
	void setNoworodek(bool option) override;
	void setCzy_ustawiony(bool option) override;
	void setRozsiany(bool option) override;
	bool getRozsiany() override;
	void zwiekszSileOTrzy() override;
	int getInicjatywa() override;
	virtual void specjalnaMoc() override;
	virtual bool czyOdbilAtak(Organizm* atakujacy) override;
	void rysowanie() override;
public:
	void setX(int x) override;
	void setY(int y) override;
	void setSila(int sila) override;
	void setSymbol(char symbol) override;
	void setInicjatywa(int inicjatywa) override;
	virtual void akcja() override;
	void rozmnazanie(Organizm* atakujacy);
	virtual void kolizja(Organizm* atakujacy) override;
	~Zwierze();
};

