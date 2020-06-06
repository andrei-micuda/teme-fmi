#include <iostream>
#include <typeinfo>
using namespace std;

class B {
    int i;

public:
    B() { i = 1; }
    int get_i() { return i; }
};
class D : /*public*/ B { // REZ: mostenim public
    int j;

public:
    D() { j = 2; }
    int get_j() { return j; }
};
int main()
{
    B* p = new D; // nu se poate face upcasting daca mostenirea este privata
    cout << p->get_i(); // si daca linia anterioara ar compila, get_i() ar fi inaccesibil in D
    if (typeid((B*)p).name() == "D*") // nu intra in if deoarece pointerul este la baza
        cout << ((D*)p)->get_j();
    return 0;
}