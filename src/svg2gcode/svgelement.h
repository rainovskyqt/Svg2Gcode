#ifndef SVGELEMENT_H
#define SVGELEMENT_H

#include <QString>
#include <QObject>
#include <QXmlStreamReader>



class SvgElement : public QObject
{
    Q_OBJECT

public:
    explicit SvgElement(QObject *parent = nullptr);
    virtual void parsing(QXmlStreamReader* reader) = 0;

    enum SvgElementType{
        Group,
        FileData
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
};

#endif // SVGELEMENT_H
