#include <iostream>
using namespace std;

class B {
protected:
	static int x;
	int i;

public:
	B()
	{
		x++;
		i = 1;
	}
	~B() { x--; }
	static int get_x() { return x; }
	int get_i() { return i; }
};
int B::x;
class D : public B {
public:
	D()
	{
		x++;
		i++;
	}
	~D()
	{
		x--;
		i--;
	}
	int f1(B o) { return 5 + get_i(); } // obiect transmis prin valoare => CC
};
int f(B* q)
{
	return (q->get_x()) + 1;
}
int main()
{
	B* p = new B[10];
	cout << f(p); // afiseaza: 11
	delete[] p;
	p = new D;
	cout << p->f1(p); // nu stie cine este f1 + f1 primeste B, nu B* (p este pointer la B)
	// REZ: nu mai apelam f1() (?)
	delete p;
	cout << D::get_x();
	return 0;
}