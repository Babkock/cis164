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
void salesReport(string filename) {
	if (!filename.empty()) {
        ofstream salesReport;
        salesReport.open(filename.c_str());
        salesReport.precision(2);
        cout << "Written sales report to " << filename << endl;

        salesReport << "Hamburgers sold: " << soldBurgers.size() << endl;
        salesReport << "Hamburger sales:" << endl;
        salesReport << "-----------------" << endl;

        double z = 0.0;
        for (const transaction& t : soldBurgers) {
            salesReport << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        salesReport << "-----------------" << endl;
        salesReport << "Total made from hamburgers: $" << fixed << z << endl;
        salesReport << "-----------------" << endl;

        salesReport << "Hotdogs sold: " << soldHotdogs.size() << endl;
        salesReport << "Hotdog sales:" << endl;
        salesReport << "-----------------" << endl;
        z = 0.0;
        for (const transaction& t : soldHotdogs) {
            salesReport << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        salesReport << "-----------------" << endl;
        salesReport << "Total made from hotdogs: $" << fixed << z << endl;
        salesReport << "-----------------" << endl;

        salesReport << "Chili burgers sold: " << chiliBurgers.size() << endl;
        salesReport << "Chili burger sales:" << endl;
        salesReport << "-----------------" << endl;
        z = 0.0;
        for (const transaction& t : chiliBurgers) {
            salesReport << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        salesReport << "-----------------" << endl;
        salesReport << "Total made from chili burgers: $" << fixed << z << endl;
        salesReport << "-----------------" << endl;

        salesReport << "Chili hotdogs sold: " << chiliHotdogs.size() << endl;
        salesReport << "Chili hotdog sales:" << endl;
        salesReport << "-----------------" << endl;
        z = 0.0;
        for (const transaction& t : chiliHotdogs) {
            cout << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        salesReport << "-----------------" << endl;
        salesReport << "Total made from chili hotdogs: $" << fixed << z << endl;
        salesReport << "-----------------" << endl;

        salesReport << "Fry baskets sold: " << soldBaskets.size() << endl;
        salesReport << "Fry basket sales:" << endl;
        salesReport << "-----------------" << endl;
        z = 0.0;
        for (const transaction& t : soldBaskets) {
            cout << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        salesReport << "-----------------" << endl;
        salesReport << "Total made from fry baskets: $" << fixed << z << endl;
        salesReport << "-----------------" << endl;
        salesReport << "Total money: $" << fixed << cashRegister << endl;

        salesReport.close();
    }
    else {
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

        cout << "Chili burgers sold: " << chiliBurgers.size() << endl;
        cout << "Chili burger sales:" << endl;
        z = 0.0;
        for (const transaction& t : chiliBurgers) {
            cout << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        cout << "Total made from chili burgers: $" << fixed << z << endl << endl;

        cout << "Chili hotdogs sold: " << chiliHotdogs.size() << endl;
        cout << "Chili hotdog sales:" << endl;
        z = 0.0;
        for (const transaction& t : chiliHotdogs) {
            cout << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        cout << "Total made from chili hotdogs: $" << fixed << z << endl << endl;

        cout << "Fry baskets sold: " << soldBaskets.size() << endl;
        cout << "Fry basket sales:" << endl;
        z = 0.0;
        for (const transaction& t : soldBaskets) {
            cout << t.quantity << "\t\t$" << fixed << t.total << endl;
            z += t.total;
        }
        cout << "Total made from fry baskets: $" << fixed << z << endl << endl;
    }
    return;
}
