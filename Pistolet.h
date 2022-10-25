#pragma once
#include "Bron.h"

class Pistolet : public Bron {
private:
	int zniszczenie;
public:
	Pistolet();
	void wystrzelPocisk(int _x, int _y, int _kierunek, int _granica);
};
