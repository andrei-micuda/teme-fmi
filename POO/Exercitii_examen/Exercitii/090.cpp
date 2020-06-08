#include <iostream>
using namespace std;

template <class T>
int f(T x, T y)
{
	return x + y;
}
int f(int x, int y)
{
	return x - y;
}
int main()
{
	int a = 5;
	float b = 8.6;
	cout << f(a, b); // afiseaza: -3 (conversie la functia non-template)
	return 0;
}