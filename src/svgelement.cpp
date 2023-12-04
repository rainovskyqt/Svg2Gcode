#include "svgelement.h"
#include "logger.h"
#include "svgemptyelement.h"
#include "svgpath.h"
#include "svgfiledata.h"
#include "svggroupelement.h"
#include "svgtranformparser.h"

SvgElement::SvgElement(QObject *parent)
    : QObject(parent)
{

}

SvgElement *SvgElement::element(const QString &name)
{
    Logger::instance()->write(QString("Обраружен элемент %1").arg(name));

    if(QString::compare(name, "svg") == 0){
        Logger::instance()->write(QString("Создали svg элемент SvgFileData"));
        return new SvgFileData();
    } else if (QString::compare(name, "g") == 0){
        return new SvgGroupElement();
    } else if (QString::compare(name, "path") == 0){
        return new SvgPath();
    }

    return new SvgEmptyElement();
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

void SvgElement::addСhild(SvgElement *element)
{
    m_elements.append(element);
}

SvgTranformStack SvgElement::parseTranform(const QString &transform, SvgTranformStack stack)
{
    SvgTranformParser parser;
    m_transformStack = parser.parse(transform, stack);

    return m_transformStack;
}
