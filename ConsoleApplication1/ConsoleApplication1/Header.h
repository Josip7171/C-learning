#pragma once
#ifndef HEADER_H
#define HEADER_H

class Zivotinja {
public:
	int broj_koraka;
	int stupnjeva;

	void kretnja_naprijed();
	void okret_ljevo();
	void okret_desno();
};

#endif

