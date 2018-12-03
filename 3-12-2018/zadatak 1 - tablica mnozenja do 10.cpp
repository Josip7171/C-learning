#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	int tab_mno[10][10];

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			tab_mno[i][j] = (i+1) * (j+1);
		}
		std::cout << std::endl;
	}

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			std::cout << tab_mno[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
