/* Memory layout with heap
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 8, 2021 */
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
void printPtr(T *ptr, int size, string name) {
	cout << "Address: " << ptr << " " << (long long)ptr << " size: " << setw(2) << size << " name: " << name << endl;
}

int *k;
double *l;
int a = 10;
double b = 20;
float c = 30;
long d = 40;
int h[10];

int e = 50;
int i;
int f = 60;
int j;

int main(void) {
	static int g = 70;
	k = new int;
	l = new double;
	cout << "Heap" << endl;
	printPtr(l, sizeof(l), "*l");
	printPtr(k, sizeof(k), "*k");

	cout << "Uninitialized Data Segment" << endl;
	printPtr(&h, sizeof(h), "h");
	printPtr(&j, sizeof(j), "j");
	printPtr(&i, sizeof(i), "i");
	printPtr(&l, sizeof(l), "l");
	printPtr(&k, sizeof(k), "k");

	cout << "Initialized Data Segment" << endl;
	printPtr(&g, sizeof(g), "g");
	printPtr(&f, sizeof(f), "f");
	printPtr(&e, sizeof(e), "e");
	printPtr(&d, sizeof(d), "d");
	printPtr(&c, sizeof(c), "c");
	printPtr(&b, sizeof(b), "b");
	printPtr(&a, sizeof(a), "a");

	cout << "Program Text Segment" << endl;
	printPtr((void *)main, sizeof((void *)main), "main");

	delete k;
	delete l;
	return 0;
}

