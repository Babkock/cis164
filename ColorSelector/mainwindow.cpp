/* Color Selector
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 11, 2021 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExpValidator>
#include <ctime>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->redSlider->setRange(0, 255);
    ui->greenSlider->setRange(0, 255);
    ui->blueSlider->setRange(0, 255);

    ui->redSlider->setValue(0);
    ui->greenSlider->setValue(0);
    ui->blueSlider->setValue(0);

    ui->redEdit->setText("0");
    ui->greenEdit->setText("0");
    ui->blueEdit->setText("0");

    QRegExpValidator* numValidater = new QRegExpValidator(QRegExp("\\d*"));
    ui->redEdit->setValidator(numValidater);
    ui->greenEdit->setValidator(numValidater);
    ui->blueEdit->setValidator(numValidater);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->colorView->setScene(scene);
    colorRectangle = scene->addRect(0, 0, ui->colorView->width(), ui->colorView->height(), QPen(Qt::black), QBrush(Qt::black));
    colorRectangle->update();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updatePreview(void) {
    colorRectangle->setBrush(QBrush(QColor(ui->redSlider->value(),
                                           ui->greenSlider->value(),
                                           ui->blueSlider->value())));
    colorRectangle->update();
}

void MainWindow::updateValues(QLineEdit* edit, QDial* dial) {
    int value = edit->text().toInt();
    if (value > 255) {
        edit->setText("255");
        value = 255;
    } else if (value < 0) {
        edit->setText("0");
        value = 0;
    }

    dial->setValue(value);
}

void MainWindow::editUpdate(void) {
    updateValues(ui->redEdit, ui->redSlider);
    updateValues(ui->greenEdit, ui->greenSlider);
    updateValues(ui->blueEdit, ui->blueSlider);
    updatePreview();
}

void MainWindow::sliderUpdate(void) {
    ui->redEdit->setText(QString::number(ui->redSlider->value()));
    ui->greenEdit->setText(QString::number(ui->greenSlider->value()));
    ui->blueEdit->setText(QString::number(ui->blueSlider->value()));
    updatePreview();
}

void MainWindow::buttonClicked(void) {
    int c1, c2, c3;
    srand(time(nullptr));
    c1 = rand() % 256;
    c2 = rand() % 256;
    c3 = rand() % 256;

    ui->redSlider->setValue(c1);
    ui->greenSlider->setValue(c2);
    ui->blueSlider->setValue(c3);

    ui->redEdit->setText(QString::number(c1));
    ui->greenEdit->setText(QString::number(c2));
    ui->blueEdit->setText(QString::number(c3));

    updatePreview();
}

void MainWindow::on_redSlider_valueChanged(int value)
{
    ui->redEdit->setText(QString::number(value));
    sliderUpdate();
}

void MainWindow::on_greenSlider_valueChanged(int value)
{
    ui->greenEdit->setText(QString::number(value));
    sliderUpdate();
}

void MainWindow::on_blueSlider_valueChanged(int value)
{
    ui->blueEdit->setText(QString::number(value));
    sliderUpdate();
}
