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
    void updateMargins(void);
    void drawAxis(void);

    int m_xleft;
    int m_xmid;
    int m_xright;

    int m_ytop;
    int m_ymid;
    int m_ybottom;

signals:

public slots:
};

#endif // CGRAPH_H
