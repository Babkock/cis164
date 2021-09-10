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
    cout << "'r' - Show cash register balance" << endl;
	
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
	int x, y, z, a;
	cout << "Enter the amount of hamburger Buns available (currently " << burgerBuns << "): ";
	cin >> x;
	if (x > MAXBUNS) {
		cerr << "We don't have enough room for that many, input ignored" << endl;
	}
	else {
		burgerBuns = x;
	}
	cout << "Enter the amount of hamburger Patties available (currently " << burgerPatties << "): ";
	cin >> y;
	if (y > MAXBURGERS) {
		cerr << "We don't have enough room for that many, input ignored" << endl;
	}
	else {
		burgerPatties = y;
	}
	cout << "Enter the amount of hotdog Buns available (currently " << hotdogBuns << "): ";
	cin >> z;
	if (z > MAXBUNS) {
		cerr << "We don't have enough room for that many, input ignored" << endl;
	}
	else {
		hotdogBuns = z;
	}
	x = 0;
	cout << "Enter the amount of hotdogs available (currently " << hotdogs << "): ";
	cin >> x;
	if (x > MAXBURGERS) {
		cerr << "We don't have enough room for that many, input ignored" << endl;
	}
	else {
		hotdogs = x;
	}
	y = 0;
	cout << "Enter the amount of chili available (currently " << chili << " ounces): ";
	cin >> y;
	if (y > MAXCHILI) {
		cerr << "We don't have enough room for that much, input ignored" << endl;
	}
	else {
		chili = y;
	}
	z = 0;
	cout << "Enter the amount of fry baskets available (currently " << fryBaskets << " baskets): ";
	cin >> z;
	if (z > MAXBUNS) {
		cerr << "We don't have enough room for that many, input ignored" << endl;
	}
	else {
		fryBaskets = z;
	}
	cout << "Enter the amount of soda available (currently " << soda << " cans): ";
	cin >> a;
	if (a > MAXSODA) {
		cerr << "We don't have enough room for that much, input ignored" << endl;
	}
	else {
		soda = a;
	}
	cout << "Finished inputting inventory" << endl;
}

int main(void) {
	char menuOption;
	int quantity;
    double subTotal, tax;
    int soldBurgers = 0, soldChiliBurgers = 0;
    int soldHotdogs = 0, soldChiliHotdogs = 0;
    int soldChili = 0, soldFryBaskets = 0, soldSoda = 0;

	cout.precision(2);
	cout << "Cash register: $" << cashRegister << endl;

	showMenu();
	do {
		if (burgerBuns <= LOWBUNS) {
			cout << "Running low on hamburger buns, only " << burgerBuns << " left" << endl;
		}
		if (hotdogBuns <= LOWBUNS) {
			cout << "Running low on hotdog buns, only " << hotdogBuns << " left" << endl;
		}
		if (burgerPatties < LOWBURGERS) {
			cout << "Running low on hamburger patties, only " << burgerPatties << " left" << endl;
		}
		if (hotdogs < LOWBURGERS) {
			cout << "Running low on hotdogs, only " << hotdogs << " left" << endl;
		}
		if (chili <= LOWCHILI) {
			cout << "Running low on chili, only " << chili << " ounces left" << endl;
		}
		if (fryBaskets <= LOWBUNS) {
			cout << "Running low on fry baskets, only " << fryBaskets << " left" << endl;
		}
		if (soda <= LOWSODA) {
			cout << "Running low on soda, only " << soda << " cans left" << endl;
		}
		cout << "Action: ";
		cin >> menuOption;

		switch (menuOption) {
			case 'i': case 'I':
				inventory();
				break;
            case 'b': case 'B': // hamburgers
                if ((burgerBuns == 0) || (burgerPatties == 0))
                    cerr << "Sorry no more burgers, because there are no more buns" << endl;
                else {
                    cout << "How many hamburgers? ";
                    cin >> quantity;
                    if ((burgerBuns - quantity) >= 0) {
                        subTotal = (double)sellHamburger(false, quantity);
                        soldBurgers += quantity;
                        // sellHamburger() takes care of tax
                        cout << "$" << fixed << subTotal << endl;
                    }
                    else {
                        cerr << "We don't have that many hamburgers" << endl;
                    }
                }
                break;
            case 'e': case 'E': // chili burgers
                if (burgerBuns == 0 || burgerPatties == 0)
                    cerr << "Sorry no more burgers, because there are no more buns" << endl;
                else if (chili < 4)
                    cerr << "Sorry not enough chili" << endl;
                else {
                    cout << "How many chili burgers? ";
                    cin >> quantity;
                    if ((burgerBuns - quantity) >= 0) {
                        subTotal = (double)sellHamburger(true, quantity);
                        cout << "$" << fixed << subTotal << endl;
                    }
                    else {
                        cerr << "We don't have that many hamburgers" << endl;
                    }
                }
                break;
			case 'h': case 'H': case 'm': case 'M':
				showMenu();
				break;
            default:
                cerr << "Unknown menu option specified" << endl;
                break;
		}
	} while (menuOption != 'q');

	return 0;
}

