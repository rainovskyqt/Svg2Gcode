#include "svgelement.h"
#include "logger.h"
#include "svgemptyelement.h"
#include "svgpath.h"
#include "svgfiledata.h"
#include "svggroupelement.h"
#include "svgtranformparser.h"
#include "svgellipse.h"
#include "svgline.h"
#include "svgcircle.h"

SvgElement::SvgElement(QObject *parent)
    : QObject(parent)
{

}

void SvgElement::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_transformStack = parseTranform(getString(&attribs, "transform"), stack);
    m_style = parseStyle(reader, style);
}

SvgElement *SvgElement::element(const QString &name)
{
    if(name == "")
        return nullptr;

    Logger::instance()->write(QString("Обраружен элемент %1").arg(name));

    if (QString::compare(name, "svg", Qt::CaseInsensitive) == 0){
        Logger::instance()->write(QString("Создали svg элемент SvgFileData"));
        return new SvgFileData();
    } else if (QString::compare(name, "g", Qt::CaseInsensitive) == 0){
        return new SvgGroupElement();
        Logger::instance()->write(QString("Создали svg элемент группы"));
    } else if (QString::compare(name, "path", Qt::CaseInsensitive) == 0){
        Logger::instance()->write(QString("Создали svg элемент path"));
        return new SvgPath();
    } else if (QString::compare(name, "ellipse", Qt::CaseInsensitive) == 0){
        Logger::instance()->write(QString("Создали svg элемент ellipse"));
        return new SvgEllipse();
    } else if (QString::compare(name, "line", Qt::CaseInsensitive) == 0){
            Logger::instance()->write(QString("Создали svg элемент line"));
            return new SvgLine();
    } else if (QString::compare(name, "circle", Qt::CaseInsensitive) == 0){
        Logger::instance()->write(QString("Создали svg элемент circle"));
        return new SvgCircle();
    } else if (QString::compare(name, "d", Qt::CaseInsensitive) == 0){
        Logger::instance()->write(QString("Создали svg элемент path"));
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

QVector<SvgElement *> SvgElement::elements()
{
    return m_elements;
}

SvgTranformStack SvgElement::transformStack() const
{
    return m_transformStack;
}

SvgStyle SvgElement::style() const
{
    return m_style;
}

SvgTranformStack SvgElement::parseTranform(const QString &transform, SvgTranformStack stack)
{
    SvgTranformParser parser;
    m_transformStack = parser.parse(transform, stack);

    return m_transformStack;
}

SvgStyle SvgElement::parseStyle(QXmlStreamReader *reader, SvgStyle parentStyle)
{
    m_style.copy(parentStyle);
    m_style.parsing(reader);
    return m_style;
}

bool SvgElement::isHidden()
{
    return m_style.visibility() == "hidden";
}

