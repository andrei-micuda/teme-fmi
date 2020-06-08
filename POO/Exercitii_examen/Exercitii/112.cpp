#include <iostream>
using namespace std;

class cls {
	int x;

public:
	cls(int y) { x = y; }
	/*friend*/ int operator*(cls a, cls b) { return (a.x * b.x); } // functia este membru al clasei, operator* trebuie sa aiba 2 operanzi => 1 singur parametru
	// REZ: definim functia ca inline friend
};
int main()
{
	cls m(100), n(15);
	cout << m * n;
	return 0;
}