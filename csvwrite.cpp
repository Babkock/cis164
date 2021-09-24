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
	vector<Order> list;
	Order iterate;
	string filename;
	ofstream orders;
	
	cout << "Please enter a filename to write orders to: ";
	cin >> filename;
	orders.open(filename, ios::out);

	cout.precision(2);
	do {
		cout << "Doing it again" << endl;
		if (!iterate.getSku().empty()) {
//			cout << "You entered: " << o.getSku() << "," << o.getQuantity() << "," << fixed << o.getPrice() << endl;
			list.push_back(iterate);
		}
	} while (iterate.promptValues());
	/* This will break the loop if the user enters a 'q' */

	int y = 1;
	for (Order x : list) {
		cout << "Writing order #" << y << endl;
		
		y++;
	}
	return 0;
}
