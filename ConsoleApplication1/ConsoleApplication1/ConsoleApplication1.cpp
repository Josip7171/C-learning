// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

int main()
{
	int broj_prepreka = 0, unos, counter = 0, prvi_najveci_skok = 29999, prva_prepreka = 29999, prva_dupla = 29999, dupla_prepreka = 0;
	std::vector<int> polja_prepreka; 

	//unos broja prepreka, unos lokacija prepreka
	std::cin >> broj_prepreka;
	for (int i = 0; i < broj_prepreka; i++) {
		std::cin >> unos;
		polja_prepreka.push_back(unos);
		if (prva_prepreka < unos)
			prva_prepreka = unos;
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
