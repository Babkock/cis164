/* Random access binary file
 * Tanner Babcock
 * December 10, 2021 */
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

int main(void) {
	ifstream in("sample.dat", ifstream::binary);
	if (!in) {
		cerr << "sample.dat could not be opened" << endl;
		return 1;
	}
	string strData;

	in.seekg(5); // move to 5th character
	getline(in, strData); // get the rest of the line
	cout << strData << endl;

	in.seekg(-15, ios::end); // move 15 bytes before end of file
	getline(in, strData); // get rest of line
	cout << strData << endl;

	return 0;
}

