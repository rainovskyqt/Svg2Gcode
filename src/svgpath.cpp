#include "svgpath.h"

SvgPath::SvgPath(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Path;
}

void SvgPath::parsing(QXmlStreamReader *reader, const SvgTranformStack stack)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_transformStack = parseTranform(getString(&attribs, "transform"), stack);
}

QString SvgPath::gcode()
{
    QString gcode;

    foreach (SvgElement* element, m_elements) {
        gcode.append(element->gcode());
        element->deleteLater();
    }
    gcode.append("Path\n");

    return gcode;
}
