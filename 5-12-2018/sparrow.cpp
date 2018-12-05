#include <iostream>
#include <string>
#include <stdint.h>
int main(){
	int counter = 0, char_to_int = 0;
	char barcode[6];
	char barcode_letter = ' ';
	//input barcode
	for(int i = 0; i < 5; i++){
		std::cin >> barcode[i];
	}
	//input barcode letters
	for (int i = 0; i < 5; i++){
		std::cin >> barcode_letter;
		if(barcode_letter == 'D'){
			char_to_int = barcode[i] - '0';
			counter += char_to_int;
		}
	}
	std::cout << counter;
}