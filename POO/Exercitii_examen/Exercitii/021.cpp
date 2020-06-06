#include <iostream>
using namespace std;

class A {
public:
	int x;
	A(int i = -13) { x = i; }
};
class B : virtual public A {
public:
	B(int i = -15) { x = i; } // se apeleaza implicit A()
};
class C : virtual public A {
public:
	C(int i = -17) { x = i; } // se apeleaza implicit A()
};
class D : virtual public A {
public:
	D(int i = -29) { x = i; } // se apeleaza implicit A()
};
class E : public B, public D, public C {
public:
	int y;
	E(int i, int j) // apeluri: A(), B(j), D(i), C(), E()
		: D(i)
		, B(j)
	{
		y = x + i + j;
	}
	E(E& ob) { y = ob.x - ob.y; } // apeluri: A(), B(), D(), C(), E(E& ob)
};
int main()
{
	E e1(5, 10), e2 = e1;
	cout << e2.y; // afiseaza: -15
	return 0;
}