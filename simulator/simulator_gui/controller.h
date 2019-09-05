#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "simulator.h"
#include <QMainWindow>
#include "ui_mainwindow.h"

Ui::MainWindow* ui=nullptr;

void HandleEvent(bool state,QLCDNumber* lcd)
{
    if(state)
    {
        lcd->display(1111);
    }
    else
    {
        lcd->display(0);
    }
}


void ViewControl()
{
    while(true)
    {
        ui->lcdNumber_7->display(get_ticks());
        HandleEvent(LEDs[0],ui->lcdNumber);
        HandleEvent(LEDs[1],ui->lcdNumber_2);
        HandleEvent(LEDs[2],ui->lcdNumber_3);
        HandleEvent(Buttons[0],ui->lcdNumber_4);
        HandleEvent(Buttons[1],ui->lcdNumber_5);
        HandleEvent(Buttons[2],ui->lcdNumber_6);
    }
}


#endif // CONTROLLER_H
