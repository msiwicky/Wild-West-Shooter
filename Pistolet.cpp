#include "Pistolet.h"
#include <time.h>

Pistolet::Pistolet()
	: Bron(1)
	, zniszczenie(5)
{ }

void Pistolet::wystrzelPocisk(int _x, int _y, int _kierunek, int _granica) {
	if (rand() % 5 != 0) {
		Pocisk kula(_x, _y);
		if(_x > 1 && _x < _granica - 2 && _y > 1 && _y < _granica - 2)
			magazynek.push_back(kula);
		for (int i = 0; i < magazynek.size(); i++) {
			if (magazynek[i].getPolozenieX() == 1 || magazynek[i].getPolozenieX() == _granica - 2 || magazynek[i].getPolozenieY() == 1 || magazynek[i].getPolozenieY() == _granica - 2)
				magazynek.pop_front();
			else
				magazynek[i].ruch(_kierunek, _granica);
		}
	}
}