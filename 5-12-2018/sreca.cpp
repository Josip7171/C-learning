#include <iostream>
int main()
{
	int broj_ucenika = 0, broj_bombona = 0, counter_srece = 0;
	std::cin >> broj_ucenika;
	for(int i = 1; i <= broj_ucenika; i++){
		std::cin >> broj_bombona;
		if(broj_bombona >= i)
			counter_srece++;
	}
	std::cout << counter_srece;
}