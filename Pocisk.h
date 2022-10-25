#pragma once
#include <iostream>


class Pocisk {
private:
	char wyglad;
	int polozenieX;
	int polozenieY;
public:
	Pocisk(int _x, int _y);
	void ruch(int _kierunek, int _granica);
	int getPolozenieX() const { return polozenieX; };
	int getPolozenieY() const { return polozenieY; };
	char getWyglad() const { return wyglad; };
};