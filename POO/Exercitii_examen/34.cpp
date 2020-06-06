#include <iostream>
using namespace std;

template <class T, class U>
T f(T x, U y)
{
	return x + y;
}
int f(int x, int y)
{
	return x - y;
}
int main()
{
	int* a = new int(3), b(23);
	cout << *f(a, b); // apeleaza functia template cu T = int*, U = int
	// afiseaz: garbage_value (de la adresa cu 23 de pozitii dupa adresa lui la care pointeaza a)
	return 0;
}