#include <iostream>
using namespace std;

class cls {
    int *v, nr;

public:
    cls(int i)
    {
        nr = i;
        v = new int[i];
        for (int j = 1; j < nr; j++)
            v[j] = 0;
    }
    int size() { return nr; }
    int& operator[](int i) { return *(v + i); }
};
int main()
{
    cls x(10);
    x[4] = -15;
    for (int i = 0; i < x.size(); i++)
        cout << x[i];

    // ruleaza: (valoare nedef)000-1500000
    // vectorul este initializat in constr de la 1, iar in main afisat de la 0, de aici prima valoare nedef
    return 0;
}