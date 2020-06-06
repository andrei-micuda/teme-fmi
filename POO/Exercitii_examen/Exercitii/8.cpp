#include <iostream>
using namespace std;

class B {
protected: // REZ: il facem pe x public
	int x;

public:
	B(int i = 28) { x = i; }
	virtual B f(B ob) { return x + ob.x + 1; }
	void afisare() { cout << x; }
};
class D : public B {
public:
	D(int i = -32)
		: B(i)
	{
	}
	B f(B ob) { return x + ob.x - 1; } // nu avem acces la ob.x
};
int main()
{
	B* p1 = new D, * p2 = new B, * p3 = new B(p1->f(*p2));
	p3->afisare();
	return 0;
}