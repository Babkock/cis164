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
	void whip(void) {
		cout << "My " << wheels << "-wheel whip is so clean" << endl;
	}
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

class Car : public Vehicle {
private:
	string color;
	string model;
	string make;
	int year;
public:
	Car(string c, string ma, string mo, int y):
		Vehicle(4, true), color(c), model(mo), make(ma), year(y) { }
	string getColor(void) { return color; }
	void setColor(const string &c) { color = c; }
	string getModel(void) { return model; }
	void setModel(const string &m) { model = m; }
	void makeSound(void) {
		cout << "Vroom vroom!! Eeerrumm... Reeeeeet!" << endl;
		cout << "This is a " << color << " " << year << " " << make << " " << model << " car. It's a tough lookin car" << endl;
	}
};

int main(void) {
	Bicycle bike("blue", "Schwinn");
	bike.makeSound();

	return 0;
}
