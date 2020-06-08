#include <iostream>
using namespace std;

class cls1 {
	int x;
public:
	cls1() {
		x = 13;
	}
	int g() {
		static int i; i++;
		return (i + x);
	}
};

class cls2 {
	int x;
public:
	cls2() {
		x = 27;
	}
	cls1& f() {
		cls1 ob; return ob; // intoarcem referinta catre un obiect local
	}
};

int main() {
	cls2 ob;
	cout << ob.f().g(); // afiseaza: garbage_value (deoarece ob.f() este o referinta catre un obiect care a fost distrus la iesirea din functie, nu se stie ce va intoarce g)
	return 0;
}