#ifndef SVGPARSER_H
#define SVGPARSER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QFile>
#include <QXmlStreamReader>
#include <QMap>

#include "logger.h"
#include "svgelement.h"


class SvgParser: public QObject
{
    Q_OBJECT

public slots:
    QVector<SvgElement *> parsing(QXmlStreamReader* reader);
    QVector<SvgElement *> parsing(QByteArray bytes);
    QVector<SvgElement *>  parsing(QString filePath);
    void setLog(QString logFilePath = QString(), bool consoleLog = true);

public:
    SvgParser(QObject *parent = nullptr);


private:
    QMap<QString, SvgElement*> m_elementsDict;

    QVector<SvgElement*> m_elements;

    void parsingElement(QXmlStreamReader* reader);
};

#endif // SVGPARSER_H
