/* Bad memory allocation
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 16, 2021 */
#include <iostream>
#include <vector>
using namespace std;

class Obj {
private:
	int value;
public:
	Obj(int v): value(v) { }
	~Obj(void) {
		value = 0;
	}
};

/* wow! This program gave my computer a beating! */

int main(void) {
	vector<Obj *> objects;
	for (int x = 0; ; x++)
		objects.push_back(new Obj(x));
	return 0;
}

