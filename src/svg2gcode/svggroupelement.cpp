#include "svggroupelement.h"

SvgGroupElement::SvgGroupElement(QObject *parent)
    : SvgElement(parent)
{

}

void SvgGroupElement::parsing(QXmlStreamReader *reader)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_label = SvgElement::getString(&attribs, "label");
    m_groupType = getGroupType(m_id);
    m_type = SvgElement::SvgElementType::Group;
}

SvgGroupElement::GroupType SvgGroupElement::getGroupType(const QString &id)  //NOTE Сдесь можно добавлять группы, для обработки
{
    if(id.contains("layer", Qt::CaseInsensitive)){
        return GroupType::Layer;
    } else {
        return GroupType::Group;
    }
}
