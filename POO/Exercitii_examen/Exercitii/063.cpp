#include<iostream>
using namespace std;

class cls {
public:
	int x;
	cls() { x = 3; }
	void f(cls& c) { cout << c.x; }
};
/*void f(const cls& c) { cout << c.x; }*/ // REZ: cls& c => const cls& c si scoatem functia in afara clasei

void main()
{
	const cls d;
	f(d); // f este metoda nestatica a clasei => trebuie apelata cu un obiect implicit + transmitem un obiect const prin referinta catre o functie al carui parametru nu este const
}