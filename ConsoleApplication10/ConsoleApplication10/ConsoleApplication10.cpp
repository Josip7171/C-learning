// ConsoleApplication10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

int main() {
	int obaveze_od = 0, obaveze_do = 0, odmor1 = 0, odmor2 = 0;
	std::cin >> obaveze_od >> obaveze_do >> odmor1 >> odmor2;


	if ((odmor1 < obaveze_od && odmor1 > obaveze_do) && (odmor2 > obaveze_od && odmor2 < obaveze_do)) {
		if (odmor1 < odmor2) {
			std::cout << odmor1;
		}
		else {
			std::cout << odmor2;
		}
	}
	else if ((odmor1 > obaveze_od && odmor1 < obaveze_do) && (odmor2 < obaveze_od && odmor2 > obaveze_do)) {
		if (odmor1 < odmor2) {
			std::cout << odmor1;
		}
		else {
			std::cout << odmor2;
		}
	}
	else{
		if (odmor1 < odmor2) {
			std::cout << odmor1;
		}
		else {
			std::cout << odmor2;
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
