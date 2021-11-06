/* Unique pointers
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 6, 2021 */
#include <iostream>
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
	double x, y;

	cout << "Enter X: ";
	cin >> x;
	cout << "Enter Y: ";
	cin >> y;

	return make_unique<Point>(x, y);
}

unique_ptr<Point> scalePoint(unique_ptr<Point> p, double sc) {
	p->setX(p->getX() * sc);
	p->setY(p->getY() * sc);
	return p;
}

vector<unique_ptr<Point>> getScaledPoints(double sc, int pts) {
	vector<unique_ptr<Point>> points;
	
	for (int i = 0; i < pts; i++) {
		points.push_back(scalePoint(inputPoint(), sc));
	}
	return points;
}

int main(void) {
	vector<unique_ptr<Point>> pointsPtr = getScaledPoints(SCALE, NUM_POINTS);

	for (int i = 0; i < NUM_POINTS; i++) {
		cout << "X: " << pointsPtr[i]->getX() << ", Y: " << pointsPtr[i]->getY();
		cout << endl;
	}
	return 0;
}

/* Output:

Enter X: 2
Enter Y: 3
Enter X: 4
Enter Y: 5
Enter X: 6
Enter Y: 7
Enter X: 8
Enter Y: 9
Enter X: 10
Enter Y: 11
X: 1, Y: 1.5
X: 2, Y: 2.5
X: 3, Y: 3.5
X: 4, Y: 4.5
X: 5, Y: 5.5

*/

