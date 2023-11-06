#ifndef GCODEGENERATOR_H
#define GCODEGENERATOR_H

#include "svgelement.h"

#include <QFile>
#include <QObject>

class GcodeGenerator : public QObject
{
    Q_OBJECT

public:
    explicit GcodeGenerator(QString desFile, QObject *parent = nullptr);

    bool genarate(QVector<SvgElement*> svgElementsList);

private:
    QFile * m_gcodeFile;

};

#endif // GCODEGENERATOR_H
