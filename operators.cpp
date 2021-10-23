/* Operator overloading
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 23, 2021 */
#include <iostream>
#include <vector>
using namespace std;

class Shape {
private:
public:
	virtual double area() {
		return 0;
	}
};

class Rectangle : public Shape {
private:
	double width, height;
public:
	Rectangle(double w, double h): width(w), height(h) { }
	double perimeter(void) {
		return width + width + height + height;
	}
	double area(void) {
		return width * height;
	}
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double r): radius(r) { }
	double area(void) {
		return 3.14 * radius * radius;
	}
};

double operator+(Shape &s1, Shape &s2) {
	return s1.area() + s2.area();
}

double operator+(double area, Shape &s) {
	return area + s.area();
}

int main(void) {
	Rectangle shape1(10, 10);
	Rectangle shape2(5, 10);
	Circle shape3(5);

	// adding shape objects together returns the sum of their areas
	double total = shape1 + shape2 + shape3;
	cout << "The total area is " << total << endl;

	return 0;
}

