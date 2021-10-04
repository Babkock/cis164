/* CSV reader
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 26, 2021 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
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

	void printSales(void) {
		cout.precision(2);
		cout << "------" << Sku << " Total: $" << fixed << (quantity * price) << " ------" << endl;
	}
};

int main(int argc, char *argv[]) {
	string filename, sku, qua, pri;
	ifstream orders;
	Order *it;
	int quantity;
	double price, total = 0.0;

	if (argc > 1)
		filename = argv[1];
	else {
		cout << "Please enter a file to read orders from: ";
		cin >> filename;
	}
	orders.open(filename, ios::in);
	cout.precision(2);

	while ((getline(orders, sku, ',')) && (sku.size() > 2)) {
		cout << "SKU: " << sku << endl;

		getline(orders, qua, ',');
		cout << "Quantity: " << qua << endl;

		getline(orders, pri);
		cout << "Price: " << pri << endl;

		quantity = stoi(qua);
		price = atof(pri.c_str());

		it = new Order(sku, quantity, price);
		it->printSales();
		total += (quantity * price);
		delete(it);

		cout << "--------------------------------------" << endl;
	}
	cout << "Total of $" << fixed << total << endl;
	orders.close();

	return 0;
}

/* When the given CSV file is this:

j0hnl3n,12,1.93
p4ul,93,2.21
g30rg3,24,4.20
R1ng0,669,6.10

Then the output of this program is this:

SKU: j0hnl3n
Quantity: 12
Price: 1.93
------j0hnl3n Total: $23.16 ------
--------------------------------------
SKU: p4ul
Quantity: 93
Price: 2.21
------p4ul Total: $205.53 ------
--------------------------------------
SKU: g30rg3
Quantity: 24
Price: 4.20
------g30rg3 Total: $100.80 ------
--------------------------------------
SKU: R1ng0
Quantity: 669
Price: 6.10
------R1ng0 Total: $4080.90 ------
--------------------------------------
Total of $4410.39

*/
