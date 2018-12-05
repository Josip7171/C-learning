// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void unos();
void ispis();

int main()
{
	int x = 0;
	do {
		system("cls");
		cout << "IZBORNIK\n1 - Unos novog zapisa\n2 - Ispis svih zapisa\n0 - Izlaz\n\n";
		cin >> x;
		switch (x) {
		case 1:
			system("cls");
			unos();
			break;
		case 2:
			system("cls");
			ispis();
			system("pause");
			break;
		case 0:
			return 0;
		default:
			system("cls");
			cout << "Niste unijeli valjani izbor! Pokusajte ponovo!\n";
		}
	} while (x != 0);
}

void ispis() {
	// ispis podataka iz datoteke
	vector <string> podaci;

	ifstream input("primjer.txt");

	// deklariranje ifstream
	// objekta input
	string line;
	while (input) { // dok ima inputa
		getline(input, line); // input se sprema u line
		podaci.push_back(line); // line se sprema u vector
	}

	input.close(); // zatvaranje stream-a

	for (int i = 0; i < podaci.size() - 1; i++) {
		cout << podaci[i] << endl;
	}
}

void unos() {
	// unos podataka u datoteku
	int id;
	string ime, prezime, za_spremanje;
	cout << "Unesite ID: ";
	cin >> id;
	cin.ignore();   // koristimo jer u streamu situacija
					// izgleda ovako 123\n -> 123 se uèita
					// u int, a \n se uèita u string pa nam
					// getline preskoèi jedan input s ignore()
					// kako bi preskoèio \n, a ne da ga uèita u
					// varijablu

	cout << "Unesite ime: ";
	getline(cin, ime);
	cout << "Unesite prezime: ";
	getline(cin, prezime);

	// priprema za spremanje
	za_spremanje = "\n" + to_string(id) + " " + ime + " " + prezime;

	ofstream output; //stvaranje ofstream objekta output
	output.open("primjer.txt", ios::out | ios::app); // ios:: - flagovi
	output << za_spremanje;
	output.close(); // zatvaranje output-a
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
