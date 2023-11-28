#ifndef SVGELEMENT_H
#define SVGELEMENT_H

#include "svgtranformstack.h"

#include <QString>
#include <QObject>
#include <QXmlStreamReader>



class SvgElement : public QObject
{
    Q_OBJECT

public:
    explicit SvgElement(QObject *parent = nullptr);
    virtual void parsing(QXmlStreamReader* reader, SvgTranformStack stack) = 0;
    virtual QStringList gcode() = 0;

    enum SvgElementType{
        Group,
        FileData,
        Path
    };

    static SvgElement *element(const QString &name);
    QString findValue(QXmlStreamAttributes* attribs, QString attributeName);
    double getDouble(QXmlStreamAttributes* attribs, QString attributeName);
    int getInt(QXmlStreamAttributes* attribs, QString attributeName);
    QString getString(QXmlStreamAttributes* attribs, QString attributeName);



    SvgElementType type() const;

protected:
    QString m_ElementName;
    QString m_id;
    SvgElementType m_type;

    SvgTranformStack m_transformStack;

    SvgTranformStack parseTranform(const QString &transform, SvgTranformStack stack);
};

#endif // SVGELEMENT_H
