#include "robowin.h"
#include "ui_robowin.h"

RoboWin::RoboWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoboWin)
{
    ui->setupUi(this);
}

RoboWin::~RoboWin()
{
    delete ui;
}
