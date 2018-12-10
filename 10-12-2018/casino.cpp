#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

int give_random(int reminder);
void game_one();
void game_two();
void game_three();



struct User{
	float credit = 5000;
	std::string ime;
	std::string prezime;
	int id;
};
User user_info;


int main (){
	int select = 0;
	std::cout << "Unesite id, vase ime i prezime: ";
	std::cin >> user_info.id >> user_info.ime >> user_info.prezime;
	do{
		system("clear");
		std::cout << "Hi "<< user_info.ime << "! Welcome to CASINO!\nYou Will Shurly LOSE!";
		std::cout << "\nYour credit = " << user_info.credit << ".";
		std::cout << "\n1. Game one\n2. Game two\n3. Game three\n4. Cash Out\n\n: ";
		std::cin >> select;
		switch(select){
			case 1:
			game_one();
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			select = 4;
			break;
			default:
			std::cout << "\n\nPogresan unos!";
			break;
		}
	}while(select != 4);

	system("clear");
	std::cout << "Ukupno ste osvojili " << user_info.credit << " kredita.\n\n";
	system("PAUSE");
	std::string save_data;
	save_data = "\n" + std::to_string(user_info.id) + " " + user_info.ime + " " + user_info.prezime + " - " + std::to_string(user_info.credit);
	std::ofstream output;
	output.open("highscore.txt", std::ios::out | std::ios::app);
	output << save_data;
	output.close();
}



void game_one(){
	std::srand(time(NULL));
	system("clear");
	int input, number1, number2, number3, number4;
	std::cout << "Welcome to Game One!";
	std::cout << "\nFour 1's = 1000 credit\nFour 2's = 2000 credit";
	std::cout << "\nFour 3's = 3000 credit\nFour 4's = 10000 redits!";
	std::cout << "\n1. Spin The Wheel\n2.Leave\n\n: ";
	std::cin >> input;
	while(input == 1){
		for(int i = 0; i < 20; i++){
			number1 = give_random(4);
			number2 = give_random(4);
			number3 = give_random(4);
			number4 = give_random(4);
		}
		system("clear");
		std::cout << "//\t" << number1 << "\t//\t" << number2 << "\t//\t" << number3 << "\t//\t" << number4 << "\t//";

		if(number1 == number2 && number1 == number3 && number1 == number4 && number1 != 4){
			std::cout << "\n\nWIN!\nYou got " << number1 * 1000 << " credits!";
			user_info.credit += (number1*1000);
		}
		else if(number1 == number2 && number1 == number3 && number1 == number4 && number1 == 4){
			std::cout << "\n\nWIN!\nYou got " << number1 * 2500 << " credits!";
			user_info.credit += (number1*2500);
		}
		else{
			std::cout << "\n\nLose.\nYou lost 50 credits!";
			user_info.credit -= 50;
			std::cout << "\nTotal credit = " << user_info.credit << ".";
		}
		std::cout << "\n\nRepeat?\n1. Yes\n2. No\n\n: ";
		std::cin >> input;
	}
}


void game_two(){

}


void game_three(){

}


int give_random(int reminder = 4){
	return (std::rand() % reminder + 1);
}