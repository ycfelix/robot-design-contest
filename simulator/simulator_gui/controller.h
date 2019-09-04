#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "simulator.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
using namespace simple_mode;

Ui::MainWindow* ui=nullptr;

void robotics_work(){

    int ticks = get_ticks();
    while(true){
        if (get_ticks() == ticks) { continue; }
        if (button_pressed(BUTTON1))
        {
            ui->lcdNumber_4->display(1);
            ui->lcdNumber->display(1);
        }
        else
        {
            ui->lcdNumber_4->display(0);
            ui->lcdNumber->display(0);
        }
    }
}

#endif // CONTROLLER_H
