/* polymorphism example
 * October 4, 2021 */
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
	Shape() { }
	virtual double area(void) {
		return 0;
	}
};

class Rectangle : public Shape {
private:
	double width, height;
public:
	Rectangle(double w, double h): width(w), height(h) { }
	double area(void) {
		return (width * height);
	}
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle() { }
	void setRadius(double r) {
		radius = r;
	}
	double area(void) {
		return (3.14 * radius * radius);
	}
};

int main(void) {
	vector<unique_ptr<Shape>> toyBox;

	/* Unique pointer to a new Rectangle object */
	unique_ptr<Rectangle> rect = make_unique<Rectangle>(10, 10);

	/* Unique pointer to a circle object */
	unique_ptr<Circle> cir = make_unique<Circle>();

	return 0;
}
