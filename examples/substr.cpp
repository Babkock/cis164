/* Substring example
 * September 16, 2021 */
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string one = "Fuck the police comin straight from the underground";
	string two = one.substr(9, 6); // should be "police"
	cout << two << endl;

	size_t pos = one.find("from");
	string three = one.substr(pos); // should be "from the underground"
	cout << two << ' ' << three << endl;

	return 0;
}
