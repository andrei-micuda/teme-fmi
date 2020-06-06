#include <iostream>
using namespace std;
class A {
protected:
    int x;

public:
    A(int i = 14) { x = i; }
};
class B : A {
public:
    B()
        : A(2)
    {
    }
    B(B& b) { x = b.x - 14; } // are acces la x, deoarece x e protected in A
    void afisare() { cout << x; } // are acces la x, deoarece x e protected in A
};
int main()
{
    B b1, b2(b1); // b1.x = 2 b2.x = 12 - 14 = -2
    b2.afisare();
    // ruleaza: -12
    return 0;
}