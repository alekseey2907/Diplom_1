#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QDebug>
#include <QtNetwork>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PB_send_clicked();

    void on_lineEdit_send_returnPressed();

    void on_PB_Narrow_clicked();

    void on_PB_Wide_clicked();

    void on_PB_Narrow_clicked(bool checked);

    void on_PB_Wide_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    quint16 senderPort_send = 12345;
    QUdpSocket *udpSocket;
    QTimer timer;
    QHostAddress receiverAddress;// ("127.0.0.1");
};
#endif // MAINWINDOW_H
