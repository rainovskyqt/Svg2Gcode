#include "svgpolygon.h"

SvgPolygon::SvgPolygon(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Polygon;
}

void SvgPolygon::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{

}

QString SvgPolygon::gcode()
{

}
