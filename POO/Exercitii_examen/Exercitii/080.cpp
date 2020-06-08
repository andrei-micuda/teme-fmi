#include <iostream>
using namespace std;

class B {
	/*protected:*/
	int x; // REZ: il facem pe x protected/public

public:
	B(int i = 10) { x = i; }
	int get_x() { return x; }
};
class D : public B {
public:
	D(int i)
		: B(i)
	{
	}
	D operator+(const D& a) { return x + a.x; } // x este inaccesibil in D
};
int main()
{
	D ob1(7), ob2(-12);
	cout << (ob1 + ob2).get_x();
	return 0;
}