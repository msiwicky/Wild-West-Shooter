#include "Shotgun.h"

Shotgun::Shotgun()
	:Bron(2)
{ }

void Shotgun::wystrzelPocisk(int _x, int _y, int _kierunek, int _granica) {
	if (_x + 1 != _granica - 1) {
		Pocisk kula2(_x + 1, _y);
		magazynek.push_back(kula2);
	}
	if (_x - 1 != 0) {
		Pocisk kula3(_x - 1, _y);
		magazynek.push_back(kula3);
	}
	Pocisk kula1(_x, _y);
	magazynek.push_back(kula1);
	for (int i = 0; i < magazynek.size(); i++) {
		if (magazynek[i].getPolozenieX() == 1 || magazynek[i].getPolozenieX() == _granica - 2 || magazynek[i].getPolozenieY() == 1 || magazynek[i].getPolozenieY() == _granica - 2)
			magazynek.pop_front();
		else
			magazynek[i].ruch(_kierunek, _granica);
	}
}