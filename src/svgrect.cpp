#include "svgrect.h"

SvgRect::SvgRect(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Rect;
}

void SvgRect::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_start.setX(SvgElement::getDouble(&attribs, "x"));
    m_start.setY(SvgElement::getDouble(&attribs, "y"));
    m_width = SvgElement::getDouble(&attribs, "width");
    m_height = SvgElement::getDouble(&attribs, "height");
    m_radiusX = SvgElement::getDouble(&attribs, "rx");
    m_radiusY = SvgElement::getDouble(&attribs, "ry");

    SvgElement::parsing(reader, stack, style);
}

QString SvgRect::gcode(GCodeTool *gCodeTool)
{
    return QString("Rectangle: s_x: %1, s_y: %2, w: %3, h: %4\n").arg(m_start.x()).arg(m_start.y()).arg(m_width).arg(m_height);
}
