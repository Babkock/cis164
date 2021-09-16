/* Vectors example
 * September 15, 2021 */
#include <iostream>
#include <vector>
using namespace std;

void otherthing(void) {
	vector<int> num{1, 2, 3, 4, 5};
	cout << "Element at index 0: " << num.at(0) << endl;
	cout << "Element at index 2: " << num.at(2) << endl;
	cout << "Element at index 4: " << num.at(4) << endl;
}

int main(void) {
	vector<int> num {1, 2, 3, 4, 5};
	cout << "Initial vector: ";

	for (const int& i : num) {
		cout << i << " ";
	}

	// add the integers 6 and 7 to the vector
	num.push_back(6);
	num.push_back(7);

	cout << endl << "Updated vector: ";

	for (const int& i : num) {
		cout << i << " ";
	}
	cout << endl;

	otherthing();
	return 0;
}

