// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>



int give_random(int reminder, int corrector);
void game_one();
void game_two();
void game_three();
void game_four();
void call_it_quits();
void gui();
void show_highscore();
char randoms_to_chars(int value);
void double_or_nothing_calc(int &price);
char number_to_kind(int number);
void deck_converter(int &value, char &kind);
void game_four2(int &price, int deck[]);
void menu();
void buy_in();
void money_to_chips();
void start();


struct User {
	int credit = 0;
	int chips = 0;
	std::string ime = "?";
	int id = 0;
};
User user_info;


int main() {
	start();
	buy_in();
	menu();
}

void menu() {
	std::srand(time(NULL));
	int select = 0;
	do {
		gui();
		std::cout << "\n1. Game one\n2. Game two\n3. Game three\n4. Game four\n5. Show Highscore\n6. Change Money\n0. Cash Out\n\n: ";
		std::cin >> select;
		switch (select) {
		case 0:
			select = 0;
			break;
		case 1:
			game_one();
			break;
		case 2:
			game_two();
			break;
		case 3:
			game_three();
			break;
		case 4:
			game_four();
			break;
		case 5:
			show_highscore();
			break;
		case 6:
			money_to_chips();
		default:
			std::cout << "\n\nPogresan unos!";
			break;
		}
	} while (select != 0);

	call_it_quits();
}


void start() {
	gui();
	std::cout << "Unesite ime : ";
	std::cin >> user_info.ime;
	std::cout << "\nUnesite ID : ";
	std::cin >> user_info.id;
}

void buy_in() {

	gui();
	do {
		std::cout << "\nKoliko novca zelite uloziti? : ";
		std::cin >> user_info.credit;
		if (user_info.credit > 5000 || user_info.credit <= 0) {
			std::cout << "\nPises cifre koje nemas.. Daj nesto realnije.. : ";
			user_info.credit = 0;
		}
		else if (user_info.credit == 5000) {
			gui();
			std::cout << "\nNakon sto uplatite taj iznos na tekuci HR171773000045145 mozes poceti igrati.\n";
			user_info.credit = 5000;
		}
		else {
			gui();
			std::cout << "\nKakva je to jadna cifra... evo ti 5000 kn.\n";
			user_info.credit = 5000;
		}
	} while (user_info.credit > 5000 || user_info.credit <= 0);
	system("PAUSE");
}

void money_to_chips() {

	gui();
	int amount = 5001;
	if (user_info.credit == 0) {
		std::cout << "\nBrate, nemas kinte.\n";
		amount = 0;
	}
	while (amount > user_info.credit) {
		std::cout << "5 kuna = 1 chip.\nKoliko zelis promjeniti? : ";
		std::cin >> amount;
		if (amount > user_info.credit || amount < 0)
			std::cout << "\nAlo brate.. imas samo " << user_info.credit << ".\n";
		else if (amount <= user_info.credit && amount >= 0) {
			user_info.credit -= amount;
			user_info.chips += (amount / 5);
			amount = 0;
		}
	}
	system("PAUSE");
}




void game_one() {
	gui();
	int input, number1, number2, number3, number4, wager = 0;
	std::cout << "\nWelcome to Game One!";
	std::cout << "\nFour +'s = 1 * wager * 10 chips\nFour X's = 1 * wager * 10 chips";
	std::cout << "\nFour *'s = 1 * wager * 10 chips\nFour 7's = 2 * wager * 777 chips!";
	std::cout << "\n\n1. Play\n2. Leave\n\n: ";
	std::cin >> input;
	while (input == 1 && user_info.chips > 1) {
		std::cout << "\nPlace your bet : ";
		std::cin >> wager;
		if (wager <= user_info.chips) {
			user_info.chips -= wager;
			std::cout << "\n\nLet's LOSE some CHIPS!";
			std::cin.ignore();
			for (int i = 0; i < 5; i++) {
				number1 = give_random(4, 1);
				number2 = give_random(4, 1);
				number3 = give_random(4, 1);
				number4 = give_random(4, 1);
			}
			gui();
			std::cout << "//\t" << randoms_to_chars(number1) << "\t//\t" << randoms_to_chars(number2) << "\t//\t" << randoms_to_chars(number3) << "\t//\t" << randoms_to_chars(number4) << "\t//";

			if (number1 == number2 && number1 == number3 && number1 == number4 && number1 != 4) {
				std::cout << "\a\n\nWIN!\nYou got " << wager * 10 << " credits!";
				user_info.chips += (wager * 10);
			}
			else if (number1 == number2 && number1 == number3 && number1 == number4 && number1 == 4) {
				std::cout << "\a\n\nWIN!\nYou got " << 2 * wager * 777 << " credits!";
				user_info.chips += (2 * wager * 777);
			}
			else {
				std::cout << "\n\nLose.\nYou lost! ";
				std::cout << "\nChips Left : " << user_info.chips << ".";
			}
			std::cout << "\n\n1. Play\n2. Leave\n\n: ";
			std::cin >> input;
		}
		else std::cout << "\n\nYou dont have enough chips! (" << user_info.chips << ")";
	}
}

void game_two() {
	int input = 0, wager = 0, winning_number = 0, choice = 0;
	std::vector<int> inputs, wagers;
	gui();
	std::cout << "\nThis is Roulette!\n";
	std::cout << "\nYou Get Your Wager * 36 If You Guess A Number\n\n1. PLAY\n2. LEAVE\n: ";
	std::cin >> choice;
	do {
		gui();
		std::cout << "\nYour Total Wages : \n";
		for (int i = 0; i < inputs.size(); i++) {
			std::cout << "Number " << inputs[i] << " = " << wagers[i] << " Chips. \n";
		}
		std::cout << "\nChose a number from 0 to 36 ( enter 37 to start the game ) : ";
		std::cin >> input;
		if (input <= 36 && input >= 0) {
			std::cout << "\nPlace Your Bet On That Number " << input << " (You have " << user_info.chips << " Chips) : ";
			std::cin >> wager;
			if (wager < 0 && wager >= user_info.chips) {
				std::cout << "\n\n You do not have enough chips!";
			}
			else {
				user_info.chips -= wager;
				inputs.push_back(input);
				wagers.push_back(wager);
			}
		}
		else std::cout << "\n\nInvalid input. Try Again";

	} while (choice != 2 && input != 37 && user_info.chips > 0);

	if (input == 37 && wagers.size() == inputs.size()) {
		winning_number = give_random(36, 0);
		for (int i = 0; i < inputs.size(); i++) {
			if (inputs[i] == winning_number) {
				std::cout << "\nYour wagers : \n";
				for (int i = 0; i < inputs.size(); i++)
					std::cout << "Number " << inputs[i] << " = " << wagers[i] << " credits. \n";
				std::cout << "\n\n\aYou Won!\nWinning number is " << winning_number << " and you put wage of " << wagers[i] << " credits.";
				std::cout << "\nYou got " << wagers[i] * 36 << " credits! (You have " << user_info.chips << " credits. ";
				user_info.credit += (wagers[i] * 36);
			}
			else {
				std::cout << "\n\nNumber droped is " << winning_number << ". ";
				std::cout << "\n\nYour wagers : \n";
				for (int i = 0; i < inputs.size(); i++) {
					std::cout << "Number " << inputs[i] << " = " << wagers[i] << " chips. \n";
				}
				std::cout << "\nYou lose. \nTry again! You will surely lose!\n";
			}
		}
	}
	system("PAUSE");
}

void game_three() {
	gui();
	int wager = 0, game_runner = 1, house_number1 = 0, house_number2 = 0, given_number1 = 0, given_number2 = 0;
	std::cout << "\nThrow Two Dices Game!";
	std::cout << "\nIf WIN You Get Your Bet * 2\nIf You Get 12 You Get Your Bet * 12";
	std::cout << "\nIf DRAW You get Your Chips back!";
	std::cout << "\nIf LOSE You lose Your Chips!";
	std::cout << "\n\n1. PLAY\n2. LEAVE\n: ";
	std::cin >> game_runner;
	while (game_runner == 1) {
		gui();
		std::cout << "\n\nPlace Your Bet : ";
		std::cin >> wager;
		if (wager > user_info.chips) {
			std::cout << "\n\nNot enough chips!";
			break;
		}
		else {
			user_info.chips -= wager;
			house_number1 = give_random(6, 1);
			std::cout << "\nHouse got " << house_number1 << "!\n";
			system("PAUSE");
			given_number1 = give_random(6, 1);
			std::cout << "\nYou got " << given_number1 << "!\n";
			system("PAUSE");
			house_number2 = give_random(6, 1);
			std::cout << "\nHouse got " << house_number2 << "!\n";
			system("PAUSE");
			given_number2 = give_random(6, 1);
			std::cout << "\nYou got " << given_number2 << "!\n";
			system("PAUSE");
			if ((house_number1 + house_number2) < (given_number1 + given_number2)) {
				if ((given_number2 + given_number1) == 12) {
					std::cout << "\nBig Win!\nWon chips : " << wager * 12 << "!";
					user_info.chips += wager * 12;
				}
				else {
					std::cout << "\n\nYou Got " << (given_number1 + given_number2) << " and House Got " << house_number1 + house_number2 << "!";
					std::cout << "\nYou Win!\nWon chips : " << wager * 2;
					user_info.chips += wager + (wager * 2);
				}
			}
			else if ((house_number1 + house_number2) > (given_number1 + given_number2)) {
				std::cout << "\n\nYou Got " << (given_number1 + given_number2) << " and House Got " << house_number1 + house_number2 << "!";
				std::cout << "\nYou Lose!\n";
			}
			else if ((house_number1 + house_number2) == given_number1 + given_number2) {
				std::cout << "\n\nYou Got " << (given_number1 + given_number2) << " and House Got " << house_number1 + house_number2 << "!";
				std::cout << "\nDraw!\n";
				user_info.chips += wager;
			}
			else {
				std::cout << "\n\nWrong input!\n";
			}
			std::cout << "\n\n1.PLAY\n2.LEAVE\n: ";
			std::cin >> game_runner;
		}
	}
}

void game_four() {
	gui();
	int deck[52], random_card, random_card2;
	char kind;
	for (int i = 0; i < 52; i++) deck[i] = i + 1;
	int input = 0, wager = 0;
	std::cout << "\nThis Is Double Or Nothing!";
	std::cout << "\nYou Draw One Card and House Draws One Card.\nHigher Card Wins.\nAfter Win, Chose to Go For Double Or Quit!\n1.PLAY 2. LEAVE\n: ";
	std::cin >> input;
	while (input != 2) {
		gui();
		std::cout << "\nInput Your Wager : ";
		std::cin >> wager;
		if (wager <= user_info.chips) {
			user_info.chips -= wager;

			random_card = give_random(52, 1);
			while (random_card == 0) random_card = give_random(52, 1);
			deck_converter(random_card, kind);
			std::cout << "\nYou Got " << random_card << " " << kind << ".";
			deck[random_card] = 0;

			random_card2 = give_random(52, 1);
			while (random_card2 == 0) random_card = give_random(52, 1);
			deck_converter(random_card2, kind);
			std::cout << "\nHouse Got " << random_card2 << " " << kind << ".";
			deck[random_card2] = 0;

			while (random_card > random_card2) {
				std::cout << "\n\nYou Win!\n";
				wager *= 2;
				std::cout << "\nYou Won " << wager << " chips.";
				std::cout << "\nDouble Or Nothing? 1.YES 2.NO : ";
				std::cin >> input;
				if (input == 1) {
					gui();
					random_card = give_random(52, 1);
					while (random_card == 0) random_card = give_random(52, 1);
					deck_converter(random_card, kind);
					std::cout << "\nYou Got " << random_card << " " << kind << ".";
					deck[random_card] = 0;

					random_card2 = give_random(52, 1);
					while (random_card2 == 0) random_card = give_random(52, 1);
					deck_converter(random_card2, kind);
					std::cout << "\nHouse Got " << random_card2 << " " << kind << ".";
					deck[random_card2] = 0;
				}

				if (input == 2) {
					user_info.chips += wager;
					wager = 0;
					gui();
					break;
				}
			}
			if (random_card < random_card2) {
				std::cout << "\n\nYou Lose!\n";
			}
			else if (random_card == random_card2) {
				std::cout << "\n\nDraw.\n";
				user_info.chips += wager;
			}
			std::cout << "\n\n1. PLAY\n2. LEAVE\n\n: ";
			std::cin >> input;
		}
		else std::cout << "\nYou Do Not Have Enough Chips!\n";
	}
	std::cout << std::endl;
	system("PAUSE");
}




int give_random(int reminder = 4, int corrector = 1) {
	return (std::rand() % reminder + corrector);
}

void call_it_quits() {
	gui();
	std::cout << "\n\nUkupno ste osvojili " << user_info.chips << " Chipova.\n\n";
	system("PAUSE");
	std::string save_data;
	save_data = "\n" + std::to_string(user_info.id) + " " + user_info.ime + " - " + std::to_string(user_info.chips);
	std::ofstream output;
	output.open("highscore.txt", std::ios::out | std::ios::app);
	output << save_data;
	output.close();
}

void gui() {
	system("cls");	//system("clear"); // for linux
	std::cout << "CASINO Games! You Can NOT win " << user_info.ime << "!";
	std::cout << "\nYour MONEY : " << user_info.credit << " --- Your CHIPS : " << user_info.chips;
	std::cout << "\n--C--A--S--I--N--O--O--O--O--O--O--O--O--O--O--O-- \n\n";
}

void show_highscore() {
	gui();
	std::vector<std::string> data;
	std::string line;
	std::ifstream input("highscore.txt");
	while (input) {
		std::getline(input, line);
		data.push_back(line);
	}

	input.close();
	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << std::endl;
	}
	system("PAUSE");
}

char randoms_to_chars(int value) {
	switch (value) {
	case 1:
		return '+';
	case 2:
		return 'X';
	case 3:
		return '*';
	case 4:
		return '7';
	default:
		break;
	}
}

char number_to_kind(int number) {
	switch (number) {
	case 1:
		return 'H';
	case 2:
		return 'T';
	case 3:
		return 'P';
	case 4:
		return 'K';
	default:
		break;
	}
}

void deck_converter(int &value, char &kind) {
	int *p_value = &value;
	char *p_kind = &kind;
	if (value <= 13) {
		*p_value = value;
		*p_kind = 'H';
	}
	else if (value > 13 && value <= 26) {
		*p_value = value % 13 + 1;
		*p_kind = 'D';
	}
	else if (value > 26 && value <= 39) {
		*p_value = value % 13 + 1;
		*p_kind = 'S';
	}
	else if (value > 39 && value <= 51) {
		*p_value = value % 13 + 1;
		*p_kind = 'C';
	}
}
