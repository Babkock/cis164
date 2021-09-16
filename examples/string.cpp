/* String example
 * September 16, 2021 */
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string one = "Hello ";
	string two = "World";
	cout << (one + two) << endl;
	
	string uno = "Goodbye ";
	string dos = "Whirl";
	cout << uno.append(dos) << endl;

	return 0;
}
