#include <iostream>
#include <vector>
int main(){
	int broj_unosa = 0, unos = 0, znamenka[4];
	std::vector<int> unosi;
	std::cin>>broj_unosa;
	int konacni_broj[broj_unosa];
	for(int i = 0; i< broj_unosa;i++){
		std::cin >> unos;
		unosi.push_back(unos);
	}

	for(int i = 0; i < broj_unosa; i++){
		unos = unosi[i];
		znamenka[0] = unos / 1000;
		znamenka[1] = (unos - 1000 * znamenka[0])/100;
		znamenka[2] = (unos - 1000 * znamenka[0] - 100 * znamenka[1])/10;
		znamenka[3] = (unos - 1000 * znamenka[0] - 100 * znamenka[1] - 10 * znamenka[2]);

		std::cout << "\nznamenka1 = "<< znamenka[0] << ", znamenka2 = "<< znamenka[1] << ", znamenka3 = " << znamenka[2] << ", znamenka4 = "<< znamenka[3];
		for(int j = 0; j< 4; j++){
			if(znamenka[0] == 0){
				if(znamenka[1] == 0){
					if(znamenka[2] == 0){					//ako je unos npr 5 odnosno 0005
						konacni_broj[i] = znamenka[3];
						j = 5;								//izade iz druge for petlje
					}
					else if(znamenka[2] > znamenka[3]){		//ako je unos 32 odnosno 0032
						konacni_broj[i] = znamenka[3];
						j = 5;	
					}
					else{									//ako je unos 23 odnosno 0023
						konacni_broj[i] = znamenka[2];
						j = 5;	
					}
				}
				else{
					
				}
			}
			else{
				int test_broj = 9;
				for(int k = 0; k < 4; k++){
					if(znamenka[k] < test_broj)
						test_broj = znamenka[k];
				}
			}
			
			//novi pokusaj
			if(znamenka[3] <= znamenka[2] && znamenka[3] <= znamenka[1] && znamenka[3] <= znamenka[0])
			
		}
	}

	//for za provjeru ispis unosa
	for(int i = 0; i< unosi.size(); i++){
		std::cout<<"\n" << unosi[i];
	}
}
