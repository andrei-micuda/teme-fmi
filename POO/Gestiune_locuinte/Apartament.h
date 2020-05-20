#pragma once
#include "Locuinta.h"
class Apartament : public Locuinta {
	int etaj;
public:
	Apartament(double=0, double=0, int=0, std::string = "", double = 0, int = -1);
	Apartament(const Apartament& other);
	~Apartament() { std::cout << "~A\n"; }

	Apartament& operator= (Apartament&);

	double calcChirie() const;
	const std::string what() const { return "apartament"; }

	std::ostream& afiseaza(std::ostream&) const;

	friend std::istream& operator>>(std::istream& in, Apartament& ob);
};