#include "Biblioteca.h"

/*// INFO IMPLEMENTATION //*/
Info::Info(int id, std::string nume): id(id), nume(nume) {}

Info::Info(const Info& other) {
	this->nume = other.nume;
	this->id = other.id;
}

Info::~Info() {
	std::cout << "Distruge Info\n";
}

Info& Info::operator=(const Info& other) {
	this->id = other.id;
	this->nume = other.nume;
	return (*this);
}

void Info::print(std::ostream& out) { out << (*this); }

std::istream& operator>>(std::istream& in, Info& ob) {
	std::cout << "Doriti sa adaugati un nume asociat cu informatia stocata? (y/n): ";
	std::string option;
	in >> option;
	if (option == "y") {
		in >> ob.nume;
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Info& ob) {
	out << "ID: " << ob.id << '\n';
	out << "Nume: " << ob.nume << '\n';
	return out;
}

/*// TEXT IMPLEMENTATION //*/
Text::Text(int id, std::string text, std::string nume) : text(text), Info(id, nume) {}

Text::Text(const Text& other) : Info(other) {
	this->text = other.text;
}

Text::~Text() {
	std::cout << "Distruge Text\n";
}

Text& Text::operator=(const Text& other)
{
	(Info&)(*this) = other;
	this->text = other.text;
	return (*this);
}

void Text::print(std::ostream& out) { out << (*this); }

std::string Text::what() { return "text"; }

Info* Text::copy() {
	Info* tmp = new Text(*this);
	return tmp;
}

bool Text::contains(std::string val) {
	return (::contains(this->text, val));
}

void Text::modifyData(std::string val) {
	this->text += val;
}

std::istream& operator>>(std::istream& in, Text& ob) {
	std::cout << "Text: ";
	in >> ob.text;
	in >> (Info&)ob;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Text& ob) {
	out << (Info&)ob;
	out << "Textul: " << ob.text << '\n';
	return out;
}

/*// NUMERIC IMPLEMENTATION //*/
Numeric::Numeric(int id, int n, std::string nume) : number(n), Info(id, nume) {}

Numeric::Numeric(const Numeric& other) : Info(other) {
	this->number = other.number;
}

Numeric::~Numeric() {
	std::cout << "Distruge Numeric\n";
}

Numeric& Numeric::operator=(const Numeric& other)
{
	(Info&)(*this) = other;
	this->number = other.number;
	return (*this);
}

void Numeric::print(std::ostream& out) { out << (*this); }

std::string Numeric::what() { return "numeric"; }

Info* Numeric::copy() {
	Info* tmp = new Numeric(*this);
	return tmp;
}

bool Numeric::contains(std::string val) {
	return (::contains(std::to_string(this->number), val));
}

void Numeric::modifyData(std::string val) {
	int tmp = std::stoi(val);
	this->number += tmp;
}

std::istream& operator>>(std::istream& in, Numeric& ob) {
	std::cout << "Numar: ";
	in >> ob.number;
	in >> (Info&)ob;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Numeric& ob) {
	out << (Info&)ob;
	out << "Numarul: " << ob.number << '\n';
	return out;
}

/*// MATEMATIC IMPLEMENTATION //*/
Matematic::Matematic(int id, int re, int im, std::string nume) : re(re), im(im), Info(id, nume) {}

Matematic::Matematic(const Matematic& other) : Info(other) {
	this->re = other.re;
	this->im = other.im;
}

Matematic::~Matematic() {
	std::cout << "Distruge Matematic\n";
}

Matematic& Matematic::operator=(const Matematic& other)
{
	(Info&)(*this) = other;
	this->re = other.re;
	this->im = other.im;
	return (*this);
}

void Matematic::print(std::ostream& out) { out << (*this); }

std::string Matematic::what() { return "matematic"; }

Info* Matematic::copy() {
	Info* tmp = new Matematic(*this);
	return tmp;
}

bool Matematic::contains(std::string val) {
	return (::contains(std::to_string(this->re), val) || ::contains(std::to_string(this->im), val));
}

void Matematic::modifyData(std::string val) {
	int delim_pos = val.find("/");
	int re = std::stoi(val.substr(0, delim_pos));
	int im = std::stoi(val.substr(delim_pos + 1));
	this->re += re;
	this->im += im;
}

std::istream& operator>>(std::istream& in, Matematic& ob) {
	std::cout << "Partea reala: ";
	in >> ob.re;
	std::cout << "Partea imaginara: ";
	in >> ob.im;
	in >> (Info&)ob;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Matematic& ob) {
	out << (Info&)ob;
	out << "Numarul complex: " << ob.re << " + " << ob.im << "i\n";
	return out;
}

/*// ADRESA IMPLEMENTATION //*/
Adresa::Adresa(int id, std::string tara, std::string judet, std::string oras, std::string strada, int numar, std::string nume) : tara(tara), judet(judet), oras(oras), strada(strada), numar(numar), Info(id, nume) {}

Adresa::Adresa(const Adresa& other) : Info(other) {
	this->tara = other.tara;
	this->judet = other.judet;
	this->oras = other.oras;
	this->strada = other.strada;
	this->numar = other.numar;
}

Adresa::~Adresa() {
	std::cout << "Distruge Adresa\n";
}

Adresa& Adresa::operator=(const Adresa& other)
{
	(Info&)(*this) = other;
	this->tara = other.tara;
	this->judet = other.judet;
	this->oras = other.oras;
	this->strada = other.strada;
	this->numar = other.numar;
	return (*this);
}

void Adresa::print(std::ostream& out) { out << (*this); }

std::string Adresa::what() { return "adresa"; }

Info* Adresa::copy() {
	Info* tmp = new Adresa(*this);
	return tmp;
}

bool Adresa::contains(std::string val) {
	return (::contains(this->tara, val) ||
		::contains(this->judet, val) ||
		::contains(this->oras, val) ||
		::contains(this->strada, val) ||
		::contains(std::to_string(this->numar), val));
}

void Adresa::modifyData(std::string val) {
	throw(myException("Information of type \"Adresa\" with the same name already exists!"));
}

std::istream& operator>>(std::istream& in, Adresa& ob) {
	std::cout << "Tara: ";
	in >> ob.tara;
	std::cout << "Judet: ";
	in >> ob.judet;
	std::cout << "Oras: ";
	in >> ob.oras;
	std::cout << "Strada: ";
	in >> ob.strada;
	std::cout << "Numar: ";
	in >> ob.numar;

	in >> (Info&)ob;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Adresa& ob) {
	out << (Info&)ob;
	out << "Adresa:\n";
	out << "Tara: " << ob.tara << '\n';
	out << "Judet: " << ob.judet<< '\n';
	out << "Oras: " << ob.oras << '\n';
	out << "Strada: " << ob.strada << '\n';
	out << "Numar: " << ob.numar << '\n';

	return out;
}

/*// BIBLIOTECA IMPLEMENTATION //*/
int Biblioteca::ID = 0;

Biblioteca::Biblioteca(const Biblioteca& other) {
	for (unsigned int i = 0; i < other.date.size(); ++i) {
		this->date.push_back(other.date[i]->copy());
	}
}

Biblioteca& Biblioteca::operator=(Biblioteca& other) {
	for (unsigned int i = 0; i < other.date.size(); ++i) {
		this->date.push_back(other.date[i]->copy());
	}

	return (*this);
}

void Biblioteca::adaugaText(std::string text, std::string nume) {
	if (nume != "") {
		unsigned int i;
		for (i = 0; i < this->date.size() && this->date[i]->nume != nume; ++i) {}
		if (i >= this->date.size()) {//new information, we need to make a new entry
			Biblioteca::ID++;
			Text* ob = new Text(ID, text, nume);
			this->date.push_back(ob);
		}
		else {//information with this name already exists
			this->date[i]->modifyData(text);
		}
	}
	else {
		Biblioteca::ID++;
		Text* ob = new Text(ID, text, nume);
		this->date.push_back(ob);
	}
}
void Biblioteca::adaugaNumeric(int n, std::string nume) {
	if (nume != "") {
		unsigned int i;
		for (i = 0; i < this->date.size() && this->date[i]->nume != nume; ++i) {}
		if (i >= this->date.size()) {//new information, we need to make a new entry
			Biblioteca::ID++;
			Numeric* ob = new Numeric(ID, n, nume);
			this->date.push_back(ob);
		}
		else {//information with this name already exists
			this->date[i]->modifyData(std::to_string(n));
		}
	}
	else {
		Biblioteca::ID++;
		Numeric* ob = new Numeric(ID, n, nume);
		this->date.push_back(ob);
	}
}
void Biblioteca::adaugaMatematic(int re, int im, std::string nume) {
	if (nume != "") {
		unsigned int i;
		for (i = 0; i < this->date.size() && this->date[i]->nume != nume; ++i) {}
		if (i >= this->date.size()) {//new information, we need to make a new entry
			Biblioteca::ID++;
			Matematic* ob = new Matematic(ID, re, im, nume);
			this->date.push_back(ob);
		}
		else {//information with this name already exists
			this->date[i]->modifyData(std::to_string(re) + "/" + std::to_string(im));
		}
	}
	else {
		Biblioteca::ID++;
		Matematic* ob = new Matematic(ID, re, im, nume);
		this->date.push_back(ob);
	}
}
void Biblioteca::adaugaAdresa(std::string tara, std::string judet, std::string oras, std::string strada, int nr, std::string nume) {
	if (nume != "") {
		unsigned int i;
		for (i = 0; i < this->date.size() && this->date[i]->nume != nume; ++i) {}
		if (i >= this->date.size()) {//new information, we need to make a new entry
			Biblioteca::ID++;
			Adresa* ob = new Adresa(ID, tara, judet, oras, strada, nr, nume);
			this->date.push_back(ob);
		}
		else {//information with this name already exists => throw error
			this->date[i]->modifyData("-1");
		}
	}
	else {
		Biblioteca::ID++;
		Adresa* ob = new Adresa(ID, tara, judet, oras, strada, nr, nume);
		this->date.push_back(ob);
	}
}

void Biblioteca::stergeDupaNume(std::string nume) {
	unsigned int i;
	for (i = 0; i < this->date.size() && this->date[i]->nume!=nume; ++i) {}
	if (i >= this->date.size()) {//name does not exist
		throw(myException("Nu exista informatii stocate cu acest nume. Stergerea nu a fost realizata."));
	}
	else {
		delete date[i];
		date.erase(date.begin() + i);
	}
}

void Biblioteca::stergeDupaID(int id) {
	unsigned int i;
	for (i = 0; i < this->date.size() && this->date[i]->id != id; ++i) {}
	if (i >= this->date.size()) {//id does not exist
		throw(myException("Nu exista informatii stocate cu acest ID. Stergerea nu a fost realizata."));
	}
	else {
		delete date[i];
		date.erase(date.begin() + i);
	}
}

void Biblioteca::regasesteDupaNume(std::string nume, std::ostream& out) {
	unsigned int i;
	for (i = 0; i < this->date.size() && this->date[i]->nume != nume; ++i) {}

	if (i >= this->date.size()) {
		throw(myException("Nu exista informatii stocate cu acest nume. Regasirea nu a fost realizata."));
	}
	else {
		this->date[i]->print(out);
	}
}
void Biblioteca::regasesteDupaID(int id, std::ostream& out) {
	unsigned int i;
	for (i = 0; i < this->date.size() && this->date[i]->id != id; ++i) {}

	if (i >= this->date.size()) {
		throw(myException("Nu exista informatii stocate cu acest ID. Regasirea nu a fost realizata."));
	}
	else {
		this->date[i]->print(out);
	}
}

void Biblioteca::cauta(std::string val, std::ostream& out) {
	bool found = false;
	for (unsigned int i = 0; i < this->date.size(); ++i) {
		if (this->date[i]->contains(val)) {
			found = true;
			this->date[i]->print(out);
			out << '\n';
		}
	}
	if (!found) {
		out << "Nu s-a gasit nicio informatie.\n";
	}
}

Biblioteca::~Biblioteca() {
	for (unsigned int i = 0; i < this->date.size(); ++i) {
		delete this->date[i];
	}
}

std::istream& operator>>(std::istream& in, Biblioteca& b) {
	std::cout << "Ce tip de date doriti sa introduceti? (text/numeric/matematic/adresa): ";
	std::string type;
	in >> type;
	if (type == "text") {
		Text tmp;
		in >> tmp;
		b.adaugaText(tmp.getText(), tmp.getNume());
	}
	else if (type == "numeric") {
		Numeric tmp;
		in >> tmp;
		b.adaugaNumeric(tmp.getNumber(), tmp.getNume());
	}
	else if (type == "matematic") {
		Matematic tmp;
		in >> tmp;
		b.adaugaMatematic(tmp.getRe(), tmp.getIm(), tmp.getNume());
	}
	else if (type == "adresa") {
		Adresa tmp;
		in >> tmp;
		b.adaugaAdresa(tmp.getTara(), tmp.getJudet(), tmp.getOras(), tmp.getStrada(), tmp.getNumar(), tmp.getNume());
	}
	else {
		std::cout << "Tip de date invalid! Apasa orice tasta pentru a continua...";
		getchar();
		getchar();
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Biblioteca& b) {
	for (unsigned int i = 0; i < b.date.size(); ++i) {
		b.date[i]->print(out);
		out << '\n';
	}
	return out;
}

/*// CUSTOM EXCEPTION //*/
myException::myException(const char* what_arg) {
	this->what_arg = what_arg;
}

const char* myException::what() const noexcept {
	return this->what_arg;
}

/*// UTILITY FUNCTIONS //*/
bool contains(std::string where, std::string what) {
	return where.find(what) != std::string::npos;
}

bool is_numeric(std::string str) {
	for (unsigned int i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}