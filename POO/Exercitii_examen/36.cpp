#include <iostream>
using namespace std;

class cls {
    int x;

public:
    cls(int i /*= 0*/) { x = i; } // REZ: dam o valoare default pentru i
    int set_x(int i)
    {
        int y = x;
        x = i;
        return y;
    }
    int get_x() { return x; }
};
int main()
{
    cls* p = new cls[10]; // nu avem constructor default pentru cls
    int i = 0;
    for (; i < 10; i++)
        p[i].set_x(i);
    for (i = 0; i < 10; i++)
        cout << p[i].get_x();
    return 0;
}