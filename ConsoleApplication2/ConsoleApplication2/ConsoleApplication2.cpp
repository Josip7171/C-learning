// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int konacni_broj1 = 0, konacni_broj2 = 0, unos = 0, broj[5];
	for (int i = 0; i < 5; i++) {
		std::cin >> unos;
		broj[i] = unos;
		konacni_broj1 += unos;
	}
	std::cin >> unos;
	for (int i = 0; i < 4; i++) {
		if((((broj[0] + broj[1]) - broj[2]) * broj[3]) / broj[4]){
			konacni_broj2 = (((broj[0] + broj[1]) - broj[2]) * broj[3]) / broj[4];
	}
	konacni_broj2 = (((broj[0] + broj[1]) - broj[2]) * broj[3]) / broj[4];
	if (konacni_broj1 == unos) {
		std::cout << broj[0] << "+" << broj[1] << "+" << broj[2] << "+" << broj[3] << "+" << broj[4] << "=" << unos;
	}
	else if (konacni_broj2 == unos) {
		std::cout << broj[0] << "+" << broj[1] << "-" << broj[2] << "*" << broj[3] << "/" << broj[4] << "=" << unos;
	}
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
