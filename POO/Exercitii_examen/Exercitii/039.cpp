#include<iostream>
using namespace std;

template<class X>void test(X& a, X& b)
{
	X temp;
	temp = a;
	a = b;
	b = temp;
	cout << "ttest\n";
}
void test(int& c, int& d) // ambiguitate cu functia urmatoare (int ~ int&)
{
	int temp;
	temp = c;
	c = d;
	d = temp;
	cout << "test 1\n";
}
void test(int/*char*/ e, int f) // REZ: schimbam tipul unuia dintre parametrii
{
	int temp;
	temp = e;
	e = f;
	f = temp;
	cout << "test 2\n";
}
void test(int g, int* h)
{
	int temp;
	temp = g;
	g = *h;
	*h = temp;
	cout << "test 3\n";
}
int main()
{
	int a = 5, b = 15, c = 25, * d = &a;
	test(a, b); // ambiguitate
	test(c, d);
	return 0;
}