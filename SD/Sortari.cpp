//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//#include <chrono>
//#include <ctime>
//#include <cmath>
//
//using namespace std;
//using namespace std::chrono;
//
//ifstream in("sortari.in");
//ofstream out("sortari.out");
//
////Utility Functions
//void PrintArray(vector<int>& v);
//void FilePrintArray(vector<int>& v);
//bool CheckSort(vector<int>& v, vector<int>& sorted);
//int BFPRT(vector<int>& v, int st, int dr); //pivot picking algorithm for QuickSort
//int Partition(vector<int>& v, int st, int dr); //partition algorithm for QuickSort
//void Merge(vector<int>& v, int st, int dr); //merge algorithm for MergeSort
//
////Sorting Algorithms
//void InsertionSort(vector<int>& v);
//void BubbleSort(vector<int>& v);
//void RadixSortBase10(vector<int>& v, int pasi);
//void RadixSortBase256(vector<int>& v);
//void QuickSort(vector<int>& v, int st, int dr);
//void MergeSort(vector<int>& v, int st, int dr);
//
//
//int main() {
//	int tests;
//	in >> tests;
//	for (int k = 0; k < tests; k++) {
//		int n, mn, mx;
//		in >> n;
//		out << "TEST CASE " << k + 1 << '\n';
//		vector<int> v, tmp, sorted;
//		for (int i = 0; i < n; i++) {
//			int x;
//			in >> x;
//			if (i == 0) {
//				mn = x;
//				mx = x;
//			}
//			if (x < mn) mn = x;
//			if (x > mx) mx = x;
//			v.push_back(x);
//			tmp.push_back(x);
//			sorted.push_back(x);
//		}
//		int nr_mn = 0, nr_mx=0;
//		while (mn) {
//			nr_mn++;
//			mn /= 10;
//		}
//		nr_mn++;
//		while(mx) {
//			nr_mx++;
//			mx /= 10;
//		}
//		nr_mx++;
//		out << "Size: 10^" << log10(n) << '\n';
//		out << "Min: -10^" << nr_mn << '\n';
//		out << "Max: 10^" << nr_mx << '\n';
//
//		//STL Sort
//		auto start = high_resolution_clock::now();
//		sort(sorted.begin(), sorted.end());
//		auto stop = high_resolution_clock::now();
//		duration<double, std::milli> fp_ms = stop - start;
//		out << "STL Sort: "<< fp_ms.count() / 1000 << "s\n";
//
//		//Insertion Sort
//		start = high_resolution_clock::now();
//		InsertionSort(tmp);
//		stop = high_resolution_clock::now();
//		fp_ms = stop - start;
//		out << "Insertion Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");
//
//		//Bubble Sort
//		for (int i = 0; i < n; i++) tmp[i] = v[i];
//		start = high_resolution_clock::now();
//		BubbleSort(tmp);
//		stop = high_resolution_clock::now();
//		fp_ms = stop - start;
//		out << "Bubble Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");
//
//		//Merge Sort
//		for (int i = 0; i < n; i++) tmp[i] = v[i];
//		start = high_resolution_clock::now();
//		MergeSort(tmp, 0, tmp.size() - 1);
//		stop = high_resolution_clock::now();
//		fp_ms = stop - start;
//		out << "Merge Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");
//
//		//Quick Sort
//		for (int i = 0; i < n; i++) tmp[i] = v[i];
//		start = high_resolution_clock::now();
//		QuickSort(tmp, 0, tmp.size() - 1);
//		stop = high_resolution_clock::now();
//		fp_ms = stop - start;
//		out << "Quick Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");
//
//		//Radix Sort Base 10
//		for (int i = 0; i < n; i++) tmp[i] = v[i];
//		start = high_resolution_clock::now();
//		RadixSortBase10(tmp, nr_mx);
//		stop = high_resolution_clock::now();
//		fp_ms = stop - start;
//		out << "Radix Sort(base 10): " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");
//
//		//Radix Sort Base 256
//		for (int i = 0; i < n; i++) tmp[i] = v[i];
//		start = high_resolution_clock::now();
//		RadixSortBase256(tmp);
//		stop = high_resolution_clock::now();
//		fp_ms = stop - start;
//		out << "Radix Sort(base 256): " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");
//
//		out << '\n';
//	}
//	return 0;
//}
//
//void PrintArray(vector<int>& v) {
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << ' ';
//	cout << '\n';
//}
//void FilePrintArray(vector<int>& v) {
//	for (int i = 0; i < v.size(); i++)
//		out << v[i] << ' ';
//	out << '\n';
//}
//bool CheckSort(vector<int>& v, vector<int>& sorted) {
//	for (int i = 0; i < v.size(); i++) {
//		if (v[i] != sorted[i]) return false;
//	}
//	return true;
//}
//int BFPRT(vector<int>& v, int st, int dr) {
//	if (dr - st + 1 <= 5) {
//		vector<int> u;
//		for (int i = st; i <= dr; i++) u.push_back(v[i]);
//		InsertionSort(u);
//		return u[u.size() / 2];
//	}
//	vector<int> u(5), mediane;
//	for (int i = st; i <= dr; i += 5) {
//		int j = 0;
//		for (j = 0; j < 5 && i + j <= dr; j++) {
//			u[j] = v[i + j];
//		}
//		//daca o sublista (ultima) are mai putin de 5 elemente, le eliminam pe cele care ramasesera in vector din sublista anterioara
//		if (j < 5) u.resize(j);
//		InsertionSort(u);
//		mediane.push_back(u[u.size() / 2]);
//	}
//	return BFPRT(mediane, 0, mediane.size() - 1);
//}
//int Partition(vector<int>& v, int st, int dr) {
//	int i = st - 1;
//	for (int j = st; j < dr; j++) {
//		if (v[j] < v[dr]) {
//			i++;
//			swap(v[i], v[j]);
//		}
//	}
//	swap(v[i + 1], v[dr]);
//	return i + 1;
//}
//void Merge(vector<int>& v, int st, int dr) {
//	int m = (st + dr) / 2;
//	int i = st, j = m + 1;
//	vector<int> u;
//	while (i <= m && j <= dr) {
//		if (v[i] < v[j])
//			u.push_back(v[i++]);
//		else
//			u.push_back(v[j++]);
//	}
//	while (i <= m)
//		u.push_back(v[i++]);
//	while (j <= dr)
//		u.push_back(v[j++]);
//
//	for (i = st; i <= dr; i++)
//		v[i] = u[i - st];
//}
//
//void InsertionSort(vector<int>& v) {
//	if (v.size() > 5000) {
//		return;
//	}
//	for (int i = 1; i < v.size(); i++) {
//		int curr = v[i], j = i - 1;
//		while (j >= 0 && v[j] > curr) {
//			v[j + 1] = v[j];
//			j--;
//		}
//		v[j + 1] = curr;
//	}
//}
//void BubbleSort(vector<int>& v) {
//	if (v.size() > 5000) {
//		return;
//	}
//	bool ok = 0;
//	while (!ok) {
//		ok = 1;
//		for (int i = 0; i < v.size() - 1; i++) {
//			if (v[i] > v[i + 1]) {
//				swap(v[i], v[i + 1]);
//				ok = 0;
//			}
//		}
//	}
//}
//void RadixSortBase10(vector<int>& v, int pasi) {
//	//aflam numarul minimul din vector
//	int n = v.size(), mn = v[0];
//	for (int i = 0; i < n; i++) {
//		if (v[i] < mn) mn = v[i];
//	}
//
//	//daca vectorul contine elemente negative, scadem minimul pentru a sorta un vector doar de elemente pozitive
//	if (mn < 0) {
//		for (int i = 0; i < n; i++) v[i] -= mn;
//	}
//
//	vector<int> liste[10];
//
//	long long pow10 = 1;
//	for(int k=0; k<pasi; k++) {
//		for (int i = 0; i < n; i++) {
//			int cif_curr = (v[i] % (pow10 * 10)) / pow10;
//			liste[cif_curr].push_back(v[i]);
//		}
//		//mutam valorile din liste inapoi in vector
//		v.clear();
//		for (int i = 0; i < 10; i++) {
//			for (int j = 0; j < liste[i].size(); j++) v.push_back(liste[i][j]);
//			liste[i].clear();
//		}
//
//		pow10 *= 10;
//	}
//
//	//daca vectorul continea initial valori negative, adaugam minimul acestora pentru a obtine valorile initiale din vector
//	if (mn < 0) {
//		for (int i = 0; i < n; i++) v[i] += mn;
//	}
//}
//void RadixSortBase256(vector<int>& v) {
//	//aflam numarul minimul din vector
//	int n = v.size(), mn = v[0];
//	for (int i = 0; i < n; i++) {
//		if (v[i] < mn) mn = v[i];
//	}
//
//	//daca vectorul contine elemente negative, scadem minimul pentru a sorta un vector doar de elemente pozitive
//	if (mn < 0) {
//		for (int i = 0; i < n; i++) v[i] -= mn;
//	}
//
//	vector<int> liste[256];
//
//	for (int i = 0; i < n; i++) {
//		liste[(v[i] & 255)].push_back(v[i]);
//	}
//
//	//mutam valorile din liste inapoi in vector
//	v.clear();
//	for (int i = 0; i < 256; i++) {
//		for (int j = 0; j < liste[i].size(); j++) v.push_back(liste[i][j]);
//		liste[i].clear();
//	}
//
//	int bits = 8;
//	bool ok = false;
//	for(int j=0; j<3; j++){
//		for (int i = 0; i < n; i++) {
//			liste[((v[i] >> bits) & 255)].push_back(v[i]);
//		}
//
//		//mutam valorile din liste inapoi in vector
//		v.clear();
//		//daca am procesat cifrele tuturor numerelor, inseamna ca vectorul este sortat
//		if (liste[0].size() == n) ok = 1;
//		for (int i = 0; i < 256; i++) {
//			for (int j = 0; j < liste[i].size(); j++) v.push_back(liste[i][j]);
//			liste[i].clear();
//		}
//
//		bits += 8;
//	}
//
//	//daca vectorul continea initial valori negative, adaugam minimul acestora pentru a obtine valorile initiale din vector
//	if (mn < 0) {
//		for (int i = 0; i < n; i++) v[i] += mn;
//	}
//}
//void QuickSort(vector<int>& v, int st, int dr) {
//	if (st < dr) {
//		int pivot = st, pivot_val = BFPRT(v, st, dr);
//		while (v[pivot] != pivot_val) pivot++;
//		swap(v[pivot], v[dr]);
//		pivot = Partition(v, st, dr);
//		QuickSort(v, st, pivot - 1);
//		QuickSort(v, pivot + 1, dr);
//	}
//}
//void MergeSort(vector<int>& v, int st, int dr) {
//	if (st == dr)
//		return ;
//	int m = (st + dr) / 2;
//	MergeSort(v, st, m);
//	MergeSort(v, m + 1, dr);
//	Merge(v, st, dr);
//}

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream in("sortari.in");
ofstream out("sortari.out");

//Utility Functions
void PrintArray(vector<long long>& v);
void FilePrintArray(vector<long long>& v);
int NrOfDigits(long long x);
bool CheckSort(vector<long long>& v, vector<long long>& sorted);
long long BFPRT(vector<long long>& v, int st, int dr); //pivot picking algorithm for QuickSort
int Partition(vector<long long>& v, int st, int dr); //partition algorithm for QuickSort
void Merge(vector<long long>& v, int st, int dr); //merge algorithm for MergeSort

//Sorting Algorithms
void InsertionSort(vector<long long>& v);
void BubbleSort(vector<long long>& v);
void RadixSortBase10(vector<long long>& v);
void RadixSortBase256(vector<long long>& v);
void QuickSort(vector<long long>& v, int st, int dr);
void MergeSort(vector<long long>& v, int st, int dr);


int main() {
	int tests;
	in >> tests;
	for (int k = 0; k < tests; k++) {
		int n;
		long long mn = 0, mx = 0;
		in >> n;
		out << "TEST CASE " << k + 1 << '\n';

		vector<long long> v, tmp, sorted;
		for (int i = 0; i < n; i++) {
			long long x;
			in >> x;
			if (i == 0) {
				mn = x;
				mx = x;
			}
			if (i == 0 || x < mn) mn = x;
			if (i == 0 || x > mx) mx = x;
			v.push_back(x);
			tmp.push_back(x);
			sorted.push_back(x);
		}
		out << "Size: 10^" << NrOfDigits(n) - 1 << '\n';
		if(mn < 0) out << "Min: -10^" << NrOfDigits(mn) << '\n';
		else out << "Min: 10^" << NrOfDigits(mn) << '\n';
		out << "Max: 10^" << NrOfDigits(mx) << '\n';

		//STL Sort
		auto start = high_resolution_clock::now();
		sort(sorted.begin(), sorted.end());
		auto stop = high_resolution_clock::now();
		duration<double, std::milli> fp_ms = stop - start;
		out << "STL Sort: " << fp_ms.count() / 1000 << "s\n";

		//Insertion Sort
		start = high_resolution_clock::now();
		InsertionSort(tmp);
		stop = high_resolution_clock::now();
		fp_ms = stop - start;
		out << "Insertion Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");

		//Bubble Sort
		for (int i = 0; i < n; i++) tmp[i] = v[i];
		start = high_resolution_clock::now();
		BubbleSort(tmp);
		stop = high_resolution_clock::now();
		fp_ms = stop - start;
		out << "Bubble Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");

		//Merge Sort
		for (int i = 0; i < n; i++) tmp[i] = v[i];
		start = high_resolution_clock::now();
		MergeSort(tmp, 0, tmp.size() - 1);
		stop = high_resolution_clock::now();
		fp_ms = stop - start;
		out << "Merge Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");

		//Quick Sort
		for (int i = 0; i < n; i++) tmp[i] = v[i];
		start = high_resolution_clock::now();
		QuickSort(tmp, 0, tmp.size() - 1);
		stop = high_resolution_clock::now();
		fp_ms = stop - start;
		out << "Quick Sort: " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");

		//Radix Sort Base 10
		for (int i = 0; i < n; i++) tmp[i] = v[i];
		start = high_resolution_clock::now();
		RadixSortBase10(tmp);
		stop = high_resolution_clock::now();
		fp_ms = stop - start;
		out << "Radix Sort(base 10): " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");

		//Radix Sort Base 256
		for (int i = 0; i < n; i++) tmp[i] = v[i];
		start = high_resolution_clock::now();
		RadixSortBase256(tmp);
		stop = high_resolution_clock::now();
		fp_ms = stop - start;
		out << "Radix Sort(base 256): " << fp_ms.count() / 1000 << "s " << (CheckSort(tmp, sorted) ? "OK\n" : "NOT OK\n");

		out << '\n';
	}
	return 0;
}

void PrintArray(vector<long long>& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << '\n';
}
void FilePrintArray(vector<long long>& v) {
	for (int i = 0; i < v.size(); i++)
		out << v[i] << ' ';
	out << '\n';
}
int NrOfDigits(long long x) {
	int digits = 0;
	while(x) {
		digits++;
		x /= 10;
	}
	return digits;
}
bool CheckSort(vector<long long>& v, vector<long long>& sorted) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != sorted[i]) return false;
	}
	return true;
}
long long BFPRT(vector<long long>& v, int st, int dr) {
	if (dr - st + 1 <= 5) {
		vector<long long> u;
		for (int i = st; i <= dr; i++) u.push_back(v[i]);
		InsertionSort(u);
		return u[u.size() / 2];
	}
	vector<long long> u(5), mediane;
	for (int i = st; i <= dr; i += 5) {
		int j = 0;
		for (j = 0; j < 5 && i + j <= dr; j++) {
			u[j] = v[i + j];
		}
		//daca o sublista (ultima) are mai putin de 5 elemente, le eliminam pe cele care ramasesera in vector din sublista anterioara
		if (j < 5) u.resize(j);
		InsertionSort(u);
		mediane.push_back(u[u.size() / 2]);
	}
	return BFPRT(mediane, 0, mediane.size() - 1);
}
int Partition(vector<long long>& v, int st, int dr) {
	int i = st - 1;
	for (int j = st; j < dr; j++) {
		if (v[j] < v[dr]) {
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[dr]);
	return i + 1;
}
void Merge(vector<long long>& v, int st, int dr) {
	int m = (st + dr) / 2;
	int i = st, j = m + 1;
	vector<long long> u;
	while (i <= m && j <= dr) {
		if (v[i] < v[j])
			u.push_back(v[i++]);
		else
			u.push_back(v[j++]);
	}
	while (i <= m)
		u.push_back(v[i++]);
	while (j <= dr)
		u.push_back(v[j++]);

	for (i = st; i <= dr; i++)
		v[i] = u[i - st];
}

void InsertionSort(vector<long long>& v) {
	if (v.size() > 5000) {
		return;
	}
	for (int i = 1; i < v.size(); i++) {
		long long curr = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > curr) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = curr;
	}
}
void BubbleSort(vector<long long>& v) {
	if (v.size() > 5000 || v.size() < 1) {
		return;
	}
	bool ok = 0;
	while (!ok) {
		ok = 1;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				ok = 0;
			}
		}
	}
}
void RadixSortBase10(vector<long long>& v) {
	//aflam numarul minimul din vector
	int n = v.size();
	if (n < 1) return;
	long long mn = v[0], mx = v[0];
	for (int i = 0; i < n; i++) {
		if (v[i] < mn) mn = v[i];
	}

	//daca vectorul contine elemente negative, scadem minimul pentru a sorta un vector doar de elemente pozitive
	if (mn < 0) {
		for (int i = 0; i < n; i++) v[i] -= mn;
	}

	for (int i = 0; i < n; i++) {
		if (v[i] > mx) mx = v[i];
	}

	int pasi = NrOfDigits(mx);

	vector<long long> liste[10];

	long long pow10 = 1;
	for (int k = 0; k < pasi; k++) {
		for (int i = 0; i < n; i++) {
			int cif_curr = (v[i] % (pow10 * 10)) / pow10;
			liste[cif_curr].push_back(v[i]);
		}
		//mutam valorile din liste inapoi in vector
		int l = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < liste[i].size(); j++) v[l++] = liste[i][j];
			liste[i].clear();
		}

		pow10 *= 10;
	}

	//daca vectorul continea initial valori negative, adaugam minimul acestora pentru a obtine valorile initiale din vector
	if (mn < 0) {
		for (int i = 0; i < n; i++) v[i] += mn;
	}
}
void RadixSortBase256(vector<long long>& v) {
	//aflam minimul din vector
	int n = v.size();
	if (n < 1) return;
	long long mn = v[0];
	for (int i = 0; i < n; i++) {
		if (v[i] < mn) mn = v[i];
	}

	//daca vectorul contine elemente negative, scadem minimul pentru a sorta un vector doar de elemente pozitive
	if (mn < 0) {
		for (int i = 0; i < n; i++) v[i] -= mn;
	}

	vector<long long> liste[256];

	for (int i = 0; i < n; i++) {
		liste[(v[i] & 255)].push_back(v[i]);
	}

	//mutam valorile din liste inapoi in vector
	int k = 0;
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < liste[i].size(); j++) v[k++] = liste[i][j];
		liste[i].clear();
	}

	int bits = 8;
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < n; i++) {
			liste[((v[i] >> bits) & 255)].push_back(v[i]);
		}

		//mutam valorile din liste inapoi in vector
		k = 0;
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < liste[i].size(); j++) v[k++] = liste[i][j];
			liste[i].clear();
		}

		bits += 8;
	}

	//daca vectorul continea initial valori negative, adaugam minimul acestora pentru a obtine valorile initiale din vector
	if (mn < 0) {
		for (int i = 0; i < n; i++) v[i] += mn;
	}
}
void QuickSort(vector<long long>& v, int st, int dr) {
	if (st < dr) {
		int pivot = st;
		long long pivot_val = BFPRT(v, st, dr);
		while (v[pivot] != pivot_val) pivot++;
		swap(v[pivot], v[dr]);
		pivot = Partition(v, st, dr);
		QuickSort(v, st, pivot - 1);
		QuickSort(v, pivot + 1, dr);
	}
}
void MergeSort(vector<long long>& v, int st, int dr) {
	if (st >= dr)
		return;
	int m = (st + dr) / 2;
	MergeSort(v, st, m);
	MergeSort(v, m + 1, dr);
	Merge(v, st, dr);
}