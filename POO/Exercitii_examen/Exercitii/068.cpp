#include <iostream>
using namespace std;

class cls2; // REZ: mutam definitia lui cls2 inaintea lui cls1

class cls1 {
public:
	int vi;
	cls1(int v = 30) { vi = v; }
	cls1(cls2 p) { vi = p.vi; } // nu putem folosi in constructorul lui cls1 un obiect dintr-o clasa inca nedefinita
};

class cls2 {
public:
	int vi;
	cls2(int v = 20) { vi = v; }
};

cls1 f(cls1 p)
{
	p.vi++; // obiect transmis prin valoare, incrementarea nu are efect in afara
	return p;
}

void main()
{
	cls1 p;
	f(p);
	cout << endl
		<< p.vi;
	cls2 r;
	f(r);
	cout << endl
		<< r.vi;
}