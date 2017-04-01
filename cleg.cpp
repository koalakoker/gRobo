#include "cleg.h"
#include <math.h>

CLeg::CLeg(CLeg *parent = 0, double lenght = 1, double angle = 0)
{
    this->parent = parent;
    this->lenght = lenght;
    this->angle = angle;
}

CLeg::CLeg()
{
    this->parent = 0;
    this->lenght = 1;
    this->angle = 0;
}

double CLeg::x(void)
{
    double xRet = 0;
    if (parent)
    {
        xRet = parent->x();
        xRet += lenght * cos(angle + parent->angle);
    }
    else
    {
        xRet = lenght * cos(angle);
    }
    return xRet;
}

double CLeg::y(void)
{
    double yRet = 0;
    if (parent)
    {
        yRet = parent->y();
        yRet += lenght * sin(angle + parent->angle);
    }
    else
    {
        yRet = lenght * sin(angle);
    }
    return yRet;
}

double CLeg::originX(void)
{
    double xRet = 0;
    if (parent)
    {
        xRet = parent->x();
    }
    return xRet;
}

double CLeg::originY(void)
{
    double yRet = 0;
    if (parent)
    {
        yRet = parent->y();
    }
    return yRet;
}
