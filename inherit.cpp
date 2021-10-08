/* Inheritance
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 6, 2021 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* This program creates a vector of three shapes:
 * Rectangle, Triangle, and Box. It uses runtime
 * polymorphism to call the dimensions() function
*/

class Shape {
private:
	string lineColor;
	string fillColor;
public:
	Shape(string lc, string fc): lineColor(lc), fillColor(fc) { }
	virtual ~Shape() {
		lineColor = "";
		fillColor = "";
	}
	void setLineColor(string lc) { lineColor = lc; }
	void setFillColor(string fc) { fillColor = fc; }
	string getLineColor(void) { return lineColor; }
	string getFillColor(void) { return fillColor; }
	/* dimensions() will be implemented in the derived classes */
	virtual void dimensions(void) { }
	void printColors(void) {
		cout << "Line color: " << lineColor << endl;
		cout << "Fill color: " << fillColor << endl;
	}
};

class Rectangle : public Shape {
private:
	double width, height;
public:
	Rectangle(double w, double h, string lc, string fc):
		Shape(lc, fc), width(w), height(h) { }
	double getArea(void) {
		return (width * height);
	}
	double getWidth(void) { return width; }
	double getHeight(void) { return height; }
	void dimensions(void) {
		cout << "--- Rectangle ---" << endl;
		printColors();
		cout.precision(2);
		cout << "Width: " << fixed << width << endl;
		cout << "Height: " << fixed << height << endl;
		cout << "Area: " << fixed << getArea() << " squared" << endl;
		cout << "-------------------" << endl;
	}
};

class Triangle : public Shape {
private:
	double width, height;
public:
	Triangle(double w, double h, string lc, string fc):
		Shape(lc, fc), width(w), height(h) { }
	double getArea(void) {
		return (width * height) / 2;
	}
	double getWidth(void) { return width; }
	double getHeight(void) { return height; }
	void dimensions(void) {
		cout << "--- Triangle ---" << endl;
		printColors();
		cout.precision(2);
		cout << "Width: " << fixed << width << endl;
		cout << "Height: " << fixed << height << endl;
		cout << "Area: " << fixed << getArea() << endl;
		cout << "------------------" << endl;
	}
};

/* Box is a three-dimensional rectangle */
class Box : public Shape {
private:
	double width, height, depth;
public:
	Box(double w, double h, double d, string lc, string fc):
		Shape(lc, fc), width(w), height(h), depth(d) { }
	double getArea(void) {
		return (width * height);
	}
	double getVolume(void) {
		return (width * height * depth);
	}
	double getWidth(void) { return width; }
	double getHeight(void) { return height; }
	double getDepth(void) { return depth; }
	void dimensions(void) {
		cout << "--- Box ---" << endl;
		printColors();
		cout.precision(2);
		cout << "Width: " << fixed << width << endl;
		cout << "Height: " << fixed << height << endl;
		cout << "Depth: " << fixed << depth << endl;
		cout << "Area: " << fixed << getArea() << " squared" << endl;
		cout << "Volume: " << fixed << getVolume() << " cubed" << endl;
		cout << "------------------" << endl;
	}
};

int main(void) {
	vector<Shape *> shapes;
	shapes.push_back(new Rectangle(10, 5, "green", "transparent"));
	shapes.push_back(new Triangle(20, 10, "blue", "cyan"));
	shapes.push_back(new Box(30, 40, 9, "white", "red"));

	cout << "Printing shapes" << endl;
	for (auto s : shapes) {
		s->dimensions();
		delete(s);
	}
	
	return 0;
}

/* Output:

Printing shapes
--- Rectangle ---
Line color: green
Fill color: transparent
Width: 10.00
Height: 5.00
Area: 50.00 squared
-------------------
--- Rectangle ---
Line color: green
Fill color: transparent
Width: 10.00
Height: 5.00
Area: 50.00 squared
-------------------
--- Triangle ---
Line color: blue
Fill color: cyan
Width: 20.00
Height: 10.00
Area: 100.00
------------------
--- Box ---
Line color: white
Fill color: red
Width: 30.00
Height: 40.00
Depth: 9.00
Area: 1200.00 squared
Volume: 10800.00 cubed
------------------
*/
