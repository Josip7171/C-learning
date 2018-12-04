#include <iostream>
int main()
{
	int unos = 0;
	std::cin >> unos;
	for(int i = 2; i <= unos; i+=2){
		std::cout << i << std::endl;
	}
}