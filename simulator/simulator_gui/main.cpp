#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include "controller.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ui=w.getUI();
    thread simulator(robotics_work);
    w.show();
    return a.exec();

}
