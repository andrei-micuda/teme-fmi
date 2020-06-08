#include <iostream>
using namespace std;

class A
{
	int x;
public:
	A(int i /*= 0*/) :x(i) {} // REZ: dam o valoare default pentru i
	int get_x() const { return x; }
};
class B : public A
{
	int* y;
public:
	B(int i) :A(i)
	{
		y = new int[i];
		for (int j = 0; j < i; j++) y[j] = 1;
	}
	B(B&);
	int& operator[](int i) { return y[i]; }
};
B::B(B& a) /*: A(a)*/ // se apeleaza implicit constructorul de INITIALIZARE al clasei A (care nu exista)
					  // REZ2: apelam explicit CC pentru clasa A
{
	y = new int[a.get_x()];
	for (int i = 0; i < a.get_x(); i++) y[i] = a[i];
}
ostream& operator<<(ostream& o, B a)
{
	for (int i = 0; i < a.get_x(); i++)o << a[i];
	return o;
}
int main()
{
	B b(5);
	cout << b;
	return 0;
}