#include "svgellipse.h"

SvgEllipse::SvgEllipse(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Ellipse;
}

void SvgEllipse::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{

}

QString SvgEllipse::gcode()
{
    return "Ellipse\n";
}
