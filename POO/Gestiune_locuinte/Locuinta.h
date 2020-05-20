#pragma once
#include <string>
#include <iostream>
#include "MyException.h"
class Locuinta {
protected:
	std::string numeClient;
	double suprafata;
	double discount;
	double pretMetru;
	int index;

	Locuinta(int, double, double, std::string = "" ,double = 0);
	Locuinta(const Locuinta& other);

	Locuinta& operator=(Locuinta&);

	virtual const std::string what() const = 0;

	friend std::istream& operator>>(std::istream& in, Locuinta& ob);
	friend std::ostream& operator<<(std::ostream& out, const Locuinta& ob);
public:
	virtual double calcChirie() const = 0;
	void setIndex(int index) { this->index = index; }
	virtual std::ostream& afiseaza(std::ostream&) const;
	void brief() const {
		std::cout << this->numeClient << "(" << this->suprafata << ")\n";
	}
	virtual ~Locuinta() { std::cout << "~L\n"; }
};