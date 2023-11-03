#ifndef SVGELEMENT_H
#define SVGELEMENT_H

#include <QString>
#include <QXmlStreamReader>



class SvgElement
{

public:
    SvgElement();
    virtual void parsing(QXmlStreamReader* reader) = 0;

    static QString findValue(QXmlStreamAttributes* attribs, QString attributeName);

    static double getDouble(QXmlStreamAttributes* attribs, QString attributeName);
    static int    getInt(QXmlStreamAttributes* attribs, QString attributeName);
    static QString getString(QXmlStreamAttributes* attribs, QString attributeName);



protected:
    QString m_ElementName;
    QString m_id;

};

#endif // SVGELEMENT_H
