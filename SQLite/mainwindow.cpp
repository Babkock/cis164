/* Qt SQLite example
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 25, 2021 */
#include <iostream>
#include <cstdlib>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    const QString DRIVER("QSQLITE");

    if (!QSqlDatabase::isDriverAvailable(DRIVER)) {
        std::cerr << "Driver is not available" << std::endl;
        delete ui;
        abort();
    }
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setHostName("babcocksql");
    db.setDatabaseName("mydb");
    db.setUserName("user");
    db.setPassword("password");
    if (!db.open()) {
        std::cerr << "Could not open database" << std::endl;
        delete ui;
        abort();
    }
    QSqlQuery create("CREATE TABLE `people` (`id` INTEGER PRIMARY KEY, `first` VARCHAR(90), `last` VARCHAR(90))");
    QSqlQuery ins1("INSERT INTO `people` VALUES (1, 'George', 'Washington')");
    QSqlQuery ins2("INSERT INTO `people` VALUES (2, 'Abraham', 'Lincoln')");
    QSqlQuery ins3("INSERT INTO `people` VALUES (3, 'Thomas', 'Jefferson')");
    QSqlQuery ins4("INSERT INTO `people` VALUES (4, 'Franklin D.', 'Rosevelt'");
}

MainWindow::~MainWindow(void) {
    delete ui;
}

void MainWindow::on_search_clicked(void)
{
    QSqlQuery first, last;
    QString fullName;
    std::cout << "Search button clicked" << std::endl;

    first.prepare("SELECT `first` FROM `people` WHERE `id` = ?");
    first.addBindValue(ui->idInput->text().toInt());
    if (!first.exec()) {
        std::cerr << "Could not execute select statement" << std::endl;
    }
    else {
        if (first.first()) {
            fullName = first.value(0).toString();
            last.prepare("SELECT `last` FROM `people` WHERE `id` = ?");
            last.addBindValue(ui->idInput->text().toInt());
            last.exec();
            if (last.first())
                fullName += " " + last.value(0).toString();
        }
        else {
            fullName = "Person not found";
        }

        ui->nameOutput->setText(fullName);
    }
}
