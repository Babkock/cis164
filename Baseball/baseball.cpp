/* Random Access Files
 * (Baseball read and write)
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 11, 2021 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void) {
	ifstream leagues, teams;
	string rleagues, rteams;
	int x = 0;
	leagues.open("Leagues.txt", ios::in);
	teams.open("Teams.txt", ios::in);
	ofstream out;

	if (!leagues) {
		cerr << "Could not read from Leagues.txt" << endl;
		return 1;
	}
	if (!teams) {
		cerr << "Could not read from Teams.txt" << endl;
		return 1;
	}
	out.open("output.txt", ios::out);
	if (!out) {
		cerr << "Could not open output.txt for writing" << endl;
		leagues.close();
		teams.close();
		return 2;
	}

	while ((!leagues.eof()) && (!teams.eof())) {
		getline(teams, rteams);
		if ((x++) == 21) {
			/* this advances Teams.txt one line without affecting Leagues.txt */
			//cout << "Found No Winner" << endl;
			continue;
		}
		getline(leagues, rleagues);
		if ((!leagues.fail()) && (!teams.fail())) {
			out << rteams << " - " << rleagues << endl;
		}
		rteams = "";
		rleagues = "";
	}
	out.close();
	leagues.close();
	teams.close();
	cout << "Done" << endl;
	return 0;
}
