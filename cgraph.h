#ifndef CGRAPH_H
#define CGRAPH_H

#include <QWidget>

typedef struct
{
    double x;
    double y;
} logicPoint;

typedef struct
{
    int x;
    int y;
} widgetPoint;

class CGraph : public QWidget
{
    Q_OBJECT
public:
    explicit CGraph(QWidget *parent = 0);

private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void updateMargins(void);
    void drawAxis(void);
    void drawLeg(void);

    widgetPoint toWidgetPoint(logicPoint p);
    logicPoint toLogicPoint(widgetPoint p);

    logicPoint legP;

    int m_xleft;
    int m_xmid;
    int m_xright;

    int m_ytop;
    int m_ymid;
    int m_ybottom;

    double m_xMax;
    double m_yMax;

    bool m_mousePressed;
    int m_mouseXPos;
    int m_mouseYPos;

signals:

public slots:
};

#endif // CGRAPH_H
