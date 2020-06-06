#include <iostream>
using namespace std;

class B {
	/*protected:*/ // REZ: il facem pe x protected
	int x;

public:
	B(int v) { v = x; }
	int get_x() { return x; }
};

class D : private B {
	int y;

public:
	D(int v)
		: B(v)
	{
	}
	int get_x() { return x; } // x este inaccesibil in derivata
};

int main()
{
	D d(10);
	cout << d.get_x();
	return 0;
}