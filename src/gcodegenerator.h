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

    QString genarate(SvgElement *rootElement);

private:

};

#endif // GCODEGENERATOR_H
