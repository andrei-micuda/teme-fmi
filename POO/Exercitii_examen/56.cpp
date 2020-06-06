#include <iostream>
using namespace std;
class cls1 {
    int x;
public:
    cls1() {
        x = 13;
    }
    int g() {
        static int i; i++;
        return (i + x);
    }
};

class cls2 {
    int x;
public:
    cls2() {
        x = 27;
    }
    cls1& f() {
        cls1 ob; return ob;
    }
};

int main() {
    cls2 ob;
    cout << ob.f().g();

    // ruleaza: garbage_value
    // f() intoarce o referinta la un obiect local care este sters la iesirea din functie, deci referinta va pointa spre o zona stearsa => nu se stie ce se afiseaza cand se apeleaza g()
    return 0;
}