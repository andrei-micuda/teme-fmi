#include<iostream>
using namespace std;
template<class X, class Y>
X f(X x, Y y)
{
    // x si y sunt pointeri si nu ii poti aduna
    return x+y;
}
int *f(int *x,int y)
{
    return x-y;
}
int main()
{
    int *a=new int(200), *b=a; // o solutie poate fi sa il facem pe b int
    cout<<a+b<<"\n"; // nu se pot aduna 2 pointeri
    cout<<*f(a,b);
    return 0;
}