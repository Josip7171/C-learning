#include<iostream>
#include<string>
#include<vector>
int main(){
	int broj_vrsta = 0, slatkisa_potrebno = 0, slatkisa_ima = 0, lokator = 0, counter = 0, counter2 = 0, trenutni_vodeci = 0;
	std::string naziv;
	std::vector<std::string>nazivi;
	std::cin>>broj_vrsta;
	for(int i = 0; i < broj_vrsta; i++){
		std::cin >> naziv;
		nazivi.push_back(naziv);
		std::cin>>slatkisa_potrebno >> slatkisa_ima;

		//counter evoluiranih pokemona
		while((slatkisa_ima-slatkisa_potrebno) >= 0){
			slatkisa_ima= (slatkisa_ima - slatkisa_potrebno)+2;
			counter++;			//counter za ukupan broj evolucija
			counter2++;			//counter za broj evolucija trenutnog pokemona
		}

		//lokator pokemona koji se moze najvise puta evoluirati
		if(counter2 > trenutni_vodeci){
			trenutni_vodeci = counter2;
			lokator = i;				//odreduje lokaciju "pobjednickog pokemona" u vectoru
		}
		counter2 = 0;			// novi pokemon, novi counter
	}
	std::cout << counter << std::endl << nazivi[lokator];
}