#ifndef SVGSTYLE_H
#define SVGSTYLE_H

#include <QString>
#include <QVector>
#include <QXmlStreamReader>


class SvgStyle
{
public:
    SvgStyle();

    void parsing(QXmlStreamReader *reader);

    QString fill() const;
    QString stroke() const;
    double strokeWidth() const;
    QString strokeLinecap() const;
    QString strokeLineJoin() const;
    double strokeMiterlimit() const;
    QVector<double> strokeDasharray() const;
    double strokeDashoffset() const;
    double strokeOpacity() const;
    QString visibility() const;
    void copy(SvgStyle style);

private:
    QString m_fill;
    QString m_stroke;
    double m_strokeWidth;
    QString m_strokeLinecap;
    QString m_strokeLineJoin;
    double m_strokeMiterlimit;
    QVector<double> m_strokeDasharray;
    double m_strokeDashoffset;
    double m_strokeOpacity;
    QString m_visibility;
};

#endif // SVGSTYLE_H
