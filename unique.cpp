/* Unique pointers
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 6, 2021 */
#include <iostream>
#include <cmath>
#include <memory>
#include <vector>
using namespace std;

const int NUM_POINTS = 5;
const double SCALE = 0.5;

class Point {
private:
	double x, y;
public:
	Point(double x, double y): x(x), y(y) { }
	Point(): Point(0, 0) { }
	double getX(void) { return x; }
	double getY(void) { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
};

unique_ptr<Point> inputPoint(void) {
	unique_ptr
}

