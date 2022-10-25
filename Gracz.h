#pragma once
#include <iostream>
#include "Bron.h"

class Arena;

class Gracz {
private:
	char wyglad;
	int polozenieX;
	int polozenieY;
	Arena* arena;
	Bron* bron;
public:
	Gracz();
	void ruch(int _x = 0, int _y = 0);
	int getPolozenieX() const { return polozenieX; };
	int getPolozenieY() const { return polozenieY; };
	char getWyglad() const { return wyglad; };
	void ustawArene(Arena* _arena);
	void ustawBron(Bron* _bron);
	void strzal(int _kierunek, int _wielkosc);
	Bron* getBron() const { return bron; };
};