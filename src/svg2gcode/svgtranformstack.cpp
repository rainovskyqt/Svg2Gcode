#include "svgtranformstack.h"

#include <QtMath>

SvgTranformStack::SvgTranformStack()
{

}

void SvgTranformStack::push(Transformation trans)
{
    m_stack.append(trans);
}

void SvgTranformStack::pop()
{
    m_stack.pop_back();
}

void SvgTranformStack::pushMatrix(Transformation trans)
{
    push(trans);
}

void SvgTranformStack::pushRotate(double rotation)
{
    rotation = qDegreesToRadians(rotation);
    Transformation t;
    //Отформатировано как матричное представление
    t.a = qCos(rotation);   t.c = -qSin(rotation);   t.e = 0;
    t.b = qSin(rotation);   t.d =  qCos(rotation);   t.f = 0;

    push(t);
}

void SvgTranformStack::pushRotate(double rotation, double cx, double cy)
{
    pushTranslate(cx, cy);

    pushRotate(rotation);

    pushTranslate(-cx, -cy);
}

void SvgTranformStack::pushScale(double sx, double sy)
{
    Transformation t;
    t.a = sx;
    t.c = 0;
    t.e = 0;
    t.b = 0;
    t.d = sy;
    t.f = 0;

    push(t);
}

void SvgTranformStack::pushTranslate(double tx, double ty)
{

    Transformation t;
    t.a = 1;
    t.c = 0;
    t.e = tx;
    t.b = 0;
    t.d = 1;
    t.f = ty;

    push(t);
}

void SvgTranformStack::pushSkew(double sx, double sy)
{
    Transformation t;
    t.a = 1;
    t.c = qTan(sx);
    t.e = 0;
    t.b = qTan(sy);
    t.d = 1;
    t.f = 0;

    push(t);
}

QPointF SvgTranformStack::process(double x, double y)
{
    //Стандартная компоновка матрицы
    // { a, c, e }  {x}
    // { b, d, f }  {y}

    //Обрабатываем каждое преобразование по порядку, сначала самое новое.
    // x' = a*x + c*y + e
    // y' = b*x + d*y + f

    QPointF result(x, y);

    for (int i = m_stack.size(); i > 0; --i)
    {
        Transformation t = m_stack.at(i - 1);
        result.setX(t.a * x + t.c * y + t.e);
        result.setY(t.b * x + t.d * y + t.f);

        x = result.x();
        y = result.y();
    }

    return result;
}
