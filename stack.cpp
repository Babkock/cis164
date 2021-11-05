/* Using the Stack
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 4, 2021 */
#include <iostream>
#include <cmath>
using namespace std;

const int NUM_POINTS = 5;
const double SCALE = 0.5;

class Point {
private:
	double x, y;
public:
	Point() : x(0), y(0) {}
	double getX(void) { return x; }
	double getY(void) { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
};

/* Gets two values from user and sets the given point to them */
void inputPoint(Point *p) {
	double x, y;
	cout << "Enter X: ";
	cin >> x;
	cout << "Enter Y: ";
	cin >> y;
	p->setX(x);
	p->setY(y);
}

void scalePoint(Point *p, double sc) {
	p->setX(p->getX() * sc);
	p->setY(p->getY() * sc);
}

/* Arguments are:
 * sc = scale factor
 * pts = number of points to get from user
 * ps = pointer to array of points
*/
void getScaledPoints(double sc, int pts, Point *ps) {
	for (int i = 0; i < pts; i++) {
		cout << "Entering point #" << (i+1) << endl;
		inputPoint(&ps[i]);
		scalePoint(&ps[i], sc);
	}
}

int main(void) {
	Point points[NUM_POINTS];
	getScaledPoints(SCALE, NUM_POINTS, points);
	for (int i = 0; i < NUM_POINTS; i++) {
		cout << "X: " << points[i].getX() << ", Y: " << points[i].getY() << endl;
	}
	return 0;
}

/* Output:

Entering point #1
Enter X: 1
Enter Y: 2
Entering point #2
Enter X: 3
Enter Y: 4
Entering point #3
Enter X: 5
Enter Y: 6
Entering point #4
Enter X: 7
Enter Y: 8
Entering point #5
Enter X: 9
Enter Y: 10
X: 0.5, Y: 1
X: 1.5, Y: 2
X: 2.5, Y: 3
X: 3.5, Y: 4
X: 4.5, Y: 5

*/

