/* Multiple inheritance
 * Tanner Babcock
 * tababcock@dmacc.edu
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
	/* each vehicle makes a different kind of sound */
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
	
	void whip(void) {
		Vehicle::whip();
	}

	void makeSound(void) {
		whip();
		cout << "Clicky clicky! Ding ding!" << endl;
		cout << "This is a " << color << " " << manufacturer << " bicycle!" << endl;
		cout << endl;
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
	string getMake(void) { return make; }
	void setMake(const string &m) { make = m; }
	int getYear(void) { return year; }
	void setYear(int y) { year = y; }

	void whip(void) {
		Vehicle::whip();
	}

	void makeSound(void) {
		whip();
		cout << "Vroom vroom!! Eeerrumm... Reeeeeet!" << endl;
		cout << "This is a " << color << " " << year << " " << make << " " << model << " car. It's a tough lookin car" << endl;
		cout << endl;
	}
};

/* This is the class with two base classes */
class Motorcycle : public Bicycle, public Vehicle {
private:
	string model;
	int year;
public:
	Motorcycle(string c, string ma, string mo, int y):
		Vehicle(2, true), Bicycle(c, ma), model(mo), year(y) { }

	int getYear(void) { return year; }
	void setYear(int y) { year = y; }
	string getModel(void) { return model; }
	void setModel(const string &m) { model = m; }
	
	void whip(void) {
		Bicycle::whip();
	}

	void makeSound(void) {
		whip();
		cout << "Vrdrdrdrdrdrdrdr dremdremdremdremdrem!!" << endl;
		cout << "This is a " << this->getColor() << " " << year << " " << this->getManufacturer() << " " << model << endl;
		cout << endl;
	}
};

int main(void) {
	/* create three vehicles: a bike, a motorcycle, and a car */
	Bicycle bike("blue", "Schwinn");
	bike.makeSound();

	Motorcycle mbike("black", "Harley-Davidson", "Overcompensator", 2016);
	mbike.makeSound();

	Car prius("blue", "Toyota", "Prius", 2012);
	prius.setColor("red");
	prius.makeSound();

	return 0;
}

/* Output:

My 2-wheel whip is so clean
Clicky clicky! Ding ding!
This is a blue Schwinn bicycle!

My 2-wheel whip is so clean
Vrdrdrdrdrdrdrdr dremdremdremdremdrem!!
This is a black 2016 Harley-Davidson Overcompensator

My 4-wheel whip is so clean
Vroom vroom!! Eeerrumm... Reeeeeet!
This is a red 2012 Toyota Prius car. It's a tough lookin car

*/