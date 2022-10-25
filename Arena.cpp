#include "Arena.h"
#include <conio.h>
#include <windows.h>
#include "Pistolet.h"
#include "Shotgun.h"
#include "Pocisk.h"

Arena::Arena(int _wielkosc) {
	wielkosc = _wielkosc;
	mapa = new char*[wielkosc];
	for (int i = 0; i < wielkosc; i++)
		mapa[i] = new char[wielkosc];
	generujMape();
	gracze[0].ustawArene(this);
	gracze[1].ustawArene(this);
}

Arena::~Arena() {
	for (int i = 0; i < wielkosc; i++)
		delete[] mapa[i];
	delete[] mapa;
}

Arena::Arena(const Arena& _zrodlo) {
	wielkosc = _zrodlo.wielkosc;
	mapa = new char* [wielkosc];
	for (int i = 0; i < wielkosc; i++)
		mapa[i] = new char[wielkosc];
	for (int i = 0; i < wielkosc; i++)
		for (int j = 0; j < wielkosc; j++)
			mapa[i][j] = _zrodlo.mapa[i][j];
}

Arena& Arena::operator=(const Arena& _zrodlo) {
	if (this == &_zrodlo)	return *this;
	wielkosc = _zrodlo.wielkosc;
	for (int i = 0; i < wielkosc; i++)
		delete[] mapa[i];
	delete[] mapa;
	mapa = new char* [wielkosc];
	for (int i = 0; i < wielkosc; i++)
		mapa[i] = new char[wielkosc];
	for (int i = 0; i < wielkosc; i++)
		for (int j = 0; j < wielkosc; j++)
			mapa[i][j] = _zrodlo.mapa[i][j];
	return *this;
}

void Arena::generujMape() {
	for (int i = 0; i < wielkosc; i++)
		for (int j = 0; j < wielkosc; j++) {
			if (j == 0 || i == 0 || i == wielkosc - 1 || j == wielkosc - 1)
				mapa[i][j] = '#';
			else
				mapa[i][j] = ' ';
		}
}

void Arena::wypisz() {
	for (int i = 0; i < wielkosc; i++) {
		for (int j = 0; j < wielkosc; j++)
			std::cout << mapa[i][j] << ' ';
		std::cout << std::endl;
	}
}

void Arena::aktualizujMape() {
	for (int i = 1; i < wielkosc - 1; i++)
		for (int j = 1; j < wielkosc - 1; j++)
			mapa[i][j] = ' ';
	for (int i = 0; i < gracze[0].getBron()->getWielkoscMag(); i++)
		mapa[gracze[0].getBron()->getPocisk(i).getPolozenieY()][gracze[0].getBron()->getPocisk(i).getPolozenieX()] = gracze[0].getBron()->getPocisk(i).getWyglad();
	for (int i = 0; i < gracze[1].getBron()->getWielkoscMag(); i++)
		mapa[gracze[1].getBron()->getPocisk(i).getPolozenieY()][gracze[1].getBron()->getPocisk(i).getPolozenieX()] = gracze[1].getBron()->getPocisk(i).getWyglad();
	mapa[gracze[0].getPolozenieY()][gracze[0].getPolozenieX()] = gracze[0].getWyglad();
	mapa[gracze[1].getPolozenieY()][gracze[1].getPolozenieX()] = gracze[1].getWyglad();
}

void Arena::pojedynek() {
	Pistolet pistolet1, pistolet2;
	Shotgun shotgun1, shotgun2;
	gracze[0].ustawBron(&pistolet1);
	gracze[1].ustawBron(&pistolet2);
	gracze[0].ruch(wielkosc / 2 - 1, 1);
	gracze[1].ruch(wielkosc / 2 - 1, wielkosc - 2);
	aktualizujMape();
	wypisz();
	tablica.wypisz();
	char znak = ' ';
	while (tablica.getPunkty(0) < 10 && tablica.getPunkty(1) < 10) {
		if(_kbhit())
			znak = _getch();
		switch (znak) {
		case 'a':
			gracze[0].ruch(-1);
			break;
		case 's':
			gracze[0].ruch(0, 1);
			break;
		case 'd':
			gracze[0].ruch(1);
			break;
		case 'w':
			gracze[0].ruch(0, -1);
			break;
		case 'c':
			gracze[0].strzal(1, wielkosc);
			break;
		case 'j':
			gracze[1].ruch(-1);
			break;
		case 'k':
			gracze[1].ruch(0, 1);
			break;
		case 'l':
			gracze[1].ruch(1);
			break;
		case 'i':
			gracze[1].ruch(0, -1);
			break;
		case 'n':
			gracze[1].strzal(-1, wielkosc);
			break;
		default:;
		}
		for (int i = 0; i < gracze[0].getBron()->getWielkoscMag(); i++) {
			if (gracze[0].getBron()->getPocisk(i).getPolozenieX() == 1 || gracze[0].getBron()->getPocisk(i).getPolozenieX() == wielkosc - 2 || gracze[0].getBron()->getPocisk(i).getPolozenieY() == 1 || gracze[0].getBron()->getPocisk(i).getPolozenieY() == wielkosc - 2)
				gracze[0].getBron()->getMag().pop_front();
			else if (gracze[0].getBron()->getPocisk(i).getPolozenieX() == gracze[1].getPolozenieX() && gracze[0].getBron()->getPocisk(i).getPolozenieY() == gracze[1].getPolozenieY()) {
				tablica.zmienPunkty(0, gracze[0].getBron()->getObrazenia());
				gracze[0].getBron()->getPocisk(i).ruch(1, wielkosc);
			}
			else 
				gracze[0].getBron()->getPocisk(i).ruch(1, wielkosc);
		}
		for (int i = 0; i < gracze[1].getBron()->getWielkoscMag(); i++) {
			if (gracze[1].getBron()->getPocisk(i).getPolozenieX() == 1 || gracze[1].getBron()->getPocisk(i).getPolozenieX() == wielkosc - 2 || gracze[1].getBron()->getPocisk(i).getPolozenieY() == 1 || gracze[1].getBron()->getPocisk(i).getPolozenieY() == wielkosc - 2)
				gracze[1].getBron()->getMag().pop_front();
			else if (gracze[1].getBron()->getPocisk(i).getPolozenieX() == gracze[0].getPolozenieX() && gracze[1].getBron()->getPocisk(i).getPolozenieY() == gracze[0].getPolozenieY()) {
				tablica.zmienPunkty(1, gracze[1].getBron()->getObrazenia());
				gracze[1].getBron()->getPocisk(i).ruch(-1, wielkosc);
			}
			else
				gracze[1].getBron()->getPocisk(i).ruch(-1, wielkosc);
		}
		aktualizujMape();
		system("CLS");
		wypisz();
		tablica.wypisz();
		if(tablica.getPunkty(0) > 5)
			gracze[1].ustawBron(&shotgun1);
		if (tablica.getPunkty(1) > 5)
			gracze[0].ustawBron(&shotgun2);
		if (gracze[0].getPolozenieX() == gracze[1].getPolozenieX() && gracze[0].getPolozenieY() == gracze[1].getPolozenieY())
			throw "Gracze nie umieja grac w strzelanki!\n";
		Sleep(50);
		znak = ' ';
	}
	tablica.werdykt();
	Sleep(3000);
}
