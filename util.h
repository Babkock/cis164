/* Utility functions
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 24, 2021 */
#ifndef UTIL_H
#define UTIL_H

template <class T>
T &max(T &a, T &b) {
	return ((a > b) ? a : b);
}

template <class T>
T square(T x) {
	return (x * x);
}

#endif
