#include <iostream>
using namespace std;

int f(int y)
{
	if (y < 0) throw y;
	return y / 2;
}
int main()
{
	int x;
	try
	{
		cout << "Da-mi un numar par: ";
		cin >> x;
		if (x % 3)x = f(x);
		else throw x;
		cout << "Numarul " << x << " e bun!\n";
	}
	catch (int i)
	{
		cout << "Numarul " << i << " nu e bun!\n";
	}
	// afiseaza:
	// I. pt x = 3k => Numarul x nu este bun!
	// II. pt x = 3k + 1 / 3k + 2, x > 0 => Numarul [x/2] este bun!
	// III. pt x = 3k + 1 / 3k + 2, x < 0 => Numarul x nu este bun!
	return 0;
}