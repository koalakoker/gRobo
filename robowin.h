#ifndef ROBOWIN_H
#define ROBOWIN_H

#include <QMainWindow>

namespace Ui {
class RoboWin;
}

class RoboWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoboWin(QWidget *parent = 0);
    ~RoboWin();

private:
    Ui::RoboWin *ui;
};

#endif // ROBOWIN_H
