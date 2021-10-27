/* Map example */
#include <iostream>
#include <map>
using namespace std;

int main(void) {
	map<char,int> first;

	// initialize
	first['a'] = 10;
	first['b'] = 20;
	first['c'] = 30;
	first['d'] = 40;

	map<char,int>::iterator i;
	for (i = first.begin(); i != first.end(); ++i) {
		cout << i->first << " => " << i->second << endl;
	}
	return 0;
}

