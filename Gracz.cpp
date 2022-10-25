#include <iostream>
#include "Gracz.h"
#include "Arena.h"


Gracz::Gracz() {
	wyglad = 'O';
}

void Gracz::ruch(int _x, int _y) {
	if (polozenieX == 0 && polozenieY == 0) {
		polozenieX = _x;
		polozenieY = _y;
	}
	else {
		if (polozenieX + _x >= 1 && polozenieX + _x <= arena->getWielkosc() - 2) {
			arena->zmienMape(polozenieX, polozenieY, ' ');
			polozenieX += _x;
		}
		if (polozenieY + _y >= 1 && polozenieY + _y <= arena->getWielkosc() - 2) {
			arena->zmienMape(polozenieX, polozenieY, ' ');
			polozenieY += _y;
		}
	}

}

void Gracz::ustawArene(Arena* _arena) {
	arena = _arena;
}
void Gracz::ustawBron(Bron* _bron) {
	bron = _bron;
}

void Gracz::strzal(int _kierunek, int _wielkosc) {
	bron->wystrzelPocisk(polozenieX, polozenieY, _kierunek , _wielkosc);
}