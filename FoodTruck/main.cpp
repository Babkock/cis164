/* Rebel Food Truck
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 18, 2021
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "foodtruck.h"
using namespace std;

int burgerPatties = MAXBURGERS;
int burgerBuns = MAXBUNS;
int hotdogs = MAXBURGERS;
int hotdogBuns = MAXBUNS;
int chili = MAXCHILI;
int fryBaskets = MAXBUNS;
int soda = MAXSODA;
double cashRegister = 0.0;

int main(void) {
    char menuOption;
    int quantity;
    double subTotal, tax;

    vector<transaction> soldBurgers;
    vector<transaction> soldHotdogs;
    vector<transaction> chiliBurgers;
    vector<transaction> chiliHotdogs;
    vector<transaction> soldChili;
    vector<transaction> soldBaskets;
    vector<transaction> soldSoda;

    cout.precision(2);
    cout << "Cash register: $" << fixed << cashRegister << endl;

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
        menuOption = cprompt(string("Action: "));

        switch (menuOption) {
            case 'i': case 'I':
                inventory();
                break;

            case 'b': case 'B': // hamburgers
                if ((burgerBuns == 0) || (burgerPatties == 0))
                    cerr << "Sorry no more burgers" << endl;
                else {
                    quantity = iprompt(string("How many hamburgers? "));
                    if ((burgerBuns - quantity) >= 0) {
                        subTotal = (double)sellHamburger(false, quantity);
                        // sellHamburger() takes care of tax
                        cout << "$" << fixed << subTotal << endl;

                        soldBurgers.push_back({ .quantity = quantity, .total = subTotal });
                    }
                    else {
                        cerr << "We don't have that many hamburgers" << endl;
                    }
                }
                break;

            case 'e': case 'E': // chili burgers
                if (burgerBuns == 0 || burgerPatties == 0)
                    cerr << "Sorry no more burgers" << endl;
                else if (chili < 4)
                    cerr << "Sorry not enough chili" << endl;
                // there has to be enough chili, and enough patties and buns
                else {
                    quantity = iprompt(string("How many chili burgers? "));
                    if (quantity <= burgerBuns) {
                        subTotal = (double)sellHamburger(true, quantity);
                        cout << "$" << fixed << subTotal << endl;

                        chiliBurgers.push_back({ .quantity = quantity, .total = subTotal });
                    }
                    else
                        cerr << "We don't have that many hamburgers" << endl;
                }
                break;

            case 'd': case 'D': // hot dogs
                if (hotdogBuns == 0 || hotdogs == 0)
                    cerr << "Sorry no more hotdogs" << endl;
                else {
                    quantity = iprompt(string("How many hot dogs? "));
                    if (quantity <= hotdogBuns) {
                        subTotal = (double)sellHotdog(false, quantity);
                        cout << "$" << fixed << subTotal << endl;

                        soldHotdogs.push_back({ .quantity = quantity, .total = subTotal });
                    }
                    else
                        cerr << "We don't have that many hot dogs" << endl;
                }
                break;

            case 'g': case 'G': // chili hot dogs
                if (hotdogBuns == 0 || hotdogs == 0)
                    cerr << "Sorry no more hot dogs" << endl;
                else if (chili < 4)
                    cerr << "Sorry not enough chili" << endl;
                else {
                    quantity = iprompt(string("How many chili hotdogs? "));
                    if (quantity <= hotdogBuns) {
                        subTotal = (double)sellHotdog(true, quantity);
                        cout << "$" << fixed << subTotal << endl;

                        chiliHotdogs.push_back({ .quantity = quantity, .total = subTotal });
                    }
                    else
                        cerr << "We don't have that many hot dogs" << endl;
                }
                break;

            case 'c': case 'C': // chili
                if (chili < 12)
                    cerr << "Sorry not enough chili for an order" << endl;
                else {
                    quantity = iprompt(string("How many 12-oz containers of chili? "));
                    if ((quantity * 12) >= chili) {
                        chili -= (quantity * 12);
                        // four dollars per 12-oz container
                        subTotal = (4.00 * quantity);
                        tax = (5.00 / 100.00) * subTotal;

                        cashRegister += (subTotal + tax);
                        cout << "$" << fixed << (subTotal + tax) << endl;

                        soldChili.push_back({ .quantity = (quantity * 12), .total = (subTotal + tax) });
                    }
                    else
                        cerr << "We don't have that much chili" << endl;
                }
                break;

            case 'f': case 'F': // fry baskets
                if (fryBaskets > 0) {
                    cout << "How many baskets of fries? ";
                    cin >> quantity;
                    if (quantity <= fryBaskets) {
                        fryBaskets -= quantity;
                        subTotal = (7.00 * quantity);
                        tax = (5.0 / 100.0) * subTotal;

                        cashRegister += (subTotal + tax);

                        soldBaskets.push_back({ .quantity = quantity, .total = (subTotal + tax) });
                    }
                    else
                        cerr << "We don't have that many fry baskets" << endl;
                }
                break;

            case 's': case 'S': // soda

                break;

            case 'h': case 'H': case 'm': case 'M':
                showMenu();
                break;
            case 'r': case 'R':
                cout << "Cash register: $" << fixed << cashRegister << endl;
                break;
            case 'q': case 'Q':
                break;
            default:
                cerr << "Unknown menu option specified" << endl;
                break;
        }
    } while (menuOption != 'q' && menuOption != 'Q');

    cout << "Hamburgers sold: " << soldBurgers.size() << endl;
    cout << "Hamburger sales:" << endl;
    double z = 0.0;
    for (const transaction& t : soldBurgers) {
        cout << t.quantity << "\t\t$" << fixed << t.total << endl;
        z += t.total;
    }
    cout << "Total made from hamburgers: $" << fixed << z << endl << endl;

    cout << "Hotdogs sold: " << soldHotdogs.size() << endl;
    cout << "Hotdog sales:" << endl;
    z = 0.0;
    for (const transaction& t : soldHotdogs) {
        cout << t.quantity << "\t\t$" << fixed << t.total << endl;
        z += t.total;
    }
    cout << "Total made from hotdogs: $" << fixed << z << endl << endl;

    return 0;
}
