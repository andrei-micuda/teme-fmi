#include <iostream>
using namespace std;
class A {
	static int x; // variabila statica nu este initializata nicaieri => eroare de compilare

public:
	A(int i = 0) { x = i; }
	int get_x() { return x; }
	int& set_x(int i) { x = i; /*return i;*/ } // nu intoarce nimic, dar nu cred ca asta vor (?)
	A operator=(A a1)
	{
		set_x(a1.get_x());
		return a1;
	}
};
/*int A::x;*/ // REZ: il initializam pe x
int main()
{
	A a(212), b;
	cout << (b = a).get_x();
	return 0;
}