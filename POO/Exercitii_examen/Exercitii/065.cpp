#include <iostream>
using namespace std;

class vector {
	int* p, nr;

public:
	operator int() { return nr; }
	vector(int);
};

vector::vector(int n)
{
	p = new int[n];
	nr = n;
	while (n--)
		p[n] = n;
}

void f(int i)
{
	while (i--)
		cout << i << endl;
}

void main()
{
	vector x(10);
	f(x); // afiseaza: 9\n 8\n 7\n 6\n 5\n 4\n 3\n 2\n 1\n 0\n
}