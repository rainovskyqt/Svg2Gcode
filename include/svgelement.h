#ifndef SVGELEMENT_H
#define SVGELEMENT_H

#include <QString>
#include <QObject>
#include <QXmlStreamReader>



class SvgElement : public QObject
{
    Q_OBJECT

public:
    SvgElement(QObject *parent = nullptr);
    virtual void parsing(QXmlStreamReader* reader) = 0;

    enum SvgElementType{
        Group,
        FileData
    };

    static QString findValue(QXmlStreamAttributes* attribs, QString attributeName);

    static double getDouble(QXmlStreamAttributes* attribs, QString attributeName);
    static int getInt(QXmlStreamAttributes* attribs, QString attributeName);
    static QString getString(QXmlStreamAttributes* attribs, QString attributeName);


    SvgElementType type() const;

protected:
    QString m_ElementName;
    QString m_id;
    SvgElementType m_type;
};

#endif // SVGELEMENT_H
