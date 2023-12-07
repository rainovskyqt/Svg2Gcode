#include "svgcircle.h"

SvgCircle::SvgCircle(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Circle;
}

void SvgCircle::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_transformStack = parseTranform(getString(&attribs, "transform"), stack);
    m_center.setX(SvgElement::getDouble(&attribs, "cx"));
    m_center.setY(SvgElement::getDouble(&attribs, "cy"));
    m_radius = SvgElement::getDouble(&attribs, "r");
}

QString SvgCircle::gcode()
{
    return QString("Circle: c_x: %1, c_y: %2, r: %3\n").arg(m_center.x()).arg(m_center.y()).arg(m_radius) ;
}
