/* Array review
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 11, 2021
*/
#include <iostream>
#include <array>
using namespace std;

int main(void) {
	const int SIZE = 9;

	array<double, SIZE> nine;

	for (int a = 0; a < SIZE; a++) {
		cout << "Enter a double for index " << a << ": ";
		cin >> nine[a];
	}

	cout << "First element: " << nine[0] << endl;
	cout << "Fifth element: " << nine[4] << endl;
	cout << "Ninth element: " << nine[8] << endl;

	return 0;
}

