#include <iostream>
using namespace std;
class cls {
	int x;

public:
	cls(int i = -20) { x = i; }
	const int& f() { return x; } // REZ: intoarcem doar referinta la int
};
int main()
{
	cls a(14);
	int b = a.f()++; // f() intoarce const, nu poate fi lvalue (i.e. nu poate fi modificat)
	cout << b;
	return 0;
}