#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <exception>

class Info {
protected:
	int id;
	std::string nume;

	Info(int = -1, std::string = "");
	Info(const Info&);
	virtual ~Info();

	virtual std::string what() = 0;
	virtual Info* copy() = 0;
	virtual bool contains(std::string) = 0;
	virtual void modifyData(std::string) = 0;

	friend std::istream& operator>>(std::istream&, Info&);
	friend std::ostream& operator<<(std::ostream&, const Info&);

	friend class Biblioteca;

public:
	Info& operator=(const Info&);

	std::string getNume() { return this->nume; }

	virtual void print(std::ostream& = std::cout);
};

class Text : public Info {
	std::string text;
public:
	Text(int = -1, std::string = "", std::string = "");
	Text(const Text&);
	~Text();
	Text& operator=(const Text&);

	std::string getText() { return this->text; }

	std::string what();
	Info* copy();
	bool contains(std::string);
	void modifyData(std::string);

	friend std::istream& operator>>(std::istream&, Text&);
	friend std::ostream& operator<<(std::ostream&, const Text&);

	friend class Biblioteca;

	void print(std::ostream & = std::cout);
};

class Numeric : public Info {
	int number;
public:
	Numeric(int = -1, int = 0, std::string = "");
	Numeric(const Numeric&);
	~Numeric();
	Numeric& operator=(const Numeric&);

	int getNumber() { return this->number; }

	std::string what();
	Info* copy();
	bool contains(std::string);
	void modifyData(std::string);

	friend std::istream& operator>>(std::istream&, Numeric&);
	friend std::ostream& operator<<(std::ostream&, const Numeric&);

	friend class Biblioteca;

	void print(std::ostream & = std::cout);
};

class Matematic : public Info {
	int re;
	int im;
public:
	Matematic(int = -1, int re = 0, int im = 0, std::string = "");
	Matematic(const Matematic&);
	~Matematic();
	Matematic& operator=(const Matematic&);

	int getRe() { return this->re; }
	int getIm() { return this->im; }

	std::string what();
	Info* copy();
	bool contains(std::string);
	void modifyData(std::string);

	friend std::istream& operator>>(std::istream&, Matematic&);
	friend std::ostream& operator<<(std::ostream&, const Matematic&);

	friend class Biblioteca;

	void print(std::ostream & = std::cout);
};

class Adresa : public Info {
	std::string tara;
	std::string judet;
	std::string oras;
	std::string strada;
	int numar;
public:
	Adresa(int = -1, std::string = "", std::string = "", std::string = "", std::string = "", int = 0, std::string = "");
	Adresa(const Adresa&);
	~Adresa();
	Adresa& operator=(const Adresa&);

	std::string getTara() { return this->tara; }
	std::string getJudet() { return this->judet; }
	std::string getOras() { return this->oras; }
	std::string getStrada() { return this->strada; }
	int getNumar() { return this->numar; }

	std::string what();
	Info* copy();
	bool contains(std::string);
	void modifyData(std::string);

	friend std::istream& operator>>(std::istream&, Adresa&);
	friend std::ostream& operator<<(std::ostream&, const Adresa&);

	friend class Biblioteca;

	void print(std::ostream & = std::cout);
};

class Biblioteca {
	std::vector<Info*> date;
	static int ID;
public:
	Biblioteca() {}
	Biblioteca(const Biblioteca&);
	~Biblioteca();
	Biblioteca& operator=(Biblioteca&);

	void adaugaText(std::string, std::string = "");
	void adaugaNumeric(int, std::string = "");
	void adaugaMatematic(int, int, std::string = "");
	void adaugaAdresa(std::string, std::string, std::string, std::string, int, std::string = "");
	void stergeDupaNume(std::string);
	void stergeDupaID(int);
	void regasesteDupaNume(std::string, std::ostream & = std::cout);
	void regasesteDupaID(int, std::ostream & = std::cout);
	void cauta(std::string, std::ostream & = std::cout);

	friend std::istream& operator>>(std::istream&, Biblioteca&);
	friend std::ostream& operator<<(std::ostream&, const Biblioteca&);
};

class myException : public std::exception {
	const char* what_arg;
public:
	myException(const char*);
	~myException() noexcept {}

	const char* what() const noexcept;
};

bool contains(std::string, std::string);
bool is_numeric(std::string);