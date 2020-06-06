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
	cout << a1 + a2; // ordinea este gresita (este functie membra) si nu se specifica timpul lui T
	/*(a1 + a2).operator<<<A>(cout);*/ // REZ: apelam corect operatorul
	return 0;
}