#include "cgraph.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CGraph g;
    g.show();
    return a.exec();
}
