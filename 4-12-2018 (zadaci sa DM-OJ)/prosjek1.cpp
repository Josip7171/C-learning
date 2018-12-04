#include <iostream>
#include <iomanip>
int main (){
	int unos = 2, counter = 0, zbroj_ocjena = 0;
	while(unos > 1){
		std::cin >> unos;
		if(unos == 1)
			std::cout << 1;
		else if(unos == 0)
			std::cout << std::fixed << std::setprecision(2) << float(zbroj_ocjena)/counter;
		zbroj_ocjena += unos;
		counter++;
	}
}