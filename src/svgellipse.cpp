#include "svgellipse.h"

SvgEllipse::SvgEllipse(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Ellipse;
}

void SvgEllipse::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_transformStack = parseTranform(getString(&attribs, "transform"), stack);
    m_center.setX(SvgElement::getDouble(&attribs, "cx"));
    m_center.setY(SvgElement::getDouble(&attribs, "cy"));
    m_radiusX = SvgElement::getDouble(&attribs, "rx");
    m_radiusY = SvgElement::getDouble(&attribs, "ry");
}

QString SvgEllipse::gcode()
{
    return QString("Ellipse: c_x: %1, c_y: %2, r_x: %3, r_y: %4\n").arg(m_center.x()).arg(m_center.y()).arg(m_radiusX).arg(m_radiusY);
}
