#pragma once
#include "Bron.h"

class Shotgun : public Bron {

public:
	Shotgun();
	void wystrzelPocisk(int _x, int _y, int _kierunek, int _granica);
};