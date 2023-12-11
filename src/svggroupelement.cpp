#include "gcodecomments.h"
#include "svggroupelement.h"

SvgGroupElement::SvgGroupElement(QObject *parent)
    : SvgElement(parent)
{
    m_type = SvgElementType::Group;
}

void SvgGroupElement::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_label = SvgElement::getString(&attribs, "label");
    m_groupType = getGroupType(m_id);

    SvgElement::parsing(reader, stack, style);
}

QString SvgGroupElement::gcode(GCodeTool *gCodeTool)
{
    if(isHidden())
        return "";

    QString gcode;

    gcode.append(GCodeComments().toString(QString("Start layer %1").arg(m_label)));

    foreach (SvgElement* element, m_elements) {
        gcode.append(element->gcode(gCodeTool));
        element->deleteLater();
    }
    gcode.append(GCodeComments().toString(QString("End layer %1").arg(m_id)));
    return gcode;
}

SvgGroupElement::GroupType SvgGroupElement::getGroupType(const QString &id)  //NOTE Сдесь можно добавлять группы, для обработки
{
    if(id.contains("layer", Qt::CaseInsensitive)){
        return GroupType::Layer;
    } else {
        return GroupType::Group;
    }
}
