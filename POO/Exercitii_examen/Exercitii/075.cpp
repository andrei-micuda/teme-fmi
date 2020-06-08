#include <iostream>
using namespace std;

class cls1 {
public:
	int x;
	cls1(int i = 20) { x = i; }
};
class cls2 {
public:
	int y;
	cls2(int i = 30) { y = i; }
	operator cls1()
	{
		cls1 ob;
		ob.x = y;
		return ob;
	}
};
cls1 f(cls1 ob)
{
	ob.x++;
	return ob;
}
int main()
{
	cls1 ob1; // ob1.x = 20
	f(ob1); // ob1.x = 21
	cout << ob1.x; // afiseaza: 20
	cls2 ob2; // ob2.y = 30
	f(ob2); // il casteaza la cls1 => ob_tmp.x = 31
	cout << ob2.y; // afiseaza: 30 (obeictul initial ramane nemodificat)
	return 0;
}