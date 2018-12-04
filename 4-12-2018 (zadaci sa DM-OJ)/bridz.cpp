#include <iostream>
#include <string>
int main(){
	std::string znakovi;
	int unosa = 0, counter = 0;
	std::cin>> unosa;
	for(int i= 0; i < unosa; i++){
		std::cin>>znakovi;
		for(int j = 0; j < 13; j++){
			if(znakovi[j] == 'A')
				counter += 4;
			else if(znakovi[j] == 'K')
				counter += 3;
			else if(znakovi[j] == 'Q')
				counter += 2;
			else if(znakovi[j] == 'J')
				counter += 1;
		}
	}
	std::cout << counter;
}