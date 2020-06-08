#include <iostream>
using namespace std;

class B {
	/*protected:*/ // REZ: il facem pe x protected
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
	D() { x++; } // nu avem acces la x
	~D() { x--; } // nu avem acces la x
};
int f(B* q)
{
	return (q->get_i()) + 1;
}
int main()
{
	B* p = new B;
	cout << f(p);
	delete p;
	p = new D;
	cout << f(p);
	delete p;
	cout << D::get_x();
	return 0;
}