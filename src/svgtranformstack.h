#ifndef SVGTRANFORMSTACK_H
#define SVGTRANFORMSTACK_H

#include <QPointF>
#include <QVector>


struct Transformation
{
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
};

class SvgTranformStack
{



public:
    SvgTranformStack();

    void push(Transformation trans);
    void push(double a, double b, double c, double d, double e, double f);
    void pop();

    void pushMatrix(Transformation trans);
    void pushRotate(double rotation);
    void pushRotate(double rotation, double cx, double cy);
    void pushScale(double sx, double sy);
    void pushTranslate(double tx, double ty);
    void pushSkew(double sx, double sy);

    QPointF process(double x, double y);
    QPointF process(QPointF point);

private:
    QVector<Transformation> m_stack;
};

#endif // SVGTRANFORMSTACK_H
