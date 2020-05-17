#include "Apartament.h"

Apartament::Apartament(double suprafata, double pretMetru, int etaj, std::string numeClient, double discount, int index): Locuinta(index, suprafata, pretMetru, numeClient, discount), etaj(etaj) {}

Apartament& Apartament::operator=(Apartament& other)
{
	this->Locuinta::operator=(other);
	this->etaj = other.etaj;

	return (*this);
}

double Apartament::calcChirie() const {
	return (this->pretMetru * this->suprafata) * (1 - this->discount / 100);
}

std::ostream& Apartament::afiseaza(std::ostream& out) const
{
	this->Locuinta::afiseaza(out);
	out << "Etaj: " << this->etaj << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Apartament& ob) {
	in >> (Locuinta&)ob;
	std::cout << "Etaj: "; in >> ob.etaj;
	return in;
}