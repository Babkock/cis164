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

/* addition */
double operator+(Shape &s1, Shape &s2) {
	return s1.area() + s2.area();
}

double operator+(double area, Shape &s) {
	return area + s.area();
}

/* subtraction */
double operator-(Shape &s1, Shape &s2) {
	return s1.area() - s2.area();
}

double operator-(double area, Shape &s) {
	return area - s.area();
}

/* multiplication */
double operator*(Shape &s1, Shape &s2) {
	return s1.area() * s2.area();
}

double operator*(double area, Shape &s) {
	return area * s.area();
}

int main(void) {
	Rectangle shape1(10, 10);
	Rectangle shape2(5, 10);
	Circle shape3(5);
	cout << "Shape1 area: " << shape1.area() << endl;
	cout << "Shape2 area: " << shape2.area() << endl;
	cout << "Shape3 area: " << shape3.area() << endl;

	// adding shape objects together returns the sum of their areas
	double total = shape1 + shape2 + shape3;
	cout << "The total area is " << total << endl;

	cout << "Shape1 minus Shape2: " << (shape1 - shape2) << endl;
	cout << "Shape3 minus Shape2: " << (shape3 - shape2) << endl;
	cout << "Shape1 times Shape2: " << (shape1 * shape2) << endl;

	return 0;
}

/* A program like this could be used by landscaping or construction
 * companies, to find out how much grass, or metal, or concrete
 * they need, to cover multiple buildings */

/* Output:

Shape1 area: 100
Shape2 area: 50
Shape3 area: 78.5
The total area is 228.5
Shape1 minus Shape2: 50
Shape3 minus Shape2: 28.5
Shape1 times Shape2: 5000

*/

