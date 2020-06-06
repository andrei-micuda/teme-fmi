#include <iostream>
using namespace std;

class A {
	int x;

public:
	A(int i = 0) { x = i; }
	A operator+(const A& a) { return x + a.x; }
	template <class T>
	ostream& operator<<(ostream&);
};
template <class T>
ostream& A::operator<<(ostream& o)
{
	o << x;
	return o;
}
int main()
{
	A a1(33), a2(-21);
	cout << a1 + a2; // ordine gresita a operanzilor (operator<< este functie membra) + nu se specifica tipul lui T
	/*(a1 + a2).operator<<<A>(cout);*/ // REZ: apelam corect functia membra
	return 0;
}