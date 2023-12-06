#include "svgline.h"

SvgLine::SvgLine(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Line;
}

void SvgLine::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_transformStack = parseTranform(getString(&attribs, "transform"), stack);
    m_start.setX(SvgElement::getDouble(&attribs,"x1"));
    m_start.setY(SvgElement::getDouble(&attribs,"y1"));
    m_end.setX(SvgElement::getDouble(&attribs,"x2"));
    m_end.setY(SvgElement::getDouble(&attribs,"y2"));
}

QString SvgLine::gcode()
{

    return QString("Line: s_x: %1, s_y: %2, e_x: %3, e_y: %4\n").arg(m_start.x()).arg(m_start.y()).arg(m_end.x()).arg(m_end.y()) ;
}

QPointF SvgLine::start() const
{
    return m_start;
}

QPointF SvgLine::end() const
{
    return m_end;
}
