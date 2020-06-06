#include <iostream>
using namespace std;
int f(int y)
{
	if (y < 0)
		throw y;
	return y / 2;
}
int f(int y, int z)
{
	if (y < z)
		throw z - y;
	return y / 2;
}
float f(int& y) // REZ: putem schimba tipul parametrului in float
{
	cout << " y este referinta";
	return (float)y / 2;
}
int main()
{
	int x;
	try {
		cout << "Da - mi un numar par : ";
		cin >> x;
		if (x % 2)
			x = f(x, 0);
		else
			x = f(x); // nu stie ce functie sa apeleze, parametrii sunt doar in aparenta diferiti (int ~ int&), iar functiile nu pot diferi doar prin return type
		cout << "Numarul ”<< x <<” e bun !" << endl;
	}
	catch (int i) {
		cout << "Numarul ”<< i <<” nu e bun !" << endl;
	}
	return 0;
}