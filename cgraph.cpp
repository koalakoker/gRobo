#include "cgraph.h"
#include <qpainter.h>

CGraph::CGraph(QWidget *parent) : QWidget(parent)
{

}

void CGraph::paintEvent(QPaintEvent *)
{
    updateMargins();

    drawAxis();
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
