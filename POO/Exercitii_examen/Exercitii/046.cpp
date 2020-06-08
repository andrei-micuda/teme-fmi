#include<iostream>
using namespace std;

class B
{
protected: int x;
public: B(int i = 0) { x = i; }
	  virtual B minus() { return (1 - x); } // REZ: intoarcem int in loc de B, deoarece compilatorul stie sa transforme un int intr-un obiect de tip D
};
class D : public B
{
public: D(int i = 0) :B(i) {}
	  void afisare() { cout << x; }
};
int main()
{
	D* p1 = new D(18);
	*p1 = p1->minus(); // nu exista operator=(D, B)
	p1->afisare();
	return 0;
}