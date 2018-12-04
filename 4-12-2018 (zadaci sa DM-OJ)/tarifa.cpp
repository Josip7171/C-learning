#include <iostream>
int main (){
	int mb = 0, mj = 0, unos, ukupno = 0;
	std::cin>> mb >>mj;
	for(int i = 0; i < mj; i++){
		std::cin>> unos;
		ukupno = ukupno + (mb- unos);
	}
	std::cout << ukupno+mb;
}