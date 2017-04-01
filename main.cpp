#include "robowin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoboWin w;
    w.show();

    return a.exec();
}
