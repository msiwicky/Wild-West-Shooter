#pragma once
#include <iostream>
#include "Pocisk.h"
#include <deque>

class Bron {
protected:
	std::deque <Pocisk> magazynek;
	int obrazenia;
public:
	Bron(int _obrazenia);
	virtual void wystrzelPocisk(int _x, int _y, int _kierunek, int _granica) = 0;
	Pocisk& getPocisk(int _ktory) { return magazynek[_ktory]; };
	int getWielkoscMag() const { return magazynek.size(); };
	std::deque <Pocisk>& getMag() { return magazynek; };
	int getObrazenia() const { return obrazenia; };
};