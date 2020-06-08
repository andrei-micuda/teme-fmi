#include <iostream>
using namespace std;

class cls
{
	int x;
public: cls(int y) { x = y; }
	  friend int operator*(cls a, cls b) { return (a.x * b.x); } // inline friend function
};
int main()
{
	cls m(100), n(15);
	cout << m * n; // afiseaza: 1500
	return 0;
}