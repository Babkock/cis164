/* Color Selector
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 11, 2021 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDial>
#include <QLineEdit>
#include <QSlider>
#include <QGraphicsRectItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void editUpdate();
    void sliderUpdate();
    void buttonClicked();

    void on_redSlider_valueChanged(int value);
    void on_greenSlider_valueChanged(int value);
    void on_blueSlider_valueChanged(int value);
private:
    Ui::MainWindow *ui;
    void updateValues(QLineEdit* edit, QDial* slider);
    QGraphicsRectItem *colorRectangle;
    void updatePreview();
};
#endif // MAINWINDOW_H
