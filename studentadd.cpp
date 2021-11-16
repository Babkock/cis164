#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
	int id;
	string name;
public:
	Student(int i, string n): id(i), name(n) { }
	void setId(int i) {
		id = i;
	}
	int getId(void) {
		return id;
	}
	void setName(const string & n) {
		name = n;
	}
	string getName(void) {
		return name;
	}
};

Student Add(void) {
	string n;
	int i;
	cout << "Student name: ";
	cin >> n;
	cout << "Student ID: ";
	cin >> i;
	Student s(i, n);
	return s;
}

int main(void) {
	Student st = Add();
	cout << "Student's name is " << st.getName() << endl;
	cout << "Student ID is " << st.getId() << endl;
	return 0;
}

