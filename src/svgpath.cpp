#include "svgpath.h"
#include "gcodecomments.h"

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

    gcode.append(GCodeComments().toString(QString("Start path %1").arg(m_id)));

    foreach (SvgElement* element, m_elements) {
        gcode.append(element->gcode());
        element->deleteLater();
    }
    gcode.append(GCodeComments().toString(QString("End path %1").arg(m_id)));

    return gcode;
}
