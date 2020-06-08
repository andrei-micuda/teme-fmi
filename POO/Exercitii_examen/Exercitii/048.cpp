#include <iostream>
using namespace std;

class cls1
{
protected: int x;
public:    cls1(int i = 10) { x = i; }
	  int get_x() { return x; }
};
class cls2 : /*public*/ cls1 // mostenire implicit private
				  // REZ: mostenim public
{
public: cls2(int i) :cls1(i) {}
};
int main()
{
	cls2 d(37);
	cout << d.get_x(); // metoda get_x() este privata in cls2 din cauza modificatorului de acces la mostenire
	return 0;
}