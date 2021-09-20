/* Rebel Food Truck
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 18, 2021
*/
#include <iostream>
#include <string>
#include "foodtruck.h"
using namespace std;

/* Prompt for an integer with given string, and return the received input */
int iprompt(const string & p) {
    int val;
    cout << p;
    cin >> val;
    return val;
}

/* Do not print newline */
char cprompt(const string & p) {
    char val;
    cout << p;
    cin >> val;
    return val;
}

/* Show the entire menu for inputting orders, setting
 * inventory, and quitting */
void showMenu(void) {
    cout << "Welcome to Billy's Burgs and Furts" << endl;
    cout << "Type one of the following characters to do something" << endl << endl;
    cout << "'i'\t\tUpdate inventory for each item" << endl;
    cout << "'q'\t\tQuits the program" << endl;
    cout << "'h'\t\tShows this menu" << endl;
    cout << "'m'\t\tShows this menu" << endl;
    cout << "'r'\t\tShow cash register balance" << endl;
    
    if ((burgerBuns > 0) && (burgerPatties > 0)) {
        cout << "'b'\t\tHamburger(s) $5.00\t\t" << burgerBuns << " left" << endl;
        if (chili > 4) {
            cout << "'e'\t\tChili hamburger(s) $7.00" << endl;
        }
    }
    if ((hotdogBuns > 0) && (hotdogs > 0)) {
        cout << "'d'\t\tHotdog(s) $5.00\t\t" << hotdogBuns << " left" << endl;
        if (chili > 4) {
            cout << "'g'\t\tChili hotdog(s) $7.00" << endl;
        }
    }
    if (chili >= 12) {
        cout << "'c'\t\t12 oz. container of chili $4.00\t" << chili << " ounces left" << endl;
    }
    if (fryBaskets > 0) {
        cout << "'f'\t\tBasket of fries $7.00\t" << fryBaskets << " left" << endl;
    }
    if (soda > 0) {
        cout << "'s'\t\tCan of soda $2.00\t" << soda << " cans left" << endl;
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
    return;
}
