#include "svgline.h"

SvgLine::SvgLine(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Line;
}

void SvgLine::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{

}

QString SvgLine::gcode()
{
    return "Line\n";
}
