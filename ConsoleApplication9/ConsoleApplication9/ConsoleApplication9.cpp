// ConsoleApplication9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main() {
	int a = 0, x = 0;
	std::cin >> a;
	while (x == 0 && (a == 1 || a == 2 )) {
		std::cout << "8";
		x++;
	}
	while (x == 0 && (a == 3 || a == 4)) {
		std::cout << "5";
		x++;
	}
	while (x == 0 && (a == 5 || a == 6)) {
		std::cout << "4";
		x++;
	}
	while (x == 0 && (a == 7 || a == 8)) {
		std::cout << "1";
		x++;
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
