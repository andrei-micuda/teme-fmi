#include <iostream>
using namespace std;

class B {
	int x;

public:
	B(int i = 7) { x = i; }
	int get_x() { return x; }
	operator int() { return x; }
};
class D : public B {
public:
	D(int i = -12)
		: B(i)
	{
	}
	D operator+(D a) { return get_x() + a.get_x() + 1; }
};
int main()
{
	D a; // a.x = -12
	int b = 18;
	b += a; // il casteaza pe a la int => 18 - 12
	cout << b; // afiseaza: 6
	return 0;
}