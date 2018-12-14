#include <iostream>
int main (){
	int gems_a = 0, gems_b = 0, number_of_rounds = 0, counter_a = 0, counter_b = 0;
	char point = ' ';
	//upisi gemove prvog i drugog igraca
	std::cin >> gems_a >> gems_b;
	//upisi broj rundi
	std::cin >> number_of_rounds;
	for(int i = 0; i < number_of_rounds; i++){
		std::cin>>point;
		if(point == 'A'){
			counter_a += 15;
			if(counter_a == 45)
				counter_a -= 5;
			if(counter_a == 130){
				gems_a++;
				counter_a = 0;
				counter_b = 0;
			}
			if(counter_a == 55 && counter_b < 40){
				gems_a++;
				counter_a = 0;
				counter_b = 0;
			}
			else if(counter_a == 55 && counter_b >= 40){
				counter_a = 115;
				counter_b = 100;
			}
		}
		else if(point == 'B'){
			counter_b += 15;
			if(counter_b == 45)
				counter_b -= 5;
			if(counter_b == 130){
				gems_b++;
				counter_a = 0;
				counter_b = 0;
			}
			if(counter_b == 55 && counter_a < 40){
				gems_b++;
				counter_a = 0;
				counter_b = 0;
			}
			else if(counter_b == 55 && counter_a >= 40){
				counter_a = 100;
				counter_b = 115;
			}
		}
		if(counter_a == 40 && counter_b == 40 && i != number_of_rounds-1){
			counter_a = 100;
			counter_b = 100;
		}
		if(counter_a == 115 && counter_b == 115){
				counter_a = 100;
				counter_b = 100;
			}
	}

	std::cout << gems_a << ":" << gems_b << " ";
	if(counter_a == 100 && counter_b == 100){
		std::cout << "deuce";
	}
	else if(counter_a == 100 && counter_b == 115){
		std::cout << "AD-B";
	}
	else if(counter_a == 115 && counter_b == 100){
		std::cout << "AD-A";
	}
	else{
		std::cout <<counter_a << ":" << counter_b;
	}
}