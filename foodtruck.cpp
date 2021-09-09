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
extern int burgerBuns;
extern int hotdogs;
extern int hotdogBuns;
extern int chili;
extern int fryBaskets;
extern int soda;
extern double cashRegister;

double sellHamburger(bool chili, int quantity = 1) {
	
}

double sellHotdog(bool chili, int quantity = 1) {
	
}

void showMenu(void) {
	
}

int main(void) {
	burgerPatties = MAXBURGERS;
	burgerBuns = MAXBUNS;
	hotdogs = MAXBURGERS;
	hotdogBuns = MAXBUNS;
	chili = MAXCHILI;
	fryBaskets = MAXBURGERS;
	soda = MAXSODA;
	cashRegister = 0.0;
	
	char menuOption;
	int quantity;
	double subTotal;
	double tax;
	
	return 0;
}

