/* Qt5 SQLite example
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 26, 2021 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
