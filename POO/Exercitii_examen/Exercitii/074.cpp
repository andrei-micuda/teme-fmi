#include <iostream>
using namespace std;

class cls {
	int vi;

public:
	cls(int v = 37) { vi = v; }
	friend int& f(cls);
};
int& f(cls c) { return c.vi; } // face o copie a obiectului, nu lucreaza pe ob const => OK
int main()
{
	const cls d(15);
	f(d) = 8;
	cout << f(d); // afiseaza: 15
	return 0;
}