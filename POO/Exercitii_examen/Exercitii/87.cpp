#include <iostream>

using namespace std;

class cls {
    int *v, nr;

public:
    cls(int i = 0)
    {
        nr = i;
        v = new int[i];
        for (int j = 0; j < size(); j++)
            v[j] = 3 * j;
    }
    // ~cls() { delete[] v; } daca nu se mai distrug obiectele, programul ruleaza
    int size() { return nr; }
    int& operator[](int i) { return v[i]; }
    cls operator+(cls);
};
cls cls::operator+(cls y)
{
    cls x(size());
    for (int i = 0; i < size(); i++)
        x[i] = v[i] + y[i];
    return x;
}
int main()
{
    cls x(10), y = x, z; // cc este cel default, copiaza bit cu bit, deci cand se apeleaza delete[] in destructor se distruge de 2 ori ac zona
    x[3] = y[6] = -15;
    z = x + y; //operator+ intoarce ob prin valoare, deci se face o copie a ob temporar, care la iesirea din functie este distrus
    for (int i = 0; i < x.size(); i++)
        cout << z[i];
    return 0;
}