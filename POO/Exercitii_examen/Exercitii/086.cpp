#include <iostream>
using namespace std;

class cls {
    static int x;

public:
    cls(int i = 1) { x = i; }
    cls f(cls a) { return x + a.x; }
    /*static int f(cls a = cls()) { return x + a.x; }*/ // o solutie ar fi sa facem functia statica si sa ii dam parametrului o valoare implicita
    static int g() { return f() / 2; } // 1. o fct statica nu are this, nu poate apela sau accesa metode/variabile nestatice fara un obiect
                                       // 2. nu exista val implicita pt param lui f
                                       // 3. f intoarcea un ob de tip cls, operatorul / nu este definit pe cls si int
};
int cls::x = 7;
int main()
{
    cls ob;
    cout << cls::g();
    return 0;
}