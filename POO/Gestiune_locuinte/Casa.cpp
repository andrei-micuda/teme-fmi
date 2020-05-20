#include "Casa.h"

Casa::Casa(double suprafata, double pretMetru, double suprafataCurte, double pretMetruCurte, int nrEtaje, const double* suprafataEtaj, std::string numeClient, double discount, int index): Locuinta(index, suprafata, pretMetru, numeClient, discount), suprafataCurte(suprafataCurte), pretMetruCurte(pretMetruCurte), nrEtaje(nrEtaje) {
	double totalSuprafataEtaje = 0;
	for (int i = 0; i < this->nrEtaje; ++i) {
		this->suprafataEtaj.push_back(suprafataEtaj[i]);
		totalSuprafataEtaje += this->suprafataEtaj[i];
	}
	if (totalSuprafataEtaje != this->suprafata) {
		throw(MyException("Suprafata utila trebuie sa fie egala cu suma suprafetelor etajelor!"));
	}
}

Casa::Casa(const Casa& other) : Locuinta(other) {
	for (int i = 0; i < this->nrEtaje; ++i) {
		this->suprafataEtaj.push_back(suprafataEtaj[i]);
	}
}

Casa& Casa::operator=(Casa& other)
{
	this->Locuinta::operator=(other);
	this->suprafataCurte = other.suprafataCurte;
	this->pretMetruCurte = other.pretMetruCurte;
	this->nrEtaje = other.nrEtaje;
	for (int i = 0; i < this->nrEtaje; ++i) {
		this->suprafataEtaj.push_back(other.suprafataEtaj[i]);
	}

	return (*this);
}

double Casa::calcChirie() const {
	return (this->pretMetru * this->suprafata) * (1 - this->discount / 100) + this->suprafataCurte * this->pretMetruCurte;
}

std::ostream& Casa::afiseaza(std::ostream& out) const
{
	this->Locuinta::afiseaza(out);
	out << "Suprafata curte: " << this->suprafataCurte << "m^2\n";
	out << "Chirie curte: " << this->pretMetruCurte << "/m^2\n";
	out << "Nr. etaje: " << this->nrEtaje << '\n';
	for (unsigned int i = 0; i < this->nrEtaje; ++i) {
		out << "Suprafata utila etaj " << i << ": " << this->suprafataEtaj[i] << "m^2\n";
	}

	return out;
}

std::istream& operator>>(std::istream& in, Casa& ob) {
	in >> (Locuinta&)ob;
	std::cout << "Suprafata curte: "; in >> ob.suprafataCurte;
	std::cout << "Chirie curte pe m^2: "; in >> ob.pretMetruCurte;
	std::cout << "Nr. etaje: "; in >> ob.nrEtaje;
	double totalSuprafataEtaje = 0;
	for (int i = 0; i < ob.nrEtaje; i++) {
		std::cout << "Suprafata etaj " << i << ": ";
		double tmp;
		in >> tmp;
		ob.suprafataEtaj.push_back(tmp);
		totalSuprafataEtaje += tmp;
	}
	if (totalSuprafataEtaje != ob.suprafata) {
		throw(MyException("Suprafata utila trebuie sa fie egala cu suma suprafetelor etajelor!"));
	}
	return in;
}