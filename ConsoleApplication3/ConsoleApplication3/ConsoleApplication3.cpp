// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>

int main (){
	int kutije[10], unos1 = 0, unos2 = 0, pomocni = 0;

	//unesi lokacije kuglica
	std::cin >> unos1 >> unos2;

	//unesi koje kutije mjenjaju svoja mjesta
	for (int i = 0; i < 10; i++) {
		kutije[i] = 0;
		if (i == unos1)
			kutije[i] = 1;
		if (i == unos2)
			kutije[i] = 1;
	}

	//unosi 5 para vrijednosti
	for (int i = 0; i < 5; i++) {
		std::cin >> unos1 >> unos2;
		pomocni = kutije[unos1];
		kutije[unos1] = kutije[unos2];
		kutije[unos2] = pomocni;
	}

	for (int i = 0; i < 10; i++) {
		if (kutije[i] == 1) {
			std::cout << i << " ";
		}
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
