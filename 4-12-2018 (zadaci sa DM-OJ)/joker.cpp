#include <iostream>
int main()
{
	int dobitni[6], unos = 0, igrani_brojevi[3], y = 0, broj = 0;
	int dobitni_counter1 = 0;
	int znamenka[6];

	//Unos 6 cijelih brojeva i odredivanje jednog konacnog 6znamenkastog dobitnog broja
	for(int i = 0; i<6; i++){
		std::cin >> unos;
		y = unos - ((unos/10)*10);
		dobitni[i] = y;
	}

	//unos 3 igrane kombinacije
	for(int i = 0; i < 3; i++){
		std::cin>>igrani_brojevi[i];
	}

	//Rasclani igrani broj na zasebne znamenke radi usporedbe sa dobitnom kombinacijom
	for (int i = 0; i < 3; i++){
		broj = igrani_brojevi[i];
		znamenka[0] = broj/100000;
		znamenka[1] = (broj - znamenka[0]*100000)/10000;
		znamenka[2] = (broj - znamenka[0]*100000 - znamenka[1]*10000)/1000;
		znamenka[3] = (broj - znamenka[0]*100000 - znamenka[1]*10000 - znamenka[2]*1000)/100;
		znamenka[4] = (broj - znamenka[0]*100000 - znamenka[1]*10000 - znamenka[2]*1000 - znamenka[3]*100)/10;
		znamenka[5] = (broj - znamenka[0]*100000 - znamenka[1]*10000 - znamenka[2]*1000 - znamenka[3]*100 - znamenka[4]*10);

		//usporedi dobitnu kombinaciju sa igranim kombinacijama
		//ako je ista uvecaj counter za jedan i tako za svaki broj iz 6znamenkastog broja
		for(int j = 5; j >= 0; j-=1){
			if(dobitni[j] == znamenka[j]){
				dobitni_counter1++;
			}
		}

		//ispisi rezultat
		if(dobitni_counter1 <2)
			std::cout << "Nedobitan" << std::endl;
		else if(dobitni_counter1==2)
			std::cout << "V. vrsta" << std::endl;
		else if (dobitni_counter1==3)
			std::cout << "IV. vrsta" << std::endl;
		else if (dobitni_counter1==4)
			std::cout << "III. vrsta" << std::endl;
		else if (dobitni_counter1==5)
			std::cout << "II. vrsta" << std::endl;
		else if (dobitni_counter1==6)
			std::cout << "I. vrsta" << std::endl;

		//vrati counter na 0 nakon evaluacije jednog igranog broja
		dobitni_counter1 = 0;
	}
}
