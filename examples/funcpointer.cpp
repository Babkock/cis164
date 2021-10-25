/* Function pointer example
 * October 25, 2021 */
#include <iostream>
using namespace std;

int add(int a, int b) {
	return (a+b);
}

int multiply(int a, int b) {
	return (a*b);
}

int operation(int x, int y, int (*handle)(int,int)) {
	int g;
	g = (*handle)(x, y);
	return g;
}

int main(void) {
	int m, n;
	// declare a pointer to a function with two int arguments
	int (*times)(int,int) = multiply;

	m = operation(25, 30, add);
	n = operation(10, 70, times);
	cout << "25 + 30 = " << m << endl;
	cout << "10 * 70 = " << n << endl;

	return 0;
}

