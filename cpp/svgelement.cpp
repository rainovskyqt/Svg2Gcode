#include "svgelement.h"

SvgElement::SvgElement(QObject *parent)
    : QObject(parent)
{

}

QString SvgElement::findValue(QXmlStreamAttributes *attribs, QString attributeName)
{
    QString at = "";
    foreach(const QXmlStreamAttribute &attr, *attribs)
    {
        if(QString::compare(attributeName, attr.name().toString(), Qt::CaseInsensitive) == 0)
        {
            at = attr.value().toString();
        }
    }

    return at;
}

double SvgElement::getDouble(QXmlStreamAttributes *attribs, QString attributeName)
{
    double val = 0;
    QString attValue = findValue(attribs, attributeName);
    if(attValue.length() > 0)
    {
        val = attValue.toDouble();
    }

    return val;
}

int SvgElement::getInt(QXmlStreamAttributes *attribs, QString attributeName)
{
    int retval = 0;
    QString attValue =  findValue(attribs, attributeName);
    if(attValue.length() > 0)
    {
        retval = attValue.toInt();
    }

    return retval;
}

QString SvgElement::getString(QXmlStreamAttributes *attribs, QString attributeName)
{
    return findValue(attribs, attributeName);
}

SvgElement::SvgElementType SvgElement::type() const
{
    return m_type;
}
