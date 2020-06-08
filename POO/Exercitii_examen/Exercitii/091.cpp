#include <iostream>
using namespace std;

class A
{
	int x;
public:
	A(int i = 25) { x = i; }
	int& f() const { return x; } // *this este constant, nu il putem transmite catre o referinta neconstanta
	// REZ: int& => const int&
	// REZ2: eliminiam const-ul de la functie
};
int main()
{
	A ob(5);
	cout << ob.f();
	return 0;
}