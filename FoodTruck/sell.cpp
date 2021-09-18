/* Rebel Food Truck
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 18, 2021
*/
#include "foodtruck.h"

/* Sells hamburgers or chili hamburgers, returns the total amount
 * of the transaction */
double sellHamburger(bool ch, int quantity = 1) {
    double total; // total amount due from customer
    double tax;   // added sales tax

    if (ch) {
        total = (CENTREE * quantity);
        chili -= (4 * quantity);
    }
    else {
        total = (ENTREE * quantity);
    }
    tax = (5.0 / 100.0) * total;
    cashRegister += (total + tax);
    
    burgerPatties -= quantity;
    burgerBuns -= quantity;
    return (total + tax);
}

/* Sells hotdogs or chili hotdogs, returns the total amount
 * of the transaction */
double sellHotdog(bool ch, int quantity = 1) {
    double total;
    double tax;

    if (ch) {
        total = (CENTREE * quantity);
        chili -= (4 * quantity);
    }
    else {
        total = (ENTREE * quantity);
    }
    tax = (5.0 / 100.0) * total;
    cashRegister += (total + tax);

    hotdogs -= quantity;
    hotdogBuns -= quantity;
    return (total + tax);
}
