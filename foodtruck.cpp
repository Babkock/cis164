/* Food truck program
 * Tanner Babcock
 * September 8, 2021
*/
#include <iostream>
#define MAXBUNS 75
#define MAXSODA 200
#define MAXBURGERS 200
#define MAXCHILI 500
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

double sellHamburger(bool chili, int quantity = 1) {
	double total; // total amount due from customer
	double tax;   // added sales tax

	if (chili) {
		total = (7.00 * quantity);
		chili -= (4 * quantity);
	}
	else {
		total = (5.00 * quantity);
	}
	tax = (5.00 / 100.00) * total;
	cashRegister += (total + tax);
	
	burgerPatties -= quantity;
	burgerBuns -= quantity;
	return (total + tax);
}

double sellHotdog(bool chili, int quantity = 1) {
	double total; // total amount due
	double tax;   // added sales tax

	if (chili) {
		total = (7.00 * quantity);
		chili -= (4 * quantity);
	}
	else {
		total = (5.00 * quantity);
	}
	tax = (5.00 / 100.00) * total;
	cashRegister += (total + tax);

	hotdogs -= quantity;
	hotdogBuns -= quantity;
	return (total + tax);
}

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

int main(void) {
	char menuOption;
	int quantity;
	double subTotal;
	double tax;
	
	double burger = sellHamburger(true, 3);
	double dog = sellHotdog(false, 2);

	cout.precision(2);
	cout << "3 chili burgers total: $" << fixed << burger << endl;
	cout << "2 hotdogs total: $" << fixed << dog << endl;

	return 0;
}

