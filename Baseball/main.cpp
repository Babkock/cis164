/* Baseball read and write
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 11, 2021 */
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	ifstream leagues, teams;
	leagues.open("Leagues.txt", ios::in);
	teams.open("Teams.txt", ios::in);
	if (!leagues) {
		cerr << "Could not read from Leagues.txt" << endl;
		return 1;
	}
	if (!teams) {
		cerr << "Could not read from Teams.txt" << endl;
		return 1;
	}
	leagues.close();
	teams.close();
	cout << "Files exist" << endl;
	return 0;
}
