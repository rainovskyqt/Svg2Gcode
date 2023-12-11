#include "svgpath.h"
#include "gcodecomments.h"

SvgPath::SvgPath(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Path;
}

void SvgPath::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    QXmlStreamAttributes attribs = reader->attributes();

    SvgElement::parsing(reader, stack, style);
}

QString SvgPath::gcode(GCodeTool *gCodeTool)
{
    QString gcode;

    gcode.append(GCodeComments().toString(QString("Start path %1").arg(m_id)));

    foreach (SvgElement* element, m_elements) {
        gcode.append(element->gcode(gCodeTool));
        element->deleteLater();
    }
    gcode.append(GCodeComments().toString(QString("End path %1").arg(m_id)));

    return gcode;
}
