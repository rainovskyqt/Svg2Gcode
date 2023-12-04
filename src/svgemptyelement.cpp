#include "svgemptyelement.h"

SvgEmptyElement::SvgEmptyElement(QObject *parent)
    : SvgElement{parent}
{}

void SvgEmptyElement::parsing(QXmlStreamReader *reader, SvgTranformStack stack)
{
    Q_UNUSED(reader)
    Q_UNUSED(stack)
}

QStringList SvgEmptyElement::gcode()
{
    return QStringList();
}
