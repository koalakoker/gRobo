#include "cgraph.h"
#include <qpainter.h>

CGraph::CGraph(QWidget *parent) : QWidget(parent)
{

}

void CGraph::paintEvent(QPaintEvent *)
{
    drawAxis();
}

void CGraph::drawAxis(void)
{
    QPainter painter(this);
    QPen pen = QPen(Qt::darkGray);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);

    int xleft = rect().x();
    int xmid = xleft + (rect().width() / 2);
    int xright = xleft + rect().width();

    int ytop = rect().y();
    int ymid = ytop + (rect().height() / 2);
    int ybottom = ytop + rect().height();

    // Draw x axis
    painter.drawLine(xleft, ymid, xright , ymid );

    // Draw y axis
    painter.drawLine(xmid, ytop, xmid , ybottom );
}
