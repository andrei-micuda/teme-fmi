#include <iostream>
using namespace std;

template <class T, class U>
T f(T x, U y)
{
	return x + y; // y pozitii dupa adresa pointata de a
}
int f(int x, int y)
{
	return x - y;
}
int main()
{
	int* a = new int(3), b(23); // a este pointer la int, b este int
	cout << *f(a, b); // afiseaza: garbage_value
	return 0;
}