#include "svgelement.h"
#include "svgstyle.h"

SvgStyle::SvgStyle()
{
    m_fill = QString();
    m_stroke = QString();
    m_strokeWidth = 0;
    m_strokeLinecap = QString();
    m_strokeLineJoin = QString();
    m_strokeMiterlimit = 0;
    m_strokeDasharray = QVector<double>();
    m_strokeDashoffset = 0;
    m_strokeOpacity = 0;
    m_visibility = "visible";
}

void SvgStyle::parsing(QXmlStreamReader *reader)
{
    QXmlStreamAttributes attribs = reader->attributes();
    QString input = SvgElement::getString(&attribs, "style");
    if(input != ""){
        QStringList parameters = input.split(";", QString::SkipEmptyParts);
        foreach (QString parameter, parameters) {
            QStringList data = parameter.simplified().split(":", QString::SkipEmptyParts);
            if(QString::compare(data.at(0), "fill", Qt::CaseInsensitive) == 0){
                m_fill = data.at(1);
            } else if(QString::compare(data.at(0), "stroke", Qt::CaseInsensitive) == 0){
                m_stroke = data.at(1);
            } else if(QString::compare(data.at(0), "stroke-width", Qt::CaseInsensitive) == 0){
                m_strokeWidth = data.at(1).toDouble();
            } else if(QString::compare(data.at(0), "stroke-linecap", Qt::CaseInsensitive) == 0){
                m_strokeLinecap = data.at(1);
            } else if(QString::compare(data.at(0), "stroke-linejoin", Qt::CaseInsensitive) == 0){
                m_strokeLineJoin = data.at(1);
            } else if(QString::compare(data.at(0), "stroke-miterlimit", Qt::CaseInsensitive) == 0){
                m_strokeMiterlimit = data.at(1).toDouble();
            } else if(QString::compare(data.at(0), "stroke-dasharray", Qt::CaseInsensitive) == 0){
                foreach (QString val, data.at(1).split(",")) {
                    m_strokeDasharray.append(val.toDouble());
                }
            } else if(QString::compare(data.at(0), "stroke-dashoffset", Qt::CaseInsensitive) == 0){
                m_strokeDashoffset = data.at(1).toDouble();
            } else if(QString::compare(data.at(0), "stroke-opacity", Qt::CaseInsensitive) == 0){
                m_strokeOpacity = data.at(1).toDouble();
            } else if(QString::compare(data.at(0), "visibility", Qt::CaseInsensitive) == 0){
                m_visibility = data.at(1).toDouble();
            }
        }
    } else {
        QString val = SvgElement::getString(&attribs, "fill");
        if(val != "")
            m_fill = val;
        val = SvgElement::getString(&attribs, "stroke");
        if(val != "")
            m_stroke = val;
        val = SvgElement::getString(&attribs, "stroke-width");
        if(val != "")
            m_strokeWidth = val.toDouble();
        val = SvgElement::getString(&attribs, "stroke-linecap");
        if(val != "")
            m_strokeLinecap = val;
        val = SvgElement::getString(&attribs, "stroke-linejoin");
        if(val != "")
            m_strokeLineJoin = val;
        val = SvgElement::getString(&attribs, "stroke-miterlimit");
        if(val != "")
            m_strokeMiterlimit = val.toDouble();
        val = SvgElement::getString(&attribs, "stroke-dasharray");
        if(val != "")
            foreach (QString val, val.split(",")) {
                m_strokeDasharray.append(val.toDouble());
            }
        val = SvgElement::getString(&attribs, "stroke-dashoffset");
        if(val != "")
            m_strokeDashoffset = val.toDouble();
        val = SvgElement::getString(&attribs, "stroke-opacity");
        if(val != "")
            m_strokeOpacity = val.toDouble();
        val = SvgElement::getString(&attribs, "visibility");
        if(val != "")
            m_visibility = val;
    }
}

QString SvgStyle::fill() const
{
    return m_fill;
}

QString SvgStyle::stroke() const
{
    return m_stroke;
}

double SvgStyle::strokeWidth() const
{
    return m_strokeWidth;
}

QString SvgStyle::strokeLinecap() const
{
    return m_strokeLinecap;
}

QString SvgStyle::strokeLineJoin() const
{
    return m_strokeLineJoin;
}

double SvgStyle::strokeMiterlimit() const
{
    return m_strokeMiterlimit;
}

QVector<double> SvgStyle::strokeDasharray() const
{
    return m_strokeDasharray;
}

double SvgStyle::strokeDashoffset() const
{
    return m_strokeDashoffset;
}

double SvgStyle::strokeOpacity() const
{
    return m_strokeOpacity;
}

QString SvgStyle::visibility() const
{
    return m_visibility;
}

void SvgStyle::copy(SvgStyle style)
{
    m_fill = style.fill();
    m_stroke = style.stroke();
    m_strokeWidth = style.strokeWidth();
    m_strokeLinecap = style.strokeLinecap();
    m_strokeLineJoin = style.strokeLineJoin();
    m_strokeMiterlimit = style.strokeMiterlimit();
    m_strokeDasharray = style.strokeDasharray();
    m_strokeDashoffset = style.strokeDashoffset();
    m_strokeOpacity = style.strokeOpacity();
    m_visibility = style.visibility();
}
