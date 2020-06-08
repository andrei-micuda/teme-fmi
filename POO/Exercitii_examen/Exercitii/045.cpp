#include<iostream>
using namespace std;

class cls
{
    int x;
public: cls(int i=3) {x=i;}
    /*const*/ int &f() const { return x;} // (*this) este constant, deci se intoarce const x, dar return type-ul nu este const
    // REZ: intoarcem const int&
};
int main()
{
    const cls a(-3);
    int b=a.f();
    cout<<b;
    return 0;
}