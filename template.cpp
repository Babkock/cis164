/* Template functions
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 24, 2021 */
#include <iostream>
#include "util.h"
using namespace std;

int main(void) {
	int a = 5, b = 6, c = 7;
	double d = 10.25, e = 20.4, f = 30.7;
	Obj o(500, "hello world");
	Obj p(600, "goodbye");

	cout << "The bigger number of " << c << " and " << a << " is " << max<int>(c, a) << endl;

	cout.precision(2);
	cout << "The bigger number of " << fixed << d;
	cout << " and " << f << " is " << max<double>(d, f) << endl;

	cout << "The square of 5 is " << square<int>(5) << endl;

	cout << "The bigger object between this: " << endl;
	o.print();
	cout << "And this:" << endl;
	p.print();
	cout << "Is this:" << endl;
	/* should print 600.00 "goodbye" */
	max<Obj>(o, p).print();

	return 0;
}

/* Output:

The bigger number of 7 and 5 is 7
The bigger number of 10.25 and 30.70 is 30.70
The square of 5 is 25
The bigger object between this:
This object is: 500.00 "hello world"
And this:
This object is: 600.00 "goodbye"
Is this:
This object is: 600.00 "goodbye"

*/
