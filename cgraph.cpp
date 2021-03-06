#include "cgraph.h"
#include <qpainter.h>
#include <QMouseEvent>

CGraph::CGraph(QWidget *parent) : QWidget(parent)
{
    m_xMax = 2;
    m_yMax = 2;

    m_mousePressed = false;
    legP = {1,1};

    m_rootLeg = new CLeg();
    m_childLeg = new CLeg(m_rootLeg, 1, 3.14/2.0);

    m_mode = 0;
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

    if (m_mode == 0)
    {
        m_mode = 1;
    }
    else
    {
        m_mode = 0;
    }

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

        IK(legP, m_rootLeg, m_childLeg);
    }

    widgetPoint widP = toWidgetPoint(legP);
//    painter.drawLine(m_xmid, m_ymid, widP.x, widP.y);

    // Draw legs
    drawLeg(m_rootLeg);
    drawLeg(m_childLeg);
}

void CGraph::drawLeg(CLeg* l)
{
    QPainter painter(this);
    QPen pen = QPen(Qt::red);
    painter.setPen(pen);

    logicPoint orgP = {l->originX(), l->originY()};
    widgetPoint widOrgP = toWidgetPoint(orgP);

    logicPoint P = {l->x(), l->y()};
    widgetPoint widP = toWidgetPoint(P);

    painter.drawLine(widOrgP.x, widOrgP.y, widP.x, widP.y);
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

void CGraph::IK(logicPoint p, CLeg *root, CLeg *child)
{
    double l = sqrt((p.x*p.x)+(p.y*p.y));
    double l1 = root->lenght;
    double l2 = child->lenght;
    if (l > (l1 + l2))
    {
        l = l1 + l2;
    }

    double teta = atan2(p.y,p.x);
    double psi = acos(((l1*l1)+(l*l)-(l2*l2))/(2*l1*l));
    double fi = acos(((l1*l1)+(l2*l2)-(l*l))/(2*l1*l2));

    if (m_mode == 0)
    {
        root->angle = teta - psi;
        child->angle = M_PI-fi;
    }
    else
    {
        root->angle = teta + psi;
        child->angle = fi-M_PI;
    }
}
