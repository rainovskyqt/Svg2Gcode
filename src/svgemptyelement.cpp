#include "svgemptyelement.h"

SvgEmptyElement::SvgEmptyElement(QObject *parent)
    : SvgElement{parent}
{
        m_type = SvgElementType::Empty;
}

void SvgEmptyElement::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{
    Q_UNUSED(stack)

    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
}

QString SvgEmptyElement::gcode()
{
    return "";
}
