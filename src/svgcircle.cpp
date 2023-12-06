#include "svgcircle.h"

SvgCircle::SvgCircle(QObject *parent)
    : SvgElement{parent}
{

}

void SvgCircle::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{

}

QString SvgCircle::gcode()
{
    return "Circle\n";
}
