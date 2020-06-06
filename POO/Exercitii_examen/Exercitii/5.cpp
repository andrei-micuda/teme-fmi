//ordinea constructorilor
#include <iostream>
using namespace std;

class B {
	int i;

public:
	B() { i = 1; }
	virtual int get_i() { return i; }
};
class D : virtual public B {
	int j;

public:
	D() { j = 2; }
	int get_i() { return B::get_i() + j; }
};
class D2 : virtual public B {
	int j2;

public:
	D2() { j2 = 3; }
	int get_i() { return B::get_i() + j2; }
};
class MM : public D, public D2 {
	int x;

public:
	MM() { x = D::get_i() + D2::get_i(); }
	int get_i() { return x; }
};
int main()
{
	B* o = new MM();
	cout << o->get_i() << "\n"; // afiseaza: 7
	MM* p = dynamic_cast<MM*>(o);
	if (p)
		cout << p->get_i() << "\n"; // afiseaza: 7
	D* p2 = dynamic_cast<D*>(o); // downcasting
	if (p2)
		cout << p2->get_i() << "\n"; // afiseaza: ?? (vptr pointeaza tot la functia din MM, dar s-a facut downcasting, deci x nu mai este vazut de p2 => nu se stie ce va afisa functia)
	return 0;
}