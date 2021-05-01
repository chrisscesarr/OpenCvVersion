#ifndef TELLO_H
#define TELLO_H
#define DISTANCE 100
#include <iostream>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QObject>
#include <unistd.h>
#include <string>
#include <QtDebug>
#include <QShortcut>


#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

using cv::CAP_FFMPEG
using cv::imshow;
using cv::VideoCapture;
using cv::waitKey;


using namespace std;

class Tello :public QObject
{
    Q_OBJECT
private:
    QUdpSocket *udpSocket;
    QHostAddress telloAddress;
public:
    Tello();

    void turnMediaStreamOn();

    void emergency();
     void stop();
    void takeOff();
    void land();
    void initializeSDK();
    void right(int mm);
    void left(int mm);
    void down(int mm);
   void up(int mm);

public slots:
    void receiveUDP();
};

#endif // TELLO_H
