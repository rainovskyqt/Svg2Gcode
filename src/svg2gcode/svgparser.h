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

public:
    SvgParser(QObject *parent = nullptr);
    ~SvgParser();

    QVector<SvgElement *> parsing(QXmlStreamReader *reader);

private:
    QVector<SvgElement*> m_elements;

    void parsingElement(QXmlStreamReader* reader, SvgTranformStack stack);
};

#endif // SVGPARSER_H
