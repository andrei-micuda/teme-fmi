#include "Biblioteca.h"

/*// INFO IMPLEMENTATION //*/
Info::Info(int id, std::string nume): id(id), nume(nume) {}

void Info::print(std::ostream& out) { out << (*this); }

std::ostream& operator<<(std::ostream& out, Info& ob) {
	out << "ID: " << ob.id << '\n';
	out << "Nume: " << ob.nume << '\n';
	return out;
}

/*// TEXT IMPLEMENTATION //*/
Text::Text(int id, std::string text, std::string nume) : text(text), Info(id, nume) {}

void Text::print(std::ostream& out) { out << (*this); }

bool Text::contains(std::string val) {
	return (::contains(this->text, val));
}

void Text::modifyData(std::string val) {
	this->text += val;
}

std::ostream& operator<<(std::ostream& out, Text& ob) {
	out << (Info&)ob;
	out << "Textul: " << ob.text << '\n';
	return out;
}

/*// NUMERIC IMPLEMENTATION //*/
Numeric::Numeric(int id, int n, std::string nume) : number(n), Info(id, nume) {}

void Numeric::print(std::ostream& out) { out << (*this); }

bool Numeric::contains(std::string val) {
	return (::contains(std::to_string(this->number), val));
}

void Numeric::modifyData(std::string val) {
	int tmp = std::stoi(val);
	this->number += tmp;
}

std::ostream& operator<<(std::ostream& out, Numeric& ob) {
	out << (Info&)ob;
	out << "Numarul: " << ob.number << '\n';
	return out;
}

/*// MATEMATIC IMPLEMENTATION //*/
Matematic::Matematic(int id, int re, int im, std::string nume) : re(re), im(im), Info(id, nume) {}

void Matematic::print(std::ostream& out) { out << (*this); }

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

std::ostream& operator<<(std::ostream& out, Matematic& ob) {
	out << (Info&)ob;
	out << "Numarul complex: " << ob.re << " + " << ob.im << "i\n";
	return out;
}

/*// ADRESA IMPLEMENTATION //*/
Adresa::Adresa(int id, std::string tara, std::string judet, std::string oras, std::string strada, int numar, std::string nume) : tara(tara), judet(judet), oras(oras), strada(strada), numar(numar), Info(id, nume) {}

void Adresa::print(std::ostream& out) { out << (*this); }

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

std::ostream& operator<<(std::ostream& out, Adresa& ob) {
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

void Biblioteca::adaugaText(std::string text, std::string nume) {
	if (nume != "") {
		int i;
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
		int i;
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
		int i;
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
		int i;
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

void Biblioteca::afiseaza(std::ostream& out) {
	for (int i = 0; i < this->date.size(); ++i) {
		this->date[i]->print(out);
		out << '\n';
	}
}

void Biblioteca::stergeDupaNume(std::string nume) {
	int i;
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
	int i;
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
	int i;
	for (i = 0; i < this->date.size() && this->date[i]->nume != nume; ++i) {}

	if (i >= this->date.size()) {
		throw(myException("Nu exista informatii stocate cu acest nume. Regasirea nu a fost realizata."));
	}
	else {
		this->date[i]->print(out);
	}
}
void Biblioteca::regasesteDupaID(int id, std::ostream& out) {
	int i;
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
	for (int i = 0; i < this->date.size(); ++i) {
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
	for (int i = 0; i < this->date.size(); ++i) {
		delete this->date[i];
	}
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
	for (int i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}