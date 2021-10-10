/* Multiple inheritance
 * October 9, 2021 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
private:
	int wheels;
	bool engine;
public:
	Vehicle(int w, bool e): wheels(w), engine(e) { }
	int getWheels(void) { return wheels; }
	void setWheels(int w) { wheels = w; }
	virtual void makeSound(void) { }
};

class Bicycle : public Vehicle {
private:
	string color;
	string manufacturer;
public:
	Bicycle(string c, string m):
		Vehicle(2, false), color(c), manufacturer(m) { }
	string getColor(void) { return color; }
	void setColor(const string &c) { color = c; }
	string getManufacturer(void) { return manufacturer; }
	void setManufacturer(const string &m) { manufacturer = m; }
	void makeSound(void) {
		cout << "Clicky clicky! Ding ding!" << endl;
		cout << "This is a " << color << " " << manufacturer << " bicycle!" << endl;
	}
};

int main(void) {
	Bicycle bike("blue", "Schwinn");
	bike.makeSound();

	return 0;
}
