/* Dynamic memory allocation
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 7, 2021 */
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	double *prices = new double[5];
	prices[0] = 7.95;
	prices[1] = 8.31;
	prices[2] = 9.25;
	prices[3] = 10.25;
	prices[4] = 99.99;
	/* This is useful for when the size of the array
	 * is determined at runtime */
	/* This can also save on memory on the stack,
	 * especially for big objects */
	cout.precision(2);
	for (int i = 0; i < 5; i++) {
		cout << "$" << fixed << prices[i] << endl;
	}
	delete[] prices;

	return 0;
}

