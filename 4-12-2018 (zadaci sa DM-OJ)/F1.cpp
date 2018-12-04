#include <iostream>
int main()
{
	float unos_niza[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int unos1 = 0, unos2 = 0, i = 0;
	for(; i<15; i++){
		std::cin >> unos_niza[i];
		if(unos_niza[i] == 0){
			std::cin >> unos1;
			std::cin >> unos2;
			break;
		}
	}
	std::cout << float(unos_niza[i-unos2+1])-unos_niza[i-unos1+1];
}