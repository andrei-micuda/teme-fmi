#include <iostream>
using namespace std;
class A
{
	static int* x;
public: A() {}
	  int get_x() { return (++(*x))++; }
};
int* A::x(new int(19));
int main()
{
	A* p = new A, b;
	cout << b.get_x() << " "; // afiseaza 20, apoi x devine 21
	cout << p->get_x(); // afiseaza 22, apoi x devine 23
	return 0;
}