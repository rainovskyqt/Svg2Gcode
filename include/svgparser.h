#ifndef SVGPARSER_H
#define SVGPARSER_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QXmlStreamReader>
#include <QMap>

#include "logger.h"
#include "svgelement.h"


class SvgParser
{

public slots:
    bool parsing(QXmlStreamReader* reader);
    bool parsing(QByteArray bytes);
    bool parsing(QString filePath);
    void parsingElement(QXmlStreamReader* reader);

public:
    SvgParser();


private:
    QMap<QString, SvgElement*> m_elementsDict;

    QVector<SvgElement*> m_elements;

    Logger *m_logger;

};

#endif // SVGPARSER_H
