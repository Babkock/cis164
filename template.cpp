/* Template functions
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 24, 2021 */
#include <iostream>
#include "util.h"
using namespace std;

int main(void) {
	int a = 5, b = 6, c = 7;
	cout << "The bigger number of " << c << " and " << a << " is " << max<int>(c, a) << endl;

	double d = 10.25, e = 20.4, f = 30.7;
	cout.precision(2);
	cout << "The bigger number of " << fixed << d;
	cout << " and " << fixed << f << " is " << fixed << max<double>(d, f) << endl;

	cout << "The square of 5 is " << square<int>(5) << endl;

	return 0;
}

/* Output:

The bigger number of 7 and 5 is 7
The bigger number of 10.25 and 30.70 is 30.70
The square of 5 is 25
*/
