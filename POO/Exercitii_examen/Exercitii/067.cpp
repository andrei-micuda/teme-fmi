#include <iostream>
using namespace std;

class Y;

class Z;

class X {
	int x;

public:
	X(int n = 0) { x = n; }
	friend Y;
	/*friend Z;*/ // REZ: il facem si pe Z friend class al lui X
};

class Y {
	int y;
	friend Z;
};

class Z {
public:
	void f(X u) { cout << u.x; } // Z nu are acces la datele private din X (friendship-ul nu este tranzitiv)
};

void main()
{
	X a;
	Z b;
	b.f(a);
}