/* Utility functions
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 24, 2021 */
#ifndef UTIL_H
#define UTIL_H

/* The template functions below will not work with this
 * object type unless we overload operators */
class Obj {
private:
	double value;
	std::string text;
public:
	Obj(double v, const std::string &t): value(v), text(t) { }
	~Obj(void) {
		value = 0;
		text = "";
	}
	double getValue(void) { return value; }
	std::string getText(void) { return text; }
	void print(void) {
		std::cout << "This object is: " << value << " \"" << text << "\"" << std::endl;
	}
};

bool operator>(Obj &o1, Obj &o2) {
	return (o1.getValue() > o2.getValue());
}

bool operator>(double a, Obj &o) {
	return (a > o.getValue());
}

double operator*(Obj &o1, Obj &o2) {
	return (o1.getValue() * o2.getValue());
}

double operator*(double a, Obj &o) {
	return (a * o.getValue());
}

template <class T>
T &max(T &a, T &b) {
	return ((a > b) ? a : b);
}

template <class T>
T square(T x) {
	return (x * x);
}

#endif
