#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <exception>

class Info {
protected:
	int id;
	std::string nume;
	Info(int id, std::string = "");

	friend std::ostream& operator<<(std::ostream&, Info& ob);
	virtual void print(std::ostream & = std::cout);
	virtual bool contains(std::string);
	virtual void modifyData(std::string) = 0;

	friend class Biblioteca;
};
	

class Text : public Info {
	std::string text;
protected:
	Text(int, std::string = "", std::string = "");
	void print(std::ostream & = std::cout);
	bool contains(std::string);
	void modifyData(std::string);

	friend std::ostream& operator<<(std::ostream&, Text&);

	friend class Biblioteca;
};

class Numeric : public Info {
	int number;
protected:
	Numeric(int, int = 0, std::string = "");
	void print(std::ostream & = std::cout);
	bool contains(std::string);
	void modifyData(std::string);

	friend std::ostream& operator<<(std::ostream&, Numeric&);

	friend class Biblioteca;
};

class Matematic : public Info {
	int re;
	int im;
protected:
	Matematic(int, int re = 0, int im = 0, std::string = "");
	void print(std::ostream & = std::cout);
	bool contains(std::string);
	void modifyData(std::string);

	friend std::ostream& operator<<(std::ostream&, Matematic&);

	friend class Biblioteca;
};

class Adresa : public Info {
	std::string tara;
	std::string judet;
	std::string oras;
	std::string strada;
	int numar;
protected:
	Adresa(int, std::string = "", std::string = "", std::string = "", std::string = "", int = 0, std::string = "");
	void print(std::ostream& = std::cout);
	bool contains(std::string);
	void modifyData(std::string);

	friend std::ostream& operator<<(std::ostream&, Adresa&);

	friend class Biblioteca;
};

class Biblioteca {
	std::vector<Info*> date;
	static int ID;
public:
	void adaugaText(std::string, std::string = "");
	void adaugaNumeric(int, std::string = "");
	void adaugaMatematic(int, int, std::string = "");
	void adaugaAdresa(std::string, std::string, std::string, std::string, int, std::string = "");
	void afiseaza(std::ostream & = std::cout);
	void stergeDupaNume(std::string);
	void stergeDupaID(int);
	void regasesteDupaNume(std::string, std::ostream& = std::cout);
	void regasesteDupaID(int, std::ostream& = std::cout);
	void cauta(std::string, std::ostream& = std::cout);

	~Biblioteca();
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