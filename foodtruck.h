#ifndef FOODTRUCK_H
#define FOODTRUCK_H

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

double sellHamburger(bool ch, int quantity);
double sellHotdog(bool ch, int quantity);
void showMenu(void);
void inventory(void);

#endif
