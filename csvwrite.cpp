/* CSV writer
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 24, 2021 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Order {
private:
	string Sku;
	int quantity;
	double price;

public:
	Order(void) {
		Sku = "";
		quantity = 0;
		price = 0.0;
	}

	Order(const string & s, int q, double p) {
		Sku = s;
		quantity = q;
		price = p;
	}

	string getSku(void) {
		return Sku;
	}

	int getQuantity(void) {
		return quantity;
	}

	double getPrice(void) {
		return price;
	}

	/* returns true if all data was retrieved, false if user entered 'q' */
	bool promptValues(void) {
		cout << "SKU (q to quit): ";
		cin >> Sku;
		if (Sku.compare("q") == 0) {
			return false;
		}
		cout << "Quantity: ";
		cin >> quantity;
		cout << "Unit Price: ";
		cin >> price;
		return true;
	}
};

int main(void) {
	Order o;
	if (o.promptValues()) {
		cout << "Data retrieved" << endl;
	}
	else {
		cout << "You entered 'q'" << endl;
	}
	return 0;
}
