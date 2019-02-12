#pragma once
#ifndef HEADER1_H
#define HEADER1_H

//ZADATAK 1
class Kocka {
	int visina, sirina, dubina;

public:
	void otvori();
	void zatvori();
};


//ZADATAK 2
class Automobil {
	std::string marka;
	std::string model;
	std::string broj_sasije;

public:
	void upali();
	void ugasi();
	void ubrzaj();
	void uspori();
	
	std::string get();
	void set();
};


#endif
