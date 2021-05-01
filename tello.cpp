#include "tello.h"


Tello::Tello()
{
    telloAddress.setAddress("192.168.10.1");
    udpSocket = new QUdpSocket();
    //udpSocket->bind(telloAddress, 8889);
    udpSocket->connectToHost(telloAddress, 8889);
    if (udpSocket->waitForConnected(1000))
        qDebug("Connected");
    QObject::connect(udpSocket, SIGNAL(readyRead()), SLOT(receiveUDP()));
    initializeSDK();

}

void Tello::initializeSDK()
{
    QString command;
     command.append("command");
     udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
}



void Tello::turnMediaStreamOn()
{
    QString command;
    command.append("streamon");
     udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);


    VideoCapture capture{"udp://0.0.0.0.11111", CAP_FFMPEG};
    while(true)
    {

        cv::Mat frame;
        capture >> frame;
        imshow("CTello Stream", frame);
        if (waitKey(1) == 27){

            break;


        }


    }

}






void Tello::emergency()
{
    QString command;
     command.append("emergency");
     udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
     //cout << "EMERGENCY!!" << endl;


}

void Tello::stop()
{
    QString command;
     command.append("stop");
     udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
     //cout << "STOP!!" << endl;


}


void Tello::takeOff()
{
    QString command;
     command.append("takeoff");
    udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
    // cout << "TAKE OFF!!" << endl;


}

void Tello::land()
{
    QString command;
    command.append("land");
    udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
    // cout << "LANDED!!" << endl;
}

void Tello::receiveUDP()
{
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        std::cout << datagram.data().toStdString() << " received\n";

    }
}

void Tello::right(int mm)
{
    QString command = "";
     QString distance = QString::number(mm);
      command.append("right " + distance);
       udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
       // qDebug() << command;
}

void Tello::left(int mm)
{
    QString command = "";
     QString distance = QString::number(mm);
      command.append("left " + distance);
       udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
       // qDebug() << command;
}

void Tello::down(int mm)
{
    QString command = "";
     QString distance = QString::number(mm);
      command.append("down " + distance);
       udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
      // qDebug() << command;
}

void Tello::up(int mm)
{
    QString command = "";
     QString distance = QString::number(mm);
      command.append("up " + distance);
       udpSocket->writeDatagram(command.toUtf8(), telloAddress, 8889);
        //qDebug() << command;
}




