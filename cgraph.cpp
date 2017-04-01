#include "cgraph.h"
#include <qpainter.h>
#include <QMouseEvent>

CGraph::CGraph(QWidget *parent) : QWidget(parent)
{
    m_xMax = 2;
    m_yMax = 2;

    m_mousePressed = false;
    legP = {1,1};
}

void CGraph::paintEvent(QPaintEvent *)
{
    updateMargins();

    drawAxis();

    drawLeg();
}

void CGraph::mousePressEvent(QMouseEvent *event)
{
    m_mousePressed = true;
    m_mouseXPos = event->x();
    m_mouseYPos = event->y();
    repaint();
}

void CGraph::mouseReleaseEvent(QMouseEvent *event)
{
    m_mousePressed = false;
    m_mouseXPos = event->x();
    m_mouseYPos = event->y();
    repaint();
}

void CGraph::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePressed)
    {
        m_mouseXPos = event->x();
        m_mouseYPos = event->y();
        repaint();
    }
}

void CGraph::drawAxis(void)
{
    QPainter painter(this);
    QPen pen = QPen(Qt::darkGray);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);

    // Draw x axis
    painter.drawLine(m_xleft, m_ymid, m_xright , m_ymid );

    // Draw y axis
    painter.drawLine(m_xmid, m_ytop, m_xmid , m_ybottom );
}

void CGraph::updateMargins(void)
{
    m_xleft = rect().x();
    m_xmid = m_xleft + (rect().width() / 2);
    m_xright = m_xleft + rect().width();

    m_ytop = rect().y();
    m_ymid = m_ytop + (rect().height() / 2);
    m_ybottom = m_ytop + rect().height();
}

void CGraph::drawLeg(void)
{
    QPainter painter(this);
    QPen pen = QPen(Qt::blue);
    painter.setPen(pen);

    if (m_mousePressed)
    {
        legP = toLogicPoint({m_mouseXPos, m_mouseYPos});
    }

    widgetPoint widP = toWidgetPoint(legP);
    painter.drawLine(m_xmid, m_ymid, widP.x, widP.y);
}

widgetPoint CGraph::toWidgetPoint(logicPoint p)
{
    widgetPoint retP;
    retP.x = m_xmid + (int)((p.x * rect().width() / 2) / m_xMax);
    retP.y = m_ymid - (int)((p.y * rect().height() / 2) / m_yMax);
    return retP;
}

logicPoint CGraph::toLogicPoint(widgetPoint p)
{
    logicPoint retP;
    retP.x = ((double)(p.x - m_xmid) * m_xMax) / ((double)(rect().width()) / 2.0);
    retP.y = ((double)(m_ymid - p.y) * m_yMax) / ((double)(rect().height()) / 2.0);
    return retP;
}
