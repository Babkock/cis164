/* File append example
 * September 16, 2021 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
	string filename("vec.cpp");
	ofstream myfile;
	myfile.open(filename, std::ios_base::app);
	if (!myfile) {
		cerr << "vec.cpp does not exist!" << endl;
		return 1;
	}
	myfile << "// this comment was added later!" << endl;
	myfile.close();
	return 0;
}

