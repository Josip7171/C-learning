// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int var1 = 0, var2 = 0, var3 = 0;
	std::cout << &var1 << ", " << &var2 << ", " << &var3 << ".\n";
	std::cout << "\n\nUnesi broj polja : ";
	int broj_polja;
	std::cin >> broj_polja;

	int *polje = new int[broj_polja];

	for (int i = 0; i < broj_polja; i++) {
		std::cin >> polje[i];
		if (i == broj_polja - 1) {
			std::cout << "\nUpisite novi broj polja : ";
			std::cin >> broj_polja;
			delete polje;
			polje = new int[broj_polja];
			i = -1;
		}
	}

	std::cout << "\n";
	for (int i = 0; i < broj_polja; i++) {
		std::cout << polje[i] << "\t";
	}
}








