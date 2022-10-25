#include <iostream>
#include "Arena.h"
#include <time.h>

int main() {
	srand(time(NULL));
	int x;
	std::cout << "Podaj wielkosc boku mapy(od 5 do 30): ";
	std::cin >> x;
	while (std::cin.fail() == true || x > 30 || x < 5) {
		std::cout << "Wykryto blad!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podaj wielkosc boku mapy(od 5 do 30): ";
		std::cin >> x;
	}
	Arena ar(x);
	system("CLS");
	try {
		ar.pojedynek();
	}
	catch (const char* opisBledu) {
		system("CLS");
		std::cout << opisBledu;
		return 0;
	}
	//Arena ar1(ar);
	//Arena ar2(10);
	//ar2 = ar;
	return 0;
}