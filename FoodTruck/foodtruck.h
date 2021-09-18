/* Rebel Food Truck
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 18, 2021
*/
#ifndef FOODTRUCK_H
#define FOODTRUCK_H

#include <string>

#define MAXBUNS 75
#define MAXSODA 200
#define MAXBURGERS 200
#define MAXCHILI 500
#define LOWBUNS 15
#define LOWSODA 40
#define LOWBURGERS 10
#define LOWCHILI 100
#define ENTREE 5.0
#define CENTREE 7.0

extern int burgerPatties;
extern int burgerBuns;
extern int hotdogs;
extern int hotdogBuns;
extern int chili;
extern int fryBaskets;
extern int soda;
extern double cashRegister;

typedef struct {
    int quantity;
    double total;
} transaction;

double sellHamburger(bool ch, int quantity);
double sellHotdog(bool ch, int quantity);
int iprompt(const std::string & p);
char cprompt(const std::string & p);
void showMenu(void);
void inventory(void);

#endif
