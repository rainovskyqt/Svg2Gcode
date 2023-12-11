#include "svgpolygon.h"

SvgPolygon::SvgPolygon(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Polygon;
}

void SvgPolygon::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    SvgElement::parsing(reader, stack, style);
}

QString SvgPolygon::gcode(GCodeTool *gCodeTool)
{

}
