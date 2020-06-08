#include <iostream>
using namespace std;

class B {
public:
	int x;
	B(int i = 16) { x = i; }
	B f(B ob) { return x + ob.x; }
};
class D : public B { // ierarhie nepolimorfica
public:
	D(int i = 25) { x = i; }
	B f(B ob) { return x + ob.x + 1; }
	void afisare() { cout << x; }
};
int main()
{
	B* p1 = new D, * p2 = new B, * p3 = new B(p1->f(*p2)); // p1->x = 25, p2->x = 16, p3->x = 41
	cout << p3->x; // afiseaza: 41
	return 0;
}