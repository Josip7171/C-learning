// zadaci_bootcamp_29_11_2018.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Hello World!\n";
	int x = 1, counter = 0;
	std::cout << "Upisite broj ( \"0\" za izlaz ) : ";
	std::cin >> x;
	counter += x;
	while (x != 0) {
		std::cout << "\nUpisite broj \"0\" za izlaz  : ";
		std::cin >> x;
		counter += x;
	}
	std::cout << "\n\nUkupan zbroj je : " << counter << ".\n";

	std::string lozinka = "123", unos_loz = " ";
	for (int i = 0; i < 3; i++) {
		std::cout << "\nUnesite lozinku (tocna lozinka je \"123\")\n(imate 3 pokusaja, ovo vam je " << i+1 << " pokusaj ) : ";
		std::cin >> unos_loz;
		if (unos_loz == lozinka) {
			std::cout << "\n\nLozinka tocna!";
			break;
		}
		else {
			std::cout << "\n\nLoznika netocna. Pokusajte ponovno.";
		}
	}
	std::cout << "\n\n";

	for (int i = 100; i >0; --i) {
		std::cout << "\n" << i << "bottles of beer on the wall, " << i << "bottles of beer.";
		std::cout << "\nTake one down and pass it around, " << i - 1 << "bottles of beer on the wall.";
	}

	std::cout << "\n\nUnesite koliko brojeva zelite deklarirati : ";
	std::cin >> x;
	for (int i = 1; i <= x; i++) {
		std::cout << "\n" << i * i << ".";
	}

	std::cout << "\n\nTablica mnozenja.. ";

	for (int i = 1; i <= 10; i++) {
		std::cout << "\n" << i;
		for (int j = 1; j <= 10; j++) {
			std::cout << " - " << i * j;
		}
	}

	std::cout << "\n\nZelite beskonacnu petlju? \n1 za DA\n2 za NE \n\t : ";
	std::cin >> x;
	while (x == 1) {
		while (true) {
			std::cout << "BESKONACNA PETLJA ISPIS BROJ " << x;
			x++;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
