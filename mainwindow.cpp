#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_emergency_clicked()
{
    telloDrone.emergency();
}


void MainWindow::on_pushButton_takeOff_clicked()
{
    telloDrone.takeOff();

}

void MainWindow::on_pushButton_land_clicked()
{
    telloDrone.land();
}


void MainWindow::on_pushButton_right_clicked()
{
    telloDrone.right(DISTANCE);

}

void MainWindow::on_pushButton_down_clicked()
{
    telloDrone.down(DISTANCE);
}

void MainWindow::on_pushButton_left_clicked()
{
     telloDrone.left(DISTANCE);
}

void MainWindow::on_pushButton_up_clicked()
{
     telloDrone.up(DISTANCE);
}




void MainWindow::keyPressEvent(QKeyEvent *event)
     {
         if(event->key() == Qt::Key_D)
         {
            telloDrone.right(DISTANCE);

         }
         if(event->key() == Qt::Key_A)
         {
             telloDrone.left(DISTANCE);
         }
         if(event->key() == Qt::Key_S)
         {
             telloDrone.down(DISTANCE);
         }
         if(event->key() == Qt::Key_W)
         {
             telloDrone.up(DISTANCE);
         }
         if(event->key() == Qt::Key_J)
         {
             telloDrone.takeOff();
         }
         if(event->key() == Qt::Key_L)
         {
             telloDrone.land();
         }
         if(event->key() == Qt::Key_K)
         {
             telloDrone.emergency();
         }
     }









void MainWindow::on_pushButton_keyboard_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_Commands_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    QString plainText = ui->textEdit->toPlainText();

    QStringList list;

    list = plainText.split("\n");

    QStringList num;

    int parameter;



    for ( int i = 0; i < list.size() ; i++ ){

        num = list[i].split(" ");









        if (num[0] == "right"){

            parameter = num[1].toInt();
            if (parameter >= 20 && parameter <= 500){
            telloDrone.right(parameter);

            }
        }





        if (num[0] == "left"){
             parameter = num[1].toInt();
            if ( parameter >= 20 && parameter <= 500 ){
            telloDrone.left(parameter);

            }
        }





        if (num[0] == "up"){
             parameter = num[1].toInt();
            if ( parameter >= 20 && parameter <= 500 ){
            telloDrone.up(parameter);

            }
        }






        if (num[0] == "down"){
            parameter = num[1].toInt();
            if ( parameter >= 20 && parameter <= 500 ){
            telloDrone.down(parameter);

            }
        }






        if (num[0] == "takeoff"){

            telloDrone.takeOff();
        }

        if (num[0] == "land"){

            telloDrone.land();
        }


        if (num[0] == "wait"){
            parameter = num[1].toInt();
            sleep(parameter);

        }



    }


}





void MainWindow::on_pushButton_2_stream_clicked()
{
    telloDrone.turnMediaStreamOn();
}


void MainWindow::on_pushButton_2_KeyStream_clicked()
{
     telloDrone.turnMediaStreamOn();
}
