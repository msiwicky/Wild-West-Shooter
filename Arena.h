#pragma once
#include <iostream>
#include "TablicaWynikow.h"
#include "Gracz.h"

class Arena {
private:
	int wielkosc;
	char** mapa;
	TablicaWynikow tablica;
	Gracz gracze[2];
public:
	Arena(int _wielkosc);
	~Arena();
	Arena(const Arena& _zrodlo);
	Arena& operator=(const Arena& _zrodlo);
	void generujMape();
	void pojedynek();
	void wypisz();
	void aktualizujMape();
	int getWielkosc() const { return wielkosc; };
	void zmienMape(int _x, int _y, char _z) { mapa[_y][_x] = _z; };
	char getPole(int _x, int _y) const { return mapa[_y][_x]; };
};