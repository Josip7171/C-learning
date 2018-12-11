// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>


void menu();
void zadatak1(int counter);
void zadatak2(int counter);
void zadatak3(int numb_r);
void zadatak4(int input, int solution);
void zadatak5(int input, int number1, int number2);

int main()
{
	menu();
}

void menu() {
	int input = 1, counter = 0, input_4, solution = 0;
	int numb_r = 0;
	int number1 = 0, number2 = 0;
	do {
		system("cls");
		std::cout << "1. Rekurzivna funkcija koja ispisuje brojeve od manjeg prema vecem";
		std::cout << "\n2. Rekurzivna funkcija koja ispisuje brojeve od veceg prema manjem";
		std::cout << "\n3. Beskonacna petlja rekurzivne funkcije";
		std::cout << "\n4. Rekurzivna funkcija broja po zelji";
		std::cout << "\n0. Izlaz";
		std::cout << "\n\n: ";
		std::cin >> input;
		switch (input) {
		case 1:
			std::cout << "\nUnesite koliko brojeva zelite ispisati : ";
			std::cin >> counter;
			zadatak1(counter);
			system("PAUSE");
			break;
		case 2:
			std::cout << "\nUnesite koliko brojeva zelite ispisati : ";
			std::cin >> counter;
			zadatak2(counter);
			system("PAUSE");
			break;
		case 3: 
			std::srand(time(NULL));
			zadatak3(numb_r);
			system("PAUSE");
			break;
		case 4: 
			std::cout << "\nUnesite broj na kojemu zelite izracunati rekurzivnu funkciju : ";
			std::cin >> input_4;
			solution = 1;
			zadatak4(input_4, solution);
			system("PAUSE");
			break;
		case 5:
			std::cout << "\nUnesite koji element u nizu zelite ispisati (niz je fibonaccijev) : ";
			std::cin >> input_4;
			zadatak5(input_4, number1, number2);
			system("PAUSE");
			break;
		case 0:
			break;
		}
	} while (input != 0);
	system("PAUSE");
}

void zadatak1(int counter) {
	counter--;
	if (counter > 0) {
		zadatak1(counter);
	}
	std::cout << counter + 1 << std::endl;
}

void zadatak2 (int counter) {
	counter--;
	std::cout << counter + 1 << std::endl;
	if (counter > 0) {
		zadatak2(counter);
	}
}


void zadatak3(int numb_r) {
	numb_r = rand() % 10 +1;
	std::cout << numb_r << " :) ";
	zadatak3(numb_r);
}


void zadatak4(int input, int solution) {
	if (input > 0) {
		solution *= input;
		input--;
		zadatak4(input, solution);
	}
	std::cout << solution << std::endl;
}


void zadatak5(int input, int number1, int number2) {

}





