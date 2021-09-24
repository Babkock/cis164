/* CSV writer
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 24, 2021 */
#include <iostream>
#include <fstream>
#include <string>
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

int main(int argc, char *argv[]) {
	vector<Order> list;
	Order iterate;
	ofstream orders;
	string filename;
	int y = 0;

	if (argc > 1)
		filename = argv[1];
	else {
		cout << "Please enter a filename to write orders to: ";
		cin >> filename;
	}

	orders.open(filename, ios::out);
	orders.precision(2);
	
	do {
		y++;
		cout << "Entering order #" << y << endl;
		if (!iterate.getSku().empty()) {
			list.push_back(iterate);
		}
	} while (iterate.promptValues());
	/* This will break the loop if the user enters a 'q' */

	y = 1;
	for (Order x : list) {
		cout << "Writing order #" << y << endl;
		orders << x.getSku() << "," << x.getQuantity() << "," << fixed << x.getPrice() << endl;
		y++;
	}

	orders << endl;
	orders.close();
	return 0;
}

/* 
Please enter a filename to write orders to: test.csv
Entering order #1
SKU (q to quit): r1hf72
Quantity: 40
Unit Price: 4.20
Entering order #2
SKU (q to quit): p00p3r
Quantity: 666
Unit Price: 4.69
Entering order #3
SKU (q to quit): q
Writing order #1
Writing order #2
*/
