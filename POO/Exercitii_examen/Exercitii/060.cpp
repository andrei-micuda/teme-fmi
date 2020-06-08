#include <iostream>
using namespace std;

class cls {
public:
	float sa;
	cls(float s = 0) { sa = s; }
	operator float() { return sa; }
	float f(float c) { return (sa * (1 + c / 100)); }
};

void main()
{
	cls p(100);
	cout << p.f(p); // afiseaza: 200 (face cast de la cls la float pentru parametrul lui f)
}