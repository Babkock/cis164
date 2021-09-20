/* Rebel Food Truck
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 19, 2021
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "foodtruck.h"
using namespace std;

/* Writes a listing of all transactions to the given filename, or
 * to stdout if there is none */
void sales(const string & filename) {
	if (!filename.empty()) {
        ofstream salesReport;
        double z = 0.0;
        int sum = 0;
        salesReport.open(filename.c_str());
        salesReport.precision(2);
        cout << "Written sales report to " << filename << endl;

        if (soldBurgers.size() > 0) {
            for (const transaction& t : soldBurgers)
                sum += t.quantity;

            salesReport << "Hamburgers sold: " << sum << endl;
            salesReport << "Hamburger transactions: " << soldBurgers.size() << endl;
            salesReport << "-----------------------------------" << endl;

            for (const transaction& t : soldBurgers) {
                salesReport << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            salesReport << "-----------------------------------" << endl;
            salesReport << "Total from hamburgers:\t$" << fixed << z << endl;
            salesReport << "-----------------------------------" << endl;
        }
        else {
            salesReport << "No hamburgers sold :(" << endl;
            salesReport << "-----------------------------------" << endl;
        }
        
        if (soldHotdogs.size() > 0) {
            sum = 0;
            for (const transaction& t : soldHotdogs)
                sum += t.quantity;

            salesReport << "Hotdogs sold: " << sum << endl;
            salesReport << "Hotdog transactions: " << soldHotdogs.size() << endl;
            salesReport << "-----------------------------------" << endl;

            z = 0.0;
            for (const transaction& t : soldHotdogs) {
                salesReport << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            salesReport << "-----------------------------------" << endl;
            salesReport << "Total from hotdogs: $" << fixed << z << endl;
            salesReport << "-----------------------------------" << endl;
        }
        else {
            salesReport << "No hotdogs sold :(" << endl;
            salesReport << "-----------------------------------" << endl;
        }
        
        if (chiliBurgers.size() > 0) {
            sum = 0;
            for (const transaction& t : chiliBurgers)
                sum += t.quantity;

            salesReport << "Chili burgers sold: " << sum << endl;
            salesReport << "Chili burger transactions: " << chiliBurgers.size() << endl;
            salesReport << "-----------------------------------" << endl;

            z = 0.0;
            for (const transaction& t : chiliBurgers) {
                salesReport << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            salesReport << "-----------------------------------" << endl;
            salesReport << "Total from chili burgers:\t$" << fixed << z << endl;
            salesReport << "-----------------------------------" << endl;
        }
        else {
            salesReport << "No chili burgers sold :(" << endl;
            salesReport << "-----------------------------------" << endl;
        }
        
        if (chiliHotdogs.size() > 0) {
            sum = 0;
            for (const transaction& t : chiliHotdogs)
                sum += t.quantity;

            salesReport << "Chili hotdogs sold: " << sum << endl;
            salesReport << "Chili hotdog transactions: " << chiliHotdogs.size() << endl;
            salesReport << "-----------------------------------" << endl;

            z = 0.0;
            for (const transaction& t : chiliHotdogs) {
                salesReport << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            salesReport << "-----------------------------------" << endl;
            salesReport << "Total from chili hotdogs:\t$" << fixed << z << endl;
            salesReport << "-----------------------------------" << endl;
        }
        else {
            salesReport << "No chili hotdogs sold :(" << endl;
            salesReport << "-----------------------------------" << endl;
        }

        if (soldChili.size() > 0) {
            sum = 0;
            for (const transaction& t : soldChili)
                sum += t.quantity;

            salesReport << "Chili containers sold: " << sum << endl;
            salesReport << "Chili transactions: " << soldChili.size() << endl;
            salesReport << "-----------------------------------" << endl;

            z = 0.0;
            for (const transaction& t : soldChili) {
                salesReport << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            salesReport << "-----------------------------------" << endl;
            salesReport << "Total from chili containers:\t$" << fixed << z << endl;
            salesReport << "-----------------------------------" << endl;
        }
        else {
            salesReport << "No chili containers sold :(" << endl;
            salesReport << "-----------------------------------" << endl;
        }

        if (soldBaskets.size() > 0) {
            sum = 0;
            for (const transaction& t : soldBaskets)
                sum += t.quantity;

            salesReport << "Fry baskets sold: " << sum << endl;
            salesReport << "Fry basket transactions: " << soldBaskets.size() << endl;
            salesReport << "-----------------------------------" << endl;
            
            z = 0.0;
            for (const transaction& t : soldBaskets) {
                salesReport << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            salesReport << "-----------------------------------" << endl;
            salesReport << "Total from fry baskets:\t$" << fixed << z << endl;
            salesReport << "-----------------------------------" << endl;
        }
        else {
            salesReport << "No fry baskets sold :( Now little Bibby Jr. is gonna get dehydrated and fat" << endl;
            salesReport << "-----------------------------------" << endl;
        }

        if (soldSoda.size() > 0) {
            sum = 0;
            for (const transaction& t : soldSoda)
                sum += t.quantity;

            salesReport << "Cans of soda sold: " << sum << endl;
            salesReport << "Soda transactions: " << soldSoda.size() << endl;
            salesReport << "----------------------------------" << endl;

            z = 0.0;
            for (const transaction& t : soldSoda) {
                salesReport << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            salesReport << "----------------------------------" << endl;
            salesReport << "Total from soda:\t$" << fixed << z << endl;
            salesReport << "----------------------------------" << endl;
        }
        else {
            salesReport << "No soda sold :(" << endl;
            salesReport << "----------------------------------" << endl;
        }
        salesReport << "Total sales:\t\t$" << fixed << cashRegister << endl;

        salesReport.close();
    }
    else {
        double z = 0.0;
        int sum = 0;
        if (soldBurgers.size() > 0) {
            for (const transaction& t : soldBurgers)
                sum += t.quantity;

            cout << "Hamburgers sold: " << sum << endl;
            cout << "Hamburger transactions: " << soldBurgers.size() << endl;

            for (const transaction& t : soldBurgers) {
                cout << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            cout << "Total from hamburgers:\t$" << fixed << z << endl << endl;
        }
        else {
            cout << "Wow business must be really bad" << endl;
        }   

        if (soldHotdogs.size() > 0) {
            sum = 0;
            for (const transaction& t : soldHotdogs)
                sum += t.quantity;

            cout << "Hotdogs sold: " << sum << endl;
            cout << "Hotdog transactions: " << soldHotdogs.size() << endl;

            z = 0.0;
            for (const transaction& t : soldHotdogs) {
                cout << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            cout << "Total from hotdogs:\t$" << fixed << z << endl << endl;
        }
        else {
            cout << "No hotdogs sold :(" << endl;
        }

        if (chiliBurgers.size() > 0) {
            sum = 0;
            for (const transaction& t : chiliBurgers)
                sum += t.quantity;

            cout << "Chili burgers sold: " << sum << endl;
            cout << "Chili burger transactions: " << chiliBurgers.size() << endl;

            z = 0.0;
            for (const transaction& t : chiliBurgers) {
                cout << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            cout << "Total from chili burgers:\t$" << fixed << z << endl << endl;
        }
        else {
            cout << "No chili burgers sold :(" << endl;
        }

        if (chiliHotdogs.size() > 0) {
            sum = 0;
            for (const transaction& t : chiliHotdogs)
                sum += t.quantity;

            cout << "Chili hotdogs sold: " << sum << endl;
            cout << "Chili hotdog transactions: " << chiliHotdogs.size() << endl;

            z = 0.0;
            for (const transaction& t : chiliHotdogs) {
                cout << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            cout << "Total from chili hotdogs:\t$" << fixed << z << endl << endl;
        }
        else {
            cout << "No chili hotdogs sold :(" << endl;
        }

        if (soldChili.size() > 0) {
            sum = 0;
            for (const transaction& t : soldChili)
                sum += t.quantity;

            cout << "Chili containers sold: " << sum << endl;
            cout << "Chili transactions: " << soldChili.size() << endl;

            z = 0.0;
            for (const transaction& t : soldChili) {
                cout << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            cout << "Total from chili containers: $" << fixed << z << endl;
        }
        else {
            cout << "No chili containers sold :(" << endl;
        }

        if (soldBaskets.size() > 0) {
            sum = 0;
            for (const transaction& t : soldBaskets)
                sum += t.quantity;

            cout << "Fry baskets sold: " << sum << endl;
            cout << "Fry basket transactions: " << soldBaskets.size() << endl;

            z = 0.0;
            for (const transaction& t : soldBaskets) {
                cout << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            cout << "Total from fry baskets:\t$" << fixed << z << endl << endl;
        }
        else {
            cout << "No fry baskets sold :(" << endl;
        }

        if (soldSoda.size() > 0) {
            sum = 0;
            for (const transaction& t : soldSoda)
                sum += t.quantity;

            cout << "Cans of soda sold: " << sum << endl;
            cout << "Soda transactions: " << soldSoda.size() << endl;

            z = 0.0;
            for (const transaction& t : soldSoda) {
                cout << t.quantity << "\t\t\t\t$" << fixed << t.total << endl;
                z += t.total;
            }
            cout << "Total from soda:\t$" << fixed << z << endl << endl;
        }
        else {
            cout << "No soda sold :(" << endl;
        }

        cout << "Total sales:\t\t$" << fixed << cashRegister << endl;
    }
    return;
}
