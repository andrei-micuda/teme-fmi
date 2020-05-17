#pragma once
#include "Locuinta.h"
#include <vector>

class Casa: public Locuinta {
	double suprafataCurte;
	double pretMetruCurte;
	int nrEtaje;
	std::vector<double> suprafataEtaj;
public:
	Casa(double=0, double=0, double=0, double=0, int=0, const double* = NULL, std::string = "", double = 0, int = -1);
	~Casa() { std::cout << "~C\n"; }

	Casa& operator=(Casa&);

	double calcChirie() const;
	const std::string what() const { return "casa"; }
	std::ostream& afiseaza(std::ostream&) const;

	friend std::istream& operator>>(std::istream& in, Casa& ob);
};