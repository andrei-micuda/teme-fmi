#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Nod {
	Nod* next;
	char info;
public:
	Nod();
	Nod(char val, Nod* last = NULL);
	~Nod();

	friend class Stiva_de_caractere;
	friend ostream& operator<<(ostream& os, Stiva_de_caractere& st);
	friend istream& operator>>(istream& is, Stiva_de_caractere& st);
};

class Stiva_de_caractere {
	Nod* stack_top;
public:
	Stiva_de_caractere(); //init stack_top = NULL
	~Stiva_de_caractere();
	void push(char val);
	char pop();
	void top();
	bool isempty();
	char* reverse(const char* str);
	Stiva_de_caractere operator-(Stiva_de_caractere& s1);
	friend ostream& operator<<(ostream& os, Stiva_de_caractere& st);
	friend istream& operator>>(istream& is, Stiva_de_caractere& st);
};

string reverse(const string& str);