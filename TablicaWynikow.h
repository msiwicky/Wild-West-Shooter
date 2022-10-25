#pragma once
#include <iostream>

class TablicaWynikow {
private:
	int punkty[2];
	std::string nazwa[2];
public:
	TablicaWynikow();
	void zmienPunkty(int _ktory, int _ile);
	void wypisz();
	void werdykt();
	int getPunkty(int _ktory) const { return punkty[_ktory]; };
};
