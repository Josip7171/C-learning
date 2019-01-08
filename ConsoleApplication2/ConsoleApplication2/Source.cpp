#include "pch.h"
#include <iostream>
#include "Header1.h"
#include <string>

//ZADATAK 1
void Kocka::otvori() {
	std::cout << "\nUnesite dimenzije kocke (1. visina 2.sirina 3.duzina): ";
	std::cin >> visina >> sirina >> dubina;
	std::cout << "\nKocka dimenzija " << visina << ", " << sirina << ", " << dubina << " je otvorena... \n";
}

void Kocka::zatvori() {
	std::cout << "\nKocka dimenzija " << visina << ", " << sirina << ", " << dubina << " je zatvorena... \n";
}



//ZADATAK 2
void Automobil::upali() {
	std::cout << "\nAutomobil marke" << marka << " je upaljen!\n";
}

void Automobil::ugasi() {
	std::cout << "\nAutomobil marke" << marka << " je ugasen!\n";
}
void Automobil::ubrzaj() {
	std::cout << "\nAutomobil marke" << marka << ", modela " << model << " je ubrzao!\n";
}
void Automobil::uspori() {
	std::cout << "\nAutomobil marke" << marka << ", modela " << model << " je usporio!\n";
}

std::string Automobil::get() {
	std::cout << "\n\n(1) za marku\n(2) za model\n(3) za broj sasije \n: ";
	int input = 0;
	std::cin >> input;
	switch (input) {
	case 1:
		return marka;
		break;
	case 2:
		return model;
		break;
	case 3:
		return broj_sasije;
		break;
	default:
		break;
	}

}
void Automobil::set() {
	std::cout << "\n\nUnesite ime marke : ";
	std::cin >> marka;
	std::cout << "\n\nUnesite model : ";
	std::cin >> model;
	std::cout << "\n\nUnesite broj sasije : ";
	std::cin >> broj_sasije;
	system("cls");
}

