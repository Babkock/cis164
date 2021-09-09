/* Food truck program
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 9, 2021
*/
#include <iostream>
#define MAXBUNS 75
#define MAXSODA 200
#define MAXBURGERS 200
#define MAXCHILI 500
#define LOWBUNS 15
#define LOWSODA 40
#define LOWBURGERS 10
#define LOWCHILI 100
#define ENTREE 5.00
#define CENTREE 7.00
using namespace std;

extern int burgerPatties;
int burgerPatties = MAXBURGERS;
extern int burgerBuns;
int burgerBuns = MAXBUNS;
extern int hotdogs;
int hotdogs = MAXBURGERS;
extern int hotdogBuns;
int hotdogBuns = MAXBUNS;
extern int chili;
int chili = MAXCHILI;
extern int fryBaskets;
int fryBaskets = MAXBUNS;
extern int soda;
int soda = MAXSODA;
extern double cashRegister;
double cashRegister = 0.0;

/* Sells hamburgers or chili hamburgers, returns the total amount
 * of the transaction */
double sellHamburger(bool chili, int quantity = 1) {
	double total; // total amount due from customer
	double tax;   // added sales tax

	if (chili) {
		total = (CENTREE * quantity);
		chili -= (4 * quantity);
	}
	else {
		total = (ENTREE * quantity);
	}
	tax = (5.00 / 100.00) * total;
	cashRegister += (total + tax);
	
	burgerPatties -= quantity;
	burgerBuns -= quantity;
	return (total + tax);
}

/* Sells hotdogs or chili hotdogs, returns the total amount
 * of the transaction */
double sellHotdog(bool chili, int quantity = 1) {
	double total;
	double tax;

	if (chili) {
		total = (CENTREE * quantity);
		chili -= (4 * quantity);
	}
	else {
		total = (ENTREE * quantity);
	}
	tax = (5.00 / 100.00) * total;
	cashRegister += (total + tax);

	hotdogs -= quantity;
	hotdogBuns -= quantity;
	return (total + tax);
}

/* Show the entire menu for inputting orders, setting
 * inventory, and quitting */
void showMenu(void) {
	cout << "Welcome to Billy's Burgs and Furts" << endl;
	cout << "Type one of the following characters to do something" << endl << endl;
	cout << "'i' - Update inventory for each item" << endl;
	cout << "'q' - Quits the program" << endl;
	cout << "'h' - Shows this menu" << endl;
	cout << "'m' - Shows this menu" << endl;
	
	if ((burgerBuns > 0) && (burgerPatties > 0)) {
		cout << "'b' - Hamburger(s) $5.00 - " << burgerBuns << " left" << endl;
		if (chili > 4) {
			cout << "'e' - Chili hamburger(s) $7.00" << endl;
		}
	}
	if ((hotdogBuns > 0) && (hotdogs > 0)) {
		cout << "'d' - Hotdog(s) $5.00 - " << hotdogBuns << " left" << endl;
		if (chili > 4) {
			cout << "'g' - Chili hotdog(s) $7.00" << endl;
		}
	}
	if (chili >= 12) {
		cout << "'c' - 12 oz. container of chili $4.00 - " << chili << " ounces left" << endl;
	}
	if (fryBaskets > 0) {
		cout << "'f' - Basket of fries $7.00" << endl;
	}
	if (soda > 0) {
		cout << "'s' - Can of soda $2.00 - " << soda << " cans left" << endl;
	}
	return;
}

/* Allows the user to input the inventory, showing current values
 * and warning for values that are too high */
void inventory(void) {
	int x, y, z;
	cout << "Enter the amount of hamburger Buns available (currently " << burgerBuns << "): ";
	cin >> x;
	burgerBuns = x;
	cout << "Enter the amount of hamburger Patties available (currently " << burgerPatties << "): ";
	cin >> y;
	burgerPatties = y;
}

int main(void) {
	char menuOption;
	int quantity;
	double subTotal;
	double tax;
	
	double burger = sellHamburger(true, 3);
	double dog = sellHotdog(false, 2);

	cout.precision(2);
	cout << "Cash register: $" << cashRegister << endl;

	showMenu();
	do {
		if (burgerBuns <= 15) {
			cout << "Running low on hamburger buns, only " << burgerBuns << " left" << endl;
		}
		if (hotdogBuns <= 15) {
			cout << "Running low on hotdog buns, only " << hotdogBuns << " left" << endl;
		}
		if (burgerPatties < 10) {
			cout << "Running low on hamburger patties, only " << burgerPatties << " left" << endl;
		}
		if (hotdogs < 10) {
			cout << "Running low on hotdogs, only " << hotdogs << " left" << endl;
		}
		if (chili <= 100) {
			cout << "Running low on chili, only " << chili << " ounces left" << endl;
		}
		if (fryBaskets <= 15) {
			cout << "Running low on fry baskets, only " << fryBaskets << " left" << endl;
		}
		if (soda <= 40) {
			cout << "Running low on soda, only " << soda << " cans left" << endl;
		}
		cout << "Action: ";
		cin >> menuOption;
		cout << "menuOption == '" << menuOption << "'" << endl;

		if (menuOption == 'i') {
			inventory();
		}
	} while (menuOption != 'q');

	return 0;
}

