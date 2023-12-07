#include "svggroupelement.h"

SvgGroupElement::SvgGroupElement(QObject *parent)
    : SvgElement(parent)
{
    m_type = SvgElementType::Group;
}

void SvgGroupElement::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_label = SvgElement::getString(&attribs, "label");
    m_groupType = getGroupType(m_id);
    m_transformStack = parseTranform(getString(&attribs, "transform"), stack);
}

QString SvgGroupElement::gcode()
{
    QString gcode;

    gcode.append(QString("Start layer %1\n").arg(m_label));

    foreach (SvgElement* element, m_elements) {
        gcode.append(element->gcode());
        element->deleteLater();
    }
    gcode.append(QString("End layer %1\n").arg(m_id));
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
