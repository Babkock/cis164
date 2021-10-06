/* Inheritance
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 6, 2021 */
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
private:
	string lineColor;
	string fillColor;
public:
	Shape(string lc, string fc): lineColor(lc), fillColor(fc) { }
	void setLineColor(string lc) { lineColor = lc; }
	void setFillColor(string fc) { fillColor = fc; }
	string getLineColor(void) { return lineColor; }
	string getFillColor(void) { return fillColor; }
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
};

int main(void) {
	Rectangle exampleShape(10, 5, "green", "transparent");

	exampleShape.setLineColor("black");

	return 0;
}

