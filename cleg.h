#ifndef CLEG_H
#define CLEG_H


class CLeg
{
public:
    CLeg(CLeg* parent, double lenght, double angle);
    CLeg();

    double lenght;
    double angle;
    CLeg* parent;

    double x(void);
    double y(void);

    double originX(void);
    double originY(void);
};

#endif // CLEG_H
