#include "Pocisk.h"

Pocisk::Pocisk(int _x, int _y) {
	wyglad = '*';
	polozenieX = _x;
	polozenieY = _y;
}



void Pocisk::ruch(int _kierunek, int _granica) {
	if (getPolozenieX() > 1 && getPolozenieX() < _granica - 2 && getPolozenieY() > 1 && getPolozenieY() < _granica - 2)
		polozenieY += _kierunek;
}