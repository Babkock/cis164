/* Writing binary file
 * Tanner Babcock
 * December 10, 2021 */
#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
	int roll_no;
	string name;
} Student;

int main(void) {
	ofstream out("student.dat", ios::out | ios::binary);

	if (!out) {
		cerr << "Could not open student.dat for writing" << endl;
		return 1;
	}

	Student wstu[3];
	wstu[0] = {
		.roll_no = 1,
		.name = "Ram"
	};
	wstu[1] = {
		.roll_no = 2,
		.name = "Shyam"
	};
	wstu[2] = {
		.roll_no = 3,
		.name = "Madhu"
	};

	for (int i = 0; i < 3; i++)
		out.write((char *)&wstu[i], sizeof(Student));
	out.close();
	if (!out.good()) {
		cerr << "Could not close file" << endl;
		return 2;
	}
	cout << "Student's Details:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Roll no: " << wstu[i].roll_no << endl;
		cout << "Name: " << wstu[i].name << endl;
		cout << endl;
	}
	return 0;
}

