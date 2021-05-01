#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tello.h"
#include <QWidget>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QDebug>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);


private slots:

    void on_pushButton_emergency_clicked();

    void on_pushButton_takeOff_clicked();

    void on_pushButton_land_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_up_clicked();


    void on_pushButton_keyboard_clicked();

    void on_pushButton_2_Commands_clicked();

    void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

   // void on_pushButton_2_stream_clicked();

private:
    Ui::MainWindow *ui;
    Tello telloDrone;
};
#endif // MAINWINDOW_H
