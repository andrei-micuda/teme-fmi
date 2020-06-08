#include <iostream>
using namespace std;
class B
{
protected: int i;
public: B(int j = 5) { cout << " cb "; i = j - 2; }
	  ~B() { cout << " db "; }
	  int get_i() { return i; }
};

class D1 : public B
{
	int j;
public: D1(int k = 10) { cout << " cd1 "; j = i - k + 3; }
	  ~D1() { cout << " dd1 "; }
};

class D2 : public D1
{
	int k;
public: D2(int l = 15) { cout << " cd2 "; k = i - l + 3; }
	  ~D2() { cout << " dd2 "; }
};
D1 f(D1 d1, D2 d2) { return d1.get_i() + d2.get_i(); }
int main()
{
	D2 ob2; // afiseaza: cb cd1 cd2
			// ob2.i = 3, ob2.j = -4, ob2.k = -9
	D1 ob1(3); // afiseaza: cb cd1
			   // ob1.i = 3, ob1.j = 3
	cout << f(ob1, ob2).get_i() + ob2.get_i(); // afiseaza: (se apeleaza cc pt obiectele transmise in functie) dd2 dd1 db dd1 db (se distrug copiile din functie) cb cd1 (se creaza obiectul direct acolo unde a fost apelata functia) 6 dd1 db (se sterge obiectul temporar)
	return 0;
	// afiseaza: dd1 db dd2 dd2 db (se sterg obiectele din main)
}