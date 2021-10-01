/* Struct inside a struct
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 30, 2021 */
#include <iostream>

typedef struct Point {
	int x;
	int y;
} Point_t;

typedef struct Line {
	struct Point start;
	struct Point end;
} Line_t;

typedef struct Rectangle {
	struct Point topLeft;
	struct Point topRight;
	struct Point bottomLeft;
	struct Point bottomRight;
} Rectangle_t;

void printLine(Line_t *l) {
	std::cout << "Line starts at (" << l->start.x << "," << l->start.y << ")";
	std::cout << " and ends at (" << l->end.x << "," << l->end.y << ")" << std::endl;
}

Line_t crossLine(Line_t *l) {
	int sx = l->start.y;
	int sy = l->start.x;
	int ex = l->end.y;
	int ey = l->end.x;

	return {
		.start = { .x = sx, .y = sy },
		.end = { .x = ex, .y = ey }
	};
}

int main(void) {
	Line_t line = {
		.start = { .x = 5, .y = 12 },
		.end = { .x = 20, .y = 40 }
	};
	printLine(&line);

	line = crossLine(&line);
	printLine(&line);

	return 0;
}

