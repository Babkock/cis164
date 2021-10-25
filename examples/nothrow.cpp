/* Memory allocation
 * October 25, 2021 */
#include <iostream>
#include <new>
using namespace std;

int main(void) {
	int i, n;
	int *p;
	cout << "How many numbers would you like to type? ";
	cin >> i;
	p = new (nothrow) int[i];
	if (p == nullptr) {
		cerr << "Could not allocate memory" << endl;
		return 1;
	}
	else {
		for (n = 0; n < i; n++) {
			cout << "Enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++)
			cout << p[n] << ", ";
		cout << endl;
		delete[] p;
		return 0;
	}
}

