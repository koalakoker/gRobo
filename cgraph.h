#ifndef CGRAPH_H
#define CGRAPH_H

#include <QWidget>

class CGraph : public QWidget
{
    Q_OBJECT
public:
    explicit CGraph(QWidget *parent = 0);

private:
    void paintEvent(QPaintEvent *event);
    void drawAxis(void);

signals:

public slots:
};

#endif // CGRAPH_H
