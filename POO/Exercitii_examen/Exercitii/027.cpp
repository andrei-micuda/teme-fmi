#include <iostream>
using namespace std;

class B {
	int i;

public:
	B() { i = 1; }
	virtual int get_i() { return i; }
};
class D : public B {
	int j;

public:
	D() { j = 2; }
	int get_i() { return B::get_i() + j; }
}/*o*/; // REZ: putem crea un obiect o global, pe care sa fie apelata metoda
int main()
{
	const int i = cin.get();
	if (i % 3) {
		D o; // scope local
	}
	else {
		B o; // scope local
	}
	cout << o.get_i(); // nu exista obiectul o(acesta este creat intr-un scope local in ambele cazuri si este distrus la iesirea din scope)
	return 0;
}