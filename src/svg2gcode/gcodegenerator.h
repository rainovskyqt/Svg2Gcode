#ifndef GCODEGENERATOR_H
#define GCODEGENERATOR_H

#include "svgelement.h"

#include <QFile>
#include <QObject>

class GcodeGenerator : public QObject
{
    Q_OBJECT

public:
    explicit GcodeGenerator(QObject *parent = nullptr);

    QStringList genarate(QVector<SvgElement*> svgElementsList);

private:

};

#endif // GCODEGENERATOR_H
