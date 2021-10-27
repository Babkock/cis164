/* Map of planets
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 27, 2021 */
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(void) {
	map<double,string> planets;
	string input;

	planets[0.39] = "Mercury";
	planets[0.72] = "Venus";
	planets[1] = "Earth";
	planets[1.52] = "Mars";
	planets[5.2] = "Jupiter";
	planets[9.54] = "Saturn";
	planets[19.2] = "Uranus";
	planets[30.06] = "Neptune";

	cout << "Enter a planet name: ";
	cin >> input;
	map<double,string>::iterator i;
	cout.precision(2);

	for (i = planets.begin(); i != planets.end(); ++i) {
		if (strcmp(input.c_str(), i->second.c_str()) == 0) {
			cout << "The planet " << i->second << " is " << i->first << " astronomical units from the sun" << endl;
			break;
		}
	}

	return 0;
}

/* Output:

Enter a planet name: Mars
The planet Mars is 1.5 astronomical units from the sun

*/

