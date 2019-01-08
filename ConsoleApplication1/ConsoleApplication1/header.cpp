#include "pch.h"
#include <iostream>
#include "header.h"


void Zivotinja::kretnja_naprijed() {
	std::cout << "\nKoliko koraka? : ";
	std::cin >> broj_koraka;
	std::cout << "\nKrecem se " << broj_koraka << " naprijed.\n";
}

void Zivotinja::okret_ljevo() {
	std::cout << "\nKoliko stupnjeva? : ";
	std::cin >> stupnjeva;
	std::cout << "\nOkrecem se za " << stupnjeva << " ljevo.\n";
}

void Zivotinja::okret_desno() {
	std::cout << "\nKoliko stupnjeva? : ";
	std::cin >> stupnjeva;
	std::cout << "\nOkrecem se za " << stupnjeva << " desno.\n";
}

