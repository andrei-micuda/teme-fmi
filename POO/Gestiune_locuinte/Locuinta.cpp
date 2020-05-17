#include "Locuinta.h"

Locuinta::Locuinta(int index, double suprafata, double pretMetru, std::string numeClient, double discount) : index(index), numeClient(numeClient), suprafata(suprafata), discount(discount), pretMetru(pretMetru) {
	if (discount < 0 || discount > 10) throw(MyException("Discount-ul trebuie sa fie inte 0-10%."));
}

Locuinta& Locuinta::operator=(Locuinta& other)
{
	this->numeClient = other.numeClient;
	this->suprafata = other.suprafata;
	this->discount = other.discount;
	this->pretMetru = other.pretMetru;
	this->index = other.index;

	return (*this);
}

std::ostream& Locuinta::afiseaza(std::ostream& out) const
{
	out << "Tip: " << this->what() << '\n';
	out << "Index: " << this->index << '\n';
	out << "Suprafata utila: " << this->suprafata << "m^2\n";
	out << "Chirie: " << this->pretMetru << "/m^2" << '\n';
	out << "Client: " << this->numeClient << '\n';
	out << "Discount: " << this->discount << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Locuinta& ob) {
	std::cout << "Nume client: ";
	getline(in, ob.numeClient);
	std::cout << "Suprafata: "; in >> ob.suprafata;
	std::cout << "Discount(0-10%): "; in >> ob.discount;
	if (ob.discount < 0 || ob.discount > 10) throw(MyException("Discount-ul trebuie sa fie inte 0-10%."));
	std::cout << "Pret pe m^2: "; in >> ob.pretMetru;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Locuinta& ob) {
	return ob.afiseaza(out);
}