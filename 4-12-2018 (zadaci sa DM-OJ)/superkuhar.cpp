#include <iostream>
int main()
{
	int tin[9] = {0,0,0,0,0,0,0,0,0}, edi[9] = {0,0,0,0,0,0,0,0,0}, zbroj1 = 0, zbroj2 = 0, unos = 0, j = 0;
	for(int i = 0; i <18; i++){
		if(i < 9){
			std::cin >> edi[i];
		}
		else if(i>= 9 && i < 18){
			std::cin >> tin[j];
			j++;
		}
	}
	for(int i = 0; i < 9; i++){
		zbroj1 += edi[i];
		zbroj2 += tin[i];
	}
	if(zbroj1 == zbroj2){
		std::cout << "Nema pobjednika " << zbroj1;
	}
	else if(zbroj1 > zbroj2){
		std::cout <<"Edi " << zbroj1;
	}
	else{
		std::cout << "Tin " << zbroj2;
	}
}