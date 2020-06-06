#include <iostream>
using namespace std;

class A {
	int x;

public:
	A(int i) { x = i; }
	int get_x() { return x; }
	int& set_x(int i) { x = i; return i; }
	A operator=(A a1)
	{
		set_x(a1.get_x());
		return a1;
	}
};
class B : public A {
	int y;

public:
	B(int i /*= 0*/) // REZ: dam o valoare default pentru i
		: A(i)
	{
		y = i;
	}
	void afisare() { cout << y; }
};
int main()
{
	B a(112), b, * c; // nu avem constructor default pt B
	cout << (b = a).get_x();
	(c = &a)->afisare(); // operator=(int*, int*) dat de compilator
	return 0;
}