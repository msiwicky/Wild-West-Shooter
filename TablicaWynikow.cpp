#include "TablicaWynikow.h"


TablicaWynikow::TablicaWynikow() {
	punkty[0] = 0;
	punkty[1] = 0;
	nazwa[0] = "Gracz 1";
	nazwa[1] = "Gracz 2";
}

void TablicaWynikow::zmienPunkty(int _ktory, int _ile) {
	punkty[_ktory] += _ile;
}

void TablicaWynikow::wypisz(){
	std::cout << '\n' << nazwa[0] << ": " << punkty[0] << "     " << nazwa[1] << ": " << punkty[1] << '\n';
}

void TablicaWynikow::werdykt() {
	if (punkty[0] == 3)
		std::cout << "Wygral " << nazwa[0] << "!\n";
	else
		std::cout << "Wygral " << nazwa[1] << "!\n";

}