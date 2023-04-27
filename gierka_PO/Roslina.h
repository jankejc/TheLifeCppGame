#pragma once
#include "Organizm.h"
#include <iostream>

class Roslina : public Organizm
{
private:
	int getX() override;
	int getY() override;
	int getSila() override;
	int getNoworodek() override;
	bool getMoc_aktywna() override;
	void setNoworodek(bool option) override;
	virtual bool getRozsiany() override;
	void zwiekszSileOTrzy() override;
	void setCzy_ustawiony(bool option) override;
	virtual void setRozsiany(bool option) override;
	int getInicjatywa() override;
	void specjalnaMoc() override;
	virtual void rysowanie() override;
public:
	Roslina();
	void setX(int x) override;
	void setY(int y) override;
	void setSila(int sila) override;
	void setSymbol(char symbol) override;
	void setInicjatywa(int inicjatywa) override;
	virtual void akcja() override;
	virtual void kolizja(Organizm* atakujacy) override;
	~Roslina();
};