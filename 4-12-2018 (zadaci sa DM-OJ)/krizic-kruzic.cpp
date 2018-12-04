// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

int main()
{

	char cijeli_unos[9] = { '.', '.', '.', '.', '.', '.', '.', '.', '.' };
	char tabla[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int unos = 0;



	system("cls");
	//crtanje pocetnih tablica i unosa
	for (int i = 1; i < 10; i++) {
		std::cout << tabla[i - 1] << " ";
		if (i % 3 == 0) {
			std::cout << "\n";
		}
	}

	std::cout << "\n";
	//crtanje polja ...
	for (int i = 1; i < 10; i++) {
		std::cout << cijeli_unos[i - 1] << " ";
		if (i % 3 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";



	//for petlja glavni kod za unos
	for (int i = 1; i < 10;i++) {
		if (i % 2 == 0) {								//ako je 'i' paran, upisuje kruzic
			std::cout << "Sad upisuje kruzic : ";
		}
		else if (i % 2 != 0) {							// ako je 'i' neparan upisuje krizic
			std::cout << "Sad upisuje krizic : ";
		}
		std::cin >> unos;
		if (unos <= 9 && unos >= 1 && cijeli_unos[unos-1] == '.') {
			if (i % 2 == 0) {								//ako je 'i' paran, upisuje kruzic
				cijeli_unos[unos - 1] = 'O';
			}
			else if (i % 2 == 1) {							// ako je 'i' neparan upisuje krizic
				cijeli_unos[unos - 1] = 'X';
			}

			system("cls");									//birsanje stare slike i printanje nove azurirane tablice
			for (int i = 1; i < 10; i++) {
				std::cout << tabla[i - 1] << " ";
				if (i % 3 == 0) {
					std::cout << "\n";
				}
			}

			std::cout << "\n";

			for (int i = 1; i < 10; i++) {
				std::cout << cijeli_unos[i - 1] << " ";
				if (i % 3 == 0) {
					std::cout << "\n";
				}
			}

			//ako je pobjedio krizic X
			if ((cijeli_unos[0] == 'X' &&  cijeli_unos[1] == 'X' && cijeli_unos[2] == 'X') || (cijeli_unos[3] == 'X' && cijeli_unos[4] == 'X' && cijeli_unos[5] == 'X')) {
				std::cout << "\n\nKrizic je pobjedio! linija 1-1\n";
				break;
			}
			else if ((cijeli_unos[6] == 'X' &&  cijeli_unos[7] == 'X' && cijeli_unos[8] == 'X') || (cijeli_unos[0] == 'X' && cijeli_unos[3] == 'X' && cijeli_unos[6] == 'X')) {
				std::cout << "\n\nKrizic je pobjedio! linija 1-2\n";
				break;
			}
			else if ((cijeli_unos[1] == 'X' &&  cijeli_unos[4] == 'X' && cijeli_unos[7] == 'X') || (cijeli_unos[2] == 'X' && cijeli_unos[5] == 'X' && cijeli_unos[8] == 'X')) {
				std::cout << "\n\nKrizic je pobjedio! linija 1-3\n";
				break;
			}
			else if ((cijeli_unos[0] == 'X' &&  cijeli_unos[4] == 'X' && cijeli_unos[8] == 'X') || (cijeli_unos[2] == 'X' && cijeli_unos[4] == 'X' && cijeli_unos[6] == 'X')) {
				std::cout << "\n\nKrizic je pobjedio! linija 1-4\n";
				break;
			}

			// Ako je pobjedio kruzic O
			if ((cijeli_unos[0] == 'O' &&  cijeli_unos[1] == 'O' && cijeli_unos[2] == 'O') || (cijeli_unos[3] == 'O' && cijeli_unos[4] == 'O' && cijeli_unos[5] == 'O')) {
				std::cout << "\nKruzic je pobjedio! linija2-1\n";
				break;
			}
			else if ((cijeli_unos[6] == 'O' &&  cijeli_unos[7] == 'O' && cijeli_unos[8] == 'O') || (cijeli_unos[0] == 'O' && cijeli_unos[3] == 'O' && cijeli_unos[6] == 'O')) {
				std::cout << "\nKruzic je pobjedio! linija2-3\n";
				break;
			}
			else if ((cijeli_unos[1] == 'O' &&  cijeli_unos[4] == 'O' && cijeli_unos[7] == 'O') || (cijeli_unos[2] == 'O' && cijeli_unos[5] == 'O' && cijeli_unos[8] == 'O')) {
				std::cout << "\nKruzic je pobjedio! linija2-4\n";
				break;
			}
			else if ((cijeli_unos[0] == 'O' &&  cijeli_unos[4] == 'O' && cijeli_unos[8] == 'O') || (cijeli_unos[2] == 'O' && cijeli_unos[4] == 'O' && cijeli_unos[6] == 'O')) {
				std::cout << "\nKruzic je pobjedio! linija2-5\n";
				break;
			}

		}
		else {
			std::cout << "\nKrivi unos!\n";
			i--;
		}
	}


	//Konacna tablica nakon zavrsetka igre
	std::cout << "\n";
	for (int i = 1; i < 10; i++) {
		std::cout << cijeli_unos[i-1] << " ";
		if (i % 3 == 0) {
			std::cout << "\n";
		}
	}
}
