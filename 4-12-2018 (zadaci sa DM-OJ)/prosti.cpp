#include <iostream>
#include <cmath>
int main()
{
	int unos = 0, i = 2;
	std::cin >> unos;
	for(; i < sqrt(unos); i++){
		if(unos%i == 0){
			std::cout << "nije prost";
			i = unos+1;
		}
	}
	if(i < unos)
		std::cout << "prost";
}