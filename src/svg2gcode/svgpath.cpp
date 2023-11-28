#include "svgpath.h"
#include "qdebug.h"

SvgPath::SvgPath(QObject *parent)
    : SvgElement{parent}
{

}

void SvgPath::parsing(QXmlStreamReader *reader, const SvgTranformStack stack)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_type = SvgElement::SvgElementType::Path;
    m_transformStack = parseTranform(getString(&attribs, "transform"), stack);
}

QStringList SvgPath::gcode()
{
return QStringList();
}
