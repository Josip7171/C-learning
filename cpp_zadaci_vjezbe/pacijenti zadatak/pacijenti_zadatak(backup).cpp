#include <iostream>
#include <iostream>
#include<vector>
#include<string>
#include <fstream>

//struktura koja ce sadrzavati sve o pacijentu
struct Pacijent {
	std::string MBO;
	std::string ime;
	std::string prezime;
	std::vector <std::string> popis_ljekova;
};


//deklaracije svih potrebnih funkcija
void ucitaj_sve(std::vector<Pacijent> &pacijent1);
void unos_pacijenta(std::vector<Pacijent> &pacijent1);
void ispis_pacijenata(std::vector<Pacijent> &pacijent1);
void pretrazi_po_MBO(std::vector<Pacijent> &pacijent1);
void dodaj_recept(std::vector <Pacijent> &pacijent1);


int main()
{
	std::vector<Pacijent> pacijent1;			//stvorimo vektor struktura koji cemo puniti i koristiti za manipulaciju podataka
	int input = 1;
	while (input != 0) {						//izbornik
		system("cls");
		ucitaj_sve(pacijent1);					//sve podatke iz .txt filea ucitaj u vektor strukture za daljnje koristenje
		std::cout << "\n\nMenu..\n1. Unos novih pacijenata\n2. ispis svih pacijenata";
		std::cout << "\n3. Pretraga pacijenata po MBO\n4. Sustav cekaonice\n";
		std::cout << "5. Dodavanje recepata za ljekove na korisnicki racun pacijenata\n0. Izlaz\n\n: ";
		std::cin >> input;

		switch (input) {
		case 0:
			break;
		case 1:
			unos_pacijenta(pacijent1);
			break;
		case 2:
			ispis_pacijenata(pacijent1);
			break;
		case 3:
			pretrazi_po_MBO(pacijent1);
			break;
		case 4:
			break;
		case 5:
		dodaj_recept(pacijent1);
			break;
		default:
			break;
		}
	}
}

//funkcija da se podaci ucitaju iz .txt datoteke u vektor strukture za koristenje i manipulaciju podataka
void ucitaj_sve(std::vector <Pacijent> &pacijent1) {
	std::ifstream input("pacijenti.txt");				//stvori vezu izmedu txt filea i programa
	pacijent1.clear();									//izbrisi sve iz vektora pa ga napuni sa podacima iz .txt
	std::string lijek;
	std::string temp = "";
	int counter = 0;
	Pacijent pacijent;

	while (input) {										//Dok ima podataka u txt fileu, vrti naredbe....
		if (counter == 0) {								//Posto radimo sa strukturom, neka se popunjava struktura po redu
			std::getline(input, pacijent.MBO);
			counter++;
		}
		else if (counter == 1) {
			std::getline(input, pacijent.ime);
			counter++;
		}
		else if (counter == 2) {
			std::getline(input, pacijent.prezime);
			counter++;
		}
		else if (counter == 3) {							//ovdje se odvoja jedan string ljekova na zasebne stringove
															//za daljnju laksu manipulaciju sa podacima (brisanje, dodavanje, izmjena)
			std::getline(input, lijek);
			for (int i = 0; i < lijek.size(); i++)
				if (lijek[i] != ' ')						//odredi separator, u ovom slucaju je razmak!
					temp += lijek[i];						//u "temp" spremaj cijelu rijec od razmaka do razmaka
				else if (lijek[i] == ' ') {
					pacijent.popis_ljekova.push_back(temp);	//kada nades razmak to je kraj naziva lijeka, pushaj tu rijec
					temp = "";								//postavi "temp" na prazno za sljedeci krug
				}
			temp = "";
			counter = 0;									//postavi counter na 0 da se sljedeca struktura popunjava
			pacijent1.push_back(pacijent);					//pushaj pacijent(struktura) u pacijent1(vektor struktura)
			pacijent.popis_ljekova.clear();					//isprazni vektor unutar strukture da sljedeceg pacijenta bude prazan
		}
	}

	input.close();											//prekini vezu sa txt fileom

}


//Ovdje se izvrsava unos novih pacijenata, dodaju se na stari popis
void unos_pacijenta(std::vector<Pacijent> &pacijent1) {
	system("cls");
	Pacijent pacijent;
	std::string ljekovi = "";
	std::cout << "Unesite MBO : ";
	std::cin >> pacijent.MBO;
	std::cout << "\nUnesite ime : ";
	std::cin >> pacijent.ime;
	std::cout << "\nUnesite prezime : ";
	std::cin >> pacijent.prezime;
	std::cout << "\nUnesite ljekove (\"stop\" za izlaz) : ";
	while (ljekovi != "stop"){									//unos ljekova, unos "stop" prekida unos i kod se nastavlja
		std::cin >> ljekovi;
		if (ljekovi != "stop")
			pacijent.popis_ljekova.push_back(ljekovi);
	}


	for(int i = 0; i < pacijent1.size(); i++)					//Provjeri dali pacijent sa tim MBO vec postoji
																//ako postoji, prekini proces pisanja novih info u txt
		if(pacijent.MBO == pacijent1[i].MBO){
			std::cout << "\n\nPacijent sa tim MBO vec postoji!\n\n";
			return;
		}


	pacijent1.push_back(pacijent);								//pushamo strukturu(pacijent) u vektor strukturi(pacijent1)

	std::ofstream output;										//stvaramo vezu izmedu txt i programa
	output.open("pacijenti.txt");
	for (int i = 0; i < pacijent1.size(); i++) {				//unesi u txt file novi unos pacijenta
		ljekovi = "";
		output << pacijent1[i].MBO + "\n" << pacijent1[i].ime + "\n" << pacijent1[i].prezime + "\n";
		for (int j = 0; j < pacijent1[i].popis_ljekova.size(); j++)
			ljekovi += pacijent1[i].popis_ljekova[j] + " ";
		output << ljekovi + " \n";	//razmak + novi red je potreban format jer se time sluzi program kod iscitavanja iz txt filea
		output.flush();				//koristi se da se isprazni output, u suprotnom ostane pun i daje krivi output
	}
	output.close();												//prekida se veza sa txt fileom

}

void ispis_pacijenata(std::vector<Pacijent> &pacijent1){
	//ispisi sve podatke koje smo iscitali iz txt datoteke
	for (int i = 0; i < pacijent1.size(); i++) {
		std::cout << "\nPacijent " << i + 1 << "\n" << pacijent1[i].MBO;
		std::cout << " - " << pacijent1[i].ime << " " << pacijent1[i].prezime;
		std::cout << ", ljekovi : ";
		for(int j = 0; j < pacijent1[i].popis_ljekova.size(); j++)
			std::cout << pacijent1[i].popis_ljekova[j] << " ";
	}

	//std::cout << "\nVelicina vektora pacijent1 = " << pacijent1.size() << std::endl;		//testna linija koda
}


void pretrazi_po_MBO(std::vector<Pacijent> &pacijent1){
	system("cls");
	std::cout << "Unesite MBO : ";
	std::string input;
	std::cin >> input;
	for(int i = 0; i < pacijent1.size(); i++)
		if(input == pacijent1[i].MBO){
			std::cout << "\n\n" << pacijent1[i].ime << " " << pacijent1[i].prezime << "\n";
			for(int j = 0; j < pacijent1[i].popis_ljekova.size(); j++)
				std::cout << pacijent1[i].popis_ljekova[j] << " ";
			return;
		}

	std::cout << "\n\nPacijent nije pronaden.\n\n";
}



void dodaj_recept(std::vector <Pacijent> &pacijent1){
	system("cls");
	std::cout << "Unesite MBO pacijenta kojemu zelite dodati lijek : ";
	std::string input, lijek;
	int lokator = -1;
	std::cin >> input;
	for(int i = 0; i < pacijent1.size(); i++)
		if(input == pacijent1[i].MBO)
			lokator = i;											//spremi lokaciju MBOa koji se podudara sa trazenim

	if(lokator != -1){												//ako je MBO pronaden...
		std::cout << "\nUnesite ljekove za " << pacijent1[lokator].ime << " (\"stop\" za izlaz) : ";
		while (lijek != "stop"){									//unos ljekova, unos "stop" prekida unos i kod se nastavlja..
			std::cin >> lijek;
			if (lijek != "stop")
				//OVO TREBA APPENDATI U TXT, INACE PROMJENA NECE BITI ZABILJEZENA
				pacijent1[lokator].popis_ljekova.push_back(lijek + " ");
		}
	}
	else															//ako MBO nije pronaden...
		std::cout << "\n\nMBO nije pronaden.\n\n";
}