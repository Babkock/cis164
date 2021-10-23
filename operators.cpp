/* Operator overloading
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 23, 2021 */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	Rectangle shape1(10, 10);
	Rectangle shape2(5, 10);
	Circle shape3(5);

	// adding shape objects together returns the sum of their areas
	double total = shape1 + shape2 + shape3;
	cout << "The total area is " << total << endl;

	return 0;
}

