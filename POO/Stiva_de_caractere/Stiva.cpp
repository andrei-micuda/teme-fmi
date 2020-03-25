#include "Stiva.h"

Nod::Nod() {
	info = NULL;
	next = NULL;
}

Nod::Nod(char val, Nod* last) {
	info = val;
	next = last;
}

Nod::~Nod() = default;

Stiva_de_caractere::Stiva_de_caractere() {
	stack_top = NULL;
}

Stiva_de_caractere::~Stiva_de_caractere() {
	while (!isempty()) {
		pop();
	}
	delete stack_top;
}

void Stiva_de_caractere::push(char val) {
	Nod* elem = new Nod(val, stack_top);
	stack_top = elem;
}

char Stiva_de_caractere::pop() {
	if (isempty())
		return NULL;
	Nod* tmp = stack_top->next;
	char val = stack_top->info;
	delete stack_top;
	stack_top = tmp;
	return val;
}

void Stiva_de_caractere::top() {
	cout << stack_top->info << '\n';
}

bool Stiva_de_caractere::isempty() {
	if (stack_top == NULL)
		return true;
	return false;
}

Stiva_de_caractere Stiva_de_caractere::operator-(Stiva_de_caractere& s1) {
	Stiva_de_caractere* res_s = new Stiva_de_caractere;
	while (!isempty() && !s1.isempty()) {
		char x = pop(), y = s1.pop();
		if (x > y) {
			res_s->push(x);
		}
		else {
			res_s->push(y);
		}
	}
	return (*res_s);
}

ostream& operator<<(ostream& os, Stiva_de_caractere& st) {
	while (st.stack_top != NULL) {
		os << st.pop();
	}
	return os;
}

istream& operator>>(istream& is, Stiva_de_caractere& st) {
	char x;
	is >> x;
	st.push(x);
	return is;
}

string reverse(const string& str) {
	Stiva_de_caractere stiva;
	for (int i = 0; i < str.size(); i++) {
		stiva.push(str[i]);
	}
	string str_rev;
	while (!stiva.isempty()) {
		str_rev.push_back(stiva.pop());
	}
	return str_rev;
}

void Citire_n_obiecte(int n) {
	vector<Stiva_de_caractere*> v;
	for (int i = 0; i < n; i++) {
		int nr_elem;
		cout << "Nr. elemente stiva " << i+1 << ": ";
		cin >> nr_elem;
		Stiva_de_caractere* st = new Stiva_de_caractere;
		for (int j = 0; j < nr_elem; j++) cin >> (*st);
		v.push_back(st);
	}
	for (int i = 0; i < n; i++) {
		cout << "Stiva " << i + 1 << ": ";
		cout << (*v[i]) << '\n';
	}
	
	for (int i = 0; i < n; i++) delete v[i];
}
