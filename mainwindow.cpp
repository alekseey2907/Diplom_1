#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 1234); // Привязываем сокет к любому адресу и порту 1234
   /* connect(&timer, &QTimer::timeout, this, &MainWindow::on_PB_Narrow_clicked);
    connect(&timer, &QTimer::timeout, this, &MainWindow::on_PB_Wide_clicked);
    connect(&timer, &QTimer::timeout, this, &MainWindow::on_PB_Narrow_clicked);
    connect(&timer, &QTimer::timeout, this, &MainWindow::on_PB_Wide_clicked);*/
           timer.start(1000); // Отправляем данные каждую секунду


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PB_send_clicked()
{

    QByteArray datagram = ui->lineEdit_send->text().toUtf8();
    udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, senderPort_send);
    if(udpSocket)
    {
        ui->lineEdit_send->clear();
    }
}


void MainWindow::on_lineEdit_send_returnPressed()
{
    QByteArray datagram = ui->lineEdit_send->text().toUtf8();
    udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, senderPort_send);
    if(udpSocket)
    {
        ui->lineEdit_send->clear();
    }
}


void MainWindow::on_PB_Narrow_clicked()
{
  /*  ui->PB_Wide->setEnabled(false);
    ui->PB_Narrow->setEnabled(true);
    int randomValue_Narrow = QRandomGenerator::global()->bounded(1000, 300000);
     QByteArray datagram =  QByteArray::number(randomValue_Narrow);
    udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, senderPort_send);
    if(udpSocket)
    {
        ui->lineEdit_send->clear();
    }*/
}


void MainWindow::on_PB_Wide_clicked()
{
  /*  ui->PB_Narrow->setEnabled(false);
    int randomValue_Wide = QRandomGenerator::global()->bounded(300000, 6500001);
     QByteArray datagram =  QByteArray::number(randomValue_Wide);
    udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, senderPort_send);
    if(udpSocket)
    {
        ui->lineEdit_send->clear();
    }*/
}


void MainWindow::on_PB_Narrow_clicked(bool checked)
{
    if(checked==true)
    {
        int flag = 1;
    //while(true)
        if(flag==1)
    {
        int randomValue_Narrow = QRandomGenerator::global()->bounded(1000, 300000);
         QByteArray datagram =  QByteArray::number(randomValue_Narrow);
        udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, senderPort_send);
        if(udpSocket)
        {
            ui->lineEdit_send->clear();
        }

          flag=2;
    }

    }
}


void MainWindow::on_PB_Wide_clicked(bool checked)
{
    if(checked==true)
    {
        int flag = 1;
      if(flag==1)
        {
        int randomValue_Wide = QRandomGenerator::global()->bounded(300000, 6500001);
         QByteArray datagram =  QByteArray::number(randomValue_Wide);
        udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, senderPort_send);
        if(udpSocket)
        {
            ui->lineEdit_send->clear();
        }
        QApplication::processEvents();
          QThread::sleep(1000);
       // delay(1000);
        }
    }
}

